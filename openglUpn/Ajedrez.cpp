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
	
	//base
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(x, y, z); //A
	glVertex3f(x, y + 24 * scal, z); //B
	glVertex3f(x - 24 * scal, y + 24 * scal, z); //C
	glVertex3f(x - 24 * scal, y , z); //D
	glEnd();

	//base top flat-0
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(x, y, z+2*scal); //A1
	glVertex3f(x, y + 24 * scal, z + 2 * scal); //B1
	glVertex3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); //C1
	glVertex3f(x - 24 * scal, y, z + 2 * scal); //D1
	glEnd();

	//covers flat-0
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.3, 0.3);
	glVertex3f(x, y, z); //A
	glVertex3f(x, y, z + 2 * scal); //A1
	glVertex3f(x - 24 * scal, y, z + 2 * scal); //D1
	glVertex3f(x - 24 * scal, y, z); //D
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.3, 0.3);
	glVertex3f(x, y, z); //A
	glVertex3f(x, y, z + 2 * scal); //A1
	glVertex3f(x, y + 24 * scal, z + 2 * scal); //B1
	glVertex3f(x, y + 24 * scal, z); //B
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.3, 0.3);
	glVertex3f(x, y + 24 * scal, z); //B
	glVertex3f(x - 24 * scal, y + 24 * scal, z); //C
	glVertex3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); //C1
	glVertex3f(x, y + 24 * scal, z + 2 * scal); //B1
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.3, 0.3);
	glVertex3f(x - 24 * scal, y + 24 * scal, z); //C
	glVertex3f(x - 24 * scal, y, z); //D
	glVertex3f(x - 24 * scal, y, z + 2 * scal); //D1
	glVertex3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); //C1
	glEnd();

	//covers flat-1
	glBegin(GL_POLYGON);
	glColor3f(0.3, 1.0, 0.3);
	glVertex3f(x, y, z + 2 * scal); //A1
	glVertex3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); //E
	glVertex3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); //H
	glVertex3f(x - 24 * scal, y, z + 2 * scal); //D1
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.3, 1.0, 0.3);
	glVertex3f(x, y, z + 2 * scal); //A1
	glVertex3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); //E
	glVertex3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); //F
	glVertex3f(x, y + 24 * scal, z + 2 * scal); //B1
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 1.0, 0.3);
	glVertex3f(x, y + 24 * scal, z + 2 * scal); //B1
	glVertex3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); //F
	glVertex3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); //G
	glVertex3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); //C1
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 1.0, 0.3);
	glVertex3f(x - 24 * scal, y, z + 2 * scal); //D1
	glVertex3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); //H
	glVertex3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); //G
	glVertex3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); //C1
	glEnd();

	//base top flat-1
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); //E
	glVertex3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); //F
	glVertex3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); //G
	glVertex3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); //H
	glEnd();

	//base top flat-2
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 3 * scal, y + 3 * scal, z + 42 * scal); //I
	glVertex3f(x - 3 * scal, y + 21 * scal, z + 42 * scal); //J
	glVertex3f(x - 21 * scal, y + 21 * scal, z + 42 * scal); //K
	glVertex3f(x - 21 * scal, y + 3 * scal, z + 42 * scal); //L
	glEnd();
	
	//covers flat-2
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); //E
	glVertex3f(x - 3 * scal, y + 3 * scal, z + 42 * scal); //I
	glVertex3f(x - 21 * scal, y + 3 * scal, z + 42 * scal); //L
	glVertex3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); //H
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); //E
	glVertex3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); //F
	glVertex3f(x - 3 * scal, y + 21 * scal, z + 42 * scal); //J
	glVertex3f(x - 3 * scal, y + 3 * scal, z + 42* scal); //I
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); //F
	glVertex3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); //G
	glVertex3f(x - 21 * scal, y + 21 * scal, z + 42 * scal); //K
	glVertex3f(x - 3 * scal, y + 21 * scal, z + 42 * scal); //J
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); //G
	glVertex3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); //H
	glVertex3f(x - 21 * scal, y + 3 * scal, z + 42 * scal); //L
	glVertex3f(x - 21 * scal, y + 21 * scal, z + 42 * scal); //K
	glEnd();
	
	//
	//base top flat-3
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.3, 0.3);
	glVertex3f(x - 2 * scal, y + 2 * scal, z + 45 * scal); //I1
	glVertex3f(x - 2 * scal, y + 22 * scal, z + 45 * scal); //J1
	glVertex3f(x - 22 * scal, y + 22 * scal, z + 45 * scal); //K1
	glVertex3f(x - 22 * scal, y + 2 * scal, z + 45 * scal); //L1
	glEnd();
	
	//covers flat-3
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.3, 0.3);
	glVertex3f(x - 3 * scal, y + 3 * scal, z + 42 * scal); //I
	glVertex3f(x - 21 * scal, y + 3 * scal, z + 42 * scal); //L
	glVertex3f(x - 22 * scal, y + 2 * scal, z + 45 * scal); //L1
	glVertex3f(x - 2 * scal, y + 2 * scal, z + 45 * scal); //I1
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.3, 0.3);
	glVertex3f(x - 3 * scal, y + 3 * scal, z + 42 * scal); //I
	glVertex3f(x - 3 * scal, y + 21 * scal, z + 42 * scal); //J
	glVertex3f(x - 2 * scal, y + 22 * scal, z + 45 * scal); //J1
	glVertex3f(x - 2 * scal, y + 2 * scal, z + 45 * scal); //I1
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.3, 0.3);
	glVertex3f(x - 3 * scal, y + 21 * scal, z + 42 * scal); //J
	glVertex3f(x - 21 * scal, y + 21 * scal, z + 42 * scal); //K
	glVertex3f(x - 22 * scal, y + 22 * scal, z + 45 * scal); //K1
	glVertex3f(x - 22 * scal, y + 2 * scal, z + 45 * scal); //L1
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.3, 0.3);
	glVertex3f(x - 21 * scal, y + 21 * scal, z + 42 * scal); //K
	glVertex3f(x - 21 * scal, y + 3 * scal, z + 42 * scal); //L
	glVertex3f(x - 22 * scal, y + 2 * scal, z + 45 * scal); //L1
	glVertex3f(x - 22 * scal, y + 22 * scal, z + 45 * scal); //K1
	glEnd();

	//covers flat-4
	glBegin(GL_POLYGON);
	glColor3f(0.3, 1.0, 0.3);
	glVertex3f(x - 2 * scal, y + 2 * scal, z + 45 * scal); //I1
	glVertex3f(x - 22 * scal, y + 2 * scal, z + 45 * scal); //L1
	glVertex3f(x - 22 * scal, y + 2 * scal, z + 50 * scal); //P
	glVertex3f(x - 2 * scal, y + 2 * scal, z + 50 * scal); //M
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 1.0, 0.3);
	glVertex3f(x - 2 * scal, y + 2 * scal, z + 45 * scal); //I1
	glVertex3f(x - 2 * scal, y + 22 * scal, z + 45 * scal); //J1
	glVertex3f(x - 2 * scal, y + 22 * scal, z + 50 * scal); //N
	glVertex3f(x - 2 * scal, y + 2 * scal, z + 50 * scal); //M
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 1.0, 0.3);
	glVertex3f(x - 2 * scal, y + 22 * scal, z + 45 * scal); //J1
	glVertex3f(x - 22 * scal, y + 22 * scal, z + 45 * scal); //K1
	glVertex3f(x - 22 * scal, y + 22 * scal, z + 50 * scal); //O
	glVertex3f(x - 2 * scal, y + 22 * scal, z + 50 * scal); //N
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 1.0, 0.3);
	glVertex3f(x - 22 * scal, y + 22 * scal, z + 45 * scal); //K1
	glVertex3f(x - 22 * scal, y + 2 * scal, z + 45 * scal); //L1
	glVertex3f(x - 22 * scal, y + 2 * scal, z + 50 * scal); //P
	glVertex3f(x - 22 * scal, y + 22 * scal, z + 50 * scal); //O
	glEnd();

	//covers flat-4 under
	glBegin(GL_POLYGON);
	glColor3f(0.3, 1.0, 0.3);
	glVertex3f(x - 6 * scal, y + 6 * scal, z + 45 * scal); //M1-
	glVertex3f(x - 18 * scal, y + 6 * scal, z + 45 * scal); //P1-
	glVertex3f(x - 18 * scal, y + 6 * scal, z + 50 * scal); //P1
	glVertex3f(x - 6 * scal, y + 6 * scal, z + 50 * scal); //M1
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 1.0, 0.3);
	glVertex3f(x - 6 * scal, y + 6 * scal, z + 45 * scal); //M1-
	glVertex3f(x - 6 * scal, y + 18 * scal, z + 45 * scal); //N1-
	glVertex3f(x - 6 * scal, y + 18 * scal, z + 50 * scal); //N1
	glVertex3f(x - 6 * scal, y + 6 * scal, z + 50 * scal); //M1
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 1.0, 0.3);
	glVertex3f(x - 6 * scal, y + 18 * scal, z + 50 * scal); //N1
	glVertex3f(x - 18 * scal, y + 18 * scal, z + 50 * scal); //O1
	glVertex3f(x - 18 * scal, y + 18 * scal, z + 45 * scal); //O1-
	glVertex3f(x - 6 * scal, y + 18 * scal, z + 45 * scal); //N1-
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 1.0, 0.3);
	glVertex3f(x - 18 * scal, y + 18 * scal, z + 50 * scal); //O1
	glVertex3f(x - 18 * scal, y + 6 * scal, z + 50 * scal); //P1
	glVertex3f(x - 18 * scal, y + 6 * scal, z + 45 * scal); //P1-
	glVertex3f(x - 18 * scal, y + 18 * scal, z + 45 * scal); //O1-
	glEnd();

	//base top flat-4
	glBegin(GL_POLYGON);
	glColor3f(0.3, 1.0, 0.3);
	glVertex3f(x - 2 * scal, y + 2 * scal, z + 50 * scal); //M
	glVertex3f(x - 22 * scal, y + 2 * scal, z + 50 * scal); //P
	glVertex3f(x - 18 * scal, y + 6 * scal, z + 50 * scal); //P1
	glVertex3f(x - 6 * scal, y + 6 * scal, z + 50 * scal); //M1
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 1.0, 0.3);
	glVertex3f(x - 2 * scal, y + 2 * scal, z + 50 * scal); //M
	glVertex3f(x - 2 * scal, y + 22 * scal, z + 50 * scal); //N
	glVertex3f(x - 6 * scal, y + 18 * scal, z + 50 * scal); //N1
	glVertex3f(x - 6 * scal, y + 6 * scal, z + 50 * scal); //M1
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 1.0, 0.3);
	glVertex3f(x - 2 * scal, y + 22 * scal, z + 50 * scal); //N
	glVertex3f(x - 22 * scal, y + 22 * scal, z + 50 * scal); //O
	glVertex3f(x - 18 * scal, y + 18 * scal, z + 50 * scal); //O1
	glVertex3f(x - 6 * scal, y + 18 * scal, z + 50 * scal); //N1
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 1.0, 0.3);
	glVertex3f(x - 22 * scal, y + 22 * scal, z + 50 * scal); //O
	glVertex3f(x - 22 * scal, y + 2 * scal, z + 50 * scal); //P
	glVertex3f(x - 18 * scal, y + 6 * scal, z + 50 * scal); //P1
	glVertex3f(x - 18 * scal, y + 18 * scal, z + 50 * scal); //O1
	glEnd();

	//base top flat-5
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 2 * scal, y + 2 * scal, z + 55 * scal); //MT
	glVertex3f(x - 2 * scal, y + 10 * scal, z + 55 * scal); //MTS
	glVertex3f(x - 6 * scal, y + 10 * scal, z + 55 * scal); //M1TS
	glVertex3f(x - 6 * scal, y + 6 * scal, z + 55 * scal); //M1T
	glVertex3f(x - 10 * scal, y + 6 * scal, z + 55 * scal); //M1TI
	glVertex3f(x - 10 * scal, y + 2 * scal, z + 55 * scal); //MTI
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 2 * scal, y + 22 * scal, z + 55 * scal); //NT
	glVertex3f(x - 10 * scal, y + 22 * scal, z + 55 * scal); //NTI
	glVertex3f(x - 10 * scal, y + 18 * scal, z + 55 * scal); //N1TI
	glVertex3f(x - 6 * scal, y + 18 * scal, z + 55 * scal); //N1T
	glVertex3f(x - 6 * scal, y + 14 * scal, z + 55 * scal); //N1TA
	glVertex3f(x - 2 * scal, y + 14 * scal, z + 55 * scal); //NTA
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 22 * scal, y + 22 * scal, z + 55 * scal); //OT
	glVertex3f(x - 14 * scal, y + 22 * scal, z + 55 * scal); //OTD
	glVertex3f(x - 14 * scal, y + 18 * scal, z + 55 * scal); //O1TD
	glVertex3f(x - 18 * scal, y + 18 * scal, z + 55 * scal); //O1T
	glVertex3f(x - 18 * scal, y + 14 * scal, z + 55 * scal); //O1TS
	glVertex3f(x - 22 * scal, y + 14 * scal, z + 55 * scal); //OTS
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 22 * scal, y + 2 * scal, z + 55 * scal); //PT
	glVertex3f(x - 22 * scal, y + 10 * scal, z + 55 * scal); //PTA
	glVertex3f(x - 18 * scal, y + 10 * scal, z + 55 * scal); //P1TA
	glVertex3f(x - 18 * scal, y + 6 * scal, z + 55 * scal); //P1T
	glVertex3f(x - 14 * scal, y + 6 * scal, z + 55 * scal); //P1TD
	glVertex3f(x - 14 * scal, y + 2 * scal, z + 55 * scal); //PTD
	glEnd();

	//covers flat-5
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 2 * scal, y + 2 * scal, z + 55 * scal); //MT
	glVertex3f(x - 10 * scal, y + 2 * scal, z + 55 * scal); //MTI
	glVertex3f(x - 10 * scal, y + 2 * scal, z + 50 * scal); //MTI--
	glVertex3f(x - 2 * scal, y + 2 * scal, z + 50 * scal); //MT--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 22 * scal, y + 2 * scal, z + 55 * scal); //PT
	glVertex3f(x - 14 * scal, y + 2 * scal, z + 55 * scal); //PTD
	glVertex3f(x - 14 * scal, y + 2 * scal, z + 50 * scal); //PTD--
	glVertex3f(x - 22 * scal, y + 2 * scal, z + 50 * scal); //PT--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 2 * scal, y + 2 * scal, z + 55 * scal); //MT
	glVertex3f(x - 2 * scal, y + 10 * scal, z + 55 * scal); //MTS
	glVertex3f(x - 2 * scal, y + 10 * scal, z + 50 * scal); //MTS--
	glVertex3f(x - 2 * scal, y + 2 * scal, z + 50 * scal); //MT--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 2 * scal, y + 22 * scal, z + 55 * scal); //NT
	glVertex3f(x - 2 * scal, y + 14 * scal, z + 55 * scal); //NTA
	glVertex3f(x - 2 * scal, y + 14 * scal, z + 50 * scal); //NTA--
	glVertex3f(x - 2 * scal, y + 22 * scal, z + 50 * scal); //NT--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 2 * scal, y + 22 * scal, z + 55 * scal); //NT
	glVertex3f(x - 10 * scal, y + 22 * scal, z + 55 * scal); //NTI
	glVertex3f(x - 10 * scal, y + 22 * scal, z + 50 * scal); //NTI--
	glVertex3f(x - 2 * scal, y + 22 * scal, z + 50 * scal); //NT--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 22 * scal, y + 22 * scal, z + 55 * scal); //OT
	glVertex3f(x - 14 * scal, y + 22 * scal, z + 55 * scal); //OTD
	glVertex3f(x - 14 * scal, y + 22 * scal, z + 50 * scal); //OTD--
	glVertex3f(x - 22 * scal, y + 22 * scal, z + 50 * scal); //OT--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 22 * scal, y + 22 * scal, z + 55 * scal); //OT
	glVertex3f(x - 22 * scal, y + 14 * scal, z + 55 * scal); //OTS
	glVertex3f(x - 22 * scal, y + 14 * scal, z + 50 * scal); //OTS--
	glVertex3f(x - 22 * scal, y + 22 * scal, z + 50 * scal); //OT--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 22 * scal, y + 2 * scal, z + 55 * scal); //PT
	glVertex3f(x - 22 * scal, y + 10 * scal, z + 55 * scal); //PTA
	glVertex3f(x - 22 * scal, y + 10 * scal, z + 50 * scal); //PTA--
	glVertex3f(x - 22 * scal, y + 2 * scal, z + 50 * scal); //PT--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 6 * scal, y + 6 * scal, z + 55 * scal); //M1T
	glVertex3f(x - 10 * scal, y + 6 * scal, z + 55 * scal); //M1TI
	glVertex3f(x - 10 * scal, y + 6 * scal, z + 50 * scal); //M1TI--
	glVertex3f(x - 6 * scal, y + 6 * scal, z + 50 * scal); //M1T--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 6 * scal, y + 6 * scal, z + 55 * scal); //M1T
	glVertex3f(x - 6 * scal, y + 10 * scal, z + 55 * scal); //M1TS
	glVertex3f(x - 6 * scal, y + 10 * scal, z + 50 * scal); //M1TS--
	glVertex3f(x - 6 * scal, y + 6 * scal, z + 50 * scal); //M1T--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 6 * scal, y + 18 * scal, z + 55 * scal); //N1T
	glVertex3f(x - 10 * scal, y + 18 * scal, z + 55 * scal); //N1TI
	glVertex3f(x - 10 * scal, y + 18 * scal, z + 50 * scal); //N1TI--
	glVertex3f(x - 6 * scal, y + 18 * scal, z + 50 * scal); //N1T--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 6 * scal, y + 18 * scal, z + 55 * scal); //N1T
	glVertex3f(x - 6 * scal, y + 14 * scal, z + 55 * scal); //N1TA
	glVertex3f(x - 6 * scal, y + 14 * scal, z + 50 * scal); //N1TA--
	glVertex3f(x - 6 * scal, y + 18 * scal, z + 50 * scal); //N1T--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 18 * scal, y + 18 * scal, z + 55 * scal); //O1T
	glVertex3f(x - 14 * scal, y + 18 * scal, z + 55 * scal); //O1TD
	glVertex3f(x - 14 * scal, y + 18 * scal, z + 50 * scal); //O1TD--
	glVertex3f(x - 18 * scal, y + 18 * scal, z + 50 * scal); //O1T--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 18 * scal, y + 18 * scal, z + 55 * scal); //O1T
	glVertex3f(x - 18 * scal, y + 14 * scal, z + 55 * scal); //O1TS
	glVertex3f(x - 18 * scal, y + 14 * scal, z + 50 * scal); //O1TS--
	glVertex3f(x - 18 * scal, y + 18 * scal, z + 50 * scal); //O1T--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 18 * scal, y + 6 * scal, z + 55 * scal); //P1T
	glVertex3f(x - 14 * scal, y + 6 * scal, z + 55 * scal); //P1TD
	glVertex3f(x - 14 * scal, y + 6 * scal, z + 50 * scal); //P1TD--
	glVertex3f(x - 18 * scal, y + 6 * scal, z + 50 * scal); //P1T--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 18 * scal, y + 6 * scal, z + 55 * scal); //P1T
	glVertex3f(x - 18 * scal, y + 10 * scal, z + 55 * scal); //P1TA
	glVertex3f(x - 18 * scal, y + 10 * scal, z + 50 * scal); //P1TA--
	glVertex3f(x - 18 * scal, y + 6 * scal, z + 50 * scal); //P1T--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 10 * scal, y + 2 * scal, z + 55 * scal); //MTI
	glVertex3f(x - 10 * scal, y + 6 * scal, z + 55 * scal); //M1TI
	glVertex3f(x - 10 * scal, y + 6 * scal, z + 50 * scal); //M1TI--
	glVertex3f(x - 10 * scal, y + 2 * scal, z + 50 * scal); //MTI--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 2 * scal, y + 10 * scal, z + 55 * scal); //MTS
	glVertex3f(x - 6 * scal, y + 10 * scal, z + 55 * scal); //M1TS
	glVertex3f(x - 6 * scal, y + 10 * scal, z + 50 * scal); //M1TS--
	glVertex3f(x - 2 * scal, y + 10 * scal, z + 50 * scal); //MTS--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 10 * scal, y + 22 * scal, z + 55 * scal); //NTI
	glVertex3f(x - 10 * scal, y + 18 * scal, z + 55 * scal); //N1TI
	glVertex3f(x - 10 * scal, y + 18 * scal, z + 50 * scal); //N1TI--
	glVertex3f(x - 10 * scal, y + 22 * scal, z + 50 * scal); //NTI--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 6 * scal, y + 14 * scal, z + 55 * scal); //N1TA
	glVertex3f(x - 2 * scal, y + 14 * scal, z + 55 * scal); //NTA
	glVertex3f(x - 2 * scal, y + 14 * scal, z + 50 * scal); //NTA--
	glVertex3f(x - 6 * scal, y + 14 * scal, z + 50 * scal); //N1TA--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 14 * scal, y + 22 * scal, z + 55 * scal); //OTD
	glVertex3f(x - 14 * scal, y + 18 * scal, z + 55 * scal); //O1TD
	glVertex3f(x - 14 * scal, y + 18 * scal, z + 50 * scal); //O1TD--
	glVertex3f(x - 14 * scal, y + 22 * scal, z + 50 * scal); //OTD--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 22 * scal, y + 14 * scal, z + 55 * scal); //OTS
	glVertex3f(x - 18 * scal, y + 14 * scal, z + 55 * scal); //O1TS
	glVertex3f(x - 18 * scal, y + 14 * scal, z + 50 * scal); //O1TS--
	glVertex3f(x - 22 * scal, y + 14 * scal, z + 50 * scal); //OTS--
	glEnd();
    
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 22 * scal, y + 10 * scal, z + 55 * scal); //PTA
	glVertex3f(x - 18 * scal, y + 10 * scal, z + 55 * scal); //P1TA
	glVertex3f(x - 18 * scal, y + 10 * scal, z + 50 * scal); //P1TA--
	glVertex3f(x - 22 * scal, y + 10 * scal, z + 50 * scal); //PTA--
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 14 * scal, y + 2 * scal, z + 55 * scal); //PTD
	glVertex3f(x - 14 * scal, y + 6 * scal, z + 55 * scal); //P1TD
	glVertex3f(x - 14 * scal, y + 6 * scal, z + 50 * scal); //P1TD--
	glVertex3f(x - 14 * scal, y + 2 * scal, z + 50 * scal); //PTD--
	glEnd();

};


