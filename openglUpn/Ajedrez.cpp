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