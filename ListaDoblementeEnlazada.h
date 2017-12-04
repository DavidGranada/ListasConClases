#pragma once
#include "Nodo2.h"
#include <conio.h>
#include <iostream>
using namespace std;

class ListaDoblementeEnlazada
{
private:
	Nodo2 *cabeza;
public:
	ListaDoblementeEnlazada();
	void InsertarInicio(int d);
	void InsertarFinal(int d);
	void InsertarEntreNodos();
	void Eliminar(int dato);
	void Imprimir();
	void BuscarNodo(int dato);
	int TamanioLista();
	int estaVacia();
};