void Ajedrez::peon(double x, double y, double z, double scal){
	//base
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(x, y, z); //A
	glVertex3f(x, y + 24 * scal, z); //B
	glVertex3f(x - 24 * scal, y + 24 * scal, z); //C
	glVertex3f(x - 24 * scal, y, z); //D
	glEnd();

	//base top flat-0
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(x, y, z + 2 * scal); //A1
	glVertex3f(x, y + 24 * scal, z + 2 * scal); //B1
	glVertex3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); //C1
	glVertex3f(x - 24 * scal, y, z + 2 * scal); //D1
	glEnd();

	//covers flat-0
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.3, 0.3);
	glVertex3f(x, y, z); //A
	glVertex3f(x, y, z + 2 * scal); //A1
	glVertex3f(x - 24 * scal, y, z + 2 * scal); //D1
	glVertex3f(x - 24 * scal, y, z); //D
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.3, 0.3);
	glVertex3f(x, y, z); //A
	glVertex3f(x, y, z + 2 * scal); //A1
	glVertex3f(x, y + 24 * scal, z + 2 * scal); //B1
	glVertex3f(x, y + 24 * scal, z); //B
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.3, 0.3);
	glVertex3f(x, y + 24 * scal, z); //B
	glVertex3f(x - 24 * scal, y + 24 * scal, z); //C
	glVertex3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); //C1
	glVertex3f(x, y + 24 * scal, z + 2 * scal); //B1
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.3, 0.3);
	glVertex3f(x - 24 * scal, y + 24 * scal, z); //C
	glVertex3f(x - 24 * scal, y, z); //D
	glVertex3f(x - 24 * scal, y, z + 2 * scal); //D1
	glVertex3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); //C1
	glEnd();

	//covers flat-1
	glBegin(GL_POLYGON);
	glColor3f(0.3, 1.0, 0.3);
	glVertex3f(x, y, z + 2 * scal); //A1
	glVertex3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); //E
	glVertex3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); //H
	glVertex3f(x - 24 * scal, y, z + 2 * scal); //D1
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 1.0, 0.3);
	glVertex3f(x, y, z + 2 * scal); //A1
	glVertex3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); //E
	glVertex3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); //F
	glVertex3f(x, y + 24 * scal, z + 2 * scal); //B1
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 1.0, 0.3);
	glVertex3f(x, y + 24 * scal, z + 2 * scal); //B1
	glVertex3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); //F
	glVertex3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); //G
	glVertex3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); //C1
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 1.0, 0.3);
	glVertex3f(x - 24 * scal, y, z + 2 * scal); //D1
	glVertex3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); //H
	glVertex3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); //G
	glVertex3f(x - 24 * scal, y + 24 * scal, z + 2 * scal); //C1
	glEnd();

	//base top flat-1
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); //E
	glVertex3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); //F
	glVertex3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); //G
	glVertex3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); //H
	glEnd();

	//base top flat-2
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 5 * scal, y + 5 * scal, z + 37 * scal); //I
	glVertex3f(x - 5 * scal, y + 19 * scal, z + 37 * scal); //J
	glVertex3f(x - 19 * scal, y + 19 * scal, z + 37 * scal); //K
	glVertex3f(x - 19 * scal, y + 5 * scal, z + 37 * scal); //L
	glEnd();

	//covers flat-2
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); //E
	glVertex3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); //H
	glVertex3f(x - 19 * scal, y + 5 * scal, z + 37 * scal); //L
	glVertex3f(x - 5 * scal, y + 5 * scal, z + 37 * scal); //I
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 2 * scal, y + 2 * scal, z + 12 * scal); //E
	glVertex3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); //F
	glVertex3f(x - 5 * scal, y + 19 * scal, z + 37 * scal); //J
	glVertex3f(x - 5 * scal, y + 5 * scal, z + 37 * scal); //I
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 2 * scal, y + 22 * scal, z + 12 * scal); //F
	glVertex3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); //G
	glVertex3f(x - 19 * scal, y + 19 * scal, z + 37 * scal); //K
	glVertex3f(x - 5 * scal, y + 19 * scal, z + 37 * scal); //J
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1.0);
	glVertex3f(x - 22 * scal, y + 22 * scal, z + 12 * scal); //G
	glVertex3f(x - 22 * scal, y + 2 * scal, z + 12 * scal); //H
	glVertex3f(x - 19 * scal, y + 5 * scal, z + 37 * scal); //L
	glVertex3f(x - 19 * scal, y + 19 * scal, z + 37 * scal); //K
	glEnd();

	//base top flat-3-1
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.3, 0.3);
	glVertex3f(x - 2 * scal, y + 2 * scal, z + 37 * scal); //E--
	glVertex3f(x - 2 * scal, y + 22 * scal, z + 37 * scal); //F--
	glVertex3f(x - 22 * scal, y + 22 * scal, z + 37 * scal); //G--
	glVertex3f(x - 22 * scal, y + 2 * scal, z + 37 * scal); //H--
	glEnd();
	
	//base top flat-3-2
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.3, 0.3);
	glVertex3f(x - 2 * scal, y + 2 * scal, z + 40 * scal); //E
	glVertex3f(x - 2 * scal, y + 22 * scal, z + 40 * scal); //F
	glVertex3f(x - 22 * scal, y + 22 * scal, z + 40 * scal); //G
	glVertex3f(x - 22 * scal, y + 2 * scal, z + 40 * scal); //H
	glEnd();

	//covers flat-3
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.3, 0.3);
	glVertex3f(x - 2 * scal, y + 2 * scal, z + 37 * scal); //E--
	glVertex3f(x - 22 * scal, y + 2 * scal, z + 37 * scal); //H--
	glVertex3f(x - 22 * scal, y + 2 * scal, z + 40 * scal); //H
	glVertex3f(x - 2 * scal, y + 2 * scal, z + 40 * scal); //E
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.3, 0.3);
	glVertex3f(x - 2 * scal, y + 2 * scal, z + 37 * scal); //E--
	glVertex3f(x - 2 * scal, y + 22 * scal, z + 37 * scal); //F--
	glVertex3f(x - 2 * scal, y + 22 * scal, z + 40 * scal); //F
	glVertex3f(x - 2 * scal, y + 2 * scal, z + 40 * scal); //E
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.3, 0.3);
	glVertex3f(x - 2 * scal, y + 22 * scal, z + 37 * scal); //F--
	glVertex3f(x - 22 * scal, y + 22 * scal, z + 37 * scal); //G--
	glVertex3f(x - 22 * scal, y + 22 * scal, z + 40 * scal); //G
	glVertex3f(x - 2 * scal, y + 22 * scal, z + 40 * scal); //F
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.3, 0.3);
	glVertex3f(x - 22 * scal, y + 22 * scal, z + 37 * scal); //G--
	glVertex3f(x - 22 * scal, y + 2 * scal, z + 37 * scal); //H--
	glVertex3f(x - 22 * scal, y + 2 * scal, z + 40 * scal); //H
	glVertex3f(x - 22 * scal, y + 22 * scal, z + 40 * scal); //G
	glEnd();
	
	//base top flat-4-1
	glBegin(GL_POLYGON);
	glColor3f(0.3, 1.0, 0.3);
	glVertex3f(x - 5 * scal, y + 5 * scal, z + 40 * scal); //M--
	glVertex3f(x - 5 * scal, y + 19 * scal, z + 40 * scal); //N--
	glVertex3f(x - 19 * scal, y + 19 * scal, z + 40 * scal); //O--
	glVertex3f(x - 19 * scal, y + 5 * scal, z + 40 * scal); //P--
	glEnd();

	//base top flat-4-2
	glBegin(GL_POLYGON);
	glColor3f(0.3, 1.0, 0.3);
	glVertex3f(x - 5 * scal, y + 5 * scal, z + 50 * scal); //M
	glVertex3f(x - 5 * scal, y + 19 * scal, z + 50 * scal); //N
	glVertex3f(x - 19 * scal, y + 19 * scal, z + 50 * scal); //O
	glVertex3f(x - 19 * scal, y + 5 * scal, z + 50 * scal); //P
	glEnd();

	//covers  flat-4
	glBegin(GL_POLYGON);
	glColor3f(0.3, 1.0, 0.3);
	glVertex3f(x - 5 * scal, y + 5 * scal, z + 40 * scal); //M--
	glVertex3f(x - 19 * scal, y + 5 * scal, z + 40 * scal); //P--
	glVertex3f(x - 19 * scal, y + 5 * scal, z + 50 * scal); //P
	glVertex3f(x - 5 * scal, y + 5 * scal, z + 50 * scal); //M
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 1.0, 0.3);
	glVertex3f(x - 5 * scal, y + 5 * scal, z + 40 * scal); //M--
	glVertex3f(x - 5 * scal, y + 19 * scal, z + 40 * scal); //N--
	glVertex3f(x - 5 * scal, y + 19 * scal, z + 50 * scal); //N
	glVertex3f(x - 5 * scal, y + 5 * scal, z + 50 * scal); //M
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 1.0, 0.3);
	glVertex3f(x - 5 * scal, y + 19 * scal, z + 40 * scal); //N--
	glVertex3f(x - 19 * scal, y + 19 * scal, z + 40 * scal); //O--
	glVertex3f(x - 19 * scal, y + 19 * scal, z + 50 * scal); //O
	glVertex3f(x - 5 * scal, y + 19 * scal, z + 50 * scal); //N
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 1.0, 0.3);
	glVertex3f(x - 19 * scal, y + 19 * scal, z + 40 * scal); //O--
	glVertex3f(x - 19 * scal, y + 5 * scal, z + 40 * scal); //P--
	glVertex3f(x - 19 * scal, y + 5 * scal, z + 50 * scal); //P
	glVertex3f(x - 19 * scal, y + 19 * scal, z + 50 * scal); //O
	glEnd();


};


