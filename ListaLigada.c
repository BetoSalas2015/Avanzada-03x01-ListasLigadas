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

nodo *raiz = NULL;		// DEfine una lista vac�a

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
		nuevo ->sig = NULL;		// se vuelve el �ltimo nodo;
		raiz = nuevo;			// raiz guarda la direcci�n de nuevo
	}
	else
	{
		nodo *recorre = raiz; // Recorre apunta al primer nodo
		while( recorre->sig != NULL ) //  Estoy posicionado en el �ltimo?
		{								// No!
			recorre = recorre ->sig;	// Avanzo al siguiente nodo
		}								// regreso a pregutar...
		nuevo ->info = dato;	//  Preservamos el dato en nodo
		nuevo ->sig = NULL;		// se vuelve el �ltimo nodo;
		recorre -> sig = nuevo;		// raiz guarda la direcci�n de nuevo

	}
}

int main()
{
	printf("nodo tiene in tama�o de %d bytes\n", sizeof(nodo));
	system("pause");
	return 0;
}


