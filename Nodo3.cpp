#include"Nodo3.h"

Nodo3::Nodo3(int d)
{
	dato = d;
	enlace = this;
}
int Nodo3::getDato()
{
	return dato;
}
Nodo3* Nodo3::getEnlace()
{
	return enlace;
}
void Nodo3::setDato(int d)
{
	dato = d;
}
void Nodo3::setEnlace(Nodo3* n)
{
	enlace = n;
}