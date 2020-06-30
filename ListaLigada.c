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

char remueve(void)
{
	nodo *recorre, *last;
	char dato = '\0';			//   dato
	if(raiz == NULL)	//  La lista esta vac�a no hay nada que remover
		return dato;
	recorre = last = raiz;
	if(last -> sig == NULL && last == raiz)	// Es una lista de 1 nodo?
	{
		dato = last -> info;	// PReservo el campo info
		free(last);			// Libero la memoria reservada por malloc()
		raiz = NULL;		// Se vuelve una lista vac�a
	}
	else
	{
		while( last -> sig != NULL) //  es el ultimo nodo
		{
			recorre = last;			// Emparejo recorre
			last = last -> sig;		// last avanza al siguiente nodo
		}
		dato = last -> info;	// PReservo el campo info
		free(last);			// Libero la memoria reservada por malloc()
		recorre ->sig = NULL;		// Se vuelve wl ultimo nodo
	}
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
	insert('R');
	insert('o');
	insert('b');
	insert('e');
	insert('r');
	insert('t');
	insert('o');

	imprimeLista();

	printf("Sale -> %c \n",remueve());
	printf("Sale -> %c \n",remueve());

	imprimeLista();

	insert('T');
	insert('O');

	imprimeLista();

	system("pause");
	return 0;
}


