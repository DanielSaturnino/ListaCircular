/**
Daniel Manzano Saturnino
*/
#include "ListaCircular.h"
/*
Constructor:
@Parametros: void
@Result: void
Crea un nodo de con H y T apuntando a NULL
*/
	ListaCircular::ListaCircular()
	{
		this->H=NULL;
		this->T=NULL;
	}
/*
Constructor
@Parametros:int Dato
@Result: void
Crea un nodo que apunta a H y  T apunta a H
*/

	ListaCircular::ListaCircular(int Dato)
	{
		Nodo * aux= new Nodo(Dato);
		this->H=aux;
		this->T->setSig(this->H);
		
	}

/*
Lista Vacia
@Parametros: void
@Result: bool True o False
Comprueba si la lista esta vacia revisando los apuntadores
de H y T si apuntan a NULL devuelve un true de lo contrario
un false
*/
	bool ListaCircular::ListaVacia()
	{
		if (this->H == NULL && this->T == NULL)
			return true;
		return false;
	}
/*
AddInicio
@Parametros: int Dato
@Result: Void
Este metodo crea un nodo auxiliar que apunta a H 
llama al metodo lista vacia si se encuentra vacia 
agrega el elemento y asigna a T el nodo creado este a su vez 
apunta a H 
de lo contrario H se le asigna el nuevo nodo
*/
	void ListaCircular::AddInicio(int Dato)
	{
		Nodo* aux = new Nodo(Dato,this->H);
		if (ListaVacia())
		{
			this->T= aux;
			T->setSig(this->H);
		}
			this->H= aux;
	}
/*
AddFinal
@Parametros: int Dato
@Result: void
Crea un nuevo nodo con dato nuevo, verifica si 
la lista esta vacia si si lo esta a H y T se le asigna
 el nuevo nodo, de lo contrario a T apunta a l nuevo nodo
 y a T se le asigna el nodo que se ha creado y hace que apunte 
a H 
*/
	void ListaCircular::AddFinal(int Dato)
	{
		Nodo* aux=new Nodo (Dato);
		if(ListaVacia())
		{
			this->H= aux;
		 	this->T= aux;
		 	T->setSig(this->H);
		}else{
			this->T->setSig(aux);
			this->T= aux;
			T->setSig(this->H);
		}

	}
/*
AddRef
@Parametros: int Dato, int Ref
@Result: void
Verifica si la lista esta vacia llamando al metodo lista Vacia
si esto se cumple crea un dato con un dato a H se le asigna 
el nodo creado y finalmente T es igual a H e imprime una leyenda
de lo contrario crea un nodo que apunta a H recorre la lista 
hasta que el nodo tenga el valor de la referencia y apunte 
a un valor diferente de T si se cumple lo  anterior apuntara
al siguiente valor hasta que llegue al elemento de referencia
una vez llegado verifica si el nodo no apunta a null
si  esto se cumple crea un nodo con el valor de dato y 
que apunta al siguiente del nodo que se creo y que 
apuntaba a H y finalmente a el primer nodo creado
se le asigna la referencia a la que apuntaba el segundo
nodo creado
si esto no se cumple arroja una leyenda
*/
	void ListaCircular::AddRef(int Dato,int Ref)
	{
		if(ListaVacia())
		{
			Nodo* aux=new Nodo(Dato);
			this->H=aux;
			this->T=this->H;
			std::cout<<"No se encontro la referencia por que la lista esta vacia"<<std::endl;
			return;
		}

			Nodo*aux=this->H;
			while(aux->getDato()!=Ref && aux!=NULL)
			{
				aux=aux->getSig();
			}
			if(aux!=NULL)
			{
					Nodo* aux2=new Nodo(Dato,aux->getSig());
					aux->setSig(aux2);
			}else
			{
					std::cout<<"NO EXISTE LA REFERENCIA EN LA LISTA"<<std::endl;
			}
	}
/*
Remove Lista
@Parametros: void
@Result: int Dato
verifica que la lista este vacia con el metodo lista Vacia
Si se cumple arroja una leyenda y regresamos un cero
si no creamos una variablede tipo entero y le asignamos
 el valor de H despues H ahora apuntara al siguiente de H
 y preguntamos si H apunta NULL
si apunta a NULL si apunta entonces T tambien apuntara a NULL
si no solo retorna un dato
*/
	int ListaCircular::RemoveInicio()
	{
		if(ListaVacia())
		{
			std::cout<<"LA LISTA ESTA VACIA"<<std::endl;
			return 0;
		}else
		{
			int Dato=H->getDato();
			this->H=H->getSig();
			if(this->H==NULL)
				this->T=NULL;
			return Dato;
		}
	}
