/*
=======================================================
UNIVERSIDAD DE LAS FUERZAS ARMADAS - "ESPE"
=======================================================
Departamento Ciencias De La Computación
=======================================================
Tema:			LISTAS
Carrera:		Ingeniería en Sistemas
Docente:		Ing. Fernando Solis
Integrantes:	Granada David
Conejo Ivan
Francisco Sampedro
=======================================================
Fecha Creación:		04/12/2017
Fecha Modificación:	04/12/2017
=======================================================
MENU LISTA SIMPLE DOBLE CIRCULAR CON CLASES
=======================================================
*/

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>
#include "validacion.h"
#include "ListaCircular.h"
#include "ListaDoblementeEnlazada.h"
#include "Lista1.h"

using namespace std;

void menuPrincipal();
void menuls();
void menuld();
void menuc();

void DrawBitmap(HDC hdcDest, char* filename, int x, int y);
void imagen();


HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

COORD CursorPosition;
void gotoXY(int, int);

void portada() {
	system("color 2F");
	cout << "\t\t**********************************************\n";
	cout << "\t\t   ++++++++++  ++++++++   ++++++++  ++++++++\n"; Sleep(100);
	cout << "\t\t   ++++++++++  ++++++++   ++++++++  ++++++++\n"; Sleep(100);
	cout << "\t\t   ++          ++         ++    ++  ++      \n"; Sleep(100);
	cout << "\t\t   ++++++++++  ++++++++   ++++++++  ++++++++\n"; Sleep(100);
	cout << "\t\t   ++++++++++  ++++++++   ++        ++++++++\n"; Sleep(100);
	cout << "\t\t   ++                ++   ++        ++      \n"; Sleep(100);
	cout << "\t\t   ++++++++++  ++++++++   ++        ++++++++\n"; Sleep(100);
	cout << "\t\t   ++++++++++  ++++++++   ++        ++++++++\n"; Sleep(100);
	cout << "\t\t**********************************************\n";
	cout << endl;
	cout << endl;
	_getch();
	system("cls");
}
void DrawBitmap(HDC hdcDest, char *filename, int x, int y)
{
	HBITMAP image;
	BITMAP bm;
	HDC hdcMem;
	image = (HBITMAP)LoadImage(0, filename, IMAGE_BITMAP, 600, 400, LR_LOADFROMFILE);
	GetObject(image, sizeof(BITMAP), &bm);
	hdcMem = CreateCompatibleDC(hdcDest);
	SelectObject(hdcMem, image);
	BitBlt(
		hdcDest,
		x, y,
		bm.bmWidth, bm.bmHeight,
		hdcMem,
		0, 0,
		SRCCOPY);
	/*TransparentBlt ( hdcDest,
	x, y,
	bm.bmWidth, bm.bmHeight,
	hdcMem,
	0, 0,bm.bmWidth, bm.bmHeight,GetPixel(a,0,0) );*/
	DeleteDC(hdcMem);
	DeleteObject((HBITMAP)image);
}
void imagen() {
	HWND foco;
	HDC  a;
	foco = GetForegroundWindow();
	a = GetDC(foco);
	HBRUSH b;
	HPEN c;
	fflush(stdin);
	do
	{
		//backcolor(RED);
		system("cls");
		//DrawBitmap(a, "espe.bmp", 0, 0);
		DrawBitmap(a, "espe.BMP", 400, 100);
		c = CreatePen(PS_DOT, 1, RGB(255, 0, 0));
		SelectObject(a, c);
		b = CreateHatchBrush(HS_CROSS, RGB(255, 0, 0));
		SelectObject(a, b);
		//SelectObject( a, CreateSolidBrush(RGB(0,255,0)));

		//	Rectangle(a, 100, 0, 150, 50);
		//apidoevents();
	} while (!(GetAsyncKeyState(VK_RETURN) & 0x8000));
	DeleteObject(c);
	DeleteObject(b);
	fflush(stdin);
	_getch();
	ReleaseDC(foco, a);
}
void color(int a, int b)
{
	int color = (a * 16) + b;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void gotoXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}
