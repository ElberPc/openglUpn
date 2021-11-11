#include<GL/glew.h>
#include<GL/freeglut.h>
#include<math.h>
#include<fstream>
#include<assert.h>
#include"ajedrez.h"


double PI = 3.1415926535897932384626433832795;
double rt_x = -45.0, rt_y = 0.0, rt_z = -18.0;
//scal isometric
double scal = 1.0 / 100.0;
double rt = 0.5;
//start isometric
double xx = 0.0, yy = 0.0, zz = 0.0;
double pas = 0.01;


void keyboard(unsigned char key, int x, int y){
	switch (key)
	{
	case 'w':{if (yy + 10 * scal<0.99) yy += pas; } break;
	case 's':{if (yy >-1.0)yy -= pas; } break;
	case 'a':{if (xx - 10 * scal>-0.99)xx -= pas; } break;
	case 'd':{if (xx <1.00)xx += pas; }break;
	case 'f':{zz -= pas; }break;
	case 'r':{zz += pas; }break;
	case '-':{scal = scal - 0.01; }break;
	case '+':{scal = scal + 0.01; }break;
	}

	glutPostRedisplay();
}

void specialKeys(int key, int x, int y){
	if (key == GLUT_KEY_RIGHT)rt_z += rt;
	else if (key == GLUT_KEY_LEFT)rt_z -= rt;
	else if (key == GLUT_KEY_UP)rt_x += rt;
	else if (key == GLUT_KEY_DOWN)rt_x -= rt;
	else if (key == GLUT_KEY_F1)rt_y -= rt;
	else if (key == GLUT_KEY_F2)rt_y -= rt;

	glutPostRedisplay();
}

void render(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.8, 0.8, 0.8, 0.0);
	glViewport(50, 100, 800, 600);

	glLoadIdentity();

	glRotatef(rt_x*PI, 1.0, 0.0, 0.0);
	glRotatef(rt_y*PI, 0.0, 1.0, 0.0);
	glRotatef(rt_z*PI, 0.0, 0.0, 1.0);
	double x = xx, y = yy, z = zz;
	
	//pintar ejemplo

	//Ajedrez::ejemplo(xx,yy,zz,scal,1);

	//pintar tablero

	Ajedrez::tablero(xx, yy, zz, 1.0/180.0,0);

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

	//Ajedrez::reina(xx, yy, zz, scal,0);

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
	Ajedrez::caballo(-0.28,-0.52, zz, 1.0 / 220.0, 1);
	Ajedrez::caballo(0.39, -0.52, zz, 1.0 / 220.0, 1);
	
	glutSwapBuffers();
}

void main(int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Tablero Ajedrez");
	Ajedrez::initrender();
	glutDisplayFunc(render);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeys);
	glutMainLoop();
}