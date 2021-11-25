#include "ajedrez.h"
#include<GL/glew.h>
#include<GL/freeglut.h>
#include<math.h>
#include<fstream>
#include<assert.h>
#include"textura.h"

void cuadrado(double x, double y, double z, double scal, int texture);
void borde(double x, double y, double z, double scal, int texture);

//ejemplo de codigo para las funciones
void Ajedrez::ejemplo(double x, double y, double z, double scal, int texture){
	glEnable(GL_TEXTURE_2D);
	texture == 0 ? glBindTexture(GL_TEXTURE_2D, ID_de_Textura1) : glBindTexture(GL_TEXTURE_2D, ID_de_Textura2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x + 6 * scal, y - 6 * scal, z); glVertex3f(x + 6 * scal, y - 6 * scal, z);	//A
	glTexCoord3f(x + 6 * scal, y + 6 * scal, z); glVertex3f(x + 6 * scal, y + 6 * scal, z);	//B
	glTexCoord3f(x - 6 * scal, y + 6 * scal, z); glVertex3f(x - 6 * scal, y + 6 * scal, z);	//C
	glTexCoord3f(x - 6 * scal, y - 6 * scal, z); glVertex3f(x - 6 * scal, y - 6 * scal, z);	//D
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

//Elber
void Ajedrez::tablero(double x, double y, double z, double scal, int texture){
	double xr = x + 96 * scal;
	double yr = y - 96 * scal;
	int color = 0;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j ++){
			if (i % 2 == 0){
				j % 2 == 0 ? color = 0 : color = 1;
			}
			else{
				j % 2 == 0 ? color = 1 : color = 0;
			}
			cuadrado(xr, yr, z, scal, color);
			xr -= 24 * scal;
		}
		xr = x + 96 * scal;
		yr += 24 * scal;
	}
	
	borde(x, y, z, scal, 0);
	
};

