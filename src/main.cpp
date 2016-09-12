/**
Daniel Manzano Saturnino
*/
#include "ListaCircular.h"

int main()
{
	ListaCircular l = ListaCircular();
	l.AddInicio(3);
	l.AddInicio(2);
	l.AddFinal(12);
	l.Show();
	l.AddRef(5,3);
	l.AddRef(9,3);
	l.Show();
	std::cout<<"Termina agregacion"<<std::endl;
	l.RemoveInicio();
	l.RemoveFinal();
	l.RemoveRef(9);
	l.Show();
	std::cout<<"Termina eliminacion"<<std::endl;
	l.BuscarElemento(3);
	l.VaciarLista();
	return 0;
}