void Ajedrez::reina(double x, double y, double z, double scal){
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(-24.0 * scal, 24.0 * scal, 0.0 * scal);//a
	glVertex3f(24.0 * scal, 24.0 * scal, 0.0 * scal);//b
	glVertex3f(24.0 * scal, -24.0 * scal, 0.0 * scal);//c
	glVertex3f(-24.0 * scal, -24.0 * scal, 0.0 * scal);//d
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.0);
	glVertex3f(-24.0 * scal, 24.0 * scal, 0.0 * scal);//a
	glVertex3f(24.0 * scal, 24.0 * scal, 0.0 * scal);//b
	glVertex3f(24.0 * scal, 24.0 * scal, 5.00 * scal);//b
	glVertex3f(-24.0 * scal, 24.0 * scal, 5.00 * scal);//a
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(24.0 * scal, 24.0 * scal, 0.0 * scal);//b
	glVertex3f(24.0 * scal, -24.0 * scal, 0.0 * scal);//c
	glVertex3f(24.0 * scal, -24.0 * scal, 5.0 * scal);//c
	glVertex3f(24.0 * scal, 24.0 * scal, 5.0 * scal);//b
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(24.0 * scal, -24.0 * scal, 0.0 * scal);//c
	glVertex3f(-24.0 * scal, -24.0 * scal, 0.0 * scal);//d
	glVertex3f(-24.0 * scal, -24.0 * scal, 5.0 * scal);//d
	glVertex3f(24.0 * scal, -24.0 * scal, 5.0 * scal);//c
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(-24.0 * scal, -24.0 * scal, 0.0 * scal);//d
	glVertex3f(-24.0 * scal, 24.0 * scal, 0.0 * scal);//a
	glVertex3f(-24.0 * scal, 24.0 * scal, 5.0 * scal);//a
	glVertex3f(-24.0 * scal, -24.0 * scal, 5.0 * scal);//d
	glEnd();

	/////////////////////////////////////////////////////////

	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(-24.0 * scal, 24.0 * scal, 5.0 * scal);//a
	glVertex3f(24.0 * scal, 24.0 * scal, 5.0 * scal);//b
	glVertex3f(18.0 * scal, 18.0 * scal, 15.0 * scal);//f
	glVertex3f(-18.0 * scal, 18.0 * scal, 15.0 * scal);//e
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(24.0 * scal, 24.0 * scal, 5.0 * scal);//b
	glVertex3f(24.0 * scal, -24.0 * scal, 5.0 * scal);//c
	glVertex3f(18.0 * scal, -18.0 * scal, 15.0 * scal);//g
	glVertex3f(18.0 * scal, 18.0 * scal, 15.0 * scal);//f
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(24.0 * scal, -24.0 * scal, 5.0 * scal);//c
	glVertex3f(-24.0 * scal, -24.0 * scal, 5.0 * scal);//d
	glVertex3f(-18.0 * scal, -18.0 * scal, 15.0 * scal);//h
	glVertex3f(18.0 * scal, -18.0 * scal, 15.0 * scal);//g
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(-24.0 * scal, 24.0 * scal, 5.0 * scal);//a
	glVertex3f(-24.0 * scal, -24.0 * scal, 5.0 * scal);//d
	glVertex3f(-18.0 * scal, -18.0 * scal, 15.0 * scal);//h
	glVertex3f(-18.0 * scal, 18.0 * scal, 15.0 * scal);//e
	glEnd();

	////////////////////////////////////////////////////////

	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(-18.0 * scal, 18.0 * scal, 15.0 * scal);//e
	glVertex3f(18.0 * scal, 18.0 * scal, 15.0 * scal);//f
	glVertex3f(15.0 * scal, 15.0 * scal, 55.0 * scal);//j
	glVertex3f(-15.0 * scal, 15.0 * scal, 55.0 * scal);//i
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(18.0 * scal, 18.0 * scal, 15.0 * scal);//f
	glVertex3f(18.0 * scal, -18.0 * scal, 15.0 * scal);//g
	glVertex3f(15.0 * scal, -15.0 * scal, 55.0 * scal);//k
	glVertex3f(15.0 * scal, 15.0 * scal, 55.0 * scal);//j
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(-18.0 * scal, -18.0 * scal, 15.0 * scal);//h
	glVertex3f(18.0 * scal, -18.0 * scal, 15.0 * scal);//g
	glVertex3f(15.0 * scal, -15.0 * scal, 55.0 * scal);//k
	glVertex3f(-15.0 * scal, -15.0 * scal, 55.0 * scal);//l
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(-18.0 * scal, 18.0 * scal, 15.0 * scal);//e
	glVertex3f(-18.0 * scal, -18.0 * scal, 15.0 * scal);//h
	glVertex3f(-15.0 * scal, -15.0 * scal, 55.0 * scal);//l
	glVertex3f(-15.0 * scal, 15.0 * scal, 55.0 * scal);//i
	glEnd();

	/////////////////////////////////////////////////////////

	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(15.0 * scal, 15.0 * scal, 55.0 * scal);//j
	glVertex3f(-15.0 * scal, 15.0 * scal, 55.0 * scal);//i
	glVertex3f(-21.0 * scal, 21.0 * scal, 65.0 * scal);//i
	glVertex3f(21.0 * scal, 21.0 * scal, 65.0 * scal);//j
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(15.0 * scal, 15.0 * scal, 55.0 * scal);//j
	glVertex3f(15.0 * scal, -15.0 * scal, 55.0 * scal);//k
	glVertex3f(21.0 * scal, -21.0 * scal, 65.0 * scal);//k
	glVertex3f(21.0 * scal, 21.0 * scal, 65.0 * scal);//j
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(-15.0 * scal, -15.0 * scal, 55.0 * scal);//l
	glVertex3f(15.0 * scal, -15.0 * scal, 55.0 * scal);//k
	glVertex3f(21.0 * scal, -21.0 * scal, 65.0 * scal);//k
	glVertex3f(-21.0 * scal, -21.0 * scal, 65.0 * scal);//l
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(-15.0 * scal, 15.0 * scal, 55.0 * scal);//i
	glVertex3f(-15.0 * scal, -15.0 * scal, 55.0 * scal);//l
	glVertex3f(-21.0 * scal, -21.0 * scal, 65.0 * scal);//l
	glVertex3f(-21.0 * scal, 21.0 * scal, 65.0 * scal);//i
	glEnd();

	////////////////////////////////////////////////////////

	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(-21.0 * scal, 21.0 * scal, 65.0 * scal);//i
	glVertex3f(21.0 * scal, 21.0 * scal, 65.0 * scal);//j
	glVertex3f(21.0 * scal, 21.0 * scal, 70.0 * scal);//j
	glVertex3f(-21.0 * scal, 21.0 * scal, 70.0 * scal);//i
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(21.0 * scal, -21.0 * scal, 65.0 * scal);//k
	glVertex3f(21.0 * scal, 21.0 * scal, 65.0 * scal);//j
	glVertex3f(21.0 * scal, 21.0 * scal, 70.0 * scal);//j
	glVertex3f(21.0 * scal, -21.0 * scal, 70.0 * scal);//k
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(21.0 * scal, -21.0 * scal, 65.0 * scal);//k
	glVertex3f(-21.0 * scal, -21.0 * scal, 65.0 * scal);//l
	glVertex3f(-21.0 * scal, -21.0 * scal, 70.0 * scal);//l
	glVertex3f(21.0 * scal, -21.0 * scal, 70.0 * scal);//k
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(-21.0 * scal, -21.0 * scal, 65.0 * scal);//l
	glVertex3f(-21.0 * scal, 21.0 * scal, 65.0 * scal);//i
	glVertex3f(-21.0 * scal, 21.0 * scal, 70.0 * scal);//i
	glVertex3f(-21.0 * scal, -21.0 * scal, 70.0 * scal);//l
	glEnd();

	/////////////////////////////////////////////////////////

	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(21.0 * scal, 21.0 * scal, 70.0 * scal);//j
	glVertex3f(-21.0 * scal, 21.0 * scal, 70.0 * scal);//i
	glVertex3f(-15.0 * scal, 15.0 * scal, 75.0 * scal);//i
	glVertex3f(15.0 * scal, 15.0 * scal, 75.0 * scal);//j
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(21.0 * scal, 21.0 * scal, 70.0 * scal);//j
	glVertex3f(21.0 * scal, -21.0 * scal, 70.0 * scal);//k
	glVertex3f(15.0 * scal, -15.0 * scal, 75.0 * scal);//k
	glVertex3f(15.0 * scal, 15.0 * scal, 75.0 * scal);//j
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(-21.0 * scal, -21.0 * scal, 70.0 * scal);//l
	glVertex3f(21.0 * scal, -21.0 * scal, 70.0 * scal);//k
	glVertex3f(15.0 * scal, -15.0 * scal, 75.0 * scal);//k
	glVertex3f(-15.0 * scal, -15.0 * scal, 75.0 * scal);//l
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(-21.0 * scal, 21.0 * scal, 70.0 * scal);//i
	glVertex3f(-21.0 * scal, -21.0 * scal, 70.0 * scal);//l
	glVertex3f(-15.0 * scal, -15.0 * scal, 75.0 * scal);//l
	glVertex3f(-15.0 * scal, 15.0 * scal, 75.0 * scal);//i
	glEnd();

	////////////////////////////////////////////////////////

	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(-15.0 * scal, 15.0 * scal, 75.0 * scal);//i
	glVertex3f(15.0 * scal, 15.0 * scal, 75.0 * scal);//j
	glVertex3f(19.0 * scal, 19.0 * scal, 90.0 * scal);//j
	glVertex3f(-19.0 * scal, 19.0 * scal, 90.0 * scal);//i
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(15.0 * scal, -15.0 * scal, 75.0 * scal);//k
	glVertex3f(15.0 * scal, 15.0 * scal, 75.0 * scal);//j
	glVertex3f(19.0 * scal, 19.0 * scal, 90.0 * scal);//j
	glVertex3f(19.0 * scal, -19.0 * scal, 90.0 * scal);//k
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(15.0 * scal, -15.0 * scal, 75.0 * scal);//k
	glVertex3f(-15.0 * scal, -15.0 * scal, 75.0 * scal);//l
	glVertex3f(-19.0 * scal, -19.0 * scal, 90.0 * scal);//l
	glVertex3f(19.0 * scal, -19.0 * scal, 90.0 * scal);//k
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(-15.0 * scal, -15.0 * scal, 75.0 * scal);//l
	glVertex3f(-15.0 * scal, 15.0 * scal, 75.0 * scal);//i
	glVertex3f(-19.0 * scal, 19.0 * scal, 90.0 * scal);//i
	glVertex3f(-19.0 * scal, -19.0 * scal, 90.0 * scal);//l
	glEnd();

	//////////////////////////////////////////////////////////

	glBegin(GL_POLYGON);
	glColor3f(0.1, 1.1, 0.1);
	glVertex3f(19.0 * scal, 19.0 * scal, 90.0 * scal);//j
	glVertex3f(-19.0 * scal, 19.0 * scal, 90.0 * scal);//i
	glVertex3f(-10.0 * scal, 10.0 * scal, 90.0 * scal);//i
	glVertex3f(10.0 * scal, 10.0 * scal, 90.0 * scal);//j
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 1.1, 0.1);
	glVertex3f(19.0 * scal, 19.0 * scal, 90.0 * scal);//j
	glVertex3f(19.0 * scal, -19.0 * scal, 90.0 * scal);//k
	glVertex3f(10.0 * scal, -10.0 * scal, 90.0 * scal);//k
	glVertex3f(10.0 * scal, 10.0 * scal, 90.0 * scal);//j
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 1.1, 0.1);
	glVertex3f(-19.0 * scal, -19.0 * scal, 90.0 * scal);//l
	glVertex3f(19.0 * scal, -19.0 * scal, 90.0 * scal);//k
	glVertex3f(10.0 * scal, -10.0 * scal, 90.0 * scal);//k
	glVertex3f(-10.0 * scal, -10.0 * scal, 90.0 * scal);//l
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 1.1, 0.1);
	glVertex3f(-19.0 * scal, 19.0 * scal, 90.0 * scal);//i
	glVertex3f(-19.0 * scal, -19.0 * scal, 90.0 * scal);//l
	glVertex3f(-10.0 * scal, -10.0 * scal, 90.0 * scal);//l
	glVertex3f(-10.0 * scal, 10.0 * scal, 90.0 * scal);//i
	glEnd();

	//////////////////////////////////////////////////////////////

	glBegin(GL_POLYGON);
	glColor3f(0.1, 1.1, 0.1);
	glVertex3f(-10.0 * scal, 10.0 * scal, 90.0 * scal);//i
	glVertex3f(10.0 * scal, 10.0 * scal, 90.0 * scal);//j
	glVertex3f(10.0 * scal, 10.0 * scal, 95.0 * scal);//j
	glVertex3f(-10.0 * scal, 10.0 * scal, 95.0 * scal);//i
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 1.1, 0.1);
	glVertex3f(10.0 * scal, -10.0 * scal, 90.0 * scal);//k
	glVertex3f(10.0 * scal, 10.0 * scal, 90.0 * scal);//j
	glVertex3f(10.0 * scal, 10.0 * scal, 95.0 * scal);//j
	glVertex3f(10.0 * scal, -10.0 * scal, 95.0 * scal);//k
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 1.1, 0.1);
	glVertex3f(10.0 * scal, -10.0 * scal, 90.0 * scal);//k
	glVertex3f(-10.0 * scal, -10.0 * scal, 90.0 * scal);//l
	glVertex3f(-10.0 * scal, -10.0 * scal, 95.0 * scal);//l
	glVertex3f(10.0 * scal, -10.0 * scal, 95.0 * scal);//k
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 1.1, 0.1);
	glVertex3f(-10.0 * scal, -10.0 * scal, 90.0 * scal);//l
	glVertex3f(-10.0 * scal, 10.0 * scal, 90.0 * scal);//i
	glVertex3f(-10.0 * scal, 10.0 * scal, 95.0 * scal);//i
	glVertex3f(-10.0 * scal, -10.0 * scal, 95.0 * scal);//l
	glEnd();

	//////////////////////////////////////////////////////////////

	glBegin(GL_POLYGON);
	glColor3f(1.1, 1.1, 0.1);
	glVertex3f(10.0 * scal, 10.0 * scal, 95.0 * scal);//j
	glVertex3f(-10.0 * scal, 10.0 * scal, 95.0 * scal);//i
	glVertex3f(-0.0 * scal, 0.0 * scal, 95.0 * scal);//i
	glVertex3f(0.0 * scal, 0.0 * scal, 95.0 * scal);//j
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.1, 1.1, 0.1);
	glVertex3f(10.0 * scal, 10.0 * scal, 95.0 * scal);//j
	glVertex3f(10.0 * scal, -10.0 * scal, 95.0 * scal);//k
	glVertex3f(0.0 * scal, -0.0 * scal, 95.0 * scal);//k
	glVertex3f(0.0 * scal, 0.0 * scal, 95.0 * scal);//j
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.1, 1.1, 0.1);
	glVertex3f(-10.0 * scal, -10.0 * scal, 95.0 * scal);//l
	glVertex3f(10.0 * scal, -10.0 * scal, 95.0 * scal);//k
	glVertex3f(0.0 * scal, 0.0 * scal, 95.0 * scal);//k
	glVertex3f(-0.0 * scal, -0.0 * scal, 95.0 * scal);//l
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.1, 1.1, 0.1);
	glVertex3f(-10.0 * scal, 10.0 * scal, 95.0 * scal);//i
	glVertex3f(-10.0 * scal, -10.0 * scal, 95.0 * scal);//l
	glVertex3f(-0.0 * scal, -0.0 * scal, 95.0 * scal);//l
	glVertex3f(-0.0 * scal, 0.0 * scal, 95.0 * scal);//i
	glEnd();

};


