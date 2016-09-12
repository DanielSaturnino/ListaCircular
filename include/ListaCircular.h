/*
Nombre: Daniel Manzano Saturnino
Descripcion: Este programa es una
lista circular, contiene todos los 
metodos que puede hacer una lista 
circular
Atributos: NODO H Y NODO T
*/
#include "Nodo.h"

class ListaCircular
{
public:
	Nodo* H;
	Nodo* T;	
	ListaCircular();
	ListaCircular(int Dato);
	bool ListaVacia();
	void AddInicio(int Dato);
	void AddFinal(int Dato);
	void AddRef(int Dato, int Ref);
	int RemoveInicio();
	int RemoveFinal();
	int RemoveRef(int Ref);
	int VaciarLista();
	Nodo* BuscarElemento(int Dato);
	void Show();
};