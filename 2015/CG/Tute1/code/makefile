
PLATFORM := $(shell uname)

ifneq (, $(findstring CYGWIN, $(PLATFORM)))
    GL_LIBS = -lopengl32 -lglut32
	EXT = .exe
    DEFS =-DWIN32
endif

ifneq (, $(findstring Linux, $(PLATFORM)))
    GL_LIBS = -lGL -lglut -lGLEW 
	GL_LIBS += -L/usr/lib/nvidia-304 # Needed for some linux drivers
	EXT = 
    DEFS =
endif

ifneq (, $(findstring Darwin, $(PLATFORM)))
    DEFS   = -DMacOSX -D__APPLE__ -m32 -arch x86_64    
    GL_LIBS = -framework GLUT -framework OpenGL -framework CoreFoundation -lGLEW
	EXT = 
endif

LINK += shader.o 
DEFS += -I../glm-0.9.4.0/

.PHONY:  clean

all : run$(EXT)

run$(EXT) : main.o $(LINK)
	g++ $(DEFS) -o run main.o $(LINK) $(GL_LIBS)

main.o : main.cpp $(LINK)
	g++ $(DEFS) -c main.cpp

shader.o : shader.cpp shader.hpp
	g++ $(DEFS) -c shader.cpp

clean:
	rm -f *.o run$(EXT)
