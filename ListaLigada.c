#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//   DEfinir el nodo de laista
struct Nodo 
{
	char info;
	struct nodo *sig;
}; 

typedef struct Nodo nodo;

nodo *raiz = NULL;		// DEfine una lista vacía

void insert(char dato)
{
	nodo *nuevo = NULL;
	nuevo = (nodo *) malloc( sizeof(nodo) ); // Creamos el nodo
	if(nuevo == NULL)			// no hubo memoria libre
	{
		printf("No hay memoria disponible\n");
		exit(1);		//  Forzamos a que el programa termine
	}
	if(raiz == NULL)	// no hay nodos en la lista
	{
		nuevo ->info = dato;	//  Preservamos el dato en nodo
		nuevo ->sig = NULL;		// se vuelve el último nodo;
		raiz = nuevo;			// raiz guarda la dirección de nuevo
	}
	else
	{
		nodo *recorre = raiz; // Recorre apunta al primer nodo
		while( recorre->sig != NULL ) //  Estoy posicionado en el último?
		{								// No!
			recorre = recorre ->sig;	// Avanzo al siguiente nodo
		}								// regreso a pregutar...
		nuevo ->info = dato;	//  Preservamos el dato en nodo
		nuevo ->sig = NULL;		// se vuelve el último nodo;
		recorre -> sig = nuevo;		// raiz guarda la dirección de nuevo

	}
}


void insertPrimero(char dato)
{
	nodo *nuevo = NULL;
	nuevo = (nodo *) malloc( sizeof(nodo) ); // Creamos el nodo
	if(nuevo == NULL)			// no hubo memoria libre
	{
		printf("No hay memoria disponible\n");
		exit(1);		//  Forzamos a que el programa termine
	}
	if(raiz == NULL)
	{
		nuevo ->info = dato;	//  Preservamos el dato en nodo
		nuevo ->sig = NULL;		// se vuelve el último nodo;
		raiz = nuevo;			// raiz guarda la dirección de nuevo
	}
	else
	{
		nuevo ->info = dato;	//  Preservamos el dato en nodo
		nuevo ->sig = raiz;		// se vuelve el último nodo;
		raiz = nuevo;			// raiz guarda la dirección de nuevo
	}
}

char remueve(void)
{
	nodo *elimina = raiz;
	char dato = '\0';			//   dato
	if(raiz == NULL)	//  La lista esta vacía no hay nada que remover
		return dato;
	dato = raiz -> info;	// PReservo el campo info
	raiz = raiz -> sig;
	free(elimina);			// Libero la memoria reservada por malloc()
	return dato;
}

void imprimeLista(void)
{
	nodo *recorre = raiz;
	while( recorre != NULL)
	{
		printf("%c, ", recorre -> info );
		recorre = recorre -> sig;
	}
	printf("\n\n");
}

int main()
{
	insertPrimero('R');
	insertPrimero('o');
	insertPrimero('b');
	insertPrimero('e');
	insertPrimero('r');
	insertPrimero('t');
	insertPrimero('o');

	imprimeLista();

	printf("Sale -> %c \n",remueve());
	printf("Sale -> %c \n",remueve());

	imprimeLista();

	insertPrimero('T');
	insertPrimero('O');

	imprimeLista();

	system("pause");
	return 0;
}


