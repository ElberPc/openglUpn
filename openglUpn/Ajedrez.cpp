#include "ajedrez.h"
#include<GL/glew.h>
#include<GL/freeglut.h>
#include<math.h>
#include<fstream>
#include<assert.h>
//#include"textura.h"

//ejemplo de codigo para las funciones
void Ajedrez::ejemplo(double x, double y, double z, double scal){
	glBegin(GL_POLYGON);
	glColor3f(0.9, 0.6, 0.4);
	glVertex3f(x, y, z);
	glVertex3f(x, y + 9 * scal, z);
	glVertex3f(x - 3 * scal, y + 6 * scal, z);
	glVertex3f(x - 3 * scal, y + 3 * scal, z);
	glEnd();
}


void Ajedrez::tablero(double x, double y, double z, double scal){
	//codigo
};


void Ajedrez::torre(double x, double y, double z, double scal){
	//codigo
};


void Ajedrez::peon(double x, double y, double z, double scal){
	//codigo
};


void Ajedrez::reina(double x, double y, double z, double scal){
	//codigo
};


void Ajedrez::rey(double x, double y, double z, double scal){
	//codigo
};


void Ajedrez::alfil(double x, double y, double z, double scal){
	//codigo
};


void Ajedrez::caballo(double x, double y, double z, double scal){
	//codigo
};