void Ajedrez::rey(double x, double y, double z, double scal){
	glBegin(GL_POLYGON);//base del rey
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x, y, z);//A
	glVertex3f(x, y + 24 * scal, z);//B
	glVertex3f(x - 24 * scal, y + 24 * scal, z);//C
	glVertex3f(x - 24 * scal, y, z);//D
	glEnd();

	glBegin(GL_POLYGON);//base del rey altura pequeña
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x, y, z + 5 * scal);//A1
	glVertex3f(x, y + 24 * scal, z + 5 * scal);//B1
	glVertex3f(x - 24 * scal, y + 24 * scal, z + 5 * scal);//C1
	glVertex3f(x - 24 * scal, y, z + 5 * scal);//D1
	glEnd();

	glBegin(GL_POLYGON);//base del rey lados 1
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x, y, z);//A
	glVertex3f(x, y, z + 5 * scal);//A1
	glVertex3f(x, y + 24 * scal, z + 5 * scal);//B1
	glVertex3f(x, y + 24 * scal, z);//B
	glEnd();

	glBegin(GL_POLYGON);//base del rey lados 2
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x, y + 24 * scal, z + 5 * scal);//B1
	glVertex3f(x - 24 * scal, y + 24 * scal, z + 5 * scal);//C1
	glVertex3f(x - 24 * scal, y + 24 * scal, z);//C
	glVertex3f(x, y + 24 * scal, z);//B
	glEnd();

	glBegin(GL_POLYGON);//base del rey lados 3
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x - 24 * scal, y + 24 * scal, z + 5 * scal);//C1
	glVertex3f(x - 24 * scal, y, z + 5 * scal);//D1
	glVertex3f(x - 24 * scal, y, z);//D
	glVertex3f(x - 24 * scal, y + 24 * scal, z);//C
	glEnd();

	glBegin(GL_POLYGON);//base del rey lados 4
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x - 24 * scal, y, z);//D
	glVertex3f(x - 24 * scal, y, z + 5 * scal);//D1
	glVertex3f(x, y, z + 5 * scal);//A1
	glVertex3f(x, y, z);//A
	glEnd();

	glBegin(GL_POLYGON);//base del rey caida 1
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x, y, z + 5 * scal);//A1
	glVertex3f(x - 5 * scal, y + 5 * scal, z + 15 * scal);//E
	glVertex3f(x - 5 * scal, y + 19 * scal, z + 15 * scal);//F
	glVertex3f(x, y + 24 * scal, z + 5 * scal);//B1
	glEnd();

	glBegin(GL_POLYGON);//base del rey caida 2
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x, y + 24 * scal, z + 5 * scal);//B1
	glVertex3f(x - 5 * scal, y + 19 * scal, z + 15 * scal);//F
	glVertex3f(x - 19 * scal, y + 19 * scal, z + 15 * scal);//H
	glVertex3f(x - 24 * scal, y + 24 * scal, z + 5 * scal);//C1
	glEnd();

	glBegin(GL_POLYGON);//base del rey caida 3
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x - 24 * scal, y + 24 * scal, z + 5 * scal);//C1
	glVertex3f(x - 19 * scal, y + 19 * scal, z + 15 * scal);//H
	glVertex3f(x - 19 * scal, y + 5 * scal, z + 15 * scal);//G
	glVertex3f(x - 24 * scal, y, z + 5 * scal);//D1
	glEnd();

	glBegin(GL_POLYGON);//base del rey caida 4
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x - 24 * scal, y, z + 5 * scal);//D1
	glVertex3f(x - 19 * scal, y + 5 * scal, z + 15 * scal);//G
	glVertex3f(x - 5 * scal, y + 5 * scal, z + 15 * scal);//E
	glVertex3f(x, y, z + 5 * scal);//A1	
	glEnd();

	glBegin(GL_POLYGON);//base del rey altura 1
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x - 5 * scal, y + 5 * scal, z + 15 * scal);//E
	glVertex3f(x - 5 * scal, y + 5 * scal, z + 35 * scal);//E1
	glVertex3f(x - 5 * scal, y + 19 * scal, z + 35 * scal);//F1
	glVertex3f(x - 5 * scal, y + 19 * scal, z + 15 * scal);//F
	glEnd();

	glBegin(GL_POLYGON);//base del rey altura 2
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x - 5 * scal, y + 19 * scal, z + 15 * scal);//F
	glVertex3f(x - 5 * scal, y + 19 * scal, z + 35 * scal);//F1
	glVertex3f(x - 19 * scal, y + 19 * scal, z + 35 * scal);//H1
	glVertex3f(x - 19 * scal, y + 19 * scal, z + 15 * scal);//H
	glEnd();

	glBegin(GL_POLYGON);//base del rey altura 3
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x - 19 * scal, y + 19 * scal, z + 15 * scal);//H
	glVertex3f(x - 19 * scal, y + 19 * scal, z + 35 * scal);//H1
	glVertex3f(x - 19 * scal, y + 5 * scal, z + 35 * scal);//G1
	glVertex3f(x - 19 * scal, y + 5 * scal, z + 15 * scal);//G
	glEnd();

	glBegin(GL_POLYGON);//base del rey altura 4
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x - 19 * scal, y + 5 * scal, z + 15 * scal);//G
	glVertex3f(x - 19 * scal, y + 5 * scal, z + 35 * scal);//G1
	glVertex3f(x - 5 * scal, y + 5 * scal, z + 35 * scal);//E1
	glVertex3f(x - 5 * scal, y + 5 * scal, z + 15 * scal);//E	
	glEnd();

	glBegin(GL_POLYGON);//rey altura 1
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x - 5 * scal, y + 5 * scal, z + 35 * scal);//E1
	glVertex3f(x - 2 * scal, y + 2 * scal, z + 40 * scal);//M
	glVertex3f(x - 2 * scal, y + 23 * scal, z + 40 * scal);//N 
	glVertex3f(x - 5 * scal, y + 19 * scal, z + 35 * scal);//F1
	glEnd();

	glBegin(GL_POLYGON);//rey altura 2
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x - 5 * scal, y + 19 * scal, z + 35 * scal);//F1
	glVertex3f(x - 2 * scal, y + 23 * scal, z + 40 * scal);//N 
	glVertex3f(x - 23 * scal, y + 23 * scal, z + 40 * scal);//Ñ
	glVertex3f(x - 19 * scal, y + 19 * scal, z + 35 * scal);//H1
	glEnd();

	glBegin(GL_POLYGON);//rey altura 3
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x - 19 * scal, y + 19 * scal, z + 35 * scal);//H1
	glVertex3f(x - 23 * scal, y + 23 * scal, z + 40 * scal);//Ñ
	glVertex3f(x - 23 * scal, y + 2 * scal, z + 40 * scal);//O
	glVertex3f(x - 19 * scal, y + 5 * scal, z + 35 * scal);//G1
	glEnd();

	glBegin(GL_POLYGON);//rey altura 4
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x - 19 * scal, y + 5 * scal, z + 35 * scal);//G1
	glVertex3f(x - 23 * scal, y + 2 * scal, z + 40 * scal);//O
	glVertex3f(x - 2 * scal, y + 2 * scal, z + 40 * scal);//M
	glVertex3f(x - 5 * scal, y + 5 * scal, z + 35 * scal);//E1	
	glEnd();

	glBegin(GL_POLYGON);//rey altura 1.1
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x - 2 * scal, y + 2 * scal, z + 40 * scal);//M
	glVertex3f(x - 5 * scal, y + 5 * scal, z + 45 * scal);//M1 glVertex3f(x-5*scal,y+5*scal,z+35*scal);//E1
	glVertex3f(x - 5 * scal, y + 19 * scal, z + 45 * scal);//N1 glVertex3f(x-5*scal,y+19*scal,z+35*scal);//F1
	glVertex3f(x - 2 * scal, y + 23 * scal, z + 40 * scal);//N
	glEnd();

	glBegin(GL_POLYGON);//rey altura 1.2
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x - 2 * scal, y + 23 * scal, z + 40 * scal);//N 
	glVertex3f(x - 5 * scal, y + 19 * scal, z + 45 * scal);//N1 
	glVertex3f(x - 19 * scal, y + 19 * scal, z + 45 * scal);//Ñ1 glVertex3f(x-19*scal,y+19*scal,z+35*scal);//H1
	glVertex3f(x - 23 * scal, y + 23 * scal, z + 40 * scal);//Ñ
	glEnd();

	glBegin(GL_POLYGON);//rey altura 1.3
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x - 23 * scal, y + 23 * scal, z + 40 * scal);//Ñ
	glVertex3f(x - 19 * scal, y + 19 * scal, z + 45 * scal);//Ñ1 glVertex3f(x-19*scal,y+19*scal,z+35*scal);//H1
	glVertex3f(x - 19 * scal, y + 5 * scal, z + 45 * scal);//O1 glVertex3f(x-19*scal,y+5*scal,z+35*scal);//G1
	glVertex3f(x - 23 * scal, y + 2 * scal, z + 40 * scal);//O
	glEnd();

	glBegin(GL_POLYGON);//rey altura 1.4
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x - 23 * scal, y + 2 * scal, z + 40 * scal);//O
	glVertex3f(x - 19 * scal, y + 5 * scal, z + 45 * scal);//O1 glVertex3f(x-19*scal,y+5*scal,z+35*scal);//G1
	glVertex3f(x - 5 * scal, y + 5 * scal, z + 45 * scal);//M1 glVertex3f(x-5*scal,y+5*scal,z+35*scal);//E1
	glVertex3f(x - 2 * scal, y + 2 * scal, z + 40 * scal);//M	
	glEnd();

	glBegin(GL_POLYGON);//rey copita 1
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x - 5 * scal, y + 5 * scal, z + 45 * scal);//M1 glVertex3f(x-5*scal,y+5*scal,z+35*scal);//E1
	glVertex3f(x - 3 * scal, y + 3 * scal, z + 50 * scal);//1A
	glVertex3f(x - 3 * scal, y + 22 * scal, z + 50 * scal);//2A
	glVertex3f(x - 5 * scal, y + 19 * scal, z + 45 * scal);//N1 
	glEnd();

	glBegin(GL_POLYGON);//rey copita 2
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x - 5 * scal, y + 19 * scal, z + 45 * scal);//N1 
	glVertex3f(x - 3 * scal, y + 22 * scal, z + 50 * scal);//2A
	glVertex3f(x - 22 * scal, y + 22 * scal, z + 50 * scal);//3A glVertex3f(x-23*scal,y+23*scal,z+40*scal);//Ñ
	glVertex3f(x - 19 * scal, y + 19 * scal, z + 45 * scal);//Ñ1 glVertex3f(x-19*scal,y+19*scal,z+35*scal);//H1
	glEnd();

	glBegin(GL_POLYGON);//rey copita 3
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x - 19 * scal, y + 19 * scal, z + 45 * scal);//Ñ1 glVertex3f(x-19*scal,y+19*scal,z+35*scal);//H1
	glVertex3f(x - 22 * scal, y + 22 * scal, z + 50 * scal);//3A glVertex3f(x-23*scal,y+23*scal,z+40*scal);//Ñ
	glVertex3f(x - 22 * scal, y + 3 * scal, z + 50 * scal);//4A glVertex3f(x-23*scal,y+2*scal,z+40*scal);//O
	glVertex3f(x - 19 * scal, y + 5 * scal, z + 45 * scal);//O1 glVertex3f(x-19*scal,y+5*scal,z+35*scal);//G1
	glEnd();

	glBegin(GL_POLYGON);//rey copita 4
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x - 19 * scal, y + 5 * scal, z + 45 * scal);//O1 glVertex3f(x-19*scal,y+5*scal,z+35*scal);//G1
	glVertex3f(x - 22 * scal, y + 3 * scal, z + 50 * scal);//4A glVertex3f(x-23*scal,y+2*scal,z+40*scal);//O
	glVertex3f(x - 3 * scal, y + 3 * scal, z + 50 * scal);//1A
	glVertex3f(x - 5 * scal, y + 5 * scal, z + 45 * scal);//M1 glVertex3f(x-5*scal,y+5*scal,z+35*scal);//E1
	glEnd();

	glBegin(GL_POLYGON);//rey copita 1.1
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x - 3 * scal, y + 3 * scal, z + 50 * scal);//1A
	glVertex3f(x - 5 * scal, y + 5 * scal, z + 55 * scal);//1A1
	glVertex3f(x - 5 * scal, y + 19 * scal, z + 55 * scal);//1A2
	glVertex3f(x - 3 * scal, y + 22 * scal, z + 50 * scal);//2A
	glEnd();

	glBegin(GL_POLYGON);//rey copita 1.2
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x - 3 * scal, y + 22 * scal, z + 50 * scal);//2A
	glVertex3f(x - 5 * scal, y + 19 * scal, z + 55 * scal);//1A2
	glVertex3f(x - 19 * scal, y + 19 * scal, z + 55 * scal);//1A3
	glVertex3f(x - 22 * scal, y + 22 * scal, z + 50 * scal);//3A glVertex3f(x-23*scal,y+23*scal,z+40*scal);//Ñ
	glEnd();

	glBegin(GL_POLYGON);//rey copita 1.3
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x - 22 * scal, y + 22 * scal, z + 50 * scal);//3A glVertex3f(x-23*scal,y+23*scal,z+40*scal);//Ñ
	glVertex3f(x - 19 * scal, y + 19 * scal, z + 55 * scal);//1A3
	glVertex3f(x - 19 * scal, y + 5 * scal, z + 55 * scal);//1A4
	glVertex3f(x - 22 * scal, y + 3 * scal, z + 50 * scal);//4A glVertex3f(x-23*scal,y+2*scal,z+40*scal);//O
	glEnd();

	glBegin(GL_POLYGON);//rey copita 1.4
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x - 22 * scal, y + 3 * scal, z + 50 * scal);//4A glVertex3f(x-23*scal,y+2*scal,z+40*scal);//O
	glVertex3f(x - 19 * scal, y + 5 * scal, z + 55 * scal);//1A4
	glVertex3f(x - 5 * scal, y + 5 * scal, z + 55 * scal);//1A1
	glVertex3f(x - 3 * scal, y + 3 * scal, z + 50 * scal);//1A	
	glEnd();

	glBegin(GL_POLYGON);//rey copita 1.4
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x - 22 * scal, y + 3 * scal, z + 50 * scal);//4A glVertex3f(x-23*scal,y+2*scal,z+40*scal);//O
	glVertex3f(x - 19 * scal, y + 5 * scal, z + 55 * scal);//1A4
	glVertex3f(x - 5 * scal, y + 5 * scal, z + 55 * scal);//1A1
	glVertex3f(x - 3 * scal, y + 3 * scal, z + 50 * scal);//1A	
	glEnd();

	/*	glBegin(GL_POLYGON);//rey cruz 1
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x-8.5*scal,y+8.5*scal,z+55*scal);//R1
	glVertex3f(x-8.5*scal,y+8.5*scal,z+64*scal);//1R1
	glVertex3f(x-8.5*scal,y+15.5*scal,z+64*scal);//2R2
	glVertex3f(x-8.5*scal,y+15.5*scal,z+55*scal);//R2
	glEnd();*/
	glBegin(GL_POLYGON);//rey cruz 1
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x - 10 * scal, y + 10 * scal, z + 55 * scal);//R1
	glVertex3f(x - 10 * scal, y + 10 * scal, z + 64 * scal);//1R1
	glVertex3f(x - 10 * scal, y + 14.5*scal, z + 64 * scal);//2R2
	glVertex3f(x - 10 * scal, y + 14.5*scal, z + 55 * scal);//R2
	glEnd();

	glBegin(GL_POLYGON);//rey cruz 2
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x - 10 * scal, y + 14.5*scal, z + 55 * scal);//R2
	glVertex3f(x - 10 * scal, y + 14.5*scal, z + 64 * scal);//2R2
	glVertex3f(x - 14.5*scal, y + 14.5*scal, z + 64 * scal);//3R3
	glVertex3f(x - 14.5*scal, y + 14.5*scal, z + 55 * scal);//R3
	glEnd();

	glBegin(GL_POLYGON);//rey cruz 3
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x - 14.5*scal, y + 14.5*scal, z + 55 * scal);//R3
	glVertex3f(x - 14.5*scal, y + 14.5*scal, z + 64 * scal);//3R3
	glVertex3f(x - 14.5*scal, y + 10 * scal, z + 64 * scal);//4R4
	glVertex3f(x - 14.5*scal, y + 10 * scal, z + 55 * scal);//R4
	glEnd();

	glBegin(GL_POLYGON);//rey cruz 4
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x - 14.5*scal, y + 10 * scal, z + 55 * scal);//R4
	glVertex3f(x - 14.5*scal, y + 10 * scal, z + 64 * scal);//4R4
	glVertex3f(x - 10 * scal, y + 10 * scal, z + 64 * scal);//1R1
	glVertex3f(x - 10 * scal, y + 10 * scal, z + 55 * scal);//R1	
	glEnd();

	glBegin(GL_POLYGON);//rey cruz H 1
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x - 7 * scal, y + 10 * scal, z + 58 * scal);//RH1
	glVertex3f(x - 7 * scal, y + 14.5*scal, z + 58 * scal);//RH2
	glVertex3f(x - 17 * scal, y + 14.5*scal, z + 58 * scal);//RH3
	glVertex3f(x - 17 * scal, y + 10 * scal, z + 58 * scal);//RH4
	glEnd();

	glBegin(GL_POLYGON);//rey cruz H 1
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x - 7 * scal, y + 10 * scal, z + 58 * scal);//RH1
	glVertex3f(x - 7 * scal, y + 10 * scal, z + 61 * scal);//1RH1
	glVertex3f(x - 7 * scal, y + 14.5*scal, z + 61 * scal);//2RH2
	glVertex3f(x - 7 * scal, y + 14.5*scal, z + 58 * scal);//RH2
	glEnd();

	glBegin(GL_POLYGON);//rey cruz H 2
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x - 7 * scal, y + 14.5*scal, z + 58 * scal);//RH2
	glVertex3f(x - 7 * scal, y + 14.5*scal, z + 61 * scal);//2RH2
	glVertex3f(x - 17 * scal, y + 14.5*scal, z + 61 * scal);//3RH3
	glVertex3f(x - 17 * scal, y + 14.5*scal, z + 58 * scal);//RH3
	glEnd();

	glBegin(GL_POLYGON);//rey cruz H 3
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x - 17 * scal, y + 14.5*scal, z + 58 * scal);//RH3
	glVertex3f(x - 17 * scal, y + 14.5*scal, z + 61 * scal);//3RH3
	glVertex3f(x - 17 * scal, y + 10 * scal, z + 61 * scal);//4RH4
	glVertex3f(x - 17 * scal, y + 10 * scal, z + 58 * scal);//RH4
	glEnd();

	glBegin(GL_POLYGON);//rey cruz H 4
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x - 17 * scal, y + 10 * scal, z + 58 * scal);//RH4
	glVertex3f(x - 17 * scal, y + 10 * scal, z + 61 * scal);//4RH4
	glVertex3f(x - 7 * scal, y + 10 * scal, z + 61 * scal);//1RH1
	glVertex3f(x - 7 * scal, y + 10 * scal, z + 58 * scal);//RH1	
	glEnd();

	glBegin(GL_POLYGON);//rey cruz H TECHO 1
	glColor3f(0.8, 0.4, 0.0);
	glVertex3f(x - 7 * scal, y + 10 * scal, z + 61 * scal);//RH1
	glVertex3f(x - 7 * scal, y + 14.5*scal, z + 61 * scal);//RH2
	glVertex3f(x - 17 * scal, y + 14.5*scal, z + 61 * scal);//RH3
	glVertex3f(x - 17 * scal, y + 10 * scal, z + 61 * scal);//RH4
	glEnd();

	glBegin(GL_POLYGON);//rey cruz TECHO 
	glColor3f(0.5, 0.4, 0.0);
	glVertex3f(x - 10 * scal, y + 10 * scal, z + 64 * scal);//1R1
	glVertex3f(x - 10 * scal, y + 14.5*scal, z + 64 * scal);//2R2
	glVertex3f(x - 14.5*scal, y + 14.5*scal, z + 64 * scal);//3R3
	glVertex3f(x - 14.5*scal, y + 10 * scal, z + 64 * scal);//4R4
	glEnd();
};


