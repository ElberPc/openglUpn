#include "engine.h"
#include "ajedrez.h"
#include<GL/glew.h>
#include<GL/freeglut.h>
#include<math.h>
#include<fstream>
#include<assert.h>
#include<ctime>
//-0.01
//double xTW = -0.28, yTW = -0.52, zTW = 0.0;

void cuadrado(double x, double y, double z, double scal){
	glBegin(GL_POLYGON);
	glColor3f(0.6, 1.0, 0.6);
	glTexCoord3f(x, y, z); glVertex3f(x, y, z); //A
	glTexCoord3f(x, y + 24 * scal, z); glVertex3f(x, y + 24 * scal, z); //B
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z); glVertex3f(x - 24 * scal, y + 24 * scal, z); //C
	glTexCoord3f(x - 24 * scal, y, z); glVertex3f(x - 24 * scal, y, z); //D
	glEnd();
}

void cuadradoRed(double x, double y, double z, double scal){
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.6, 0.6);
	glTexCoord3f(x, y, z); glVertex3f(x, y, z); //A
	glTexCoord3f(x, y + 24 * scal, z); glVertex3f(x, y + 24 * scal, z); //B
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z); glVertex3f(x - 24 * scal, y + 24 * scal, z); //C
	glTexCoord3f(x - 24 * scal, y, z); glVertex3f(x - 24 * scal, y, z); //D
	glEnd();
}

//Draw chessBoard
void Engine::origin(double xx, double yy, double zz, double scal){

	//pintar tablero

	Ajedrez::tablero(xx, yy, zz, 1.0 / 180.0, 0);

	//pintar torre

	//Ajedrez::torre(-0.5, 0.0, zz, 1.0 / 200.0, 1);
	//white
	Ajedrez::torre(-0.4, 0.4, zz, 1.0 / 220.0, 0);
	Ajedrez::torre(0.524, 0.41, zz, 1.0 / 220.0, 0);
	//black
	Ajedrez::torre(-0.41, -0.52, zz, 1.0 / 220.0, 1);
	Ajedrez::torre(0.524, -0.52, zz, 1.0 / 220.0, 1);
	//pintar peon

	//white
	Ajedrez::peon(-0.42, 0.29, zz, 1.0 / 270.0, 0);
	Ajedrez::peon(0.51, 0.29, zz, 1.0 / 270.0, 0);
	Ajedrez::peon(-0.29, 0.29, zz, 1.0 / 270.0, 0);
	Ajedrez::peon(0.38, 0.29, zz, 1.0 / 270.0, 0);
	Ajedrez::peon(-0.16, 0.29, zz, 1.0 / 270.0, 0);
	Ajedrez::peon(0.25, 0.29, zz, 1.0 / 270.0, 0);
	Ajedrez::peon(-0.02, 0.29, zz, 1.0 / 270.0, 0);
	Ajedrez::peon(0.11, 0.29, zz, 1.0 / 270.0, 0);
	//black
	Ajedrez::peon(-0.42, -0.38, zz, 1.0 / 270.0, 1);
	Ajedrez::peon(0.51, -0.38, zz, 1.0 / 270.0, 1);
	Ajedrez::peon(-0.29, -0.38, zz, 1.0 / 270.0, 1);
	Ajedrez::peon(0.38, -0.38, zz, 1.0 / 270.0, 1);
	Ajedrez::peon(-0.16, -0.38, zz, 1.0 / 270.0, 1);
	Ajedrez::peon(0.25, -0.38, zz, 1.0 / 270.0, 1);
	Ajedrez::peon(-0.02, -0.38, zz, 1.0 / 270.0, 1);
	Ajedrez::peon(0.11, -0.38, zz, 1.0 / 270.0, 1);
	//pintar alfil
	//white
	Ajedrez::alfil(-0.15, 0.41, zz, 1.0 / 220.0, 0);
	Ajedrez::alfil(0.255, 0.41, zz, 1.0 / 220.0, 0);
	//black
	Ajedrez::alfil(-0.15, -0.52, zz, 1.0 / 220.0, 1);
	Ajedrez::alfil(0.255, -0.52, zz, 1.0 / 220.0, 1);
	//pintar reina

	//Ajedrez::reina(xx, yy, zz, 1.0 / 270.0, 1);

	//pintar rey
	//white
	Ajedrez::rey(0.13, 0.41, zz, 1.0 / 200.0, 0);
	//black
	Ajedrez::rey(0.13, -0.52, zz, 1.0 / 200.0, 1);
	//pintar caballo
	//white
	Ajedrez::caballo(-0.28, 0.41, zz, 1.0 / 220.0, 0);
	Ajedrez::caballo(0.39, 0.41, zz, 1.0 / 220.0, 0);
	//black
	Ajedrez::caballo(-0.28, -0.52, zz, 1.0 / 220.0, 1);
	Ajedrez::caballo(0.39, -0.52, zz, 1.0 / 220.0, 1);

	
}

