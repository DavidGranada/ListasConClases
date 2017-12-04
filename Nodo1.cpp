#include"Nodo1.h"

Nodo1::Nodo1(int d)
{
	dato = d;
	enlace = NULL;
}
int Nodo1::getDato()
{
	return dato;
}
Nodo1* Nodo1::getEnlace()
{
	return enlace;
}
void Nodo1::setDato(int d)
{
	dato = d;
}
void Nodo1::setEnlace(Nodo1* n)
{
	enlace = n;
}