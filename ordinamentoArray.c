/* PROGRAMMA PER ORDINAMENTO DI UN ARRAY DI n NUMERI 
TIPI DI ORDINAMENTO: 
- SELEZIONE
- BUBBLE SORT
*/

// librerie
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// funzione per algoritmo di ordinamento per selezione
int *ordinamentoSelezione(int *arrayNumeri, int nNumeri)
{
	int i, j;
	int numeroBasso;
	
	for (i = 0; i < nNumeri; i++)
	{	
		for (j = i + 1; j < nNumeri; j++)
		{
			//
		}
	}
	
	return arrayNumeri; // restituzione dell'array ordinato
}

// funzione per algoritmo di ordinamento per bubble sort
int *ordinamentoBubbleSort(int *arrayNumeri, int nNumeri)
{
	//
}

// funzione per generazione di un array di n numeri casuali
int *generaNumeri (int nNumeri)
{	
	int i;
	int  *arrayNumeri = malloc(nNumeri * sizeof(int)); // array che conterra i numeri casuali
	
	// inizializzazione del generazione
	srand(0);
	
	// generazione e aggiunta dei numeri casuali all'array
	for (i = 0; i < nNumeri; i++)
	{
		arrayNumeri[i] = rand();
	}	
	
	return arrayNumeri;
}

// funzione principale
int main()
{	
	int nNumeri, i;
	int *arrayNumeri;
	
	printf("Numero del numei di numeri da aggiungere all'array [max 1000]: ");
	scanf("%d", &nNumeri);
	
	// generazione dell'array di numeri casuali
	arrayNumeri = generaNumeri(nNumeri);
	
	
	// liberazione della memoria
	free(arrayNumeri);
	
	return 0;
}