//Elber
void Ajedrez::torre(double x, double y, double z, double scal, int texture){
	glEnable(GL_TEXTURE_2D);
	texture == 0 ? glBindTexture(GL_TEXTURE_2D, ID_de_Textura1) : glBindTexture(GL_TEXTURE_2D, ID_de_Textura2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//base
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x, y, z); glVertex3f(x, y, z); //A
	glTexCoord3f(x, y + 24 * scal, z); glVertex3f(x, y + 24 * scal, z); //B
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z); glVertex3f(x - 24 * scal, y + 24 * scal, z); //C
	glTexCoord3f(x - 24 * scal, y, z); glVertex3f(x - 24 * scal, y, z); //D
	glEnd();

	//base top flat-0
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x, y, z + 2 * scal); glVertex3f(x, y, z + 2 * scal); //A1
	glTexCoord3f(x, y + 24 * scal, z + 2 * scal); glVertex3f(x, y + 24 * scal, z + 2 * scal); //B1
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); glVertex3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); //C1
	glTexCoord3f(x - 24 * scal, y, z + 2 * scal); glVertex3f(x - 24 * scal, y, z + 2 * scal); //D1
	glEnd();

	//covers flat-0
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x, y, z); glVertex3f(x, y, z); //A
	glTexCoord3f(x, y, z + 2 * scal); glVertex3f(x, y, z + 2 * scal); //A1
	glTexCoord3f(x - 24 * scal, y, z + 2 * scal); glVertex3f(x - 24 * scal, y, z + 2 * scal); //D1
	glTexCoord3f(x - 24 * scal, y, z); glVertex3f(x - 24 * scal, y, z); //D
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x, y, z); glVertex3f(x, y, z); //A
	glTexCoord3f(x, y, z + 2 * scal); glVertex3f(x, y, z + 2 * scal); //A1
	glTexCoord3f(x, y + 24 * scal, z + 2 * scal); glVertex3f(x, y + 24 * scal, z + 2 * scal); //B1
	glTexCoord3f(x, y + 24 * scal, z); glVertex3f(x, y + 24 * scal, z); //B
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x, y + 24 * scal, z); glVertex3f(x, y + 24 * scal, z); //B
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z); glVertex3f(x - 24 * scal, y + 24 * scal, z); //C
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); glVertex3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); //C1
	glTexCoord3f(x, y + 24 * scal, z + 2 * scal); glVertex3f(x, y + 24 * scal, z + 2 * scal); //B1
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z); glVertex3f(x - 24 * scal, y + 24 * scal, z); //C
	glTexCoord3f(x - 24 * scal, y, z); glVertex3f(x - 24 * scal, y, z); //D
	glTexCoord3f(x - 24 * scal, y, z + 2 * scal); glVertex3f(x - 24 * scal, y, z + 2 * scal); //D1
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); glVertex3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); //C1
	glEnd();

	//covers flat-1
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x, y, z + 2 * scal); glVertex3f(x, y, z + 2 * scal); //A1
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); //E
	glTexCoord3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); glVertex3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); //H
	glTexCoord3f(x - 24 * scal, y, z + 2 * scal); glVertex3f(x - 24 * scal, y, z + 2 * scal); //D1
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x, y, z + 2 * scal); glVertex3f(x, y, z + 2 * scal); //A1
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); //E
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); //F
	glTexCoord3f(x, y + 24 * scal, z + 2 * scal); glVertex3f(x, y + 24 * scal, z + 2 * scal); //B1
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x, y + 24 * scal, z + 2 * scal); glVertex3f(x, y + 24 * scal, z + 2 * scal); //B1
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); //F
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); //G
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); glVertex3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); //C1
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 24 * scal, y, z + 2 * scal); glVertex3f(x - 24 * scal, y, z + 2 * scal); //D1
	glTexCoord3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); glVertex3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); //H
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); //G
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); glVertex3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); //C1
	glEnd();

	//base top flat-1
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); //E
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); //F
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); //G
	glTexCoord3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); glVertex3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); //H
	glEnd();

	//base top flat-2
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 3 * scal, y + 3 * scal, z + 42 * scal); glVertex3f(x - 3 * scal, y + 3 * scal, z + 42 * scal); //I
	glTexCoord3f(x - 3 * scal, y + 21 * scal, z + 42 * scal); glVertex3f(x - 3 * scal, y + 21 * scal, z + 42 * scal); //J
	glTexCoord3f(x - 21 * scal, y + 21 * scal, z + 42 * scal); glVertex3f(x - 21 * scal, y + 21 * scal, z + 42 * scal); //K
	glTexCoord3f(x - 21 * scal, y + 3 * scal, z + 42 * scal); glVertex3f(x - 21 * scal, y + 3 * scal, z + 42 * scal); //L
	glEnd();
	
	//covers flat-2
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); //E
	glTexCoord3f(x - 3 * scal, y + 3 * scal, z + 42 * scal); glVertex3f(x - 3 * scal, y + 3 * scal, z + 42 * scal); //I
	glTexCoord3f(x - 21 * scal, y + 3 * scal, z + 42 * scal); glVertex3f(x - 21 * scal, y + 3 * scal, z + 42 * scal); //L
	glTexCoord3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); glVertex3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); //H
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); //E
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); //F
	glTexCoord3f(x - 3 * scal, y + 21 * scal, z + 42 * scal); glVertex3f(x - 3 * scal, y + 21 * scal, z + 42 * scal); //J
	glTexCoord3f(x - 3 * scal, y + 3 * scal, z + 42 * scal); glVertex3f(x - 3 * scal, y + 3 * scal, z + 42 * scal); //I
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); //F
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); //G
	glTexCoord3f(x - 21 * scal, y + 21 * scal, z + 42 * scal); glVertex3f(x - 21 * scal, y + 21 * scal, z + 42 * scal); //K
	glTexCoord3f(x - 3 * scal, y + 21 * scal, z + 42 * scal); glVertex3f(x - 3 * scal, y + 21 * scal, z + 42 * scal); //J
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); //G
	glTexCoord3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); glVertex3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); //H
	glTexCoord3f(x - 21 * scal, y + 3 * scal, z + 42 * scal); glVertex3f(x - 21 * scal, y + 3 * scal, z + 42 * scal); //L
	glTexCoord3f(x - 21 * scal, y + 21 * scal, z + 42 * scal); glVertex3f(x - 21 * scal, y + 21 * scal, z + 42 * scal); //K
	glEnd();
	
	//
	//base top flat-3
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 45 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 45 * scal); //I1
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 45 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 45 * scal); //J1
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 45 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 45 * scal); //K1
	glTexCoord3f(x - 22 * scal, y + 2 * scal, z + 45 * scal); glVertex3f(x - 22 * scal, y + 2 * scal, z + 45 * scal); //L1
	glEnd();
	
	//covers flat-3
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 3 * scal, y + 3 * scal, z + 42 * scal); glVertex3f(x - 3 * scal, y + 3 * scal, z + 42 * scal); //I
	glTexCoord3f(x - 21 * scal, y + 3 * scal, z + 42 * scal); glVertex3f(x - 21 * scal, y + 3 * scal, z + 42 * scal); //L
	glTexCoord3f(x - 22 * scal, y + 2 * scal, z + 45 * scal); glVertex3f(x - 22 * scal, y + 2 * scal, z + 45 * scal); //L1
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 45 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 45 * scal); //I1
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 3 * scal, y + 3 * scal, z + 42 * scal); glVertex3f(x - 3 * scal, y + 3 * scal, z + 42 * scal); //I
	glTexCoord3f(x - 3 * scal, y + 21 * scal, z + 42 * scal); glVertex3f(x - 3 * scal, y + 21 * scal, z + 42 * scal); //J
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 45 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 45 * scal); //J1
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 45 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 45 * scal); //I1
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 3 * scal, y + 21 * scal, z + 42 * scal); glVertex3f(x - 3 * scal, y + 21 * scal, z + 42 * scal); //J
	glTexCoord3f(x - 21 * scal, y + 21 * scal, z + 42 * scal); glVertex3f(x - 21 * scal, y + 21 * scal, z + 42 * scal); //K
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 45 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 45 * scal); //K1
	glTexCoord3f(x - 22 * scal, y + 2 * scal, z + 45 * scal); glVertex3f(x - 22 * scal, y + 2 * scal, z + 45 * scal); //L1
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 21 * scal, y + 21 * scal, z + 42 * scal); glVertex3f(x - 21 * scal, y + 21 * scal, z + 42 * scal); //K
	glTexCoord3f(x - 21 * scal, y + 3 * scal, z + 42 * scal); glVertex3f(x - 21 * scal, y + 3 * scal, z + 42 * scal); //L
	glTexCoord3f(x - 22 * scal, y + 2 * scal, z + 45 * scal); glVertex3f(x - 22 * scal, y + 2 * scal, z + 45 * scal); //L1
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 45 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 45 * scal); //K1
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	texture == 0 ? glBindTexture(GL_TEXTURE_2D, ID_de_Textura1) : glBindTexture(GL_TEXTURE_2D, ID_de_Textura2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//covers flat-4
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 45 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 45 * scal); //I1
	glTexCoord3f(x - 22 * scal, y + 2 * scal, z + 45 * scal); glVertex3f(x - 22 * scal, y + 2 * scal, z + 45 * scal); //L1
	glTexCoord3f(x - 22 * scal, y + 2 * scal, z + 50 * scal); glVertex3f(x - 22 * scal, y + 2 * scal, z + 50 * scal); //P
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 50 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 50 * scal); //M
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 45 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 45 * scal); //I1
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 45 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 45 * scal); //J1
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 50 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 50 * scal); //N
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 50 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 50 * scal); //M
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 45 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 45 * scal); //J1
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 45 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 45 * scal); //K1
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 50 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 50 * scal); //O
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 50 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 50 * scal); //N
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 45 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 45 * scal); //K1
	glTexCoord3f(x - 22 * scal, y + 2 * scal, z + 45 * scal); glVertex3f(x - 22 * scal, y + 2 * scal, z + 45 * scal); //L1
	glTexCoord3f(x - 22 * scal, y + 2 * scal, z + 50 * scal); glVertex3f(x - 22 * scal, y + 2 * scal, z + 50 * scal); //P
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 50 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 50 * scal); //O
	glEnd();

	//covers flat-4 under
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 6 * scal, y + 6 * scal, z + 45 * scal); glVertex3f(x - 6 * scal, y + 6 * scal, z + 45 * scal); //M1-
	glTexCoord3f(x - 18 * scal, y + 6 * scal, z + 45 * scal); glVertex3f(x - 18 * scal, y + 6 * scal, z + 45 * scal); //P1-
	glTexCoord3f(x - 18 * scal, y + 6 * scal, z + 50 * scal); glVertex3f(x - 18 * scal, y + 6 * scal, z + 50 * scal); //P1
	glTexCoord3f(x - 6 * scal, y + 6 * scal, z + 50 * scal); glVertex3f(x - 6 * scal, y + 6 * scal, z + 50 * scal); //M1
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 6 * scal, y + 6 * scal, z + 45 * scal); glVertex3f(x - 6 * scal, y + 6 * scal, z + 45 * scal); //M1-
	glTexCoord3f(x - 6 * scal, y + 18 * scal, z + 45 * scal); glVertex3f(x - 6 * scal, y + 18 * scal, z + 45 * scal); //N1-
	glTexCoord3f(x - 6 * scal, y + 18 * scal, z + 50 * scal); glVertex3f(x - 6 * scal, y + 18 * scal, z + 50 * scal); //N1
	glTexCoord3f(x - 6 * scal, y + 6 * scal, z + 50 * scal); glVertex3f(x - 6 * scal, y + 6 * scal, z + 50 * scal); //M1
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 6 * scal, y + 18 * scal, z + 50 * scal); glVertex3f(x - 6 * scal, y + 18 * scal, z + 50 * scal); //N1
	glTexCoord3f(x - 18 * scal, y + 18 * scal, z + 50 * scal); glVertex3f(x - 18 * scal, y + 18 * scal, z + 50 * scal); //O1
	glTexCoord3f(x - 18 * scal, y + 18 * scal, z + 45 * scal); glVertex3f(x - 18 * scal, y + 18 * scal, z + 45 * scal); //O1-
	glTexCoord3f(x - 6 * scal, y + 18 * scal, z + 45 * scal); glVertex3f(x - 6 * scal, y + 18 * scal, z + 45 * scal); //N1-
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 18 * scal, y + 18 * scal, z + 50 * scal); glVertex3f(x - 18 * scal, y + 18 * scal, z + 50 * scal); //O1
	glTexCoord3f(x - 18 * scal, y + 6 * scal, z + 50 * scal); glVertex3f(x - 18 * scal, y + 6 * scal, z + 50 * scal); //P1
	glTexCoord3f(x - 18 * scal, y + 6 * scal, z + 45 * scal); glVertex3f(x - 18 * scal, y + 6 * scal, z + 45 * scal); //P1-
	glTexCoord3f(x - 18 * scal, y + 18 * scal, z + 45 * scal); glVertex3f(x - 18 * scal, y + 18 * scal, z + 45 * scal); //O1-
	glEnd();

	//base top flat-4
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 50 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 50 * scal); //M
	glTexCoord3f(x - 22 * scal, y + 2 * scal, z + 50 * scal); glVertex3f(x - 22 * scal, y + 2 * scal, z + 50 * scal); //P
	glTexCoord3f(x - 18 * scal, y + 6 * scal, z + 50 * scal); glVertex3f(x - 18 * scal, y + 6 * scal, z + 50 * scal); //P1
	glTexCoord3f(x - 6 * scal, y + 6 * scal, z + 50 * scal); glVertex3f(x - 6 * scal, y + 6 * scal, z + 50 * scal); //M1
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 50 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 50 * scal); //M
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 50 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 50 * scal); //N
	glTexCoord3f(x - 6 * scal, y + 18 * scal, z + 50 * scal); glVertex3f(x - 6 * scal, y + 18 * scal, z + 50 * scal); //N1
	glTexCoord3f(x - 6 * scal, y + 6 * scal, z + 50 * scal); glVertex3f(x - 6 * scal, y + 6 * scal, z + 50 * scal); //M1
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 50 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 50 * scal); //N
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 50 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 50 * scal); //O
	glTexCoord3f(x - 18 * scal, y + 18 * scal, z + 50 * scal); glVertex3f(x - 18 * scal, y + 18 * scal, z + 50 * scal); //O1
	glTexCoord3f(x - 6 * scal, y + 18 * scal, z + 50 * scal); glVertex3f(x - 6 * scal, y + 18 * scal, z + 50 * scal); //N1
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 50 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 50 * scal); //O
	glTexCoord3f(x - 22 * scal, y + 2 * scal, z + 50 * scal); glVertex3f(x - 22 * scal, y + 2 * scal, z + 50 * scal); //P
	glTexCoord3f(x - 18 * scal, y + 6 * scal, z + 50 * scal); glVertex3f(x - 18 * scal, y + 6 * scal, z + 50 * scal); //P1
	glTexCoord3f(x - 18 * scal, y + 18 * scal, z + 50 * scal); glVertex3f(x - 18 * scal, y + 18 * scal, z + 50 * scal); //O1
	glEnd();

	//base top flat-5
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 55 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 55 * scal); //MT
	glTexCoord3f(x - 2 * scal, y + 10 * scal, z + 55 * scal); glVertex3f(x - 2 * scal, y + 10 * scal, z + 55 * scal); //MTS
	glTexCoord3f(x - 6 * scal, y + 10 * scal, z + 55 * scal); glVertex3f(x - 6 * scal, y + 10 * scal, z + 55 * scal); //M1TS
	glTexCoord3f(x - 6 * scal, y + 6 * scal, z + 55 * scal); glVertex3f(x - 6 * scal, y + 6 * scal, z + 55 * scal); //M1T
	glTexCoord3f(x - 10 * scal, y + 6 * scal, z + 55 * scal); glVertex3f(x - 10 * scal, y + 6 * scal, z + 55 * scal); //M1TI
	glTexCoord3f(x - 10 * scal, y + 2 * scal, z + 55 * scal); glVertex3f(x - 10 * scal, y + 2 * scal, z + 55 * scal); //MTI
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 55 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 55 * scal); //NT
	glTexCoord3f(x - 10 * scal, y + 22 * scal, z + 55 * scal); glVertex3f(x - 10 * scal, y + 22 * scal, z + 55 * scal); //NTI
	glTexCoord3f(x - 10 * scal, y + 18 * scal, z + 55 * scal); glVertex3f(x - 10 * scal, y + 18 * scal, z + 55 * scal); //N1TI
	glTexCoord3f(x - 6 * scal, y + 18 * scal, z + 55 * scal); glVertex3f(x - 6 * scal, y + 18 * scal, z + 55 * scal); //N1T
	glTexCoord3f(x - 6 * scal, y + 14 * scal, z + 55 * scal); glVertex3f(x - 6 * scal, y + 14 * scal, z + 55 * scal); //N1TA
	glTexCoord3f(x - 2 * scal, y + 14 * scal, z + 55 * scal); glVertex3f(x - 2 * scal, y + 14 * scal, z + 55 * scal); //NTA
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 55 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 55 * scal); //OT
	glTexCoord3f(x - 14 * scal, y + 22 * scal, z + 55 * scal); glVertex3f(x - 14 * scal, y + 22 * scal, z + 55 * scal); //OTD
	glTexCoord3f(x - 14 * scal, y + 18 * scal, z + 55 * scal); glVertex3f(x - 14 * scal, y + 18 * scal, z + 55 * scal); //O1TD
	glTexCoord3f(x - 18 * scal, y + 18 * scal, z + 55 * scal); glVertex3f(x - 18 * scal, y + 18 * scal, z + 55 * scal); //O1T
	glTexCoord3f(x - 18 * scal, y + 14 * scal, z + 55 * scal); glVertex3f(x - 18 * scal, y + 14 * scal, z + 55 * scal); //O1TS
	glTexCoord3f(x - 22 * scal, y + 14 * scal, z + 55 * scal); glVertex3f(x - 22 * scal, y + 14 * scal, z + 55 * scal); //OTS
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 22 * scal, y + 2 * scal, z + 55 * scal); glVertex3f(x - 22 * scal, y + 2 * scal, z + 55 * scal); //PT
	glTexCoord3f(x - 22 * scal, y + 10 * scal, z + 55 * scal); glVertex3f(x - 22 * scal, y + 10 * scal, z + 55 * scal); //PTA
	glTexCoord3f(x - 18 * scal, y + 10 * scal, z + 55 * scal); glVertex3f(x - 18 * scal, y + 10 * scal, z + 55 * scal); //P1TA
	glTexCoord3f(x - 18 * scal, y + 6 * scal, z + 55 * scal); glVertex3f(x - 18 * scal, y + 6 * scal, z + 55 * scal); //P1T
	glTexCoord3f(x - 14 * scal, y + 6 * scal, z + 55 * scal); glVertex3f(x - 14 * scal, y + 6 * scal, z + 55 * scal); //P1TD
	glTexCoord3f(x - 14 * scal, y + 2 * scal, z + 55 * scal); glVertex3f(x - 14 * scal, y + 2 * scal, z + 55 * scal); //PTD
	glEnd();

	//covers flat-5
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 55 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 55 * scal); //MT
	glTexCoord3f(x - 10 * scal, y + 2 * scal, z + 55 * scal); glVertex3f(x - 10 * scal, y + 2 * scal, z + 55 * scal); //MTI
	glTexCoord3f(x - 10 * scal, y + 2 * scal, z + 50 * scal); glVertex3f(x - 10 * scal, y + 2 * scal, z + 50 * scal); //MTI--
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 50 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 50 * scal); //MT--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 22 * scal, y + 2 * scal, z + 55 * scal); glVertex3f(x - 22 * scal, y + 2 * scal, z + 55 * scal); //PT
	glTexCoord3f(x - 14 * scal, y + 2 * scal, z + 55 * scal); glVertex3f(x - 14 * scal, y + 2 * scal, z + 55 * scal); //PTD
	glTexCoord3f(x - 14 * scal, y + 2 * scal, z + 50 * scal); glVertex3f(x - 14 * scal, y + 2 * scal, z + 50 * scal); //PTD--
	glTexCoord3f(x - 22 * scal, y + 2 * scal, z + 50 * scal); glVertex3f(x - 22 * scal, y + 2 * scal, z + 50 * scal); //PT--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 55 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 55 * scal); //MT
	glTexCoord3f(x - 2 * scal, y + 10 * scal, z + 55 * scal); glVertex3f(x - 2 * scal, y + 10 * scal, z + 55 * scal); //MTS
	glTexCoord3f(x - 2 * scal, y + 10 * scal, z + 50 * scal); glVertex3f(x - 2 * scal, y + 10 * scal, z + 50 * scal); //MTS--
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 50 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 50 * scal); //MT--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 55 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 55 * scal); //NT
	glTexCoord3f(x - 2 * scal, y + 14 * scal, z + 55 * scal); glVertex3f(x - 2 * scal, y + 14 * scal, z + 55 * scal); //NTA
	glTexCoord3f(x - 2 * scal, y + 14 * scal, z + 50 * scal); glVertex3f(x - 2 * scal, y + 14 * scal, z + 50 * scal); //NTA--
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 50 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 50 * scal); //NT--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 55 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 55 * scal); //NT
	glTexCoord3f(x - 10 * scal, y + 22 * scal, z + 55 * scal); glVertex3f(x - 10 * scal, y + 22 * scal, z + 55 * scal); //NTI
	glTexCoord3f(x - 10 * scal, y + 22 * scal, z + 50 * scal); glVertex3f(x - 10 * scal, y + 22 * scal, z + 50 * scal); //NTI--
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 50 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 50 * scal); //NT--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 55 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 55 * scal); //OT
	glTexCoord3f(x - 14 * scal, y + 22 * scal, z + 55 * scal); glVertex3f(x - 14 * scal, y + 22 * scal, z + 55 * scal); //OTD
	glTexCoord3f(x - 14 * scal, y + 22 * scal, z + 50 * scal); glVertex3f(x - 14 * scal, y + 22 * scal, z + 50 * scal); //OTD--
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 50 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 50 * scal); //OT--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 55 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 55 * scal); //OT
	glTexCoord3f(x - 22 * scal, y + 14 * scal, z + 55 * scal); glVertex3f(x - 22 * scal, y + 14 * scal, z + 55 * scal); //OTS
	glTexCoord3f(x - 22 * scal, y + 14 * scal, z + 50 * scal); glVertex3f(x - 22 * scal, y + 14 * scal, z + 50 * scal); //OTS--
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 50 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 50 * scal); //OT--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 22 * scal, y + 2 * scal, z + 55 * scal); glVertex3f(x - 22 * scal, y + 2 * scal, z + 55 * scal); //PT
	glTexCoord3f(x - 22 * scal, y + 10 * scal, z + 55 * scal); glVertex3f(x - 22 * scal, y + 10 * scal, z + 55 * scal); //PTA
	glTexCoord3f(x - 22 * scal, y + 10 * scal, z + 50 * scal); glVertex3f(x - 22 * scal, y + 10 * scal, z + 50 * scal); //PTA--
	glTexCoord3f(x - 22 * scal, y + 2 * scal, z + 50 * scal); glVertex3f(x - 22 * scal, y + 2 * scal, z + 50 * scal); //PT--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 6 * scal, y + 6 * scal, z + 55 * scal); glVertex3f(x - 6 * scal, y + 6 * scal, z + 55 * scal); //M1T
	glTexCoord3f(x - 10 * scal, y + 6 * scal, z + 55 * scal); glVertex3f(x - 10 * scal, y + 6 * scal, z + 55 * scal); //M1TI
	glTexCoord3f(x - 10 * scal, y + 6 * scal, z + 50 * scal); glVertex3f(x - 10 * scal, y + 6 * scal, z + 50 * scal); //M1TI--
	glTexCoord3f(x - 6 * scal, y + 6 * scal, z + 50 * scal); glVertex3f(x - 6 * scal, y + 6 * scal, z + 50 * scal); //M1T--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 6 * scal, y + 6 * scal, z + 55 * scal); glVertex3f(x - 6 * scal, y + 6 * scal, z + 55 * scal); //M1T
	glTexCoord3f(x - 6 * scal, y + 10 * scal, z + 55 * scal); glVertex3f(x - 6 * scal, y + 10 * scal, z + 55 * scal); //M1TS
	glTexCoord3f(x - 6 * scal, y + 10 * scal, z + 50 * scal); glVertex3f(x - 6 * scal, y + 10 * scal, z + 50 * scal); //M1TS--
	glTexCoord3f(x - 6 * scal, y + 6 * scal, z + 50 * scal); glVertex3f(x - 6 * scal, y + 6 * scal, z + 50 * scal); //M1T--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 6 * scal, y + 18 * scal, z + 55 * scal); glVertex3f(x - 6 * scal, y + 18 * scal, z + 55 * scal); //N1T
	glTexCoord3f(x - 10 * scal, y + 18 * scal, z + 55 * scal); glVertex3f(x - 10 * scal, y + 18 * scal, z + 55 * scal); //N1TI
	glTexCoord3f(x - 10 * scal, y + 18 * scal, z + 50 * scal); glVertex3f(x - 10 * scal, y + 18 * scal, z + 50 * scal); //N1TI--
	glTexCoord3f(x - 6 * scal, y + 18 * scal, z + 50 * scal); glVertex3f(x - 6 * scal, y + 18 * scal, z + 50 * scal); //N1T--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 6 * scal, y + 18 * scal, z + 55 * scal); glVertex3f(x - 6 * scal, y + 18 * scal, z + 55 * scal); //N1T
	glTexCoord3f(x - 6 * scal, y + 14 * scal, z + 55 * scal); glVertex3f(x - 6 * scal, y + 14 * scal, z + 55 * scal); //N1TA
	glTexCoord3f(x - 6 * scal, y + 14 * scal, z + 50 * scal); glVertex3f(x - 6 * scal, y + 14 * scal, z + 50 * scal); //N1TA--
	glTexCoord3f(x - 6 * scal, y + 18 * scal, z + 50 * scal); glVertex3f(x - 6 * scal, y + 18 * scal, z + 50 * scal); //N1T--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 18 * scal, y + 18 * scal, z + 55 * scal); glVertex3f(x - 18 * scal, y + 18 * scal, z + 55 * scal); //O1T
	glTexCoord3f(x - 14 * scal, y + 18 * scal, z + 55 * scal); glVertex3f(x - 14 * scal, y + 18 * scal, z + 55 * scal); //O1TD
	glTexCoord3f(x - 14 * scal, y + 18 * scal, z + 50 * scal); glVertex3f(x - 14 * scal, y + 18 * scal, z + 50 * scal); //O1TD--
	glTexCoord3f(x - 18 * scal, y + 18 * scal, z + 50 * scal); glVertex3f(x - 18 * scal, y + 18 * scal, z + 50 * scal); //O1T--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 18 * scal, y + 18 * scal, z + 55 * scal); glVertex3f(x - 18 * scal, y + 18 * scal, z + 55 * scal); //O1T
	glTexCoord3f(x - 18 * scal, y + 14 * scal, z + 55 * scal); glVertex3f(x - 18 * scal, y + 14 * scal, z + 55 * scal); //O1TS
	glTexCoord3f(x - 18 * scal, y + 14 * scal, z + 50 * scal); glVertex3f(x - 18 * scal, y + 14 * scal, z + 50 * scal); //O1TS--
	glTexCoord3f(x - 18 * scal, y + 18 * scal, z + 50 * scal); glVertex3f(x - 18 * scal, y + 18 * scal, z + 50 * scal); //O1T--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 18 * scal, y + 6 * scal, z + 55 * scal); glVertex3f(x - 18 * scal, y + 6 * scal, z + 55 * scal); //P1T
	glTexCoord3f(x - 14 * scal, y + 6 * scal, z + 55 * scal); glVertex3f(x - 14 * scal, y + 6 * scal, z + 55 * scal); //P1TD
	glTexCoord3f(x - 14 * scal, y + 6 * scal, z + 50 * scal); glVertex3f(x - 14 * scal, y + 6 * scal, z + 50 * scal); //P1TD--
	glTexCoord3f(x - 18 * scal, y + 6 * scal, z + 50 * scal); glVertex3f(x - 18 * scal, y + 6 * scal, z + 50 * scal); //P1T--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 18 * scal, y + 6 * scal, z + 55 * scal); glVertex3f(x - 18 * scal, y + 6 * scal, z + 55 * scal); //P1T
	glTexCoord3f(x - 18 * scal, y + 10 * scal, z + 55 * scal); glVertex3f(x - 18 * scal, y + 10 * scal, z + 55 * scal); //P1TA
	glTexCoord3f(x - 18 * scal, y + 10 * scal, z + 50 * scal); glVertex3f(x - 18 * scal, y + 10 * scal, z + 50 * scal); //P1TA--
	glTexCoord3f(x - 18 * scal, y + 6 * scal, z + 50 * scal); glVertex3f(x - 18 * scal, y + 6 * scal, z + 50 * scal); //P1T--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 10 * scal, y + 2 * scal, z + 55 * scal); glVertex3f(x - 10 * scal, y + 2 * scal, z + 55 * scal); //MTI
	glTexCoord3f(x - 10 * scal, y + 6 * scal, z + 55 * scal); glVertex3f(x - 10 * scal, y + 6 * scal, z + 55 * scal); //M1TI
	glTexCoord3f(x - 10 * scal, y + 6 * scal, z + 50 * scal); glVertex3f(x - 10 * scal, y + 6 * scal, z + 50 * scal); //M1TI--
	glTexCoord3f(x - 10 * scal, y + 2 * scal, z + 50 * scal); glVertex3f(x - 10 * scal, y + 2 * scal, z + 50 * scal); //MTI--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 2 * scal, y + 10 * scal, z + 55 * scal); glVertex3f(x - 2 * scal, y + 10 * scal, z + 55 * scal); //MTS
	glTexCoord3f(x - 6 * scal, y + 10 * scal, z + 55 * scal); glVertex3f(x - 6 * scal, y + 10 * scal, z + 55 * scal); //M1TS
	glTexCoord3f(x - 6 * scal, y + 10 * scal, z + 50 * scal); glVertex3f(x - 6 * scal, y + 10 * scal, z + 50 * scal); //M1TS--
	glTexCoord3f(x - 2 * scal, y + 10 * scal, z + 50 * scal); glVertex3f(x - 2 * scal, y + 10 * scal, z + 50 * scal); //MTS--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 10 * scal, y + 22 * scal, z + 55 * scal); glVertex3f(x - 10 * scal, y + 22 * scal, z + 55 * scal); //NTI
	glTexCoord3f(x - 10 * scal, y + 18 * scal, z + 55 * scal); glVertex3f(x - 10 * scal, y + 18 * scal, z + 55 * scal); //N1TI
	glTexCoord3f(x - 10 * scal, y + 18 * scal, z + 50 * scal); glVertex3f(x - 10 * scal, y + 18 * scal, z + 50 * scal); //N1TI--
	glTexCoord3f(x - 10 * scal, y + 22 * scal, z + 50 * scal); glVertex3f(x - 10 * scal, y + 22 * scal, z + 50 * scal); //NTI--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 6 * scal, y + 14 * scal, z + 55 * scal); glVertex3f(x - 6 * scal, y + 14 * scal, z + 55 * scal); //N1TA
	glTexCoord3f(x - 2 * scal, y + 14 * scal, z + 55 * scal); glVertex3f(x - 2 * scal, y + 14 * scal, z + 55 * scal); //NTA
	glTexCoord3f(x - 2 * scal, y + 14 * scal, z + 50 * scal); glVertex3f(x - 2 * scal, y + 14 * scal, z + 50 * scal); //NTA--
	glTexCoord3f(x - 6 * scal, y + 14 * scal, z + 50 * scal); glVertex3f(x - 6 * scal, y + 14 * scal, z + 50 * scal); //N1TA--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 14 * scal, y + 22 * scal, z + 55 * scal); glVertex3f(x - 14 * scal, y + 22 * scal, z + 55 * scal); //OTD
	glTexCoord3f(x - 14 * scal, y + 18 * scal, z + 55 * scal); glVertex3f(x - 14 * scal, y + 18 * scal, z + 55 * scal); //O1TD
	glTexCoord3f(x - 14 * scal, y + 18 * scal, z + 50 * scal); glVertex3f(x - 14 * scal, y + 18 * scal, z + 50 * scal); //O1TD--
	glTexCoord3f(x - 14 * scal, y + 22 * scal, z + 50 * scal); glVertex3f(x - 14 * scal, y + 22 * scal, z + 50 * scal); //OTD--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 22 * scal, y + 14 * scal, z + 55 * scal); glVertex3f(x - 22 * scal, y + 14 * scal, z + 55 * scal); //OTS
	glTexCoord3f(x - 18 * scal, y + 14 * scal, z + 55 * scal); glVertex3f(x - 18 * scal, y + 14 * scal, z + 55 * scal); //O1TS
	glTexCoord3f(x - 18 * scal, y + 14 * scal, z + 50 * scal); glVertex3f(x - 18 * scal, y + 14 * scal, z + 50 * scal); //O1TS--
	glTexCoord3f(x - 22 * scal, y + 14 * scal, z + 50 * scal); glVertex3f(x - 22 * scal, y + 14 * scal, z + 50 * scal); //OTS--
	glEnd();
    
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 22 * scal, y + 10 * scal, z + 55 * scal); glVertex3f(x - 22 * scal, y + 10 * scal, z + 55 * scal); //PTA
	glTexCoord3f(x - 18 * scal, y + 10 * scal, z + 55 * scal); glVertex3f(x - 18 * scal, y + 10 * scal, z + 55 * scal); //P1TA
	glTexCoord3f(x - 18 * scal, y + 10 * scal, z + 50 * scal); glVertex3f(x - 18 * scal, y + 10 * scal, z + 50 * scal); //P1TA--
	glTexCoord3f(x - 22 * scal, y + 10 * scal, z + 50 * scal); glVertex3f(x - 22 * scal, y + 10 * scal, z + 50 * scal); //PTA--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 14 * scal, y + 2 * scal, z + 55 * scal); glVertex3f(x - 14 * scal, y + 2 * scal, z + 55 * scal); //PTD
	glTexCoord3f(x - 14 * scal, y + 6 * scal, z + 55 * scal); glVertex3f(x - 14 * scal, y + 6 * scal, z + 55 * scal); //P1TD
	glTexCoord3f(x - 14 * scal, y + 6 * scal, z + 50 * scal); glVertex3f(x - 14 * scal, y + 6 * scal, z + 50 * scal); //P1TD--
	glTexCoord3f(x - 14 * scal, y + 2 * scal, z + 50 * scal); glVertex3f(x - 14 * scal, y + 2 * scal, z + 50 * scal); //PTD--
	glEnd();
	glDisable(GL_TEXTURE_2D);

};

