


/*********************************************************
Version 1.000

 Code provided by Michael Hemsley and Anthony Dick
 for the course 
 COMP SCI 3014/7090 Computer Graphics
 School of Computer Science
 University of Adelaide

 Permission is granted for anyone to copy, use, modify, or distribute this
 program and accompanying programs and documents for any purpose, provided
 this copyright notice is retained and prominently displayed, along with
 a note saying that the original programs are available from the aforementioned 
 course web page. 
 
 The programs and documents are distributed without any warranty, express or
 implied.  As the programs were written for research purposes only, they have
 not been tested to the degree that would be advisable in any important
 application.  All use of these programs is entirely at the user's own risk.
*********************************************************/


/**
 * A typical program flow and methods for rendering simple polygons using GLUT and openGL + GLSL
 * The comments describe ways in which you can play with the program
 */

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>
#include <fstream>

#include <GL/glew.h>

#ifdef __APPLE__
#include <GL/glut.h>
#else
#include <GL/glut.h>
#endif

#include "shader.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define WINDOW_WIDTH 	400
#define WINDOW_HEIGHT 	400

#define VALS_PER_VERT 3
#define VALS_PER_COLOUR 4
#define NUM_VERTS 3			// Total number of vertices to load/render

unsigned int vertexVaoHandle;	// Handle to our VAO generated in setShaderData method

unsigned int programID;

// These matrices will be used to update the modelview matrix in render
glm::mat4 cameraMatrix;

/**
 * Sends a single 4x4 matrix of floats to the shader program
 * @param programHandle, shader program handle
 * @param uniformLable, null terminated string with the name of uniform in the shader program
 * @param matrix, array of 16 floats to send to shader program
 * @returns 0 for success, error otherwise
 */
int setUniformMatrix(unsigned int programHandle, const char *uniformLabel, float *matrix) {

	// Get the uniform from the shader program
	// All active uniforms can be found by name using this function
	int uniformHandle = glGetUniformLocation(programHandle, uniformLabel);

	if (uniformHandle == -1) {
		std::cout << "Uniform: " << uniformLabel << " was not an active uniform label\n";
		return 1;
	}

	// Set its value to the supplied matrix
	// Note the function suffix *Matrix4fv, meaning a 4x4 matrix of floats
	// There exists many forms of this function for sending different data-types/amounts
	glUniformMatrix4fv( uniformHandle, 1, false, matrix );

	return 0;
}


/**
 * Sets the shader uniforms and vertex data
 * This happens ONCE only, before any frames are rendered
 * @param program, Shader program object to use
 * @returns 0 for success, error otherwise
 */
