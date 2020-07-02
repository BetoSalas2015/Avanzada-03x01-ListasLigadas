#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "ListaLigada.h"

int main()
{
	insertn('$', 5);

	imprimeLista();
	system("pause");

	insert('R');
	insert('o');
	insert('b');
	insert('e');
	insert('r');
	insert('t');
	insert('o');

	imprimeLista();

	insertn('1', 1);

	imprimeLista();
	system("pause");

	insertn('|', 6);

	imprimeLista();

	system("pause");
	return 0;
}