//Elber
void Ajedrez::peon(double x, double y, double z, double scal, int texture){
	glEnable(GL_TEXTURE_2D);
	texture == 0 ? glBindTexture(GL_TEXTURE_2D, ID_de_Textura1) : glBindTexture(GL_TEXTURE_2D, ID_de_Textura2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//base
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x, y, z); glVertex3f(x, y, z); //A
	glTexCoord3f(x, y + 24 * scal, z); glVertex3f(x, y + 24 * scal, z); //B
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z); glVertex3f(x - 24 * scal, y + 24 * scal, z); //C
	glTexCoord3f(x - 24 * scal, y, z); glVertex3f(x - 24 * scal, y, z); //D
	glEnd();

	//base top flat-0
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x, y, z + 2 * scal); glVertex3f(x, y, z + 2 * scal); //A1
	glTexCoord3f(x, y + 24 * scal, z + 2 * scal); glVertex3f(x, y + 24 * scal, z + 2 * scal); //B1
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); glVertex3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); //C1
	glTexCoord3f(x - 24 * scal, y, z + 2 * scal); glVertex3f(x - 24 * scal, y, z + 2 * scal); //D1
	glEnd();

	//covers flat-0
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x, y, z); glVertex3f(x, y, z); //A
	glTexCoord3f(x, y, z + 2 * scal); glVertex3f(x, y, z + 2 * scal); //A1
	glTexCoord3f(x - 24 * scal, y, z + 2 * scal); glVertex3f(x - 24 * scal, y, z + 2 * scal); //D1
	glTexCoord3f(x - 24 * scal, y, z); glVertex3f(x - 24 * scal, y, z); //D
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x, y, z); glVertex3f(x, y, z); //A
	glTexCoord3f(x, y, z + 2 * scal); glVertex3f(x, y, z + 2 * scal); //A1
	glTexCoord3f(x, y + 24 * scal, z + 2 * scal); glVertex3f(x, y + 24 * scal, z + 2 * scal); //B1
	glTexCoord3f(x, y + 24 * scal, z); glVertex3f(x, y + 24 * scal, z); //B
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x, y + 24 * scal, z); glVertex3f(x, y + 24 * scal, z); //B
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z); glVertex3f(x - 24 * scal, y + 24 * scal, z); //C
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); glVertex3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); //C1
	glTexCoord3f(x, y + 24 * scal, z + 2 * scal); glVertex3f(x, y + 24 * scal, z + 2 * scal); //B1
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z); glVertex3f(x - 24 * scal, y + 24 * scal, z); //C
	glTexCoord3f(x - 24 * scal, y, z); glVertex3f(x - 24 * scal, y, z); //D
	glTexCoord3f(x - 24 * scal, y, z + 2 * scal); glVertex3f(x - 24 * scal, y, z + 2 * scal); //D1
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); glVertex3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); //C1
	glEnd();

	//covers flat-1
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x, y, z + 2 * scal); glVertex3f(x, y, z + 2 * scal); //A1
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); //E
	glTexCoord3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); glVertex3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); //H
	glTexCoord3f(x - 24 * scal, y, z + 2 * scal); glVertex3f(x - 24 * scal, y, z + 2 * scal); //D1
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x, y, z + 2 * scal); glVertex3f(x, y, z + 2 * scal); //A1
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); //E
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); //F
	glTexCoord3f(x, y + 24 * scal, z + 2 * scal); glVertex3f(x, y + 24 * scal, z + 2 * scal); //B1
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x, y + 24 * scal, z + 2 * scal); glVertex3f(x, y + 24 * scal, z + 2 * scal); //B1
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); //F
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); //G
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); glVertex3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); //C1
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 24 * scal, y, z + 2 * scal); glVertex3f(x - 24 * scal, y, z + 2 * scal); //D1
	glTexCoord3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); glVertex3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); //H
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); //G
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); glVertex3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); //C1
	glEnd();

	//base top flat-1
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); //E
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); //F
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); //G
	glTexCoord3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); glVertex3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); //H
	glEnd();

	//base top flat-2
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 37 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 37 * scal); //I
	glTexCoord3f(x - 5 * scal, y + 19 * scal, z + 37 * scal); glVertex3f(x - 5 * scal, y + 19 * scal, z + 37 * scal); //J
	glTexCoord3f(x - 19 * scal, y + 19 * scal, z + 37 * scal); glVertex3f(x - 19 * scal, y + 19 * scal, z + 37 * scal); //K
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 37 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 37 * scal); //L
	glEnd();

	//covers flat-2
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); //E
	glTexCoord3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); glVertex3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); //H
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 37 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 37 * scal); //L
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 37 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 37 * scal); //I
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); //E
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); //F
	glTexCoord3f(x - 5 * scal, y + 19 * scal, z + 37 * scal); glVertex3f(x - 5 * scal, y + 19 * scal, z + 37 * scal); //J
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 37 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 37 * scal); //I
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); //F
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); //G
	glTexCoord3f(x - 19 * scal, y + 19 * scal, z + 37 * scal); glVertex3f(x - 19 * scal, y + 19 * scal, z + 37 * scal); //K
	glTexCoord3f(x - 5 * scal, y + 19 * scal, z + 37 * scal); glVertex3f(x - 5 * scal, y + 19 * scal, z + 37 * scal); //J
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); //G
	glTexCoord3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); glVertex3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); //H
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 37 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 37 * scal); //L
	glTexCoord3f(x - 19 * scal, y + 19 * scal, z + 37 * scal); glVertex3f(x - 19 * scal, y + 19 * scal, z + 37 * scal); //K
	glEnd();

	//base top flat-3-1
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 37 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 37 * scal); //E--
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 37 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 37 * scal); //F--
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 37 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 37 * scal); //G--
	glTexCoord3f(x - 22 * scal, y + 2 * scal, z + 37 * scal); glVertex3f(x - 22 * scal, y + 2 * scal, z + 37 * scal); //H--
	glEnd();
	
	//base top flat-3-2
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 40 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 40 * scal); //E
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 40 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 40 * scal); //F
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 40 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 40 * scal); //G
	glTexCoord3f(x - 22 * scal, y + 2 * scal, z + 40 * scal); glVertex3f(x - 22 * scal, y + 2 * scal, z + 40 * scal); //H
	glEnd();

	//covers flat-3
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 37 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 37 * scal); //E--
	glTexCoord3f(x - 22 * scal, y + 2 * scal, z + 37 * scal); glVertex3f(x - 22 * scal, y + 2 * scal, z + 37 * scal); //H--
	glTexCoord3f(x - 22 * scal, y + 2 * scal, z + 40 * scal); glVertex3f(x - 22 * scal, y + 2 * scal, z + 40 * scal); //H
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 40 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 40 * scal); //E
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 37 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 37 * scal); //E--
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 37 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 37 * scal); //F--
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 40 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 40 * scal); //F
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 40 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 40 * scal); //E
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 37 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 37 * scal); //F--
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 37 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 37 * scal); //G--
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 40 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 40 * scal); //G
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 40 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 40 * scal); //F
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 37 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 37 * scal); //G--
	glTexCoord3f(x - 22 * scal, y + 2 * scal, z + 37 * scal); glVertex3f(x - 22 * scal, y + 2 * scal, z + 37 * scal); //H--
	glTexCoord3f(x - 22 * scal, y + 2 * scal, z + 40 * scal); glVertex3f(x - 22 * scal, y + 2 * scal, z + 40 * scal); //H
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 40 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 40 * scal); //G
	glEnd();
	
	//base top flat-4-1
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 40 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 40 * scal); //M--
	glTexCoord3f(x - 5 * scal, y + 19 * scal, z + 40 * scal); glVertex3f(x - 5 * scal, y + 19 * scal, z + 40 * scal); //N--
	glTexCoord3f(x - 19 * scal, y + 19 * scal, z + 40 * scal); glVertex3f(x - 19 * scal, y + 19 * scal, z + 40 * scal); //O--
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 40 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 40 * scal); //P--
	glEnd();

	//base top flat-4-2
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 50 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 50 * scal); //M
	glTexCoord3f(x - 5 * scal, y + 19 * scal, z + 50 * scal); glVertex3f(x - 5 * scal, y + 19 * scal, z + 50 * scal); //N
	glTexCoord3f(x - 19 * scal, y + 19 * scal, z + 50 * scal); glVertex3f(x - 19 * scal, y + 19 * scal, z + 50 * scal); //O
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 50 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 50 * scal); //P
	glEnd();

	//covers  flat-4
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 40 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 40 * scal); //M--
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 40 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 40 * scal); //P--
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 50 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 50 * scal); //P
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 50 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 50 * scal); //M
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 40 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 40 * scal); //M--
	glTexCoord3f(x - 5 * scal, y + 19 * scal, z + 40 * scal); glVertex3f(x - 5 * scal, y + 19 * scal, z + 40 * scal); //N--
	glTexCoord3f(x - 5 * scal, y + 19 * scal, z + 50 * scal); glVertex3f(x - 5 * scal, y + 19 * scal, z + 50 * scal); //N
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 50 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 50 * scal); //M
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 5 * scal, y + 19 * scal, z + 40 * scal); glVertex3f(x - 5 * scal, y + 19 * scal, z + 40 * scal); //N--
	glTexCoord3f(x - 19 * scal, y + 19 * scal, z + 40 * scal); glVertex3f(x - 19 * scal, y + 19 * scal, z + 40 * scal); //O--
	glTexCoord3f(x - 19 * scal, y + 19 * scal, z + 50 * scal); glVertex3f(x - 19 * scal, y + 19 * scal, z + 50 * scal); //O
	glTexCoord3f(x - 5 * scal, y + 19 * scal, z + 50 * scal); glVertex3f(x - 5 * scal, y + 19 * scal, z + 50 * scal); //N
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 19 * scal, y + 19 * scal, z + 40 * scal); glVertex3f(x - 19 * scal, y + 19 * scal, z + 40 * scal); //O--
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 40 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 40 * scal); //P--
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 50 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 50 * scal); //P
	glTexCoord3f(x - 19 * scal, y + 19 * scal, z + 50 * scal); glVertex3f(x - 19 * scal, y + 19 * scal, z + 50 * scal); //O
	glEnd();

	glDisable(GL_TEXTURE_2D);

};