void Ajedrez::alfil(double x, double y, double z, double scal){
	double ang = 0.0;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(x, y, z);						//A
	glVertex3f(x - 24 * scal, y, z);				//B
	glVertex3f(x - 24 * scal, y + 24 * scal, z);			//C
	glVertex3f(x, y + 24 * scal, z);				//D
	glEnd();


	//////////////////////BASE///////////////////////////////


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(x, y, z);						//A
	glVertex3f(x, y, z + 5 * scal);				//A1
	glVertex3f(x - 24 * scal, y, z + 5 * scal);	//B1
	glVertex3f(x - 24 * scal, y, z);			//B
	glEnd();



	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.11, 0.11, 0.11);
	glVertex3f(x - 24 * scal, y, z);						//B
	glVertex3f(x - 24 * scal, y, z + 5 * scal);				//B1
	glVertex3f(x - 24 * scal, y + 24 * scal, z + 5 * scal);	//C1
	glVertex3f(x - 24 * scal, y + 24 * scal, z);			//C
	glEnd();



	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(x - 24 * scal, y + 24 * scal, z);			//C
	glVertex3f(x - 24 * scal, y + 24 * scal, z + 5 * scal);	//C1
	glVertex3f(x, y + 24 * scal, z + 5 * scal);				//D1
	glVertex3f(x, y + 24 * scal, z);						//D
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.11, 0.11, 0.11);
	glVertex3f(x, y, z);						//A
	glVertex3f(x, y, z + 5 * scal);				//A1
	glVertex3f(x, y + 24 * scal, z + 5 * scal);	//D1
	glVertex3f(x, y + 24 * scal, z);			//D
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.15, 0.15, 0.15);
	glVertex3f(x, y, z + 5 * scal);							//A1
	glVertex3f(x - 24 * scal, y, z + 5 * scal);				//B1
	glVertex3f(x - 24 * scal, y + 24 * scal, z + 5 * scal);	//C1
	glVertex3f(x, y + 24 * scal, z + 5 * scal);				//D1
	glEnd();



	////////////////////////TRINCO///////////////////////////////



	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(x - 4 * scal, y + 4 * scal, z + 5 * scal);	//A2
	glVertex3f(x - 20 * scal, y + 4 * scal, z + 5 * scal);	//B2
	glVertex3f(x - 20 * scal, y + 20 * scal, z + 5 * scal);	//C2
	glVertex3f(x - 4 * scal, y + 20 * scal, z + 5 * scal);	//D2
	glEnd();



	///////laterales del tronco



	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(x - 4 * scal, y + 4 * scal, z + 5 * scal);	//A2
	glVertex3f(x - 20 * scal, y + 4 * scal, z + 5 * scal);	//B2
	glVertex3f(x - 18 * scal, y + 6 * scal, z + 40 * scal);	//B3
	glVertex3f(x - 6 * scal, y + 6 * scal, z + 40 * scal);	//A3
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.11, 0.11, 0.11);
	glVertex3f(x - 20 * scal, y + 4 * scal, z + 5 * scal);	//B2
	glVertex3f(x - 20 * scal, y + 20 * scal, z + 5 * scal);	//C2
	glVertex3f(x - 18 * scal, y + 18 * scal, z + 40 * scal);//C3
	glVertex3f(x - 18 * scal, y + 6 * scal, z + 40 * scal);	//B3
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(x - 20 * scal, y + 20 * scal, z + 5 * scal);	//C2
	glVertex3f(x - 4 * scal, y + 20 * scal, z + 5 * scal);	//D2
	glVertex3f(x - 6 * scal, y + 18 * scal, z + 40 * scal);	//D3
	glVertex3f(x - 18 * scal, y + 18 * scal, z + 40 * scal);//C3
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.11, 0.11, 0.11);
	glVertex3f(x - 4 * scal, y + 4 * scal, z + 5 * scal);	//A2
	glVertex3f(x - 4 * scal, y + 20 * scal, z + 5 * scal);	//D2
	glVertex3f(x - 6 * scal, y + 18 * scal, z + 40 * scal);	//D3
	glVertex3f(x - 6 * scal, y + 6 * scal, z + 40 * scal);	//A3
	glEnd();


	///////////////////////////



	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.05, 0.05, 0.05);
	glVertex3f(x - 6 * scal, y + 6 * scal, z + 40 * scal);	//A3
	glVertex3f(x - 18 * scal, y + 6 * scal, z + 40 * scal);	//B3
	glVertex3f(x - 18 * scal, y + 18 * scal, z + 40 * scal);//C3
	glVertex3f(x - 6 * scal, y + 18 * scal, z + 40 * scal);	//D3
	glEnd();


	//////////////////////////DIVISION///////////////////////////////////////


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(x - 5.5 * scal, y + 5.5 * scal, z + 40 * scal);	//A4
	glVertex3f(x - 18.5 * scal, y + 5.5 * scal, z + 40 * scal);	//B4
	glVertex3f(x - 18.5 * scal, y + 18.5 * scal, z + 40 * scal);//C4
	glVertex3f(x - 5.5 * scal, y + 18.5 * scal, z + 40 * scal);	//D4
	glEnd();



	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.11, 0.11, 0.11);
	glVertex3f(x - 5.5 * scal, y + 5.5 * scal, z + 40 * scal);	//A4
	glVertex3f(x - 18.5 * scal, y + 5.5 * scal, z + 40 * scal);	//B4
	glVertex3f(x - 18.5 * scal, y + 5.5 * scal, z + 42 * scal);	//B5
	glVertex3f(x - 5.5 * scal, y + 5.5 * scal, z + 42 * scal);	//A5
	glEnd();



	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(x - 18.5 * scal, y + 5.5 * scal, z + 40 * scal);	//B4
	glVertex3f(x - 18.5 * scal, y + 18.5 * scal, z + 40 * scal);//C4
	glVertex3f(x - 18.5 * scal, y + 18.5 * scal, z + 42 * scal);//C5
	glVertex3f(x - 18.5 * scal, y + 5.5 * scal, z + 42 * scal);	//B5
	glEnd();



	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.11, 0.11, 0.11);
	glVertex3f(x - 18.5 * scal, y + 18.5 * scal, z + 40 * scal);//C4
	glVertex3f(x - 5.5 * scal, y + 18.5 * scal, z + 40 * scal);	//D4
	glVertex3f(x - 5.5 * scal, y + 18.5 * scal, z + 42 * scal);	//D5
	glVertex3f(x - 18.5 * scal, y + 18.5 * scal, z + 42 * scal);//C5
	glEnd();



	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(x - 5.5 * scal, y + 5.5 * scal, z + 42 * scal);	//A5
	glVertex3f(x - 18.5 * scal, y + 5.5 * scal, z + 42 * scal);	//B5
	glVertex3f(x - 18.5 * scal, y + 18.5 * scal, z + 42 * scal);//C5
	glVertex3f(x - 5.5 * scal, y + 18.5 * scal, z + 42 * scal);	//D5
	glEnd();


	//////////////////////////CAEBZA///////////////////////////////////////


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.11, 0.11, 0.11);
	glVertex3f(x - 6 * scal, y + 6 * scal, z + 42 * scal);	//A7
	glVertex3f(x - 18 * scal, y + 6 * scal, z + 42 * scal);	//B7
	glVertex3f(x - 18 * scal, y + 18 * scal, z + 42 * scal);//C7
	glVertex3f(x - 6 * scal, y + 18 * scal, z + 42 * scal);	//D7
	glEnd();




	///////////////////////////


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(x - 4 * scal, y + 4 * scal, z + 48 * scal);	//A6
	glVertex3f(x - 20 * scal, y + 4 * scal, z + 48 * scal);	//B6
	glVertex3f(x - 18 * scal, y + 6 * scal, z + 42 * scal);	//B7
	glVertex3f(x - 6 * scal, y + 6 * scal, z + 42 * scal);	//A7
	glEnd();




	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(x - 20 * scal, y + 4 * scal, z + 48 * scal);	//B6
	glVertex3f(x - 20 * scal, y + 20 * scal, z + 48 * scal);//C6
	glVertex3f(x - 18 * scal, y + 18 * scal, z + 42 * scal);//C7
	glVertex3f(x - 18 * scal, y + 6 * scal, z + 42 * scal);	//B7
	glEnd();




	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.11, 0.11, 0.11);
	glVertex3f(x - 20 * scal, y + 20 * scal, z + 48 * scal);//C6
	glVertex3f(x - 4 * scal, y + 20 * scal, z + 48 * scal);	//D6
	glVertex3f(x - 6 * scal, y + 18 * scal, z + 42 * scal);	//D7
	glVertex3f(x - 18 * scal, y + 18 * scal, z + 42 * scal);//C7
	glEnd();




	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(x - 4 * scal, y + 20 * scal, z + 48 * scal);	//D6
	glVertex3f(x - 4 * scal, y + 4 * scal, z + 48 * scal);	//A6
	glVertex3f(x - 6 * scal, y + 18 * scal, z + 42 * scal);	//D7
	glVertex3f(x - 6 * scal, y + 6 * scal, z + 42 * scal);	//A7
	glEnd();


	///////////////////////////


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(x - 4 * scal, y + 4 * scal, z + 48 * scal);	//A6
	glVertex3f(x - 20 * scal, y + 4 * scal, z + 48 * scal);	//B6
	glVertex3f(x - 20 * scal, y + 20 * scal, z + 48 * scal);//C6
	glVertex3f(x - 4 * scal, y + 20 * scal, z + 48 * scal);	//D6
	glEnd();


	///////////////////////////


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.11, 0.11, 0.11);
	glVertex3f(x - 12 * scal, y + 6 * scal, z + 54 * scal);	//A8.1
	glVertex3f(x - 17 * scal, y + 6 * scal, z + 54 * scal);	//B8.1
	glVertex3f(x - 20 * scal, y + 4 * scal, z + 48 * scal);	//B6
	glVertex3f(x - 11 * scal, y + 6 * scal, z + 48 * scal);	//A8.1.1
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(x - 20 * scal, y + 20 * scal, z + 48 * scal);//C6
	glVertex3f(x - 20 * scal, y + 4 * scal, z + 48 * scal);	//B6
	glVertex3f(x - 17 * scal, y + 6 * scal, z + 54 * scal);	//B8
	glVertex3f(x - 17 * scal, y + 20 * scal, z + 54 * scal);//C8
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.11, 0.11, 0.11);
	glVertex3f(x - 20 * scal, y + 20 * scal, z + 48 * scal);//C6
	glVertex3f(x - 15 * scal, y + 20 * scal, z + 48 * scal);//C8.1.1
	glVertex3f(x - 12 * scal, y + 20 * scal, z + 54 * scal);//D8.1
	glVertex3f(x - 17 * scal, y + 20 * scal, z + 54 * scal);//C8
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(x - 11 * scal, y + 6 * scal, z + 48 * scal);	//A8.1.1
	glVertex3f(x - 15 * scal, y + 20 * scal, z + 48 * scal);//C8.1.1
	glVertex3f(x - 12 * scal, y + 20 * scal, z + 54 * scal);//D8.1
	glVertex3f(x - 12 * scal, y + 6 * scal, z + 54 * scal);	//A8.1
	glEnd();


	//----------------------------------------------------



	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.11, 0.11, 0.11);
	glVertex3f(x - 10 * scal, y + 8 * scal, z + 54 * scal);	//B8.2
	glVertex3f(x - 11 * scal, y + 20 * scal, z + 48 * scal);//D8..1.1
	glVertex3f(x - 4 * scal, y + 20 * scal, z + 48 * scal);	//D6
	glVertex3f(x - 8 * scal, y + 17 * scal, z + 54 * scal);	//D8.2
	glEnd();



	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(x - 4 * scal, y + 4 * scal, z + 48 * scal);	//A6
	glVertex3f(x - 4 * scal, y + 20 * scal, z + 48 * scal);	//D6
	glVertex3f(x - 8 * scal, y + 17 * scal, z + 54 * scal);	//D8.2
	glVertex3f(x - 8 * scal, y + 8 * scal, z + 54 * scal);	//A8.2
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.11, 0.11, 0.11);
	glVertex3f(x - 8 * scal, y + 8 * scal, z + 54 * scal);	//A8.2
	glVertex3f(x - 10 * scal, y + 8 * scal, z + 54 * scal);	//B8.2
	glVertex3f(x - 11 * scal, y + 6 * scal, z + 48 * scal);	//A8.1.1
	glVertex3f(x - 4 * scal, y + 4 * scal, z + 48 * scal);	//A6
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(x - 15 * scal, y + 6 * scal, z + 48 * scal);	//B8.1.1
	glVertex3f(x - 15 * scal, y + 20 * scal, z + 48 * scal);//C8.1.1
	glVertex3f(x - 10 * scal, y + 17 * scal, z + 54 * scal);//C8.2
	glVertex3f(x - 10 * scal, y + 8 * scal, z + 54 * scal);	//B8.2
	glEnd();

	///////////////////////////

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(x - 12 * scal, y + 6 * scal, z + 54 * scal);	//A8.1
	glVertex3f(x - 17 * scal, y + 6 * scal, z + 54 * scal);	//B8.1
	glVertex3f(x - 17 * scal, y + 20 * scal, z + 54 * scal);//C8.1
	glVertex3f(x - 12 * scal, y + 20 * scal, z + 54 * scal);//D8.1
	glEnd();



	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(x - 8 * scal, y + 8 * scal, z + 54 * scal);	//A8.2
	glVertex3f(x - 10 * scal, y + 8 * scal, z + 54 * scal);	//B8.2
	glVertex3f(x - 10 * scal, y + 17 * scal, z + 54 * scal);//C8.2
	glVertex3f(x - 8 * scal, y + 17 * scal, z + 54 * scal);	//D8.2
	glEnd();

};


