#include<GL/glew.h>
#include<GL/freeglut.h>
#include<math.h>
#include<fstream>
#include<assert.h>
#include"ajedrez.h"
#include"engine.h"
#include <string>

double PI = 3.1415926535897932384626433832795;
double rt_x = -45.0, rt_y = 0.0, rt_z = -18.0;
double scal = 1.0 / 100.0;
double rt = 0.5;
double xx = 0.0, yy = 0.0, zz = 0.0;
double pas = 0.01;

//config varibles
int showBoard = 0;
int option = 0;
int nivel = 0;
int timerState = 0;
int movements;
int step = 1;
int vrt = 0;
int win = 0;
//nivel1 varibales
double xTW = -0.28, yTW = -0.52;
double xTW2 = 0.39, yTW2 = 0.41;
double xTW3 = 0.39, yTW3 = -0.52;
int sup = 0;


//rotar 
void specialKeys(int key, int x, int y){
	if (key == GLUT_KEY_RIGHT)rt_z += rt;
	else if (key == GLUT_KEY_LEFT)rt_z -= rt;
	else if (key == GLUT_KEY_UP)rt_x += rt;
	else if (key == GLUT_KEY_DOWN)rt_x -= rt;
	else if (key == GLUT_KEY_F1)rt_y -= rt;
	else if (key == GLUT_KEY_F2)rt_y -= rt;

	glutPostRedisplay();
}



//timer 
void timerChess(int value){
	//Button green
	if (timerState == 1 && option == 1){
		if (nivel == 1 && step == 1){
			if (xTW <= -0.01){
				xTW += 0.01;
			}
			else if (xTW3 >= -0.02){
				xTW3 -= 0.01;
			}
			else{
				sup = 1;
				step = 2;
				timerState = 0;
				option = 0;

			}
		}
		else if (nivel == 1 && step == 2){
			if (yTW2 >= -0.38){
				yTW2 -= 0.01;
			}
			else if (yTW3 <= 0.02){
				yTW3 += 0.01;
			}
			else{
				step = 3;
				timerState = 0;
				option = 0;
				vrt = 2;
			}
		}
		else if (nivel == 1 && step == 3 && vrt == 1){
			if (yTW2 >= -0.520){
				yTW2 -= 0.01;
			}
			else{
				step = 4;
				timerState = 0;
				option = 0;
			}
		}
		else if (nivel == 1 && step == 3 && vrt == 2){
			if (xTW2 <= 0.515){
				xTW2 += 0.01;
			}
			else{
				win += 1;
				step = 4;
				timerState = 0;
				option = 0;
			}
		}
	}
	//Button red
	else if (timerState == 1 && option==2){
		if (nivel == 1 && step == 1){
			if (yTW <= -0.39){
				yTW += 0.01;
			}
			else if (xTW3 >= -0.02){
				xTW3 -= 0.01;
			}
			else{
				win += 1;
				step = 2;
				timerState = 0;
				option = 0;

			}
		}
		else if (nivel == 1 && step == 2){
			if (xTW2 >= 0.13){
				xTW2 -= 0.01;
			}
			else if (yTW3 <= 0.02){
				yTW3 += 0.01;
			}
			else{
				win += 1;
				step = 3;
				timerState = 0;
				option = 0;
				vrt = 1;

			}
		}
		else if (nivel == 1 && step == 3 && vrt == 1){
			if (xTW2 >= -0.15){
				xTW2 -= 0.01;
			}
		    else{
				step = 4;
				timerState = 0;
				option = 0;
			}
		}
		else if (nivel == 1 && step == 3 && vrt == 2){
			if (yTW2 >= -0.520){
				yTW2 -= 0.01;
			}
			else{
				step = 4;
				timerState = 0;
				option = 0;
			}
		}
	}

	glutPostRedisplay();
	glutTimerFunc(5, timerChess, 0);
}

//drawScene
void render(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.4, 0.4, 0.4, 0.0);
	glViewport(50, 100, 800, 600);

	glLoadIdentity();

	glRotatef(rt_x*PI, 1.0, 0.0, 0.0);
	glRotatef(rt_y*PI, 0.0, 1.0, 0.0);
	glRotatef(rt_z*PI, 0.0, 0.0, 1.0);
	double x = xx, y = yy, z = zz;

	switch (nivel)
	{
	case 0: Engine::origin(xx, yy, zz, scal); break;
	case 1: Engine::levelOne(xx, yy, zz, scal, xTW, yTW, xTW2, yTW2, xTW3, yTW3, step, vrt, sup); break;
	default:
		break;
	}


	glutSwapBuffers();
}

//funcion main Opengl
void main2(int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(800, 700);
	glutCreateWindow("Tablero Ajedrez");
	Ajedrez::initrender();
	glutDisplayFunc(render);
	glutSpecialFunc(specialKeys);
	glutTimerFunc(5, timerChess, 0);
	glutMainLoop();
}

#include "controlForm.h"
using namespace openglUpn;
//funcion main Form
void main(int argc, char *argv[]){
	Application::EnableVisualStyles();
	Application::Run(gcnew controlForm);
}

