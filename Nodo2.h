#pragma once
#include<iostream>
#include<conio.h>

using namespace std;

class Nodo2
{
private:
	int dato;
	Nodo2 *siguiente;
	Nodo2 *anterior;
public:
	Nodo2(int d);
	int getDato();
	Nodo2* getSiguiente();
	Nodo2* getAnterior();
	void setDato(int d);
	void setSiguiente(Nodo2* s);
	void setAnterior(Nodo2* a);
};