void Ajedrez::caballo(double x, double y, double z, double scal){
	//codigo
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(x, y, z);						//A
	glVertex3f(x - 24 * scal, y, z);				//B
	glVertex3f(x - 24 * scal, y + 24 * scal, z);			//C
	glVertex3f(x, y + 24 * scal, z);				//D
	glEnd();


	//////////////////////BASE///////////////////////////////


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(x, y, z);						//A
	glVertex3f(x, y, z + 5 * scal);				//A1
	glVertex3f(x - 24 * scal, y, z + 5 * scal);	//B1
	glVertex3f(x - 24 * scal, y, z);			//B
	glEnd();



	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(x - 24 * scal, y, z);						//B
	glVertex3f(x - 24 * scal, y, z + 5 * scal);				//B1
	glVertex3f(x - 24 * scal, y + 24 * scal, z + 5 * scal);	//C1
	glVertex3f(x - 24 * scal, y + 24 * scal, z);			//C
	glEnd();



	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(x - 24 * scal, y + 24 * scal, z);			//C
	glVertex3f(x - 24 * scal, y + 24 * scal, z + 5 * scal);	//C1
	glVertex3f(x, y + 24 * scal, z + 5 * scal);				//D1
	glVertex3f(x, y + 24 * scal, z);						//D
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(x, y, z);						//A
	glVertex3f(x, y, z + 5 * scal);				//A1
	glVertex3f(x, y + 24 * scal, z + 5 * scal);	//D1
	glVertex3f(x, y + 24 * scal, z);			//D
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(x, y, z + 5 * scal);							//A1
	glVertex3f(x - 24 * scal, y, z + 5 * scal);				//B1
	glVertex3f(x - 24 * scal, y + 24 * scal, z + 5 * scal);	//C1
	glVertex3f(x, y + 24 * scal, z + 5 * scal);				//D1
	glEnd();

	//TRONCO 
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.9, 0.7, 0.2);
	glVertex3f(x - 4 * scal, y + 4 * scal, z + 5 * scal);	//A2
	glVertex3f(x - 20 * scal, y + 4 * scal, z + 5 * scal);	//B2
	glVertex3f(x - 20 * scal, y + 20 * scal, z + 5 * scal);	//C2
	glVertex3f(x - 4 * scal, y + 20 * scal, z + 5 * scal);	//D2
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.9, 0.7, 0.2);
	glVertex3f(x - 6 * scal, y + 6 * scal, z + 29 * scal);	//A3
	glVertex3f(x - 18 * scal, y + 6 * scal, z + 29 * scal);	//B3
	glVertex3f(x - 18 * scal, y + 18 * scal, z + 29 * scal);//C3
	glVertex3f(x - 6 * scal, y + 18 * scal, z + 29 * scal);	//D3
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.9, 0.7, 0.2);
	glVertex3f(x - 4 * scal, y + 4 * scal, z + 5 * scal);	//A2
	glVertex3f(x - 20 * scal, y + 4 * scal, z + 5 * scal);	//B2
	glVertex3f(x - 18 * scal, y + 6 * scal, z + 29 * scal);	//B3
	glVertex3f(x - 6 * scal, y + 6 * scal, z + 29 * scal);	//A3
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.9, 0.7, 0.2);;
	glVertex3f(x - 20 * scal, y + 4 * scal, z + 5 * scal);	//B2
	glVertex3f(x - 20 * scal, y + 20 * scal, z + 5 * scal);	//C2
	glVertex3f(x - 18 * scal, y + 18 * scal, z + 29 * scal);//C3
	glVertex3f(x - 18 * scal, y + 6 * scal, z + 29 * scal);	//B3
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.9, 0.7, 0.2);
	glVertex3f(x - 20 * scal, y + 20 * scal, z + 5 * scal);	//C2
	glVertex3f(x - 4 * scal, y + 20 * scal, z + 5 * scal);	//D2
	glVertex3f(x - 6 * scal, y + 18 * scal, z + 29 * scal);	//D3
	glVertex3f(x - 18 * scal, y + 18 * scal, z + 29 * scal);//C3
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.9, 0.7, 0.2);
	glVertex3f(x - 4 * scal, y + 20 * scal, z + 5 * scal);	//D2
	glVertex3f(x - 4 * scal, y + 4 * scal, z + 5 * scal);	//A2
	glVertex3f(x - 6 * scal, y + 6 * scal, z + 29 * scal);	//A3
	glVertex3f(x - 6 * scal, y + 18 * scal, z + 29 * scal);	//D3
	glEnd();


	//PECHO

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.9, 0.7, 0.2);
	glVertex3f(x - 15 * scal, y + 23 * scal, z + 15 * scal);//C2.1
	glVertex3f(x - 9 * scal, y + 23 * scal, z + 15 * scal);	//D2.1
	glVertex3f(x - 9 * scal, y + 23 * scal, z + 24 * scal);	//D3.1
	glVertex3f(x - 15 * scal, y + 23 * scal, z + 24 * scal);//C3.1
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.9, 0.7, 0.2);
	glVertex3f(x - 20 * scal, y + 20 * scal, z + 5 * scal);	//C2
	glVertex3f(x - 4 * scal, y + 20 * scal, z + 5 * scal);	//D2
	glVertex3f(x - 9 * scal, y + 23 * scal, z + 15 * scal);	//D2.1
	glVertex3f(x - 15 * scal, y + 23 * scal, z + 15 * scal);//C2.1
	glEnd();



	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.9, 0.7, 0.2);
	glVertex3f(x - 4 * scal, y + 20 * scal, z + 5 * scal);	//D2
	glVertex3f(x - 6 * scal, y + 18 * scal, z + 29 * scal);	//D3
	glVertex3f(x - 9 * scal, y + 23 * scal, z + 24 * scal);	//D3.1
	glVertex3f(x - 9 * scal, y + 23 * scal, z + 15 * scal);	//D2.1
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.9, 0.7, 0.2);
	glVertex3f(x - 6 * scal, y + 18 * scal, z + 29 * scal);	//D3
	glVertex3f(x - 18 * scal, y + 18 * scal, z + 29 * scal);//C3
	glVertex3f(x - 15 * scal, y + 23 * scal, z + 24 * scal);//C3.1
	glVertex3f(x - 9 * scal, y + 23 * scal, z + 24 * scal);	//D3.1
	glEnd();



	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.9, 0.7, 0.2);
	glVertex3f(x - 20 * scal, y + 20 * scal, z + 5 * scal);	//C2
	glVertex3f(x - 18 * scal, y + 18 * scal, z + 29 * scal);//C3
	glVertex3f(x - 15 * scal, y + 23 * scal, z + 24 * scal);//C3.1
	glVertex3f(x - 15 * scal, y + 23 * scal, z + 15 * scal);//C2.1
	glEnd();
};