//Marco
void Ajedrez::reina(double x, double y, double z, double scal, int texture){
	glEnable(GL_TEXTURE_2D);
	texture == 0 ? glBindTexture(GL_TEXTURE_2D, ID_de_Textura1) : glBindTexture(GL_TEXTURE_2D, ID_de_Textura2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x, y, z); glVertex3f(x, y, z);
	glTexCoord3f(x, y + 24 * scal, z); glVertex3f(x, y + 24 * scal, z);
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z); glVertex3f(x - 24 * scal, y + 24 * scal, z);
	glTexCoord3f(x - 24 * scal, y, z); glVertex3f(x - 24 * scal, y, z);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x, y, z + 5 * scal); glVertex3f(x, y, z + 5 * scal);
	glTexCoord3f(x, y + 24 * scal, z + 5 * scal); glVertex3f(x, y + 24 * scal, z + 5 * scal);
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z + 5 * scal); glVertex3f(x - 24 * scal, y + 24 * scal, z + 5 * scal);
	glTexCoord3f(x - 24 * scal, y, z + 5 * scal); glVertex3f(x - 24 * scal, y, z + 5 * scal);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x, y, z); glVertex3f(x, y, z);
	glTexCoord3f(x, y, z + 5 * scal); glVertex3f(x, y, z + 5 * scal);
	glTexCoord3f(x, y + 24 * scal, z + 5 * scal); glVertex3f(x, y + 24 * scal, z + 5 * scal);
	glTexCoord3f(x, y + 24 * scal, z); glVertex3f(x, y + 24 * scal, z);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x, y + 24 * scal, z + 5 * scal); glVertex3f(x, y + 24 * scal, z + 5 * scal);
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z + 5 * scal); glVertex3f(x - 24 * scal, y + 24 * scal, z + 5 * scal);
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z); glVertex3f(x - 24 * scal, y + 24 * scal, z);
	glTexCoord3f(x, y + 24 * scal, z); glVertex3f(x, y + 24 * scal, z);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z + 5 * scal); glVertex3f(x - 24 * scal, y + 24 * scal, z + 5 * scal);
	glTexCoord3f(x - 24 * scal, y, z + 5 * scal); glVertex3f(x - 24 * scal, y, z + 5 * scal);
	glTexCoord3f(x - 24 * scal, y, z); glVertex3f(x - 24 * scal, y, z);
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z); glVertex3f(x - 24 * scal, y + 24 * scal, z);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 24 * scal, y, z); glVertex3f(x - 24 * scal, y, z);
	glTexCoord3f(x - 24 * scal, y, z + 5 * scal); glVertex3f(x - 24 * scal, y, z + 5 * scal);
	glTexCoord3f(x, y, z + 5 * scal); glVertex3f(x, y, z + 5 * scal);
	glTexCoord3f(x, y, z); glVertex3f(x, y, z);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x, y, z + 5 * scal); glVertex3f(x, y, z + 5 * scal);
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 15 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 15 * scal);
	glTexCoord3f(x - 5 * scal, y + 19 * scal, z + 15 * scal); glVertex3f(x - 5 * scal, y + 19 * scal, z + 15 * scal);
	glTexCoord3f(x, y + 24 * scal, z + 5 * scal); glVertex3f(x, y + 24 * scal, z + 5 * scal);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x, y + 24 * scal, z + 5 * scal); glVertex3f(x, y + 24 * scal, z + 5 * scal);
	glTexCoord3f(x - 5 * scal, y + 19 * scal, z + 15 * scal); glVertex3f(x - 5 * scal, y + 19 * scal, z + 15 * scal);
	glTexCoord3f(x - 19 * scal, y + 19 * scal, z + 15 * scal); glVertex3f(x - 19 * scal, y + 19 * scal, z + 15 * scal);
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z + 5 * scal); glVertex3f(x - 24 * scal, y + 24 * scal, z + 5 * scal);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z + 5 * scal); glVertex3f(x - 24 * scal, y + 24 * scal, z + 5 * scal);
	glTexCoord3f(x - 19 * scal, y + 19 * scal, z + 15 * scal); glVertex3f(x - 19 * scal, y + 19 * scal, z + 15 * scal);
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 15 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 15 * scal);
	glTexCoord3f(x - 24 * scal, y, z + 5 * scal); glVertex3f(x - 24 * scal, y, z + 5 * scal);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 24 * scal, y, z + 5 * scal); glVertex3f(x - 24 * scal, y, z + 5 * scal);
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 15 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 15 * scal);
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 15 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 15 * scal);
	glTexCoord3f(x, y, z + 5 * scal); glVertex3f(x, y, z + 5 * scal);
	glEnd();

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 15 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 15 * scal);
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 45 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 45 * scal);
	glTexCoord3f(x - 5 * scal, y + 19 * scal, z + 45 * scal); glVertex3f(x - 5 * scal, y + 19 * scal, z + 45 * scal);
	glTexCoord3f(x - 5 * scal, y + 19 * scal, z + 15 * scal); glVertex3f(x - 5 * scal, y + 19 * scal, z + 15 * scal);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 5 * scal, y + 19 * scal, z + 15 * scal); glVertex3f(x - 5 * scal, y + 19 * scal, z + 15 * scal);
	glTexCoord3f(x - 5 * scal, y + 19 * scal, z + 45 * scal); glVertex3f(x - 5 * scal, y + 19 * scal, z + 45 * scal);
	glTexCoord3f(x - 19 * scal, y + 19 * scal, z + 45 * scal); glVertex3f(x - 19 * scal, y + 19 * scal, z + 45 * scal);
	glTexCoord3f(x - 19 * scal, y + 19 * scal, z + 15 * scal); glVertex3f(x - 19 * scal, y + 19 * scal, z + 15 * scal);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 19 * scal, y + 19 * scal, z + 15 * scal); glVertex3f(x - 19 * scal, y + 19 * scal, z + 15 * scal);
	glTexCoord3f(x - 19 * scal, y + 19 * scal, z + 45 * scal); glVertex3f(x - 19 * scal, y + 19 * scal, z + 45 * scal);
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 45 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 45 * scal);
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 15 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 15 * scal);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 15 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 15 * scal);
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 45 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 45 * scal);
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 45 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 45 * scal);
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 15 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 15 * scal);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 45 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 45 * scal);
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 50 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 50 * scal);
	glTexCoord3f(x - 2 * scal, y + 23 * scal, z + 50 * scal); glVertex3f(x - 2 * scal, y + 23 * scal, z + 50 * scal);
	glTexCoord3f(x - 5 * scal, y + 19 * scal, z + 45 * scal); glVertex3f(x - 5 * scal, y + 19 * scal, z + 45 * scal);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 5 * scal, y + 19 * scal, z + 45 * scal); glVertex3f(x - 5 * scal, y + 19 * scal, z + 45 * scal);
	glTexCoord3f(x - 2 * scal, y + 23 * scal, z + 50 * scal); glVertex3f(x - 2 * scal, y + 23 * scal, z + 50 * scal);
	glTexCoord3f(x - 23 * scal, y + 23 * scal, z + 50 * scal); glVertex3f(x - 23 * scal, y + 23 * scal, z + 50 * scal);
	glTexCoord3f(x - 19 * scal, y + 19 * scal, z + 45 * scal); glVertex3f(x - 19 * scal, y + 19 * scal, z + 45 * scal);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 19 * scal, y + 19 * scal, z + 45 * scal); glVertex3f(x - 19 * scal, y + 19 * scal, z + 45 * scal);
	glTexCoord3f(x - 23 * scal, y + 23 * scal, z + 50 * scal); glVertex3f(x - 23 * scal, y + 23 * scal, z + 50 * scal);
	glTexCoord3f(x - 23 * scal, y + 2 * scal, z + 50 * scal); glVertex3f(x - 23 * scal, y + 2 * scal, z + 50 * scal);
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 45 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 45 * scal);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 45 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 45 * scal);
	glTexCoord3f(x - 23 * scal, y + 2 * scal, z + 50 * scal); glVertex3f(x - 23 * scal, y + 2 * scal, z + 50 * scal);
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 50 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 50 * scal);
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 45 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 45 * scal);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 50 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 50 * scal);
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 55 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 55 * scal);
	glTexCoord3f(x - 5 * scal, y + 19 * scal, z + 55 * scal); glVertex3f(x - 5 * scal, y + 19 * scal, z + 55 * scal);
	glTexCoord3f(x - 2 * scal, y + 23 * scal, z + 50 * scal); glVertex3f(x - 2 * scal, y + 23 * scal, z + 50 * scal);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 2 * scal, y + 23 * scal, z + 50 * scal); glVertex3f(x - 2 * scal, y + 23 * scal, z + 50 * scal);
	glTexCoord3f(x - 5 * scal, y + 19 * scal, z + 55 * scal); glVertex3f(x - 5 * scal, y + 19 * scal, z + 55 * scal);
	glTexCoord3f(x - 19 * scal, y + 19 * scal, z + 55 * scal); glVertex3f(x - 19 * scal, y + 19 * scal, z + 55 * scal);
	glTexCoord3f(x - 23 * scal, y + 23 * scal, z + 50 * scal); glVertex3f(x - 23 * scal, y + 23 * scal, z + 50 * scal);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 23 * scal, y + 23 * scal, z + 50 * scal); glVertex3f(x - 23 * scal, y + 23 * scal, z + 50 * scal);
	glTexCoord3f(x - 19 * scal, y + 19 * scal, z + 55 * scal); glVertex3f(x - 19 * scal, y + 19 * scal, z + 55 * scal);
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 55 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 55 * scal);
	glTexCoord3f(x - 23 * scal, y + 2 * scal, z + 50 * scal); glVertex3f(x - 23 * scal, y + 2 * scal, z + 50 * scal);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 23 * scal, y + 2 * scal, z + 50 * scal); glVertex3f(x - 23 * scal, y + 2 * scal, z + 50 * scal);
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 55 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 55 * scal);
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 55 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 55 * scal);
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 50 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 50 * scal);
	glEnd();

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////BASE

	glBegin(GL_POLYGON);
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 55 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 55 * scal);//C
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 55 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 55 * scal);//A
	glTexCoord3f(x - 5 * scal, y + 19 * scal, z + 55 * scal); glVertex3f(x - 5 * scal, y + 19 * scal, z + 55 * scal);//B
	glTexCoord3f(x - 19 * scal, y + 19 * scal, z + 55 * scal); glVertex3f(x - 19 * scal, y + 19 * scal, z + 55 * scal);//D
	glEnd();

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////CORONA

	glBegin(GL_POLYGON);//corona
	glTexCoord3f(x - 15 * scal, y + 15 * scal, z + 55 * scal); glVertex3f(x - 15 * scal, y + 15 * scal, z + 55 * scal);//E
	glTexCoord3f(x - 9 * scal, y + 15 * scal, z + 55 * scal); glVertex3f(x - 9 * scal, y + 15 * scal, z + 55 * scal);//F
	glTexCoord3f(x - 9 * scal, y + 15 * scal, z + 55 * scal); glVertex3f(x - 9 * scal, y + 15 * scal, z + 60 * scal);//F
	glTexCoord3f(x - 15 * scal, y + 15 * scal, z + 55 * scal); glVertex3f(x - 15 * scal, y + 15 * scal, z + 60 * scal);//E
	glEnd();

	glBegin(GL_POLYGON);//corona
	glTexCoord3f(x - 9 * scal, y + 15 * scal, z + 55 * scal); glVertex3f(x - 9 * scal, y + 15 * scal, z + 55 * scal);//F
	glTexCoord3f(x - 9 * scal, y + 9 * scal, z + 55 * scal); glVertex3f(x - 9 * scal, y + 9 * scal, z + 55 * scal);//G
	glTexCoord3f(x - 9 * scal, y + 9 * scal, z + 55 * scal); glVertex3f(x - 9 * scal, y + 9 * scal, z + 60 * scal);//G
	glTexCoord3f(x - 9 * scal, y + 15 * scal, z + 55 * scal); glVertex3f(x - 9 * scal, y + 15 * scal, z + 60 * scal);//F
	glEnd();

	glBegin(GL_POLYGON);//corona
	glTexCoord3f(x - 9 * scal, y + 9 * scal, z + 55 * scal); glVertex3f(x - 9 * scal, y + 9 * scal, z + 55 * scal);//G
	glTexCoord3f(x - 15 * scal, y + 9 * scal, z + 55 * scal); glVertex3f(x - 15 * scal, y + 9 * scal, z + 55 * scal);//H
	glTexCoord3f(x - 15 * scal, y + 9 * scal, z + 60 * scal); glVertex3f(x - 15 * scal, y + 9 * scal, z + 60 * scal);//H
	glTexCoord3f(x - 9 * scal, y + 9 * scal, z + 55 * scal); glVertex3f(x - 9 * scal, y + 9 * scal, z + 60 * scal);//G
	glEnd();

	glBegin(GL_POLYGON);//corona
	glTexCoord3f(x - 15 * scal, y + 15 * scal, z + 55 * scal); glVertex3f(x - 15 * scal, y + 15 * scal, z + 55 * scal);//E
	glTexCoord3f(x - 15 * scal, y + 9 * scal, z + 55 * scal); glVertex3f(x - 15 * scal, y + 9 * scal, z + 55 * scal);//H
	glTexCoord3f(x - 15 * scal, y + 9 * scal, z + 60 * scal); glVertex3f(x - 15 * scal, y + 9 * scal, z + 60 * scal);//H
	glTexCoord3f(x - 15 * scal, y + 15 * scal, z + 55 * scal); glVertex3f(x - 15 * scal, y + 15 * scal, z + 60 * scal);//E
	glEnd();

	glBegin(GL_POLYGON);//corona
	glTexCoord3f(x - 9 * scal, y + 15 * scal, z + 55 * scal); glVertex3f(x - 9 * scal, y + 15 * scal, z + 60 * scal);//F
	glTexCoord3f(x - 15 * scal, y + 15 * scal, z + 55 * scal); glVertex3f(x - 15 * scal, y + 15 * scal, z + 60 * scal);//E
	glTexCoord3f(x - 15 * scal, y + 9 * scal, z + 60 * scal); glVertex3f(x - 15 * scal, y + 9 * scal, z + 60 * scal);//H
	glTexCoord3f(x - 9 * scal, y + 9 * scal, z + 55 * scal); glVertex3f(x - 9 * scal, y + 9 * scal, z + 60 * scal);//G
	glEnd();

	glDisable(GL_TEXTURE_2D);
};

