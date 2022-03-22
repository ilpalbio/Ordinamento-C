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
	int numeroPiuBasso, indexNumeroBasso;
	int numeroSostituito;
	
	for (i = 0; i < nNumeri; i++)
	{		
		// ricerca del numero più piccolo
		numeroPiuBasso = arrayNumeri[i];
		
		for (j = i + 1; j < nNumeri; j++)
		{
			if (numeroPiuBasso > arrayNumeri[j]) // seviene trovato un numero più piccolo
			{
				numeroPiuBasso = arrayNumeri[j]; // sostituzione del numero piu piccolo
				indexNumeroBasso = j; // si tiene conto dell'indice dell'elemento nella lista
			}
		}
		
		// sostituzione del numero piu piccolo con quello piu grande
		numeroSostituito = arrayNumeri[indexNumeroBasso]; 
		arrayNumeri[indexNumeroBasso] =  arrayNumeri[i];
		arrayNumeri[i] = numeroSostituito;
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
		arrayNumeri[i] = rand() % 50;
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
	
	printf("\nArray non ordinato\n");
	for (i = 0; i < nNumeri; i++)
	{
		printf("%d ", arrayNumeri[i]);
	}
	
	// ordinamento dell'array per selzione
	arrayNumeri = ordinamentoSelezione(arrayNumeri, nNumeri);
	
	printf("\n\nArray ordinato\n");
	for (i = 0; i < nNumeri; i++)
	{
		printf("%d ", arrayNumeri[i]);
	}
	
	
	// liberazione della memoria
	free(arrayNumeri);
	
	return 0;
}
