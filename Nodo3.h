#pragma once
#include<iostream>
#include<conio.h>

using namespace std;

class Nodo3
{
private:
	int dato;
	Nodo3* enlace;
public:
	Nodo3(int d);
	int getDato();
	Nodo3* getEnlace();
	void setDato(int d);
	void setEnlace(Nodo3* n);
};