int setShaderData(const unsigned int &id) 
{
	// Set the program to use a (2D) orthographic projection matrix
    // and send it to the shader program.
    // This sets the visible volume to [-1, 1] in x, y, z. 
    glm::mat4 projection = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);

	// Load it to the shader program
	if ( setUniformMatrix(id, "projection_matrix", glm::value_ptr(projection)))
		return 1;

	// Create an identity matrix for our modelview matrix
    glm::mat4 modelview;

	/*
	 * What we want to draw
	 * Each set of 3 vertices (9 floats) defines one triangle
	 * You can define more triangles to draw here
	 */
	float vertices[ NUM_VERTS*VALS_PER_VERT ] = {
			-0.5f, -0.5f, -0.0f,	// Bottom left
			0.5f, -0.5f, -0.0f,		// Bottom right
			0.0f, 0.5f, -0.0f		// Top
	};
    
    // Colours for each vertex; red, green, blue and alpha
	// This data is indexed the same order as the vertex data, but reads 4 values
	// Alpha will not be used directly in this example program
	float colours[ NUM_VERTS*VALS_PER_COLOUR ] = {
            0.8f, 0.7f, 0.5f, 1.0f,
            0.3f, 0.7f, 0.1f, 1.0f,
            0.8f, 0.2f, 0.5f, 1.0f,
	};

	// Generate storage on the GPU for our triangle and make it current.
	// A VAO is a set of data buffers on the GPU
    glGenVertexArrays(1, &vertexVaoHandle);		
	glBindVertexArray(vertexVaoHandle);

	// Generate new buffers in our VAO
	// A single data buffer store for generic, per-vertex attributes
	unsigned int buffer[2];
	glGenBuffers(2, buffer);

	// Allocate GPU memory for our vertices and copy them over
	glBindBuffer(GL_ARRAY_BUFFER, buffer[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*NUM_VERTS*VALS_PER_VERT, vertices, GL_STATIC_DRAW);
    
	// Do the same for our vertex colours
	glBindBuffer(GL_ARRAY_BUFFER, buffer[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*NUM_VERTS*VALS_PER_COLOUR, colours, GL_STATIC_DRAW);

	// Now we tell OpenGL how to interpret the data we just gave it
	// Tell OpenGL what shader variable it corresponds to
    // Tell OpenGL how it's formatted (floating point, 3 values per vertex)
	int vertLoc = glGetAttribLocation(id, "a_vertex");
	glBindBuffer(GL_ARRAY_BUFFER, buffer[0]);
	glEnableVertexAttribArray(vertLoc);
	glVertexAttribPointer(vertLoc, VALS_PER_VERT, GL_FLOAT, GL_FALSE, 0, 0);
    
    // Do the same for the vertex colours
	int colourLoc = glGetAttribLocation(id, "a_colour");
	glBindBuffer(GL_ARRAY_BUFFER, buffer[1]);
	glEnableVertexAttribArray(colourLoc);
	glVertexAttribPointer(colourLoc, VALS_PER_COLOUR, GL_FLOAT, GL_FALSE, 0, 0);
    
	// An argument of zero un-binds all VAO's and stops us
    // from accidentally changing the VAO state
	glBindVertexArray(0);

	// The same is true for buffers, so we un-bind it too
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	return 0;	// return success
}


/**
 * Renders a frame of the state and shaders we have set up to the window
 * Executed each time a frame is to be drawn.
 */
void render() 
{
	// Clear the previous pixels we have drawn to the colour buffer (display buffer)
	// Clears the depth buffer which held depth information about the colour pixels
	// Called each frame so we don't draw over the top of everything previous
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glUseProgram(programID);

    cameraMatrix = glm::mat4();
    // Camera matrix defines where the camera is relative to our vertices
    // This is where we can define transformations to move vertices around
    // For example: 
    //    cameraMatrix = glm::rotate(cameraMatrix, 30.0f,
    //                                glm::vec3(0.0f, 0.0f, 1.0f));	// rotation about the Z axis
    
	// Make the VAO with our vertex data buffer current
	glBindVertexArray(vertexVaoHandle);

    // Send the updated matrix to the shader
    if ( setUniformMatrix( programID,
                           "modelview_matrix",
                           glm::value_ptr(cameraMatrix) ) ) {
        return;
    }
    
    glDrawArrays(GL_TRIANGLES, 0, NUM_VERTS);

	glBindVertexArray(0);	// Un-bind the VAO

	glutSwapBuffers();	// Swap the back buffer with the front buffer, showing what has been rendered

	glFlush();	// Guarantees previous commands have been completed before continuing
}


/**
 * Program entry. Sets up OpenGL state, GLSL Shaders and GLUT window and function call backs
 * Takes no arguments
 */
int main(int argc, char **argv) {

	// Set up GLUT window
	glutInit(&argc, argv);				// Starts GLUT systems, passing in command line args
	glutInitWindowPosition(100, 0);		// Positions the window on the screen relative to top left
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);	// Size in pixels

	// Display mode takes bit flags defining properties you want the window to have;
	//  GLUT_RGBA : Set the pixel format to have Red Green Blue and Alpha colour channels
	//  GLUT_DOUBLE : Each frame is drawn to a hidden back buffer hiding the image construction
	//  GLUT_DEPTH : A depth buffer is kept so that polygons can be drawn in-front/behind others
#ifdef __APPLE__    
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_3_2_CORE_PROFILE);
#else
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );
#endif
	
	glutCreateWindow("Simple Shader");	// Makes the actual window and displays

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}
    
	// Sets the (background) colour for each time the frame-buffer (colour buffer) is cleared
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glEnable(GL_DEPTH_TEST);

	// Set up the shaders we are to use. 0 indicates error.
	programID = LoadShaders("minimal.vert", "minimal.frag");
	if (programID == 0)
		return 1;
    
	// Set this program in use, replacing the fixed functionality with our shaders
	// This is an OpenGL state modification and persists unless changed
	glUseProgram(programID);
    
	// Set the data for the program; uniforms and generic attributes
	if (setShaderData(programID) != 0)
		return 1;

	// Render call to a function we defined, that is called each time GLUT thinks we need to update
	// the window contents, this method has our drawing logic
	glutDisplayFunc(render);

	// Start an infinite loop where GLUT handles calling methods (like render) set with glut*Func
	// calls till something kills the window
	glutMainLoop();

	return 0;
}
