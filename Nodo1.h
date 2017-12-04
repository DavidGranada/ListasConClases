#pragma once
#include<iostream>
#include<conio.h>

using namespace std;

class Nodo1
{
private:
	int dato;
	Nodo1 *enlace;
public:
	Nodo1(int d);
	int getDato();
	void setDato(int d);

	Nodo1* getEnlace();
	void setEnlace(Nodo1* n);
};