#include"Nodo2.h"

Nodo2::Nodo2(int d)
{
	dato = d;
	siguiente = NULL;
	anterior = NULL;
}
int Nodo2::getDato()
{
	return dato;
}
Nodo2* Nodo2::getSiguiente()
{
	return siguiente;
}
Nodo2* Nodo2::getAnterior()
{
	return anterior;
}
void Nodo2::setDato(int d)
{
	dato = d;
}
void Nodo2::setSiguiente(Nodo2* s)
{
	siguiente = s;
}
void Nodo2::setAnterior(Nodo2* a)
{
	anterior = a;
}
