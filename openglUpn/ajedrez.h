#pragma once

//clase ajedrez 

class Ajedrez
{
public:
	static void ejemplo(double x, double y, double z, double scal, int texture);
	//tablero funcion
	static void tablero(double x, double y, double z, double scal, int texture);
	//torre funcion
	static void torre(double x, double y, double z, double scal, int texture);
	//peon funcion
	static void peon(double x, double y, double z, double scal, int texture);
	//reina funcion
	static void reina(double x, double y, double z, double scal, int texture);
	//rey funcion
	static void rey(double x, double y, double z, double scal, int texture);
	//alfil funcion
	static void alfil(double x, double y, double z, double scal, int texture);
	//caballo funcion
	static void caballo(double x, double y, double z, double scal, int texture);
	//rende textura
	static void initrender();
private:

};