//Naty
void Ajedrez::rey(double x, double y, double z, double scal, int texture){

	glEnable(GL_TEXTURE_2D);
	texture == 0 ? glBindTexture(GL_TEXTURE_2D, ID_de_Textura1) : glBindTexture(GL_TEXTURE_2D, ID_de_Textura2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glBegin(GL_POLYGON);//base del rey
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x, y, z); glVertex3f(x, y, z);//A
	glTexCoord3f(x, y + 24 * scal, z); glVertex3f(x, y + 24 * scal, z);//B
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z); glVertex3f(x - 24 * scal, y + 24 * scal, z);//C
	glTexCoord3f(x - 24 * scal, y, z); glVertex3f(x - 24 * scal, y, z);//D
	glEnd();

	glBegin(GL_POLYGON);//base del rey altura pequeña
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x, y, z + 5 * scal); glVertex3f(x, y, z + 5 * scal);//A1
	glTexCoord3f(x, y + 24 * scal, z + 5 * scal); glVertex3f(x, y + 24 * scal, z + 5 * scal);//B1
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z + 5 * scal); glVertex3f(x - 24 * scal, y + 24 * scal, z + 5 * scal);//C1
	glTexCoord3f(x - 24 * scal, y, z + 5 * scal); glVertex3f(x - 24 * scal, y, z + 5 * scal);//D1
	glEnd();

	glBegin(GL_POLYGON);//base del rey lados 1
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x, y, z); glVertex3f(x, y, z);//A
	glTexCoord3f(x, y, z + 5 * scal); glVertex3f(x, y, z + 5 * scal);//A1
	glTexCoord3f(x, y + 24 * scal, z + 5 * scal); glVertex3f(x, y + 24 * scal, z + 5 * scal);//B1
	glTexCoord3f(x, y + 24 * scal, z); glVertex3f(x, y + 24 * scal, z);//B
	glEnd();

	glBegin(GL_POLYGON);//base del rey lados 2
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x, y + 24 * scal, z + 5 * scal); glVertex3f(x, y + 24 * scal, z + 5 * scal);//B1
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z + 5 * scal); glVertex3f(x - 24 * scal, y + 24 * scal, z + 5 * scal);//C1
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z); glVertex3f(x - 24 * scal, y + 24 * scal, z);//C
	glTexCoord3f(x, y + 24 * scal, z); glVertex3f(x, y + 24 * scal, z);//B
	glEnd();

	glBegin(GL_POLYGON);//base del rey lados 3
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z + 5 * scal); glVertex3f(x - 24 * scal, y + 24 * scal, z + 5 * scal);//C1
	glTexCoord3f(x - 24 * scal, y, z + 5 * scal); glVertex3f(x - 24 * scal, y, z + 5 * scal);//D1
	glTexCoord3f(x - 24 * scal, y, z); glVertex3f(x - 24 * scal, y, z);//D
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z); glVertex3f(x - 24 * scal, y + 24 * scal, z);//C
	glEnd();

	glBegin(GL_POLYGON);//base del rey lados 4
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 24 * scal, y, z); glVertex3f(x - 24 * scal, y, z);//D
	glTexCoord3f(x - 24 * scal, y, z + 5 * scal); glVertex3f(x - 24 * scal, y, z + 5 * scal);//D1
	glTexCoord3f(x, y, z + 5 * scal); glVertex3f(x, y, z + 5 * scal);//A1
	glTexCoord3f(x, y, z); glVertex3f(x, y, z);//A
	glEnd();

	glBegin(GL_POLYGON);//base del rey caida 1
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x, y, z + 5 * scal); glVertex3f(x, y, z + 5 * scal);//A1
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 15 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 15 * scal);//E
	glTexCoord3f(x - 5 * scal, y + 19 * scal, z + 15 * scal); glVertex3f(x - 5 * scal, y + 19 * scal, z + 15 * scal);//F
	glTexCoord3f(x, y + 24 * scal, z + 5 * scal); glVertex3f(x, y + 24 * scal, z + 5 * scal);//B1
	glEnd();

	glBegin(GL_POLYGON);//base del rey caida 2
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x, y + 24 * scal, z + 5 * scal); glVertex3f(x, y + 24 * scal, z + 5 * scal);//B1
	glTexCoord3f(x - 5 * scal, y + 19 * scal, z + 15 * scal); glVertex3f(x - 5 * scal, y + 19 * scal, z + 15 * scal);//F
	glTexCoord3f(x - 19 * scal, y + 19 * scal, z + 15 * scal); glVertex3f(x - 19 * scal, y + 19 * scal, z + 15 * scal);//H
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z + 5 * scal); glVertex3f(x - 24 * scal, y + 24 * scal, z + 5 * scal);//C1
	glEnd();

	glBegin(GL_POLYGON);//base del rey caida 3
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z + 5 * scal); glVertex3f(x - 24 * scal, y + 24 * scal, z + 5 * scal);//C1
	glTexCoord3f(x - 19 * scal, y + 19 * scal, z + 15 * scal); glVertex3f(x - 19 * scal, y + 19 * scal, z + 15 * scal);//H
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 15 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 15 * scal);//G
	glTexCoord3f(x - 24 * scal, y, z + 5 * scal); glVertex3f(x - 24 * scal, y, z + 5 * scal);//D1
	glEnd();

	glBegin(GL_POLYGON);//base del rey caida 4
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 24 * scal, y, z + 5 * scal); glVertex3f(x - 24 * scal, y, z + 5 * scal);//D1
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 15 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 15 * scal);//G
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 15 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 15 * scal);//E
	glTexCoord3f(x, y, z + 5 * scal); glVertex3f(x, y, z + 5 * scal);//A1	
	glEnd();

	glBegin(GL_POLYGON);//base del rey altura 1
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 15 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 15 * scal);//E
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 35 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 35 * scal);//E1
	glTexCoord3f(x - 5 * scal, y + 19 * scal, z + 35 * scal); glVertex3f(x - 5 * scal, y + 19 * scal, z + 35 * scal);//F1
	glTexCoord3f(x - 5 * scal, y + 19 * scal, z + 15 * scal); glVertex3f(x - 5 * scal, y + 19 * scal, z + 15 * scal);//F
	glEnd();

	glBegin(GL_POLYGON);//base del rey altura 2
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 5 * scal, y + 19 * scal, z + 15 * scal); glVertex3f(x - 5 * scal, y + 19 * scal, z + 15 * scal);//F
	glTexCoord3f(x - 5 * scal, y + 19 * scal, z + 35 * scal); glVertex3f(x - 5 * scal, y + 19 * scal, z + 35 * scal);//F1
	glTexCoord3f(x - 19 * scal, y + 19 * scal, z + 35 * scal); glVertex3f(x - 19 * scal, y + 19 * scal, z + 35 * scal);//H1
	glTexCoord3f(x - 19 * scal, y + 19 * scal, z + 15 * scal); glVertex3f(x - 19 * scal, y + 19 * scal, z + 15 * scal);//H
	glEnd();

	glBegin(GL_POLYGON);//base del rey altura 3
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 19 * scal, y + 19 * scal, z + 15 * scal); glVertex3f(x - 19 * scal, y + 19 * scal, z + 15 * scal);//H
	glTexCoord3f(x - 19 * scal, y + 19 * scal, z + 35 * scal); glVertex3f(x - 19 * scal, y + 19 * scal, z + 35 * scal);//H1
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 35 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 35 * scal);//G1
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 15 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 15 * scal);//G
	glEnd();

	glBegin(GL_POLYGON);//base del rey altura 4
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 15 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 15 * scal);//G
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 35 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 35 * scal);//G1
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 35 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 35 * scal);//E1
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 15 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 15 * scal);//E	
	glEnd();

	glBegin(GL_POLYGON);//rey altura 1
	glColor3f(0.5, 0.5, 0.5);
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 35 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 35 * scal);//E1
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 40 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 40 * scal);//M
	glTexCoord3f(x - 2 * scal, y + 23 * scal, z + 40 * scal); glVertex3f(x - 2 * scal, y + 23 * scal, z + 40 * scal);//N 
	glTexCoord3f(x - 5 * scal, y + 19 * scal, z + 35 * scal); glVertex3f(x - 5 * scal, y + 19 * scal, z + 35 * scal);//F1
	glEnd();

	glBegin(GL_POLYGON);//rey altura 2
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 5 * scal, y + 19 * scal, z + 35 * scal); glVertex3f(x - 5 * scal, y + 19 * scal, z + 35 * scal);//F1
	glTexCoord3f(x - 2 * scal, y + 23 * scal, z + 40 * scal); glVertex3f(x - 2 * scal, y + 23 * scal, z + 40 * scal);//N 
	glTexCoord3f(x - 23 * scal, y + 23 * scal, z + 40 * scal); glVertex3f(x - 23 * scal, y + 23 * scal, z + 40 * scal);//Ñ
	glTexCoord3f(x - 19 * scal, y + 19 * scal, z + 35 * scal); glVertex3f(x - 19 * scal, y + 19 * scal, z + 35 * scal);//H1
	glEnd();

	glBegin(GL_POLYGON);//rey altura 3
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 19 * scal, y + 19 * scal, z + 35 * scal); glVertex3f(x - 19 * scal, y + 19 * scal, z + 35 * scal);//H1
	glTexCoord3f(x - 23 * scal, y + 23 * scal, z + 40 * scal); glVertex3f(x - 23 * scal, y + 23 * scal, z + 40 * scal);//Ñ
	glTexCoord3f(x - 23 * scal, y + 2 * scal, z + 40 * scal); glVertex3f(x - 23 * scal, y + 2 * scal, z + 40 * scal);//O
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 35 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 35 * scal);//G1
	glEnd();

	glBegin(GL_POLYGON);//rey altura 4
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 35 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 35 * scal);//G1
	glTexCoord3f(x - 23 * scal, y + 2 * scal, z + 40 * scal); glVertex3f(x - 23 * scal, y + 2 * scal, z + 40 * scal);//O
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 40 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 40 * scal);//M
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 35 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 35 * scal);//E1	
	glEnd();

	glBegin(GL_POLYGON);//rey altura 1.1
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 40 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 40 * scal);//M
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 45 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 45 * scal);//M1 glVertex3f(x-5*scal,y+5*scal,z+35*scal);//E1
	glTexCoord3f(x - 5 * scal, y + 19 * scal, z + 45 * scal); glVertex3f(x - 5 * scal, y + 19 * scal, z + 45 * scal);//N1 glVertex3f(x-5*scal,y+19*scal,z+35*scal);//F1
	glTexCoord3f(x - 2 * scal, y + 23 * scal, z + 40 * scal); glVertex3f(x - 2 * scal, y + 23 * scal, z + 40 * scal);//N
	glEnd();

	glBegin(GL_POLYGON);//rey altura 1.2
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 2 * scal, y + 23 * scal, z + 40 * scal); glVertex3f(x - 2 * scal, y + 23 * scal, z + 40 * scal);//N 
	glTexCoord3f(x - 5 * scal, y + 19 * scal, z + 45 * scal); glVertex3f(x - 5 * scal, y + 19 * scal, z + 45 * scal);//N1 
	glTexCoord3f(x - 19 * scal, y + 19 * scal, z + 45 * scal); glVertex3f(x - 19 * scal, y + 19 * scal, z + 45 * scal);//Ñ1 glVertex3f(x-19*scal,y+19*scal,z+35*scal);//H1
	glTexCoord3f(x - 23 * scal, y + 23 * scal, z + 40 * scal); glVertex3f(x - 23 * scal, y + 23 * scal, z + 40 * scal);//Ñ
	glEnd();

	glBegin(GL_POLYGON);//rey altura 1.3
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 23 * scal, y + 23 * scal, z + 40 * scal); glVertex3f(x - 23 * scal, y + 23 * scal, z + 40 * scal);//Ñ
	glTexCoord3f(x - 19 * scal, y + 19 * scal, z + 45 * scal); glVertex3f(x - 19 * scal, y + 19 * scal, z + 45 * scal);//Ñ1 glVertex3f(x-19*scal,y+19*scal,z+35*scal);//H1
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 45 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 45 * scal);//O1 glVertex3f(x-19*scal,y+5*scal,z+35*scal);//G1
	glTexCoord3f(x - 23 * scal, y + 2 * scal, z + 40 * scal); glVertex3f(x - 23 * scal, y + 2 * scal, z + 40 * scal);//O
	glEnd();

	glBegin(GL_POLYGON);//rey altura 1.4
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 23 * scal, y + 2 * scal, z + 40 * scal); glVertex3f(x - 23 * scal, y + 2 * scal, z + 40 * scal);//O
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 45 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 45 * scal);//O1 glVertex3f(x-19*scal,y+5*scal,z+35*scal);//G1
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 45 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 45 * scal);//M1 glVertex3f(x-5*scal,y+5*scal,z+35*scal);//E1
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 40 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 40 * scal);//M	
	glEnd();

	glBegin(GL_POLYGON);//rey copita 1
	glColor3f(0.5, 0.5, 0.5);
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 45 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 45 * scal);//M1 glVertex3f(x-5*scal,y+5*scal,z+35*scal);//E1
	glTexCoord3f(x - 3 * scal, y + 3 * scal, z + 50 * scal); glVertex3f(x - 3 * scal, y + 3 * scal, z + 50 * scal);//1A
	glTexCoord3f(x - 3 * scal, y + 22 * scal, z + 50 * scal); glVertex3f(x - 3 * scal, y + 22 * scal, z + 50 * scal);//2A
	glTexCoord3f(x - 5 * scal, y + 19 * scal, z + 45 * scal); glVertex3f(x - 5 * scal, y + 19 * scal, z + 45 * scal);//N1 
	glEnd();

	glBegin(GL_POLYGON);//rey copita 2
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 5 * scal, y + 19 * scal, z + 45 * scal); glVertex3f(x - 5 * scal, y + 19 * scal, z + 45 * scal);//N1 
	glTexCoord3f(x - 3 * scal, y + 22 * scal, z + 50 * scal); glVertex3f(x - 3 * scal, y + 22 * scal, z + 50 * scal);//2A
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 50 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 50 * scal);//3A glVertex3f(x-23*scal,y+23*scal,z+40*scal);//Ñ
	glTexCoord3f(x - 19 * scal, y + 19 * scal, z + 45 * scal); glVertex3f(x - 19 * scal, y + 19 * scal, z + 45 * scal);//Ñ1 glVertex3f(x-19*scal,y+19*scal,z+35*scal);//H1
	glEnd();

	glBegin(GL_POLYGON);//rey copita 3
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 19 * scal, y + 19 * scal, z + 45 * scal); glVertex3f(x - 19 * scal, y + 19 * scal, z + 45 * scal);//Ñ1 glVertex3f(x-19*scal,y+19*scal,z+35*scal);//H1
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 50 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 50 * scal);//3A glVertex3f(x-23*scal,y+23*scal,z+40*scal);//Ñ
	glTexCoord3f(x - 22 * scal, y + 3 * scal, z + 50 * scal); glVertex3f(x - 22 * scal, y + 3 * scal, z + 50 * scal);//4A glVertex3f(x-23*scal,y+2*scal,z+40*scal);//O
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 45 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 45 * scal);//O1 glVertex3f(x-19*scal,y+5*scal,z+35*scal);//G1
	glEnd();

	glBegin(GL_POLYGON);//rey copita 4
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 45 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 45 * scal);//O1 glVertex3f(x-19*scal,y+5*scal,z+35*scal);//G1
	glTexCoord3f(x - 22 * scal, y + 3 * scal, z + 50 * scal); glVertex3f(x - 22 * scal, y + 3 * scal, z + 50 * scal);//4A glVertex3f(x-23*scal,y+2*scal,z+40*scal);//O
	glTexCoord3f(x - 3 * scal, y + 3 * scal, z + 50 * scal); glVertex3f(x - 3 * scal, y + 3 * scal, z + 50 * scal);//1A
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 45 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 45 * scal);//M1 glVertex3f(x-5*scal,y+5*scal,z+35*scal);//E1
	glEnd();

	glBegin(GL_POLYGON);//rey copita 1.1
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 3 * scal, y + 3 * scal, z + 50 * scal); glVertex3f(x - 3 * scal, y + 3 * scal, z + 50 * scal);//1A
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 55 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 55 * scal);//1A1
	glTexCoord3f(x - 5 * scal, y + 19 * scal, z + 55 * scal); glVertex3f(x - 5 * scal, y + 19 * scal, z + 55 * scal);//1A2
	glTexCoord3f(x - 3 * scal, y + 22 * scal, z + 50 * scal); glVertex3f(x - 3 * scal, y + 22 * scal, z + 50 * scal);//2A
	glEnd();

	glBegin(GL_POLYGON);//rey copita 1.2
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 3 * scal, y + 22 * scal, z + 50 * scal); glVertex3f(x - 3 * scal, y + 22 * scal, z + 50 * scal);//2A
	glTexCoord3f(x - 5 * scal, y + 19 * scal, z + 55 * scal); glVertex3f(x - 5 * scal, y + 19 * scal, z + 55 * scal);//1A2
	glTexCoord3f(x - 19 * scal, y + 19 * scal, z + 55 * scal); glVertex3f(x - 19 * scal, y + 19 * scal, z + 55 * scal);//1A3
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 50 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 50 * scal);//3A glVertex3f(x-23*scal,y+23*scal,z+40*scal);//Ñ
	glEnd();

	glBegin(GL_POLYGON);//rey copita 1.3
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 50 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 50 * scal);//3A glVertex3f(x-23*scal,y+23*scal,z+40*scal);//Ñ
	glTexCoord3f(x - 19 * scal, y + 19 * scal, z + 55 * scal); glVertex3f(x - 19 * scal, y + 19 * scal, z + 55 * scal);//1A3
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 55 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 55 * scal);//1A4
	glTexCoord3f(x - 22 * scal, y + 3 * scal, z + 50 * scal); glVertex3f(x - 22 * scal, y + 3 * scal, z + 50 * scal);//4A glVertex3f(x-23*scal,y+2*scal,z+40*scal);//O
	glEnd();

	glBegin(GL_POLYGON);//rey copita 1.4
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 22 * scal, y + 3 * scal, z + 50 * scal); glVertex3f(x - 22 * scal, y + 3 * scal, z + 50 * scal);//4A glVertex3f(x-23*scal,y+2*scal,z+40*scal);//O
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 55 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 55 * scal);//1A4
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 55 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 55 * scal);//1A1
	glTexCoord3f(x - 3 * scal, y + 3 * scal, z + 50 * scal); glVertex3f(x - 3 * scal, y + 3 * scal, z + 50 * scal);//1A	
	glEnd();

	glBegin(GL_POLYGON);//rey copita 1.4
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 22 * scal, y + 3 * scal, z + 50 * scal); glVertex3f(x - 22 * scal, y + 3 * scal, z + 50 * scal);//4A glVertex3f(x-23*scal,y+2*scal,z+40*scal);//O
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 55 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 55 * scal);//1A4
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 55 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 55 * scal);//1A1
	glTexCoord3f(x - 3 * scal, y + 3 * scal, z + 50 * scal); glVertex3f(x - 3 * scal, y + 3 * scal, z + 50 * scal);//1A	
	glEnd();

	glBegin(GL_POLYGON);//rey techito copita
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 5 * scal, y + 5 * scal, z + 55 * scal); glVertex3f(x - 5 * scal, y + 5 * scal, z + 55 * scal);//1A1
	glTexCoord3f(x - 5 * scal, y + 19 * scal, z + 55 * scal); glVertex3f(x - 5 * scal, y + 19 * scal, z + 55 * scal);//1A2
	glTexCoord3f(x - 19 * scal, y + 19 * scal, z + 55 * scal); glVertex3f(x - 19 * scal, y + 19 * scal, z + 55 * scal);//1A3
	glTexCoord3f(x - 19 * scal, y + 5 * scal, z + 55 * scal); glVertex3f(x - 19 * scal, y + 5 * scal, z + 55 * scal);//1A4
	glEnd();

	glBegin(GL_POLYGON);//rey cruz 1
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 10 * scal, y + 10 * scal, z + 55 * scal); glVertex3f(x - 10 * scal, y + 10 * scal, z + 55 * scal);//R1
	glTexCoord3f(x - 10 * scal, y + 10 * scal, z + 64 * scal); glVertex3f(x - 10 * scal, y + 10 * scal, z + 64 * scal);//1R1
	glTexCoord3f(x - 10 * scal, y + 14.5*scal, z + 64 * scal); glVertex3f(x - 10 * scal, y + 14.5*scal, z + 64 * scal);//2R2
	glTexCoord3f(x - 10 * scal, y + 14.5*scal, z + 55 * scal); glVertex3f(x - 10 * scal, y + 14.5*scal, z + 55 * scal);//R2
	glEnd();

	glBegin(GL_POLYGON);//rey cruz 2
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 10 * scal, y + 14.5*scal, z + 55 * scal); glVertex3f(x - 10 * scal, y + 14.5*scal, z + 55 * scal);//R2
	glTexCoord3f(x - 10 * scal, y + 14.5*scal, z + 64 * scal); glVertex3f(x - 10 * scal, y + 14.5*scal, z + 64 * scal);//2R2
	glTexCoord3f(x - 14.5*scal, y + 14.5*scal, z + 64 * scal); glVertex3f(x - 14.5*scal, y + 14.5*scal, z + 64 * scal);//3R3
	glTexCoord3f(x - 14.5*scal, y + 14.5*scal, z + 55 * scal); glVertex3f(x - 14.5*scal, y + 14.5*scal, z + 55 * scal);//R3
	glEnd();

	glBegin(GL_POLYGON);//rey cruz 3
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 14.5*scal, y + 14.5*scal, z + 55 * scal); glVertex3f(x - 14.5*scal, y + 14.5*scal, z + 55 * scal);//R3
	glTexCoord3f(x - 14.5*scal, y + 14.5*scal, z + 64 * scal); glVertex3f(x - 14.5*scal, y + 14.5*scal, z + 64 * scal);//3R3
	glTexCoord3f(x - 14.5*scal, y + 10 * scal, z + 64 * scal); glVertex3f(x - 14.5*scal, y + 10 * scal, z + 64 * scal);//4R4
	glTexCoord3f(x - 14.5*scal, y + 10 * scal, z + 55 * scal); glVertex3f(x - 14.5*scal, y + 10 * scal, z + 55 * scal);//R4
	glEnd();

	glBegin(GL_POLYGON);//rey cruz 4
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 14.5*scal, y + 10 * scal, z + 55 * scal); glVertex3f(x - 14.5*scal, y + 10 * scal, z + 55 * scal);//R4
	glTexCoord3f(x - 14.5*scal, y + 10 * scal, z + 64 * scal); glVertex3f(x - 14.5*scal, y + 10 * scal, z + 64 * scal);//4R4
	glTexCoord3f(x - 10 * scal, y + 10 * scal, z + 64 * scal); glVertex3f(x - 10 * scal, y + 10 * scal, z + 64 * scal);//1R1
	glTexCoord3f(x - 10 * scal, y + 10 * scal, z + 55 * scal); glVertex3f(x - 10 * scal, y + 10 * scal, z + 55 * scal);//R1	
	glEnd();

	glBegin(GL_POLYGON);//rey cruz H 1
	glColor3f(0.5, 0.5, 0.5);
	glTexCoord3f(x - 7 * scal, y + 10 * scal, z + 58 * scal); glVertex3f(x - 7 * scal, y + 10 * scal, z + 58 * scal);//RH1
	glTexCoord3f(x - 7 * scal, y + 14.5*scal, z + 58 * scal); glVertex3f(x - 7 * scal, y + 14.5*scal, z + 58 * scal);//RH2
	glTexCoord3f(x - 17 * scal, y + 14.5*scal, z + 58 * scal); glVertex3f(x - 17 * scal, y + 14.5*scal, z + 58 * scal);//RH3
	glTexCoord3f(x - 17 * scal, y + 10 * scal, z + 58 * scal); glVertex3f(x - 17 * scal, y + 10 * scal, z + 58 * scal);//RH4
	glEnd();

	glBegin(GL_POLYGON);//rey cruz H 1
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 7 * scal, y + 10 * scal, z + 58 * scal); glVertex3f(x - 7 * scal, y + 10 * scal, z + 58 * scal);//RH1
	glTexCoord3f(x - 7 * scal, y + 10 * scal, z + 61 * scal); glVertex3f(x - 7 * scal, y + 10 * scal, z + 61 * scal);//1RH1
	glTexCoord3f(x - 7 * scal, y + 14.5*scal, z + 61 * scal); glVertex3f(x - 7 * scal, y + 14.5*scal, z + 61 * scal);//2RH2
	glTexCoord3f(x - 7 * scal, y + 14.5*scal, z + 58 * scal); glVertex3f(x - 7 * scal, y + 14.5*scal, z + 58 * scal);//RH2
	glEnd();

	glBegin(GL_POLYGON);//rey cruz H 2
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 7 * scal, y + 14.5*scal, z + 58 * scal); glVertex3f(x - 7 * scal, y + 14.5*scal, z + 58 * scal);//RH2
	glTexCoord3f(x - 7 * scal, y + 14.5*scal, z + 61 * scal); glVertex3f(x - 7 * scal, y + 14.5*scal, z + 61 * scal);//2RH2
	glTexCoord3f(x - 17 * scal, y + 14.5*scal, z + 61 * scal); glVertex3f(x - 17 * scal, y + 14.5*scal, z + 61 * scal);//3RH3
	glTexCoord3f(x - 17 * scal, y + 14.5*scal, z + 58 * scal); glVertex3f(x - 17 * scal, y + 14.5*scal, z + 58 * scal);//RH3
	glEnd();

	glBegin(GL_POLYGON);//rey cruz H 3
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 17 * scal, y + 14.5*scal, z + 58 * scal); glVertex3f(x - 17 * scal, y + 14.5*scal, z + 58 * scal);//RH3
	glTexCoord3f(x - 17 * scal, y + 14.5*scal, z + 61 * scal); glVertex3f(x - 17 * scal, y + 14.5*scal, z + 61 * scal);//3RH3
	glTexCoord3f(x - 17 * scal, y + 10 * scal, z + 61 * scal); glVertex3f(x - 17 * scal, y + 10 * scal, z + 61 * scal);//4RH4
	glTexCoord3f(x - 17 * scal, y + 10 * scal, z + 58 * scal); glVertex3f(x - 17 * scal, y + 10 * scal, z + 58 * scal);//RH4
	glEnd();

	glBegin(GL_POLYGON);//rey cruz H 4
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 17 * scal, y + 10 * scal, z + 58 * scal); glVertex3f(x - 17 * scal, y + 10 * scal, z + 58 * scal);//RH4
	glTexCoord3f(x - 17 * scal, y + 10 * scal, z + 61 * scal); glVertex3f(x - 17 * scal, y + 10 * scal, z + 61 * scal);//4RH4
	glTexCoord3f(x - 7 * scal, y + 10 * scal, z + 61 * scal); glVertex3f(x - 7 * scal, y + 10 * scal, z + 61 * scal);//1RH1
	glTexCoord3f(x - 7 * scal, y + 10 * scal, z + 58 * scal); glVertex3f(x - 7 * scal, y + 10 * scal, z + 58 * scal);//RH1	
	glEnd();
	
	glBegin(GL_POLYGON);//rey cruz H TECHO 1
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 7 * scal, y + 10 * scal, z + 61 * scal); glVertex3f(x - 7 * scal, y + 10 * scal, z + 61 * scal);//RH1
	glTexCoord3f(x - 7 * scal, y + 14.5*scal, z + 61 * scal); glVertex3f(x - 7 * scal, y + 14.5*scal, z + 61 * scal);//RH2
	glTexCoord3f(x - 17 * scal, y + 14.5*scal, z + 61 * scal); glVertex3f(x - 17 * scal, y + 14.5*scal, z + 61 * scal);//RH3
	glTexCoord3f(x - 17 * scal, y + 10 * scal, z + 61 * scal); glVertex3f(x - 17 * scal, y + 10 * scal, z + 61 * scal);//RH4
	glEnd();

	glBegin(GL_POLYGON);//rey cruz TECHO 
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 10 * scal, y + 10 * scal, z + 64 * scal); glVertex3f(x - 10 * scal, y + 10 * scal, z + 64 * scal);//1R1
	glTexCoord3f(x - 10 * scal, y + 14.5*scal, z + 64 * scal); glVertex3f(x - 10 * scal, y + 14.5*scal, z + 64 * scal);//2R2
	glTexCoord3f(x - 14.5*scal, y + 14.5*scal, z + 64 * scal); glVertex3f(x - 14.5*scal, y + 14.5*scal, z + 64 * scal);//3R3
	glTexCoord3f(x - 14.5*scal, y + 10 * scal, z + 64 * scal); glVertex3f(x - 14.5*scal, y + 10 * scal, z + 64 * scal);//4R4
	glEnd();
	glDisable(GL_TEXTURE_2D);
};