/*
RemoveFinal
@Parametros: void
@Result: int Dato 
Verifica si la lista esta vacia con el metodo Lista Vacia
si esta vacia da una leyenda y retorna un cero 
si no crea un dato se le asigna el dato de T 
y pregunta si H es diferente de T si esto es correcto
crea un nodo que apunta a H recorre la lista con un 
while hasta que apunte a T cuando llegue sale y a T se
le asigna el nuevo nodo que apunta a H  y  el nodo nuevo es T 
ahora el T anterior apunta a un NULL, 
si no se cumplio lo anterior H y T apuntan a NuLL
al final regresa un dato  
*/
	int ListaCircular::RemoveFinal()
	{
		if(ListaVacia())
		{
			std::cout<<"LA LISTA ESTA VACIA"<<std::endl;
			return 0;
		}
		int Dato=T->getDato();
			if(this->H!=this->T)
			{
				Nodo* aux=this->H;
				while(aux->getSig()!=this->T)
				{
					aux=aux->getSig();
				}
					aux->setSig(this->H);
					this->T=aux;
					this->T->setSig(NULL);
			}else
			{
				this->H=NULL;
				this->T=NULL;
			}
	return Dato;
	}
/*
RemoveRef
@Parametros:int Ref
@Result: int Dato
Verifica si la lista esta vacia con el metodo Lista Vacia
si esta vacia retorna UN NuLL si no va crear dos nodos el primero 
se recorrera desde H hasta el dato dado por   el usuario
el segundo desde H hasta uno antes del primer nodo creado
y preguntamos si el primer nodo
creado no apunta NULL si se cumple al segundo creado se le
asigna el siguiente del primer nodo perdiendo la referencia del
primer nodo si apunta a NULL arroja una leyenda de que no se
encontro nada
retorna un Dato
*/

	int ListaCircular::RemoveRef(int Ref)
	{
		if(ListaVacia())
		{
			std::cout<<"LA LISTA ESTA VACIA"<<std::endl;
			return 0;
		}else
		{
			Nodo*aux=this->H;
			while(aux->getDato()!=Ref && aux!=this->T)
			{
					
				aux=aux->getSig();
			}
				Nodo* aux2=this->H;
				while(aux2->getSig()!=aux)
				{
					aux2=aux2->getSig();
				}
			if(aux!=NULL)
				{
						
						aux2->setSig(aux->getSig());
						
				}else
				{
						std::cout<<"NO EXISTE LA REFERENCIA EN LA LISTA"<<std::endl;
				}
				return Ref;
		}

	}
/*
Lista Vacia
@Parametros: void
@Result: int Dato
Verifica si la liasta esta vacia con el metodo Lista vacia
si lo esta envia una leyenda y retorna un cero si
no a H y T los apunta a NULL e imprime una leyenda
retorna un cero
*/
	int ListaCircular::VaciarLista()
	{
		if (ListaVacia())
		{
				std::cout<<"La lista esta vacia"<<std::endl;
				return 0;
		}else{
				this->H=NULL;
				this->T=NULL;
				std::cout<<"He vasiado la lista"<<std::endl;
			
		}
		return 0;
	}
/*
Buscar elemento 
@paramametros: int Ref
@Result: Nodo*
Verifica con el metodo lista vacia si la lista esta vacia
si esta arroja una leyenda y devuelve un NULL
de lo contrario crea un nodo y lo recorre hasta encontrar
el dato y pregunta si el dato es igual al dato que esta en ese 
nodo entonces imprime una leyenda y el valor del nodo
si no devuelve una leyenda en ambos casos regresa el nodo
creado
*/
	Nodo* ListaCircular::BuscarElemento(int Dato)
	{
		if (ListaVacia())
		{
			std::cout<<"NO SE ENCOTRO ELEMENTOS PORQUE LA LISTA ESTA VACIA"<<std::endl;	
			return NULL;
		}else
		{
			Nodo* aux=this->H;
			while(aux->getDato()!=Dato && aux!=this->T)
			{
				aux=aux->getSig();
			}
			if(aux->getDato()==Dato)
			{
				std::cout<<"ELEMENTO ENCONTRADO:"<<std::endl;
				std::cout<<aux->getDato()<<std::endl;
				return aux;
			}
			std::cout<<"NO se encontro el elemento"<<std::endl;
		}
			
	}
/*
Show
@parametros: void
@Result: void
Crea un nodo auxiliar que apunta a H
y este nodo recorre la lista hasta llegar a T
caba vez que cambia imprime el dato donde se encuentra
*/
	void ListaCircular::Show()
	{
		Nodo* aux = this->H;
		while(aux!=T)
		{
			std::cout<<aux->getDato()<<std::endl;
			aux=aux->getSig();
		}
		std::cout<<T->getDato()<<std::endl;
	}