void menuls()
{
	Nodo1 *n = NULL;
	ListaSimple Lista;
	int opc;
	int num;
	do
	{
		system("cls");
		cout << "\n";
		cout << "\n\tMENU LISTA SIMPLE ENLAZADA\n" << endl;
		cout << "[1] Insertar al inicio" << endl;
		cout << "[2] Insertar al final" << endl;
		cout << "[3] Insertar entre nodos" << endl;
		cout << "[4] Numero de elementos insertados" << endl;
		cout << "[5] Imprimir" << endl;
		cout << "[6] Eliminar dato" << endl;
		cout << "[7] Buscar dato" << endl;
		cout << "[8] Salir" << endl << endl;
		cout << "Opcion: ";
		cin >> opc;
		cout << endl;

		switch (opc)
		{
		case 1:
		{
			if (Lista.estaVacia())
				cout << "La lista esta vacia, ingrese valores" << endl << endl;
			cout << endl << "Ingrese un nuevo valor: ";
			cin >> num;
			Lista.InsertarInicio(num);
			cout << "Ha insertado el valor: " << num;
			cout << endl << endl << "Lista actual:" << endl;
			Lista.Imprimir();
			cout << endl;
			_getch();
		}break;

		case 2:
		{
			if (Lista.estaVacia())
				cout << "La lista esta vacia, ingrese valores" << endl << endl;
			cout << endl << "Ingrese un nuevo valor: ";
			cin >> num;
			Lista.InsertarFinal(num);
			cout << "Ha insertado el valor: " << num;
			cout << endl << endl << "Lista actual:" << endl;
			Lista.Imprimir();
			cout << endl;
			_getch();

		}break;

		case 3:
		{
			if (Lista.estaVacia())
				cout << "La lista esta vacia, no hay valores antes.!" << endl << endl;
			else
			{
				Lista.Imprimir();
				cout << endl << endl;
				Lista.InsertarEntreNodos();
				cout << endl << endl << "Lista actual:" << endl;
				Lista.Imprimir();
				cout << endl;
			}
			_getch();

		}break;

		case 4:
		{
			if (Lista.estaVacia())
				cout << "La lista esta vacia..." << endl << endl;
			cout << Lista.TamanioLista() << endl << endl;
			cout << "Verificando..." << endl;
			cout << "Esta es la lista:" << endl;
			Lista.Imprimir();
			_getch();
		}
		break;

		case 5:
		{
			if (Lista.estaVacia())
				cout << "La lista esta vacia..." << endl << endl;
			else
				Lista.Imprimir();
			_getch();
		}
		break;

		case 6:
		{
			if (Lista.estaVacia())
				cout << "La lista esta vacia..." << endl << endl;
			else
			{
				cout << endl << "Lista actual:" << endl;
				Lista.Imprimir();
				cout << endl;
				cout << endl << "Ingrese el valor a eliminar: ";
				cin >> num;
				Lista.Eliminar(num);
				cout << "La nueva lista es:" << endl;
				Lista.Imprimir();
			}
			_getch();
		}break;
		case 7:
		{
			if (Lista.estaVacia())
				cout << "La lista esta vacia..." << endl << endl;
			else
			{
				cout << "Ingrese dato a buscar: ";
				cin >> num;
				Lista.BuscarNodo(num);
				cout << endl << endl;;
				cout << "Verificando..." << endl;
				cout << "Esta es la lista:" << endl;
				Lista.Imprimir();
			}
			_getch();
		}break;
		case 8:
		{
			menuPrincipal();
		}break;
		default:
		{
			cout << endl << "Opcion no Valida";
			_getch();
		}break;
		}
		cout << endl;
	} while (opc != 8);
}
void menuld()
{
	Nodo2 *n = NULL;
	ListaDoblementeEnlazada Lista;
	int opc, band = 0;
	int num;
	do
	{
		do {
			try {

				system("cls");
				cout << "\n";
				cout << "\n\tMENU LISTAS DOBLEMENTE ENLAZADAS\n" << endl;
				cout << "[1] Insertar al inicio" << endl;
				cout << "[2] Insertar al final" << endl;
				cout << "[3] Insertar entre nodos" << endl;
				cout << "[4] Numero de elementos insertados" << endl;
				cout << "[5] Imprimir" << endl;
				cout << "[6] Eliminar dato" << endl;
				cout << "[7] Buscar dato" << endl;
				cout << "[8] Salir" << endl << endl;
				cout << "Opcion: ";
				cin >> opc;
				cout << endl;

				switch (opc)
				{
				case 1:
				{
					if (Lista.estaVacia())
						cout << "La lista esta vacia, ingrese valores" << endl << endl;
					cout << endl << "Ingrese un nuevo valor: ";
					cin >> num;
					Lista.InsertarInicio(num);
					cout << "Ha insertado el valor: " << num;
					cout << endl << endl << "Lista actual:" << endl;
					Lista.Imprimir();
					cout << endl;
					_getch();
				}break;

				case 2:
				{
					if (Lista.estaVacia())
						cout << "La lista esta vacia, ingrese valores" << endl << endl;
					cout << endl << "Ingrese un nuevo valor: ";
					cin >> num;
					Lista.InsertarFinal(num);
					cout << "Ha insertado el valor: " << num;
					cout << endl << endl << "Lista actual:" << endl;
					Lista.Imprimir();
					cout << endl;
					_getch();

				}break;

				case 3:
				{
					if (Lista.estaVacia())
						cout << "La lista esta vacia, no hay valores antes.!" << endl << endl;
					else
					{
						Lista.Imprimir();
						Lista.InsertarEntreNodos();
						cout << endl << endl << "Lista actual:" << endl;
						Lista.Imprimir();
						cout << endl;
					}
					_getch();

				}break;

				case 4:
				{
					if (Lista.estaVacia())
						cout << "La lista esta vacia..." << endl << endl;
					cout << Lista.TamanioLista() << endl << endl;
					cout << "Verificando..." << endl;
					cout << "Esta es la lista:" << endl;
					Lista.Imprimir();
					_getch();
				}
				break;

				case 5:
				{
					if (Lista.estaVacia())
						cout << "La lista esta vacia..." << endl << endl;
					else
						Lista.Imprimir();
					_getch();
				}
				break;

				case 6:
				{
					if (Lista.estaVacia())
						cout << "La lista esta vacia..." << endl << endl;
					else
					{
						cout << endl << "Lista actual:" << endl;
						Lista.Imprimir();
						cout << endl;
						cout << endl << "Ingrese el valor a eliminar: ";
						cin >> num;
						Lista.Eliminar(num);
						cout << "La nueva lista es:" << endl;
						Lista.Imprimir();
					}
					_getch();
				}break;
				case 7:
				{
					if (Lista.estaVacia())
						cout << "La lista esta vacia..." << endl << endl;
					else
					{
						cout << "Ingrese dato a buscar: ";
						cin >> num;
						Lista.BuscarNodo(num);
						cout << endl << endl;;
						cout << "Verificando..." << endl;
						cout << "Esta es la lista:" << endl;
						Lista.Imprimir();
					}
					_getch();
				}break;
				case 8:
				{
					menuPrincipal();
				}break;
				default:
				{
					cout << endl << "Opcion no Valida";
					_getch();
				}break;
				}
				band = 0;
			}
			catch (exception e) {
				cout << endl << "Ingrese solo numeros";
				band = 1;

			}
		} while (band == 1);
		cout << endl;
	} while (opc != 8);

	_getch();
	system("pause");

}
void menuc()
{
	Nodo3 *n = NULL;
	ListaCircular Lista;
	int opc;
	int num;
	do
	{
		system("cls");
		cout << "\n";
		cout << "\n\tMENU LISTAS CIRCULARES\n" << endl;
		cout << "[1] Insertar al inicio" << endl;
		cout << "[2] Insertar entre nodos" << endl;
		cout << "[3] Numero de elementos insertados" << endl;
		cout << "[4] Imprimir" << endl;
		cout << "[5] Eliminar dato" << endl;
		cout << "[6] Buscar dato" << endl;
		cout << "[7] Salir" << endl << endl;
		cout << "Opcion: ";
		cin >> opc;
		cout << endl;

		switch (opc)
		{
		case 1:
		{
			if (Lista.estaVacia())
				cout << "La lista esta vacia, ingrese valores" << endl << endl;
			cout << endl << "Ingrese un nuevo valor: ";
			cin >> num;
			Lista.Insertar(num);
			cout << "Ha insertado el valor: " << num;
			cout << endl << endl << "Lista actual:" << endl;
			Lista.Imprimir();
			cout << endl;
			_getch();
		}break;

		case 2:
		{
			if (Lista.estaVacia())
				cout << "La lista esta vacia, no hay valores antes.!" << endl << endl;
			else
			{
				Lista.Imprimir();
				cout << endl << endl;
				Lista.InsertarEntreNodos();
				cout << endl << endl << "Lista actual:" << endl;
				Lista.Imprimir();
				cout << endl;
			}
			_getch();

		}break;

		case 3:
		{
			if (Lista.estaVacia())
				cout << "La lista esta vacia..." << endl << endl;
			cout << Lista.TamanioLista() << endl << endl;
			cout << "Verificando..." << endl;
			cout << "Esta es la lista:" << endl;
			Lista.Imprimir();
			_getch();
		}
		break;

		case 4:
		{
			if (Lista.estaVacia())
				cout << "La lista esta vacia..." << endl << endl;
			else
				Lista.Imprimir();
			_getch();
		}
		break;

		case 5:
		{
			if (Lista.estaVacia())
				cout << "La lista esta vacia..." << endl << endl;
			else
			{
				cout << endl << "Lista actual:" << endl;
				Lista.Imprimir();
				cout << endl;
				cout << endl << "Ingrese el valor a eliminar: ";
				cin >> num;
				Lista.Eliminar(num);
				cout << "La nueva lista es:" << endl;
				Lista.Imprimir();
			}
			_getch();
		}break;
		case 6:
		{
			if (Lista.estaVacia())
				cout << "La lista esta vacia..." << endl << endl;
			else
			{
				cout << "Ingrese dato a buscar: ";
				cin >> num;
				Lista.BuscarNodo(num);
				cout << endl << endl;;
				cout << "Verificando..." << endl;
				cout << "Esta es la lista:" << endl;
				Lista.Imprimir();
			}
			_getch();
		}break;
		case 7:
		{
			menuPrincipal();
		}break;
		default:
		{
			cout << endl << "Opcion no Valida";
			_getch();
		}break;
		}
		cout << endl;
	} while (opc != 7);

	_getch();
	system("pause");
}
void menu1()
{
	gotoXY(5, 10); cout << "Insertar ";
	gotoXY(5, 11); cout << "Agregar ";
	gotoXY(5, 12); cout << "Buscar ";
	gotoXY(5, 13); cout << "Eliminar";
	gotoXY(25, 10); cout << "         ";
	gotoXY(25, 11); cout << "          ";
	gotoXY(25, 12); cout << "          ";
	gotoXY(25, 13); cout << "         ";
	gotoXY(25, 14); cout << "         ";
	gotoXY(45, 10); cout << "         ";
	gotoXY(45, 11); cout << "         ";
	gotoXY(45, 12); cout << "         ";
	gotoXY(45, 13); cout << "         ";
	gotoXY(45, 14); cout << "         ";

}
void menu2()
{
	gotoXY(25, 10); cout << "Agregar ";
	gotoXY(25, 11); cout << "Insertar primero ";
	gotoXY(25, 12); cout << "Insertar ultimo";
	gotoXY(25, 13); cout << "Buscar";
	gotoXY(25, 14); cout << "Eliminar";
}
void menu3()
{
	gotoXY(45, 10); cout << "Agregar ";
	gotoXY(45, 11); cout << "Insertar primero ";
	gotoXY(45, 12); cout << "Insertar ultimo";
	gotoXY(45, 13); cout << "Buscar";
	gotoXY(45, 14); cout << "Eliminar";
}
void menuPrincipal()
{
	system("cls");
	//imagen();
	int x = 10, y = 20;
	color(0, 2);
	gotoXY(24, 0);
	cout << "\t\::::::::::::: MENU LISTAS :::::::::::::::" << endl;
	gotoXY(24, 1);
	color(0, 14);
	cout << "\t\::::::::::::: ESTRUCTURA DE DATOS  ::::::::::::" << endl;
	gotoXY(5, 5); cout << "Listas Simples";
	gotoXY(25, 5); cout << "Listas Dobles";
	gotoXY(45, 5); cout << "Listas Circulares";
	gotoXY(65, 5); cout << "Salir";

	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD InputRecord;
	DWORD Events;
	COORD coord;
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 25;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hout, &cci);
	SetConsoleMode(hin, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);


	while (1)
	{

		ReadConsoleInput(hin, &InputRecord, 1, &Events);
		if (InputRecord.EventType == MOUSE_EVENT)
		{
			if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				/*coord.X= 5;
				coord.Y= 7;*/
				if ((InputRecord.Event.MouseEvent.dwMousePosition.X >= 5 && InputRecord.Event.MouseEvent.dwMousePosition.X <= 18) && (InputRecord.Event.MouseEvent.dwMousePosition.Y == 5))
				{
					//menu1();
					menuls();
				}
				if ((InputRecord.Event.MouseEvent.dwMousePosition.X >= 25 && InputRecord.Event.MouseEvent.dwMousePosition.X <= 38) && (InputRecord.Event.MouseEvent.dwMousePosition.Y == 5))
				{
					menuld();
				}
				if ((InputRecord.Event.MouseEvent.dwMousePosition.X >= 45 && InputRecord.Event.MouseEvent.dwMousePosition.X <= 58) && (InputRecord.Event.MouseEvent.dwMousePosition.Y == 5))
				{
					menuc();
				}
				if ((InputRecord.Event.MouseEvent.dwMousePosition.X >= 65 && InputRecord.Event.MouseEvent.dwMousePosition.X <= 70) && (InputRecord.Event.MouseEvent.dwMousePosition.Y == 5))
				{
					system("cls");
					exit(0);
				}

			}
		}
		FlushConsoleInputBuffer(hin);
	}
}
int main()
{
	system("cls");
	menuPrincipal();
	return 0;
}

