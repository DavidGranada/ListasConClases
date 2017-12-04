#include"ListaDoblementeEnlazada.h"

ListaDoblementeEnlazada::ListaDoblementeEnlazada()
{
	cabeza = NULL;
}

void ListaDoblementeEnlazada::InsertarInicio(int d)
{
	Nodo2* nuevo = new Nodo2(d);
	nuevo->setSiguiente(cabeza);
	if (cabeza != NULL)
		cabeza->setAnterior(nuevo);
	cabeza = nuevo;
}

void ListaDoblementeEnlazada::InsertarFinal(int d)
{
	Nodo2* nuevo = new Nodo2(d);
	if (cabeza == NULL)
		InsertarInicio(d);
	else
	{
		Nodo2 *aux = cabeza;
		while (aux->getSiguiente() != NULL)
			aux = aux->getSiguiente();
		aux->setSiguiente(nuevo);
		nuevo->setAnterior(aux);
		aux = nuevo;
	}
}

void ListaDoblementeEnlazada::InsertarEntreNodos()
{
	int dato;
	Nodo2* actual = cabeza;
	bool encontrado = false;
	cout << "\nIngrese dato despues de: ";
	cin >> dato;
	while ((actual != NULL) && (!encontrado))
	{
		encontrado = (actual->getDato() == dato);
		if (!encontrado)
			actual = actual->getSiguiente();
	}
	if (encontrado == false)
		cout << "Elemento no encontrado";
	else
	{
		int d = 0;
		cout << "Da el Numero a insertar despues de " << dato << " : ";
		cin >> d;
		Nodo2* nuevo = new Nodo2(d);
		nuevo->setSiguiente(actual->getSiguiente());
		actual->setSiguiente(nuevo);
		actual = actual->getSiguiente();
		nuevo->setAnterior(actual->getAnterior());
		actual->setAnterior(nuevo);
		actual = nuevo;
	}
}

void ListaDoblementeEnlazada::Eliminar(int dato)
{
	Nodo2* actual;
	bool encontrado = false;
	actual = cabeza;
	// Bucle de búsqueda
	while ((actual != NULL) && (!encontrado))
	{
		encontrado = (actual->getDato() == dato);
		if (!encontrado)
			actual = actual->getSiguiente();
	}
	if (encontrado == false)
		cout << "Elemento no encontrado";
	// Enlace de nodo anterior con el siguiente
	if (actual != NULL)
	{
		//distingue entre nodo cabecera o resto de la lista
		if (actual == cabeza)
		{
			cabeza = actual->getSiguiente();
			if (actual->getSiguiente() != NULL)
				actual->getSiguiente()->setAnterior(NULL);
		}
		else if (actual->getSiguiente() != NULL) // No es el último
		{
			actual->getAnterior()->setSiguiente(actual->getSiguiente());
			actual->getSiguiente()->setAnterior(actual->getAnterior());
		}
		else // último nodo
			actual->getAnterior()->setSiguiente(NULL);
	}
}

void ListaDoblementeEnlazada::Imprimir()
{
	Nodo2* pNodo2 = cabeza;
	int n = 0;
	cout << "|| ";
	while (pNodo2 != NULL)
	{
		cout << pNodo2->getDato() << " || ";
		pNodo2 = pNodo2->getSiguiente();
	}
}

void ListaDoblementeEnlazada::BuscarNodo(int dato)
{
	Nodo2* actual = cabeza;
	bool encontrado = false;
	while ((actual != NULL) && (!encontrado))
	{
		encontrado = (actual->getDato() == dato);
		if (!encontrado)
			actual = actual->getSiguiente();
	}
	if (encontrado == false)
		cout << "El elemento no fue encontrado";
	else
		cout << "El elemento fue encontrado";
}

int ListaDoblementeEnlazada::TamanioLista() //Crea un puntero y lo iguala al nodo siguiente de inicio. Crea //un contador=0. Inicia un ciclo: “mientras que el puntero sea diferente que la //dirección del nodo final” y aumenta al contador en 1 y avanza un nodo hacia //adelante
{
	Nodo2* pNodo2 = cabeza;
	int iContador = 0;

	while (pNodo2 != NULL)
	{
		iContador++;
		pNodo2 = pNodo2->getSiguiente();
	}
	cout << "Numeros guardados actualmente: ";
	return iContador;

}

int ListaDoblementeEnlazada::estaVacia()
{
	if (cabeza == NULL)
		return 1;
	else
		return 0;
}