//Jhonatan
void Ajedrez::alfil(double x, double y, double z, double scal, int texture){

	glEnable(GL_TEXTURE_2D);
	texture == 0 ? glBindTexture(GL_TEXTURE_2D, ID_de_Textura1) : glBindTexture(GL_TEXTURE_2D, ID_de_Textura2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x, y, z); glVertex3f(x, y, z);						//A
	glTexCoord3f(x - 24 * scal, y, z); glVertex3f(x - 24 * scal, y, z);				//B
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z); glVertex3f(x - 24 * scal, y + 24 * scal, z);			//C
	glTexCoord3f(x, y + 24 * scal, z); glVertex3f(x, y + 24 * scal, z);				//D
	glEnd();

	//////////////////////BASE///////////////////////////////


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x, y, z);						 glVertex3f(x, y, z);						//A
	glTexCoord3f(x, y, z + 5 * scal);				 glVertex3f(x, y, z + 5 * scal);				//A1
	glTexCoord3f(x - 24 * scal, y, z + 5 * scal);	 glVertex3f(x - 24 * scal, y, z + 5 * scal);	//B1
	glTexCoord3f(x - 24 * scal, y, z);			 glVertex3f(x - 24 * scal, y, z);			//B
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 24 * scal, y, z);						 glVertex3f(x - 24 * scal, y, z);						//B
	glTexCoord3f(x - 24 * scal, y, z + 5 * scal);			 glVertex3f(x - 24 * scal, y, z + 5 * scal);				//B1
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z + 5 * scal); glVertex3f(x - 24 * scal, y + 24 * scal, z + 5 * scal);	//C1
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z);			 glVertex3f(x - 24 * scal, y + 24 * scal, z);			//C
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z);			 glVertex3f(x - 24 * scal, y + 24 * scal, z);			//C
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z + 5 * scal); glVertex3f(x - 24 * scal, y + 24 * scal, z + 5 * scal);	//C1
	glTexCoord3f(x, y + 24 * scal, z + 5 * scal);			 glVertex3f(x, y + 24 * scal, z + 5 * scal);				//D1
	glTexCoord3f(x, y + 24 * scal, z);						 glVertex3f(x, y + 24 * scal, z);						//D
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x, y, z);						 glVertex3f(x, y, z);						//A
	glTexCoord3f(x, y, z + 5 * scal);			 glVertex3f(x, y, z + 5 * scal);				//A1
	glTexCoord3f(x, y + 24 * scal, z + 5 * scal); glVertex3f(x, y + 24 * scal, z + 5 * scal);	//D1
	glTexCoord3f(x, y + 24 * scal, z);			 glVertex3f(x, y + 24 * scal, z);			//D
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x, y, z + 5 * scal);						 glVertex3f(x, y, z + 5 * scal);							//A1
	glTexCoord3f(x - 24 * scal, y, z + 5 * scal);			 glVertex3f(x - 24 * scal, y, z + 5 * scal);				//B1
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z + 5 * scal); glVertex3f(x - 24 * scal, y + 24 * scal, z + 5 * scal);	//C1
	glTexCoord3f(x, y + 24 * scal, z + 5 * scal);			 glVertex3f(x, y + 24 * scal, z + 5 * scal);				//D1
	glEnd();


	////////////////////////TRINCO///////////////////////////////

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 4 * scal, y + 4 * scal, z + 5 * scal);	 glVertex3f(x - 4 * scal, y + 4 * scal, z + 5 * scal);	//A2
	glTexCoord3f(x - 20 * scal, y + 4 * scal, z + 5 * scal);	 glVertex3f(x - 20 * scal, y + 4 * scal, z + 5 * scal);	//B2
	glTexCoord3f(x - 20 * scal, y + 20 * scal, z + 5 * scal); glVertex3f(x - 20 * scal, y + 20 * scal, z + 5 * scal);	//C2
	glTexCoord3f(x - 4 * scal, y + 20 * scal, z + 5 * scal);	 glVertex3f(x - 4 * scal, y + 20 * scal, z + 5 * scal);	//D2
	glEnd();


	///////laterales del tronco

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 4 * scal, y + 4 * scal, z + 5 * scal);	 glVertex3f(x - 4 * scal, y + 4 * scal, z + 5 * scal);	//A2
	glTexCoord3f(x - 20 * scal, y + 4 * scal, z + 5 * scal);	 glVertex3f(x - 20 * scal, y + 4 * scal, z + 5 * scal);	//B2
	glTexCoord3f(x - 18 * scal, y + 6 * scal, z + 40 * scal); glVertex3f(x - 18 * scal, y + 6 * scal, z + 40 * scal);	//B3
	glTexCoord3f(x - 6 * scal, y + 6 * scal, z + 40 * scal);	 glVertex3f(x - 6 * scal, y + 6 * scal, z + 40 * scal);	//A3
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 20 * scal, y + 4 * scal, z + 5 * scal);	  glVertex3f(x - 20 * scal, y + 4 * scal, z + 5 * scal);	  //B2
	glTexCoord3f(x - 20 * scal, y + 20 * scal, z + 5 * scal); glVertex3f(x - 20 * scal, y + 20 * scal, z + 5 * scal);	//C2
	glTexCoord3f(x - 18 * scal, y + 18 * scal, z + 40 * scal); glVertex3f(x - 18 * scal, y + 18 * scal, z + 40 * scal); //C3
	glTexCoord3f(x - 18 * scal, y + 6 * scal, z + 40 * scal);  glVertex3f(x - 18 * scal, y + 6 * scal, z + 40 * scal);  	//B3
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 20 * scal, y + 20 * scal, z + 5 * scal); glVertex3f(x - 20 * scal, y + 20 * scal, z + 5 * scal);	//C2
	glTexCoord3f(x - 4 * scal, y + 20 * scal, z + 5 * scal);  glVertex3f(x - 4 * scal, y + 20 * scal, z + 5 * scal);	//D2
	glTexCoord3f(x - 6 * scal, y + 18 * scal, z + 40 * scal); glVertex3f(x - 6 * scal, y + 18 * scal, z + 40 * scal);	//D3
	glTexCoord3f(x - 18 * scal, y + 18 * scal, z + 40 * scal); glVertex3f(x - 18 * scal, y + 18 * scal, z + 40 * scal);//C3
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 4 * scal, y + 4 * scal, z + 5 * scal);	 glVertex3f(x - 4 * scal, y + 4 * scal, z + 5 * scal);	//A2
	glTexCoord3f(x - 4 * scal, y + 20 * scal, z + 5 * scal);	 glVertex3f(x - 4 * scal, y + 20 * scal, z + 5 * scal);	//D2
	glTexCoord3f(x - 6 * scal, y + 18 * scal, z + 40 * scal); glVertex3f(x - 6 * scal, y + 18 * scal, z + 40 * scal);	//D3
	glTexCoord3f(x - 6 * scal, y + 6 * scal, z + 40 * scal);	 glVertex3f(x - 6 * scal, y + 6 * scal, z + 40 * scal);	//A3
	glEnd();

	///////////////////////////

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 6 * scal, y + 6 * scal, z + 40 * scal);	 glVertex3f(x - 6 * scal, y + 6 * scal, z + 40 * scal);	//A3
	glTexCoord3f(x - 18 * scal, y + 6 * scal, z + 40 * scal);	 glVertex3f(x - 18 * scal, y + 6 * scal, z + 40 * scal);	//B3
	glTexCoord3f(x - 18 * scal, y + 18 * scal, z + 40 * scal); glVertex3f(x - 18 * scal, y + 18 * scal, z + 40 * scal);//C3
	glTexCoord3f(x - 6 * scal, y + 18 * scal, z + 40 * scal);	 glVertex3f(x - 6 * scal, y + 18 * scal, z + 40 * scal);	//D3
	glEnd();

	//////////////////////////DIVISION///////////////////////////////////////


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 5.5 * scal, y + 5.5 * scal, z + 40 * scal);	 glVertex3f(x - 5.5 * scal, y + 5.5 * scal, z + 40 * scal);	//A4
	glTexCoord3f(x - 18.5 * scal, y + 5.5 * scal, z + 40 * scal);	 glVertex3f(x - 18.5 * scal, y + 5.5 * scal, z + 40 * scal);	//B4
	glTexCoord3f(x - 18.5 * scal, y + 18.5 * scal, z + 40 * scal); glVertex3f(x - 18.5 * scal, y + 18.5 * scal, z + 40 * scal);//C4
	glTexCoord3f(x - 5.5 * scal, y + 18.5 * scal, z + 40 * scal);	 glVertex3f(x - 5.5 * scal, y + 18.5 * scal, z + 40 * scal);	//D4
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 5.5 * scal, y + 5.5 * scal, z + 40 * scal);	 glVertex3f(x - 5.5 * scal, y + 5.5 * scal, z + 40 * scal);	//A4
	glTexCoord3f(x - 18.5 * scal, y + 5.5 * scal, z + 40 * scal); glVertex3f(x - 18.5 * scal, y + 5.5 * scal, z + 40 * scal);	//B4
	glTexCoord3f(x - 18.5 * scal, y + 5.5 * scal, z + 42 * scal); glVertex3f(x - 18.5 * scal, y + 5.5 * scal, z + 42 * scal);	//B5
	glTexCoord3f(x - 5.5 * scal, y + 5.5 * scal, z + 42 * scal);	 glVertex3f(x - 5.5 * scal, y + 5.5 * scal, z + 42 * scal);	//A5
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 18.5 * scal, y + 5.5 * scal, z + 40 * scal);  glVertex3f(x - 18.5 * scal, y + 5.5 * scal, z + 40 * scal); 	//B4
	glTexCoord3f(x - 18.5 * scal, y + 18.5 * scal, z + 40 * scal); glVertex3f(x - 18.5 * scal, y + 18.5 * scal, z + 40 * scal);//C4
	glTexCoord3f(x - 18.5 * scal, y + 18.5 * scal, z + 42 * scal); glVertex3f(x - 18.5 * scal, y + 18.5 * scal, z + 42 * scal);//C5
	glTexCoord3f(x - 18.5 * scal, y + 5.5 * scal, z + 42 * scal);  glVertex3f(x - 18.5 * scal, y + 5.5 * scal, z + 42 * scal); 	//B5
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 18.5 * scal, y + 18.5 * scal, z + 40 * scal); glVertex3f(x - 18.5 * scal, y + 18.5 * scal, z + 40 * scal);//C4
	glTexCoord3f(x - 5.5 * scal, y + 18.5 * scal, z + 40 * scal); glVertex3f(x - 5.5 * scal, y + 18.5 * scal, z + 40 * scal);	//D4
	glTexCoord3f(x - 5.5 * scal, y + 18.5 * scal, z + 42 * scal); glVertex3f(x - 5.5 * scal, y + 18.5 * scal, z + 42 * scal);	//D5
	glTexCoord3f(x - 18.5 * scal, y + 18.5 * scal, z + 42 * scal); glVertex3f(x - 18.5 * scal, y + 18.5 * scal, z + 42 * scal);//C5
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 5.5 * scal, y + 5.5 * scal, z + 42 * scal);  glVertex3f(x - 5.5 * scal, y + 5.5 * scal, z + 42 * scal);  //A5
	glTexCoord3f(x - 18.5 * scal, y + 5.5 * scal, z + 42 * scal); glVertex3f(x - 18.5 * scal, y + 5.5 * scal, z + 42 * scal); 	//B5
	glTexCoord3f(x - 18.5 * scal, y + 18.5 * scal, z + 42 * scal); glVertex3f(x - 18.5 * scal, y + 18.5 * scal, z + 42 * scal);//C5
	glTexCoord3f(x - 5.5 * scal, y + 18.5 * scal, z + 42 * scal); glVertex3f(x - 5.5 * scal, y + 18.5 * scal, z + 42 * scal); 	//D5
	glEnd();

	//////////////////////////CAEBZA///////////////////////////////////////

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 6 * scal, y + 6 * scal, z + 42 * scal);  glVertex3f(x - 6 * scal, y + 6 * scal, z + 42 * scal); 	//A7
	glTexCoord3f(x - 18 * scal, y + 6 * scal, z + 42 * scal);  glVertex3f(x - 18 * scal, y + 6 * scal, z + 42 * scal); 	//B7
	glTexCoord3f(x - 18 * scal, y + 18 * scal, z + 42 * scal); glVertex3f(x - 18 * scal, y + 18 * scal, z + 42 * scal);//C7
	glTexCoord3f(x - 6 * scal, y + 18 * scal, z + 42 * scal);  glVertex3f(x - 6 * scal, y + 18 * scal, z + 42 * scal); 	//D7
	glEnd();


	///////////////////////////

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 4 * scal, y + 4 * scal, z + 48 * scal);  glVertex3f(x - 4 * scal, y + 4 * scal, z + 48 * scal); 	//A6
	glTexCoord3f(x - 20 * scal, y + 4 * scal, z + 48 * scal); glVertex3f(x - 20 * scal, y + 4 * scal, z + 48 * scal);	//B6
	glTexCoord3f(x - 18 * scal, y + 6 * scal, z + 42 * scal); glVertex3f(x - 18 * scal, y + 6 * scal, z + 42 * scal);	//B7
	glTexCoord3f(x - 6 * scal, y + 6 * scal, z + 42 * scal);  glVertex3f(x - 6 * scal, y + 6 * scal, z + 42 * scal); 	//A7
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 20 * scal, y + 4 * scal, z + 48 * scal);  glVertex3f(x - 20 * scal, y + 4 * scal, z + 48 * scal); 	//B6
	glTexCoord3f(x - 20 * scal, y + 20 * scal, z + 48 * scal); glVertex3f(x - 20 * scal, y + 20 * scal, z + 48 * scal);//C6
	glTexCoord3f(x - 18 * scal, y + 18 * scal, z + 42 * scal); glVertex3f(x - 18 * scal, y + 18 * scal, z + 42 * scal);//C7
	glTexCoord3f(x - 18 * scal, y + 6 * scal, z + 42 * scal);  glVertex3f(x - 18 * scal, y + 6 * scal, z + 42 * scal); 	//B7
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 20 * scal, y + 20 * scal, z + 48 * scal); glVertex3f(x - 20 * scal, y + 20 * scal, z + 48 * scal);//C6
	glTexCoord3f(x - 4 * scal, y + 20 * scal, z + 48 * scal);  glVertex3f(x - 4 * scal, y + 20 * scal, z + 48 * scal); 	//D6
	glTexCoord3f(x - 6 * scal, y + 18 * scal, z + 42 * scal);  glVertex3f(x - 6 * scal, y + 18 * scal, z + 42 * scal); 	//D7
	glTexCoord3f(x - 18 * scal, y + 18 * scal, z + 42 * scal); glVertex3f(x - 18 * scal, y + 18 * scal, z + 42 * scal);//C7
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 4 * scal, y + 20 * scal, z + 48 * scal); glVertex3f(x - 4 * scal, y + 20 * scal, z + 48 * scal);	//D6
	glTexCoord3f(x - 4 * scal, y + 4 * scal, z + 48 * scal);  glVertex3f(x - 4 * scal, y + 4 * scal, z + 48 * scal); 	//A6
	glTexCoord3f(x - 6 * scal, y + 18 * scal, z + 42 * scal); glVertex3f(x - 6 * scal, y + 18 * scal, z + 42 * scal);	//D7
	glTexCoord3f(x - 6 * scal, y + 6 * scal, z + 42 * scal);  glVertex3f(x - 6 * scal, y + 6 * scal, z + 42 * scal); 	//A7
	glEnd();

	///////////////////////////

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 4 * scal, y + 4 * scal, z + 48 * scal);  glVertex3f(x - 4 * scal, y + 4 * scal, z + 48 * scal); 	//A6
	glTexCoord3f(x - 20 * scal, y + 4 * scal, z + 48 * scal);  glVertex3f(x - 20 * scal, y + 4 * scal, z + 48 * scal); 	//B6
	glTexCoord3f(x - 20 * scal, y + 20 * scal, z + 48 * scal); glVertex3f(x - 20 * scal, y + 20 * scal, z + 48 * scal);//C6
	glTexCoord3f(x - 4 * scal, y + 20 * scal, z + 48 * scal);  glVertex3f(x - 4 * scal, y + 20 * scal, z + 48 * scal); 	//D6
	glEnd();

	///////////////////////////

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 12 * scal, y + 6 * scal, z + 54 * scal); glVertex3f(x - 12 * scal, y + 6 * scal, z + 54 * scal);	//A8.1
	glTexCoord3f(x - 17 * scal, y + 6 * scal, z + 54 * scal); glVertex3f(x - 17 * scal, y + 6 * scal, z + 54 * scal);	//B8.1
	glTexCoord3f(x - 20 * scal, y + 4 * scal, z + 48 * scal); glVertex3f(x - 20 * scal, y + 4 * scal, z + 48 * scal);	//B6
	glTexCoord3f(x - 11 * scal, y + 6 * scal, z + 48 * scal); glVertex3f(x - 11 * scal, y + 6 * scal, z + 48 * scal);	//A8.1.1
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 20 * scal, y + 20 * scal, z + 48 * scal); glVertex3f(x - 20 * scal, y + 20 * scal, z + 48 * scal);//C6
	glTexCoord3f(x - 20 * scal, y + 4 * scal, z + 48 * scal);  glVertex3f(x - 20 * scal, y + 4 * scal, z + 48 * scal); 	//B6
	glTexCoord3f(x - 17 * scal, y + 6 * scal, z + 54 * scal);  glVertex3f(x - 17 * scal, y + 6 * scal, z + 54 * scal); 	//B8
	glTexCoord3f(x - 17 * scal, y + 20 * scal, z + 54 * scal); glVertex3f(x - 17 * scal, y + 20 * scal, z + 54 * scal);//C8
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 20 * scal, y + 20 * scal, z + 48 * scal); glVertex3f(x - 20 * scal, y + 20 * scal, z + 48 * scal);//C6
	glTexCoord3f(x - 15 * scal, y + 20 * scal, z + 48 * scal); glVertex3f(x - 15 * scal, y + 20 * scal, z + 48 * scal);//C8.1.1
	glTexCoord3f(x - 12 * scal, y + 20 * scal, z + 54 * scal); glVertex3f(x - 12 * scal, y + 20 * scal, z + 54 * scal);//D8.1
	glTexCoord3f(x - 17 * scal, y + 20 * scal, z + 54 * scal); glVertex3f(x - 17 * scal, y + 20 * scal, z + 54 * scal);//C8
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 11 * scal, y + 6 * scal, z + 48 * scal);  glVertex3f(x - 11 * scal, y + 6 * scal, z + 48 * scal); 	//A8.1.1
	glTexCoord3f(x - 15 * scal, y + 20 * scal, z + 48 * scal); glVertex3f(x - 15 * scal, y + 20 * scal, z + 48 * scal);//C8.1.1
	glTexCoord3f(x - 12 * scal, y + 20 * scal, z + 54 * scal); glVertex3f(x - 12 * scal, y + 20 * scal, z + 54 * scal);//D8.1
	glTexCoord3f(x - 12 * scal, y + 6 * scal, z + 54 * scal);  glVertex3f(x - 12 * scal, y + 6 * scal, z + 54 * scal); 	//A8.1
	glEnd();


	//----------------------------------------------------

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 10 * scal, y + 8 * scal, z + 54 * scal);  glVertex3f(x - 10 * scal, y + 8 * scal, z + 54 * scal); 	//B8.2
	glTexCoord3f(x - 11 * scal, y + 20 * scal, z + 48 * scal); glVertex3f(x - 11 * scal, y + 20 * scal, z + 48 * scal);//D8..1.1
	glTexCoord3f(x - 4 * scal, y + 20 * scal, z + 48 * scal);  glVertex3f(x - 4 * scal, y + 20 * scal, z + 48 * scal); 	//D6
	glTexCoord3f(x - 8 * scal, y + 17 * scal, z + 54 * scal);  glVertex3f(x - 8 * scal, y + 17 * scal, z + 54 * scal); 	//D8.2
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 4 * scal, y + 4 * scal, z + 48 * scal);  glVertex3f(x - 4 * scal, y + 4 * scal, z + 48 * scal); 	//A6
	glTexCoord3f(x - 4 * scal, y + 20 * scal, z + 48 * scal); glVertex3f(x - 4 * scal, y + 20 * scal, z + 48 * scal);	//D6
	glTexCoord3f(x - 8 * scal, y + 17 * scal, z + 54 * scal); glVertex3f(x - 8 * scal, y + 17 * scal, z + 54 * scal);	//D8.2
	glTexCoord3f(x - 8 * scal, y + 8 * scal, z + 54 * scal);  glVertex3f(x - 8 * scal, y + 8 * scal, z + 54 * scal); 	//A8.2
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 8 * scal, y + 8 * scal, z + 54 * scal);  glVertex3f(x - 8 * scal, y + 8 * scal, z + 54 * scal); 	//A8.2
	glTexCoord3f(x - 10 * scal, y + 8 * scal, z + 54 * scal); glVertex3f(x - 10 * scal, y + 8 * scal, z + 54 * scal);	//B8.2
	glTexCoord3f(x - 11 * scal, y + 6 * scal, z + 48 * scal); glVertex3f(x - 11 * scal, y + 6 * scal, z + 48 * scal);	//A8.1.1
	glTexCoord3f(x - 4 * scal, y + 4 * scal, z + 48 * scal);  glVertex3f(x - 4 * scal, y + 4 * scal, z + 48 * scal); 	//A6
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 15 * scal, y + 6 * scal, z + 48 * scal);  glVertex3f(x - 15 * scal, y + 6 * scal, z + 48 * scal); 	//B8.1.1
	glTexCoord3f(x - 15 * scal, y + 20 * scal, z + 48 * scal); glVertex3f(x - 15 * scal, y + 20 * scal, z + 48 * scal);//C8.1.1
	glTexCoord3f(x - 10 * scal, y + 17 * scal, z + 54 * scal); glVertex3f(x - 10 * scal, y + 17 * scal, z + 54 * scal);//C8.2
	glTexCoord3f(x - 10 * scal, y + 8 * scal, z + 54 * scal);  glVertex3f(x - 10 * scal, y + 8 * scal, z + 54 * scal); 	//B8.2
	glEnd();

	///////////////////////////
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 12 * scal, y + 6 * scal, z + 54 * scal);  glVertex3f(x - 12 * scal, y + 6 * scal, z + 54 * scal); 	//A8.1
	glTexCoord3f(x - 17 * scal, y + 6 * scal, z + 54 * scal);  glVertex3f(x - 17 * scal, y + 6 * scal, z + 54 * scal); 	//B8.1
	glTexCoord3f(x - 17 * scal, y + 20 * scal, z + 54 * scal); glVertex3f(x - 17 * scal, y + 20 * scal, z + 54 * scal);//C8.1
	glTexCoord3f(x - 12 * scal, y + 20 * scal, z + 54 * scal); glVertex3f(x - 12 * scal, y + 20 * scal, z + 54 * scal);//D8.1
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 8 * scal, y + 8 * scal, z + 54 * scal);  glVertex3f(x - 8 * scal, y + 8 * scal, z + 54 * scal); 	//A8.2
	glTexCoord3f(x - 10 * scal, y + 8 * scal, z + 54 * scal); glVertex3f(x - 10 * scal, y + 8 * scal, z + 54 * scal);	//B8.2
	glTexCoord3f(x - 10 * scal, y + 17 * scal, z + 54 * scal); glVertex3f(x - 10 * scal, y + 17 * scal, z + 54 * scal);//C8.2
	glTexCoord3f(x - 8 * scal, y + 17 * scal, z + 54 * scal);  glVertex3f(x - 8 * scal, y + 17 * scal, z + 54 * scal); 	//D8.2
	glEnd();
	glDisable(GL_TEXTURE_2D);

};

