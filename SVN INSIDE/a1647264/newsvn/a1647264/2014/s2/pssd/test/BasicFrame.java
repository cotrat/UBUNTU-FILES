// Import the basic graphics classes.
// based on example from Mark Graybill
import java.awt.*;
import javax.swing.*;
import java.util.*;


// a canvas on which to draw the intersecting roads of a map of Binomia

public class BasicFrame extends JFrame{

    // list of lines to draw (these are just the ones that intersect)
    ArrayList<MyLine> lines = new ArrayList<MyLine>();

    // Constructor method 
    public BasicFrame(){
	// just call the super class constructor
	super();
    }
    
    // paint method will draw the intersecting roads on the canvas of 
    // this frame whenever it is initialised or resized
    public void paint(Graphics g){
	for(MyLine l: lines){
	    g.drawLine((int)l.from.x,(int)l.from.y,(int)l.to.x,(int)l.to.y);
	}
    }

    // add a road to this canvas
    public void addLine(MyLine line){
	lines.add(line);
    }

    // main method ... NOT USED in this application but retained for testing
    public static void main(String arg[]){
	// call the constructor
	BasicFrame frame = new BasicFrame();
	// set the frame size
	frame.setSize(500,500);

	// Make the window show on the screen.
	frame.setVisible(true);
    }
}