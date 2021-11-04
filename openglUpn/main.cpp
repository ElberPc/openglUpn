#include<GL/glew.h>
#include<GL/freeglut.h>
#include<math.h>
#include<fstream>
#include<assert.h>
//#include"textura.h"
#include"ajedrez.h"


double PI = 3.1415926535897932384626433832795;
double rt_x = -15.0, rt_y = 0.0, rt_z = -15.0;
//scal isometric
double scal = 1.0 / 100.0;
double rt = 0.5;
//start isometric
double xx = 0.5, yy = -0.4, zz = 0.0;
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
	glClearColor(1.0, 1.0, 1.0, 0.0);
	//glViewport(100, 10, 500, 500);
	glLoadIdentity();
	//glEnable(GL_TEXTURE_2D);
	//glBindTexture(GL_TEXTURE_2D, ID_de_Textura1);
	//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

	glRotatef(rt_x*PI, 1.0, 0.0, 0.0);
	glRotatef(rt_y*PI, 0.0, 1.0, 0.0);
	glRotatef(rt_z*PI, 0.0, 0.0, 1.0);
	double x = xx, y = yy, z = zz;
	
	//pintar ejemplo

	//Ajedrez::ejemplo(xx,yy,zz,scal);

	//pintar tablero

	//Ajedrez::tablero(xx, yy, zz, scal);

	//pintar torre

	//Ajedrez::torre(xx, yy, zz, scal);

	//pintar peon
	
	//Ajedrez::peon(xx, yy, zz, scal);

	//pintar alfil

	//Ajedrez::alfil(xx, yy, zz, scal);

	//pintar reina

	//Ajedrez::reina(xx, yy, zz, scal);

	//pintar rey

	//Ajedrez::rey(xx, yy, zz, scal);

	//pintar caballo

	//Ajedrez::caballo(xx, yy, zz, scal);
	
	
	glutSwapBuffers();
}

void main(int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Tablero Ajedrez");
	//initRendering();
	glutDisplayFunc(render);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeys);
	glutMainLoop();
}