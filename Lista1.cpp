#include"Lista1.h"

ListaSimple::ListaSimple()
{
	cabeza = NULL;
}

int ListaSimple::estaVacia()
{
	if (cabeza == NULL)
		return 1;
	else
		return 0;
}

void ListaSimple::InsertarInicio(int d)
{
	Nodo1* nuevo = new Nodo1(d);
	nuevo->setEnlace(cabeza);
	cabeza = nuevo;
}

void ListaSimple::InsertarFinal(int d)
{
	Nodo1*nuevo = new Nodo1(d);
	if (cabeza == NULL)
		InsertarInicio(d);
	else
	{
		Nodo1* aux = cabeza;
		while (aux->getEnlace() != NULL)
			aux = aux->getEnlace();
		aux->setEnlace(nuevo);
		aux = nuevo;
	}
}

void ListaSimple::InsertarEntreNodos()
{
	int dato;
	Nodo1* actual = cabeza;
	bool encontrado = false;
	cout << "Ingrese dato despues de: ";
	cin >> dato;
	while ((actual != NULL) && (!encontrado))
	{
		encontrado = (actual->getDato() == dato);
		if (!encontrado)
			actual = actual->getEnlace();
	}
	if (encontrado == false)
		cout << "Elemento no encontrado";
	else
	{
		int d = 0;
		cout << "Da el Numero a insertar despues de " << dato << " : ";
		cin >> d;
		Nodo1* nuevo = new Nodo1(d);
		nuevo->setEnlace(actual->getEnlace());
		actual->setEnlace(nuevo);
	}
}

void ListaSimple::BuscarNodo(int d)
{
	Nodo1* actual = cabeza;
	bool encontrado = false;
	while ((actual != NULL))
	{
		encontrado = (actual->getDato() == d);
		actual = actual->getEnlace();
	}
	if (encontrado == false)
		cout << "El elemento no fue encontrado";
	else
		cout << "El elemento fue encontrado";
}

int ListaSimple::TamanioLista()
{
	Nodo1* pNodo = cabeza;
	int iContador = 0;

	while (pNodo != NULL)
	{
		iContador++;
		pNodo = pNodo->getEnlace();
	}
	cout << "Numeros guardados actualmente: ";
	return iContador;

}

void ListaSimple::Eliminar(int d)
{
	Nodo1 *actual, *anterior;
	bool encontrado;
	actual = cabeza;
	anterior = NULL;
	encontrado = false;
	// búsqueda del nodo y del anterior
	while ((actual != NULL) && !encontrado)
	{
		encontrado = (actual->getDato() == d);
		if (!encontrado)
		{
			anterior = actual;
			actual = actual->getEnlace();
		}
	}
	if (encontrado == false)
		cout << "El elemento no fue encontrado\n\n";

	// enlace del nodo anterior con el siguiente
	if (actual != NULL)
	{
		// distingue entre cabecera y resto de la lista
		if (actual == cabeza)
		{
			cabeza = actual->getEnlace();
		}
		else
		{
			anterior->setEnlace(actual->getEnlace());
		}
		delete actual;
	}
}

void ListaSimple::Imprimir()
{
	Nodo1*nuevo = cabeza;
	cout << "||";
	while (nuevo != NULL)
	{
		cout << nuevo->getDato() << "||";
		nuevo = nuevo->getEnlace();
	}
}
