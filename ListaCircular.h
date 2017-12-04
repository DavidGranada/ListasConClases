#pragma once
#include"Nodo3.h"

class ListaCircular
{
private:
	Nodo3* cabeza;
public:
	ListaCircular();
	int estaVacia();
	void Insertar(int d);
	void InsertarEntreNodos();
	void BuscarNodo(int d);
	int TamanioLista();
	void Eliminar(int d);
	void Imprimir();
};