//Antonia
void Ajedrez::caballo(double x, double y, double z, double scal, int texture){
	glEnable(GL_TEXTURE_2D);
	texture == 0 ? glBindTexture(GL_TEXTURE_2D, ID_de_Textura1) : glBindTexture(GL_TEXTURE_2D, ID_de_Textura2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//base
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x, y, z); glVertex3f(x, y, z); //A
	glTexCoord3f(x, y + 24 * scal, z); glVertex3f(x, y + 24 * scal, z); //B
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z); glVertex3f(x - 24 * scal, y + 24 * scal, z); //C
	glTexCoord3f(x - 24 * scal, y, z); glVertex3f(x - 24 * scal, y, z); //D
	glEnd();

	//base top flat-0
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x, y, z + 2 * scal); glVertex3f(x, y, z + 2 * scal); //A1
	glTexCoord3f(x, y + 24 * scal, z + 2 * scal); glVertex3f(x, y + 24 * scal, z + 2 * scal); //B1
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); glVertex3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); //C1
	glTexCoord3f(x - 24 * scal, y, z + 2 * scal); glVertex3f(x - 24 * scal, y, z + 2 * scal); //D1
	glEnd();

	//covers flat-0
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x, y, z); glVertex3f(x, y, z); //A
	glTexCoord3f(x, y, z + 2 * scal); glVertex3f(x, y, z + 2 * scal); //A1
	glTexCoord3f(x - 24 * scal, y, z + 2 * scal); glVertex3f(x - 24 * scal, y, z + 2 * scal); //D1
	glTexCoord3f(x - 24 * scal, y, z); glVertex3f(x - 24 * scal, y, z); //D
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x, y, z); glVertex3f(x, y, z); //A
	glTexCoord3f(x, y, z + 2 * scal); glVertex3f(x, y, z + 2 * scal); //A1
	glTexCoord3f(x, y + 24 * scal, z + 2 * scal); glVertex3f(x, y + 24 * scal, z + 2 * scal); //B1
	glTexCoord3f(x, y + 24 * scal, z); glVertex3f(x, y + 24 * scal, z); //B
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x, y + 24 * scal, z); glVertex3f(x, y + 24 * scal, z); //B
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z); glVertex3f(x - 24 * scal, y + 24 * scal, z); //C
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); glVertex3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); //C1
	glTexCoord3f(x, y + 24 * scal, z + 2 * scal); glVertex3f(x, y + 24 * scal, z + 2 * scal); //B1
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z); glVertex3f(x - 24 * scal, y + 24 * scal, z); //C
	glTexCoord3f(x - 24 * scal, y, z); glVertex3f(x - 24 * scal, y, z); //D
	glTexCoord3f(x - 24 * scal, y, z + 2 * scal); glVertex3f(x - 24 * scal, y, z + 2 * scal); //D1
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); glVertex3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); //C1
	glEnd();

	//covers flat-1
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x, y, z + 2 * scal); glVertex3f(x, y, z + 2 * scal); //A1
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); //E
	glTexCoord3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); glVertex3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); //H
	glTexCoord3f(x - 24 * scal, y, z + 2 * scal); glVertex3f(x - 24 * scal, y, z + 2 * scal); //D1
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x, y, z + 2 * scal); glVertex3f(x, y, z + 2 * scal); //A1
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); //E
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); //F
	glTexCoord3f(x, y + 24 * scal, z + 2 * scal); glVertex3f(x, y + 24 * scal, z + 2 * scal); //B1
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x, y + 24 * scal, z + 2 * scal); glVertex3f(x, y + 24 * scal, z + 2 * scal); //B1
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); //F
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); //G
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); glVertex3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); //C1
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 24 * scal, y, z + 2 * scal); glVertex3f(x - 24 * scal, y, z + 2 * scal); //D1
	glTexCoord3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); glVertex3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); //H
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); //G
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); glVertex3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); //C1
	glEnd();

	//base top flat-1
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); //E
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); //F
	glTexCoord3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); glVertex3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); //G
	glTexCoord3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); glVertex3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); //H
	glEnd();

	//caballo 
	/*glBegin(GL_LINE_STRIP);
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(x - 4 * scal, y + 2 * scal, z + 12 * scal); //AC
	glVertex3f(x - 2 * scal, y + 2 * scal, z + 22 * scal); //BC
	glVertex3f(x-2 * scal, y + 2 * scal, z + 25 * scal); //CC
	glVertex3f(x - 11 * scal , y + 4 * scal, z + 35 * scal); //DC
	glVertex3f(x - 2.5 * scal, y + 4 * scal, z + 30 * scal); //EC
	glVertex3f(x - 2 * scal, y + 4 * scal, z + 36 * scal); //FC
	glVertex3f(x - 11 * scal, y + 6 * scal, z + 45 * scal); //GC
	glVertex3f(x - 22 * scal, y + 6 * scal, z + 42 * scal); //HC
	glVertex3f(x - 24 * scal, y + 4 * scal, z + 35 * scal); //IC
	glVertex3f(x - 20 * scal, y + 2 * scal, z + 12 * scal); //JC
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(x - 4 * scal, y + 22 * scal, z + 12 * scal); //ACB
	glVertex3f(x - 2 * scal, y + 22 * scal, z + 22 * scal); //BCB
	glVertex3f(x - 2 * scal, y + 22 * scal, z + 25 * scal); //CCB
	glVertex3f(x - 11 * scal, y + 20 * scal, z + 35 * scal); //DCB
	glVertex3f(x - 2.5 * scal, y + 20 * scal, z + 30 * scal); //ECB
	glVertex3f(x - 2 * scal, y + 20 * scal, z + 36 * scal); //FCB
	glVertex3f(x - 11 * scal, y + 18 * scal, z + 45 * scal); //GCB
	glVertex3f(x - 22 * scal, y + 18 * scal, z + 42 * scal); //HCB
	glVertex3f(x - 24 * scal, y + 20 * scal, z + 35 * scal); //ICB
	glVertex3f(x - 20 * scal, y + 22 * scal, z + 12 * scal); //JCB
	glEnd();
	*/
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 4 * scal, y + 2 * scal, z + 12 * scal); glVertex3f(x - 4 * scal, y + 2 * scal, z + 12 * scal); //AC
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 22 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 22 * scal); //BC
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 22 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 22 * scal); //BCB
	glTexCoord3f(x - 4 * scal, y + 22 * scal, z + 12 * scal); glVertex3f(x - 4 * scal, y + 22 * scal, z + 12 * scal); //ACB
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 22 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 22 * scal); //BC
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 25 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 25 * scal); //CC
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 25 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 25 * scal); //CCB
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 22 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 22 * scal); //BCB
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 25 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 25 * scal); //CC
	glTexCoord3f(x - 11 * scal, y + 4 * scal, z + 35 * scal); glVertex3f(x - 11 * scal, y + 4 * scal, z + 35 * scal); //DC
	glTexCoord3f(x - 11 * scal, y + 20 * scal, z + 35 * scal); glVertex3f(x - 11 * scal, y + 20 * scal, z + 35 * scal); //DCB
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 25 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 25 * scal); //CCB
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 11 * scal, y + 4 * scal, z + 35 * scal); glVertex3f(x - 11 * scal, y + 4 * scal, z + 35 * scal); //DC
	glTexCoord3f(x - 2.5 * scal, y + 4 * scal, z + 30 * scal); glVertex3f(x - 2.5 * scal, y + 4 * scal, z + 30 * scal); //EC
	glTexCoord3f(x - 2.5 * scal, y + 20 * scal, z + 30 * scal); glVertex3f(x - 2.5 * scal, y + 20 * scal, z + 30 * scal); //ECB
	glTexCoord3f(x - 11 * scal, y + 20 * scal, z + 35 * scal); glVertex3f(x - 11 * scal, y + 20 * scal, z + 35 * scal); //DCB
    glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 2.5 * scal, y + 4 * scal, z + 30 * scal); glVertex3f(x - 2.5 * scal, y + 4 * scal, z + 30 * scal); //EC
	glTexCoord3f(x - 2 * scal, y + 4 * scal, z + 36 * scal); glVertex3f(x - 2 * scal, y + 4 * scal, z + 36 * scal); //FC
	glTexCoord3f(x - 2 * scal, y + 20 * scal, z + 36 * scal); glVertex3f(x - 2 * scal, y + 20 * scal, z + 36 * scal); //FCB
	glTexCoord3f(x - 2.5 * scal, y + 20 * scal, z + 30 * scal); glVertex3f(x - 2.5 * scal, y + 20 * scal, z + 30 * scal); //ECB
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 2 * scal, y + 4 * scal, z + 36 * scal); glVertex3f(x - 2 * scal, y + 4 * scal, z + 36 * scal); //FC
	glTexCoord3f(x - 11 * scal, y + 6 * scal, z + 45 * scal); glVertex3f(x - 11 * scal, y + 6 * scal, z + 45 * scal); //GC
	glTexCoord3f(x - 11 * scal, y + 18 * scal, z + 45 * scal); glVertex3f(x - 11 * scal, y + 18 * scal, z + 45 * scal); //GCB
	glTexCoord3f(x - 2 * scal, y + 20 * scal, z + 36 * scal); glVertex3f(x - 2 * scal, y + 20 * scal, z + 36 * scal); //FCB
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x - 11 * scal, y + 6 * scal, z + 45 * scal); glVertex3f(x - 11 * scal, y + 6 * scal, z + 45 * scal); //GC
	glTexCoord3f(x - 22 * scal, y + 6 * scal, z + 42 * scal); glVertex3f(x - 22 * scal, y + 6 * scal, z + 42 * scal); //HC
	glTexCoord3f(x - 22 * scal, y + 18 * scal, z + 42 * scal); glVertex3f(x - 22 * scal, y + 18 * scal, z + 42 * scal); //HCB
	glTexCoord3f(x - 11 * scal, y + 18 * scal, z + 45 * scal); glVertex3f(x - 11 * scal, y + 18 * scal, z + 45 * scal); //GCB
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 22 * scal, y + 6 * scal, z + 42 * scal); glVertex3f(x - 22 * scal, y + 6 * scal, z + 42 * scal); //HC
	glTexCoord3f(x - 24 * scal, y + 4 * scal, z + 35 * scal); glVertex3f(x - 24 * scal, y + 4 * scal, z + 35 * scal); //IC
	glTexCoord3f(x - 20 * scal, y + 2 * scal, z + 12 * scal); glVertex3f(x - 20 * scal, y + 2 * scal, z + 12 * scal); //JC
	glTexCoord3f(x - 20 * scal, y + 22 * scal, z + 12 * scal); glVertex3f(x - 20 * scal, y + 22 * scal, z + 12 * scal); //JCB
	glTexCoord3f(x - 24 * scal, y + 20 * scal, z + 35 * scal); glVertex3f(x - 24 * scal, y + 20 * scal, z + 35 * scal); //ICB
	glTexCoord3f(x - 22 * scal, y + 18 * scal, z + 42 * scal); glVertex3f(x - 22 * scal, y + 18 * scal, z + 42 * scal); //HCB
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 4 * scal, y + 2 * scal, z + 12 * scal); glVertex3f(x - 4 * scal, y + 2 * scal, z + 12 * scal); //AC
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 22 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 22 * scal); //BC
	glTexCoord3f(x - 2 * scal, y + 2 * scal, z + 25 * scal); glVertex3f(x - 2 * scal, y + 2 * scal, z + 25 * scal); //CC
	glTexCoord3f(x - 11 * scal, y + 4 * scal, z + 35 * scal); glVertex3f(x - 11 * scal, y + 4 * scal, z + 35 * scal); //DC
	glTexCoord3f(x - 24 * scal, y + 4 * scal, z + 35 * scal); glVertex3f(x - 24 * scal, y + 4 * scal, z + 35 * scal); //IC
	glTexCoord3f(x - 20 * scal, y + 2 * scal, z + 12 * scal); glVertex3f(x - 20 * scal, y + 2 * scal, z + 12 * scal); //JC
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 4 * scal, y + 22 * scal, z + 12 * scal); glVertex3f(x - 4 * scal, y + 22 * scal, z + 12 * scal); //ACB
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 22 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 22 * scal); //BCB
	glTexCoord3f(x - 2 * scal, y + 22 * scal, z + 25 * scal); glVertex3f(x - 2 * scal, y + 22 * scal, z + 25 * scal); //CCB
	glTexCoord3f(x - 11 * scal, y + 20 * scal, z + 35 * scal); glVertex3f(x - 11 * scal, y + 20 * scal, z + 35 * scal); //DCB
	glTexCoord3f(x - 24 * scal, y + 20 * scal, z + 35 * scal); glVertex3f(x - 24 * scal, y + 20 * scal, z + 35 * scal); //ICB
	glTexCoord3f(x - 20 * scal, y + 22 * scal, z + 12 * scal); glVertex3f(x - 20 * scal, y + 22 * scal, z + 12 * scal); //JCB
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 11 * scal, y + 4 * scal, z + 35 * scal); glVertex3f(x - 11 * scal, y + 4 * scal, z + 35 * scal); //DC
	glTexCoord3f(x - 2.5 * scal, y + 4 * scal, z + 30 * scal); glVertex3f(x - 2.5 * scal, y + 4 * scal, z + 30 * scal); //EC
	glTexCoord3f(x - 2 * scal, y + 4 * scal, z + 36 * scal); glVertex3f(x - 2 * scal, y + 4 * scal, z + 36 * scal); //FC
	glTexCoord3f(x - 11 * scal, y + 6 * scal, z + 45 * scal); glVertex3f(x - 11 * scal, y + 6 * scal, z + 45 * scal); //GC
	glTexCoord3f(x - 22 * scal, y + 6 * scal, z + 42 * scal); glVertex3f(x - 22 * scal, y + 6 * scal, z + 42 * scal); //HC
	glTexCoord3f(x - 24 * scal, y + 4 * scal, z + 35 * scal); glVertex3f(x - 24 * scal, y + 4 * scal, z + 35 * scal); //IC
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 11 * scal, y + 20 * scal, z + 35 * scal); glVertex3f(x - 11 * scal, y + 20 * scal, z + 35 * scal); //DCB
	glTexCoord3f(x - 2.5 * scal, y + 20 * scal, z + 30 * scal); glVertex3f(x - 2.5 * scal, y + 20 * scal, z + 30 * scal); //ECB
	glTexCoord3f(x - 2 * scal, y + 20 * scal, z + 36 * scal); glVertex3f(x - 2 * scal, y + 20 * scal, z + 36 * scal); //FCB
	glTexCoord3f(x - 11 * scal, y + 18 * scal, z + 45 * scal); glVertex3f(x - 11 * scal, y + 18 * scal, z + 45 * scal); //GCB
	glTexCoord3f(x - 22 * scal, y + 18 * scal, z + 42 * scal); glVertex3f(x - 22 * scal, y + 18 * scal, z + 42 * scal); //HCB
	glTexCoord3f(x - 24 * scal, y + 20 * scal, z + 35 * scal); glVertex3f(x - 24 * scal, y + 20 * scal, z + 35 * scal); //ICB
	glEnd();

	glDisable(GL_TEXTURE_2D);

};