//Draw level One

void Engine::levelOne(
	                   double xx, 
					   double yy, 
					   double zz, 
					   double scal, 
					   double xTW, 
					   double yTW, 
					   double xTW2, 
					   double yTW2, 
					   double xTW3, 
					   double yTW3,
					   int step, 
					   int vrt,
					   int sup){
	//pintar tablero

	Ajedrez::tablero(xx, yy, zz, 1.0 / 180.0, 0);

	//pintar torre

	//white
	Ajedrez::torre(xTW2, yTW2, zz, 1.0 / 220.0, 0);
	sup == 0 ? Ajedrez::torre(xTW, yTW, 0.0, 1.0 / 220.0, 0) : sup=1;//
	//black
	Ajedrez::torre(xTW3, yTW3, zz, 1.0 / 220.0, 1);
	Ajedrez::torre(0.25, 0.28, zz, 1.0 / 220.0, 1);
	
	// Pintar Rey
	//white
	Ajedrez::rey(-0.27, 0.41, zz, 1.0 / 200.0, 0);
	//black
	Ajedrez::rey(0.53, -0.525, zz, 1.0 / 200.0, 1);
	
	//Pintar Peon
	//white
	Ajedrez::peon(-0.42, 0.29, zz, 1.0 / 270.0, 0);
	Ajedrez::peon(-0.29, 0.29, zz, 1.0 / 270.0, 0);
	Ajedrez::peon(-0.16, 0.16, zz, 1.0 / 270.0, 0);
	Ajedrez::peon(-0.02, 0.02, zz, 1.0 / 270.0, 0);
	Ajedrez::peon(0.245, 0.02, zz, 1.0 / 270.0, 0);

	//black
	Ajedrez::peon(-0.42, -0.38, zz, 1.0 / 270.0, 1);
	Ajedrez::peon(-0.16, -0.24, zz, 1.0 / 270.0, 1);
	Ajedrez::peon(0.51, -0.115, zz, 1.0 / 270.0, 1);

	//Pintar Alfil
	//black
	Ajedrez::alfil(-0.28, -0.255, zz, 1.0 / 220.0, 1);

	//delay(3);
	if (step == 1){
		cuadrado(0.0, -0.531, 0.01, 1.0 / 180.0);
		cuadrado(-0.135, -0.531, 0.01, 1.0 / 180.0);
		cuadradoRed(-0.27, -0.4, 0.01, 1.0 / 180.0);
	}


	if (step == 2){
		cuadrado(0.4, 0.271, 0.01, 1.0 / 180.0);
		cuadrado(0.4, 0.136, 0.01, 1.0 / 180.0);
		cuadrado(0.4, 0.001, 0.01, 1.0 / 180.0);
		cuadrado(0.4, -0.134, 0.01, 1.0 / 180.0);
		cuadrado(0.4, -0.269, 0.01, 1.0 / 180.0);
		cuadrado(0.4, -0.404, 0.01, 1.0 / 180.0);
		cuadradoRed(0.265, 0.4, 0.01, 1.0 / 180.0);
		cuadradoRed(0.13, 0.4, 0.01, 1.0 / 180.0);
	}
	
	if (step == 3 && vrt == 1 ){
		cuadrado(0.13, 0.271, 0.01, 1.0 / 180.0);
		cuadrado(0.13, 0.136, 0.01, 1.0 / 180.0);
		cuadrado(0.13, 0.001, 0.01, 1.0 / 180.0);
		cuadrado(0.13, -0.134, 0.01, 1.0 / 180.0);
		cuadrado(0.13, -0.269, 0.01, 1.0 / 180.0);
		cuadrado(0.13, -0.404, 0.01, 1.0 / 180.0);
		cuadrado(0.13, -0.539, 0.01, 1.0 / 180.0);
		cuadradoRed(0.0, 0.406, 0.01, 1.0 / 180.0);
		cuadradoRed(-0.135, 0.406, 0.01, 1.0 / 180.0);
	}

	if (step == 3 && vrt == 2){
		cuadrado(0.53, -0.392, 0.01, 1.0 / 180.0);
		cuadradoRed(0.4, -0.527, 0.01, 1.0 / 180.0);
	}
}