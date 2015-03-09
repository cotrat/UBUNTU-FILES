#include "Die.h"
#include<cstdlib>
#include <time.h>
//Argument-less Constructor

Die::Die(){
}

Die::Die(unsigned int face):m_face(face){
}

Die::~Die(){
}

unsigned int Die::getFace() const{
	return m_face;
}

void Die::roll(){
	
	m_face = rand() % 6 + 1;
}
	
