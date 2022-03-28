/* PROGRAMMA PER ORDINAMENTO DI UN ARRAY DI n NUMERI 
TIPI DI ORDINAMENTO: 
- SELEZIONE
- BUBBLE SORT
*/

// librerie
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// costanti
#define grandezzaRand 1

// funzione per algoritmo di ordinamento per selezione
int *ordinamentoSelezione(int *arrayNumeri, int nNumeri)
{
	int i, j;
	int numeroPiuBasso;
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

				// sostituzione del numero piu piccolo con quello piu grande
				numeroSostituito = arrayNumeri[j]; 
				arrayNumeri[j] =  arrayNumeri[i];
				arrayNumeri[i] = numeroSostituito;
			}
		}
		
	}
	
	return arrayNumeri; // restituzione dell'array ordinato
}

// funzione per algoritmo di ordinamento per bubble sort
int *ordinamentoBubbleSort(int *arrayNumeri, int nNumeri)
{
	int i, j;
	int numeroSostituito;

	for (j = 0; j < nNumeri - 1; j++)
	{
		for (i = 0; i < nNumeri - 1; i++)
		{
			// comparazione tra i due numeri
			if (arrayNumeri[i] > arrayNumeri[i + 1]) // se il numero successivo è più piccolo
			{	
				// scambio tra i due numeri
				numeroSostituito = arrayNumeri[i];
				arrayNumeri[i] = arrayNumeri[i + 1];
				arrayNumeri[i + 1] = numeroSostituito;
			}
		}
	}

	return arrayNumeri; // restituzione dell'array ordinato
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
		arrayNumeri[i] = rand() % grandezzaRand;
	}	
	
	return arrayNumeri;
}

// funzione principale
int main()
{	
	int nNumeri;
	int *arrayNumeri;
	
	printf("Numero del numei di numeri da aggiungere all'array [max 1000]: ");
	scanf("%d", &nNumeri);
	
	// generazione dell'array di numeri casuali
	arrayNumeri = generaNumeri(nNumeri);
	
	// ordinamento dell'array per selzione
	arrayNumeri = ordinamentoBubbleSort(arrayNumeri, nNumeri);
	
	
	// liberazione della memoria
	free(arrayNumeri);
	
	return 0;
}