//render textures
void Ajedrez::initrender(){
	initRendering();
}

//board
void cuadrado(double x, double y, double z, double scal, int texture){
	glEnable(GL_TEXTURE_2D);
	texture == 0 ? glBindTexture(GL_TEXTURE_2D, ID_de_Textura1) : glBindTexture(GL_TEXTURE_2D, ID_de_Textura2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 0.6);
	glTexCoord3f(x, y, z); glVertex3f(x, y, z); //A
	glTexCoord3f(x, y + 24 * scal, z); glVertex3f(x, y + 24 * scal, z); //B
	glTexCoord3f(x - 24 * scal, y + 24 * scal, z); glVertex3f(x - 24 * scal, y + 24 * scal, z); //C
	glTexCoord3f(x - 24 * scal, y, z); glVertex3f(x - 24 * scal, y, z); //D
	glEnd();
	glDisable(GL_TEXTURE_2D);


}

double vag, vzg;

void bucle(double x, double y, double z,double va,double vz, int nv, double r, double g, double v){
	
	for (int i = 0; i < nv; i++)
	{
		glBegin(GL_LINE_STRIP);
		glColor3f(r, g, v);
		glTexCoord3f(x - va, y + va, z - vz); glVertex3f(x - va, y + va, z - vz); // A
		glTexCoord3f(x + va, y + va, z - vz); glVertex3f(x + va, y + va, z - vz); // B
		glTexCoord3f(x + va, y - va, z - vz); glVertex3f(x + va, y - va, z - vz); // C
		glTexCoord3f(x - va, y - va, z - vz); glVertex3f(x - va, y - va, z - vz); // D
		glTexCoord3f(x - va, y + va, z - vz); glVertex3f(x - va, y + va, z - vz); // A
		glEnd();

		va += 0.001;
		vz += 0.001;
	}
	vag = va;
	vzg = vz;
}


void borde(double x, double y, double z, double scal, int texture){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ID_de_Textura1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glTexCoord3f(x - 103 * scal, y + 103 * scal, z - 2 * scal); glVertex3f(x - 103 * scal, y + 103 * scal, z - 2 * scal); // A
	glTexCoord3f(x + 103 * scal, y + 103 * scal, z - 2 * scal); glVertex3f(x + 103 * scal, y + 103 * scal, z - 2 * scal); // B
	glTexCoord3f(x + 103 * scal, y - 103 * scal, z - 2 * scal); glVertex3f(x + 103 * scal, y - 103 * scal, z - 2 * scal); // C
	glTexCoord3f(x - 103 * scal, y - 103 * scal, z - 2 * scal); glVertex3f(x - 103 * scal, y - 103 * scal, z - 2 * scal); // D
	glTexCoord3f(x - 103 * scal, y + 103 * scal, z - 2 * scal); glVertex3f(x - 103 * scal, y + 103 * scal, z - 2 * scal); // A
	glEnd();
	glDisable(GL_TEXTURE_2D);


	double va = 103 * scal, vz = 2 * scal;

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ID_de_Textura2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	bucle(x, y, z, va, vz, 7, 0.7, 0.7, 0.7);
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ID_de_Textura2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    bucle(x, y, z, vag, vzg, 20, 1.0, 0.7, 0.7);
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ID_de_Textura2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	bucle(x, y, z, vag, vzg, 7, 0.7, 0.7, 0.7);
	glDisable(GL_TEXTURE_2D);


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ID_de_Textura1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	bucle(x, y, z, vag, vzg, 30, 0.7, 0.7, 0.7);
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ID_de_Textura2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	for (int i = 0; i < 20; i++)
	{
		glBegin(GL_LINE_STRIP);
		glColor3f(1.0, 0.7, 0.7);
		glTexCoord3f(x - vag, y + (vag - (60 * scal)), z - vzg); glVertex3f(x - vag, y + (vag - (60 * scal)), z - vzg); // D
		glTexCoord3f(x - vag, y + vag, z - vzg); glVertex3f(x - vag, y + vag, z - vzg); // A
		glTexCoord3f(x - (vag - (60 * scal)), y + vag, z - vzg); glVertex3f(x - (vag - (60 * scal)), y + vag, z - vzg); // A
		glEnd();

		glBegin(GL_LINE_STRIP);
		glColor3f(1.0, 0.7, 0.7);
		glTexCoord3f(x + (vag - (60 * scal)), y + vag, z - vzg); glVertex3f(x + (vag - (60 * scal)), y + vag, z - vzg); // A
		glTexCoord3f(x + vag, y + vag, z - vzg); glVertex3f(x + vag, y + vag, z - vzg); // B
		glTexCoord3f(x + vag, y + (vag - (60 * scal)), z - vzg); glVertex3f(x + vag, y + (vag - (60 * scal)), z - vzg); // D
		glEnd();

		glBegin(GL_LINE_STRIP);
		glColor3f(1.0, 0.7, 0.7);
		glTexCoord3f(x + (vag - (60 * scal)), y - vag, z - vzg); glVertex3f(x + (vag - (60 * scal)), y - vag, z - vzg); // A
		glTexCoord3f(x + vag, y - vag, z - vzg); glVertex3f(x + vag, y - vag, z - vzg); // C
		glTexCoord3f(x + vag, y - (vag - (60 * scal)), z - vzg); glVertex3f(x + vag, y - (vag - (60 * scal)), z - vzg); // D
		glEnd();

		glBegin(GL_LINE_STRIP);
		glColor3f(1.0, 0.7, 0.7);
		glTexCoord3f(x - (vag - (60 * scal)), y - vag, z - vzg); glVertex3f(x - (vag - (60 * scal)), y - vag, z - vzg); // A
		glTexCoord3f(x - vag, y - vag, z - vzg); glVertex3f(x - vag, y - vag, z - vzg); // D
		glTexCoord3f(x - vag, y - (vag - (60 * scal)), z - vzg); glVertex3f(x - vag, y - (vag - (60 * scal)), z - vzg); // D
		glEnd();

		vag += 0.001;
		vzg += 0.001;
	}

	glDisable(GL_TEXTURE_2D);


}
