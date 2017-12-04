#pragma once
#include"Nodo1.h"

class ListaSimple
{
private:
	Nodo1* cabeza;
public:
	ListaSimple();
	int estaVacia();
	void InsertarInicio(int d);
	void InsertarFinal(int d);
	void InsertarEntreNodos();
	void BuscarNodo(int d);
	int TamanioLista();
	void Eliminar(int d);
	void Imprimir();

};
