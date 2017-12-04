#pragma once
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <string.h>

#define TAM 10

#define ENTER 13

int validar(float &num1, float &num2);
int validarFilasColumnas(int &fila, int &columna);

int validar(float &num1, float &num2) {

	char c;

	int n, numCaracterBuffer;

	system("cls");
	fflush(stdin);

	numCaracterBuffer = 0;

	printf("ingrese un numero: ");
	n = scanf_s("%f", &num1);

	while ((c = getchar()) != '\n') {
		numCaracterBuffer++;
	}

	if (n == 1 && numCaracterBuffer == 0) {
		printf("ingrese otro numero: ");
		fflush(stdin);
		n = scanf_s("%f", &num2);

		while ((c = getchar()) != '\n') {
			numCaracterBuffer++;
		}
	}

	if (n == 0 || numCaracterBuffer != 0) {
		return 0;
	}
	else {
		return 1;
	}
}

int validarFilasColumnas(int &fila, int &columna) {
	char c;

	int n, numCaracterBuffer;

	//system("cls");
	fflush(stdin);

	numCaracterBuffer = 0;

	printf("Ingrese las filas de matriz: ");
	n = scanf_s("%d", &fila);

	while ((c = getchar()) != '\n') {
		numCaracterBuffer++;
	}

	if (n == 1 && numCaracterBuffer == 0) {
		printf("Ingrese las columnas de matriz: ");
		fflush(stdin);
		n = scanf_s("%d", &columna);

		while ((c = getchar()) != '\n') {
			numCaracterBuffer++;
		}
	}

	if (n == 0 || numCaracterBuffer != 0) {
		return 0;
	}
	else {
		return 1;
	}

}
//FUNCION VALIDAR ENTEROS
int ValidarEnteroM()
{
	char *pass = new char[10];
	int i = 0;
	while (pass[i] != 13 || i<1)
	{
		pass[i] = _getch();
		if (i > 0 && pass[i] == 8)
		{
			printf("\b \b");
			pass[--i] = '\0';
		}
		if ((pass[i]>32 && i<10) && (pass[i] >= 48 && pass[i] <= 57))
		{
			printf_s("%c", pass[i]);
			i++;
		}
		else if (pass[i] == 3 && i>0)
		{
			putchar(8);
			putchar(' ');
			putchar(8);
			i--;
		}
	}
	pass[i] = '\0';
	int entero = atoi(pass);
	return entero;

}

int valida_TM(int num1) {
	int sum = 0;
	int cont = 0;
	while (num1 > 0) {
		sum += num1 % 10;
		num1 /= 10;
		cont++;

	}
	if (num1 == 0) {
		cont++;
	}
	return cont;
}
int valida_TF(int num) {
	int sum = 0;
	int cont = 0;
	while (num > 0) {
		sum += num % 10;
		num /= 10;
		cont++;
	}
	return cont;
}
//FUNCION VALIDAR ENTEROS
int ValidarEnteroF()
{
	char *pass = new char[10];
	int i = 0;
	while (pass[i] != 13 || i<1)
	{
		pass[i] = _getch();
		if (i > 0 && pass[i] == 8)
		{
			printf("\b \b");
			pass[--i] = '\0';
		}
		if ((pass[i]>32 && i<7) && (pass[i] >= 48 && pass[i] <= 57))
		{
			printf_s("%c", pass[i]);
			i++;
		}
		else if (pass[i] == 3 && i>0)
		{
			putchar(8);
			putchar(' ');
			putchar(8);
			i--;
		}
	}
	pass[i] = '\0';
	int entero = atoi(pass);
	return entero;

}
//FUNCION VALIDAR LETRAS
void validar_letras(char *p)
{
	int i;
	char tecla;
	i = 0;
	p[0] = '\0';

	do
	{
		tecla = _getch();
		if (i > 0 && tecla == 8)
		{
			printf("\b \b");
			p[--i] = '\0';
		}
		else
		{
			if ((tecla >= 65 && tecla <= 95) ||
				(tecla >= 97 && tecla <= 122))
			{
				printf("%c", tecla);
				p[i++] = tecla;
			}
		}
	} while ((tecla != 13 || p[0] == '\0') && i < TAM);
	p[i] = '\0';

	return;
}

//FUNCION VALIDAR DECIMALES
float flotante()
{
	char *pass = new char[10];
	int conta = 0;
	int i = 0, punto = 0, acm = 0;
	while (pass[i] != 13 || i<1)
	{


		pass[i] = _getch();


		if ((pass[i]>32 && i<20) && (pass[i] >= 48 && pass[i] <= 57) || pass[i] == 46)
		{
			if (pass[i] == 46)
			{
				punto++;
				if (punto>1)
					acm++;
			}
			if (acm > 0)
			{
				if (pass[i] != 46)
				{
					printf("%c", pass[i]);
					i++;
				}

			}
			else
			{
				printf("%c", pass[i]);
				i++;
			}


		}
		else if (pass[i] == 8 && i>0)
		{
			if (pass[i - 1] == 46)acm = 0;

			putchar(8);
			putchar(' ');
			putchar(8);
			i--;
			if (pass[i] == 46)
			{
				punto = 0;
			}
		}

	}
	pass[i] = '\0';
	float flotante = atof(pass);
	return flotante;

}

