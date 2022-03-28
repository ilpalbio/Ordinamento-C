/* PROGRAMMA PER ORDINAMENTO DI UN ARRAY DI n NUMERI 
TIPI DI ORDINAMENTO: 
- SELEZIONE
- BUBBLE SORT
*/

// librerie
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

// costanti
#define grandezzaRand 1

// struct per tupla
typedef struct
{
	int *arrayNumeri;
	double tempoEsecuzione;
}Tupla;


// funzione per algoritmo di ordinamento per selezione
Tupla *ordinamentoSelezione(int *arrayNumeri, int nNumeri)
{
	int i, j;
	int numeroPiuBasso;
	int numeroSostituito;

	// dichiarazioni variablili per tempo di esecuzione
	clock_t tempoInizio, tempoFine, tempoTotale;
	
	// partenza del cronometro
	tempoInizio = clock();

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

	// fine del cronometro
	tempoFine = clock();

	// calcolo del tempo totale
	tempoTotale = (double)(tempoFine - tempoInizio) / CLOCKS_PER_SEC;

	Tupla *risultati = malloc(1 * sizeof*risultati);
	risultati->arrayNumeri = arrayNumeri;
	risultati->tempoEsecuzione = tempoTotale;
	
	return risultati; // restituzione dell'array ordinato
}

// funzione per algoritmo di ordinamento per bubble sort
Tupla *ordinamentoBubbleSort(int *arrayNumeri, int nNumeri)
{
	int i, j;
	int numeroSostituito;

	// dichiarazioni variablili per tempo di esecuzione
	clock_t tempoInizio, tempoFine, tempoTotale;

	// partenza del cronometro
	tempoInizio = clock();

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

	// fine del cronometro
	tempoFine = clock();

	// calcolo del tempo totale
	tempoTotale = (double)(tempoFine - tempoInizio) / CLOCKS_PER_SEC;

	Tupla *risultati = malloc(1 * sizeof*risultati);
	risultati->arrayNumeri = arrayNumeri;
	risultati->tempoEsecuzione = tempoTotale;


	return risultati; // restituzione dell'array ordinato
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

	Tupla *risultati;
	double tempoEsecuzione;
	int  *arrayNumeriOrdinati;

	
	printf("Numero del numei di numeri da aggiungere all'array: ");
	scanf("%d", &nNumeri);
	
	// generazione dell'array di numeri casuali
	arrayNumeri = generaNumeri(nNumeri);
	
	// ordinamento dell'array per selezione
	risultati = ordinamentoSelezione(arrayNumeri, nNumeri);
	
	arrayNumeriOrdinati = risultati->arrayNumeri;
	tempoEsecuzione = risultati->tempoEsecuzione;

	// scrittura dei dati per l'algoritmo a selezione
	printf("\nAlgoritmo ordinamento per selezione");
	printf("\n-------------------------------------------------------");
	printf("\nNumero elementi da ordinare: %d", nNumeri);
	printf("\nTempo di esecuzione: %f", tempoEsecuzione);
	printf("\n-------------------------------------------------------\n");


	// ordinamento dell'array per BubbleSort
	risultati = ordinamentoBubbleSort(arrayNumeri, nNumeri);

	arrayNumeriOrdinati = risultati->arrayNumeri;
	tempoEsecuzione = risultati->tempoEsecuzione;

	// scrittura dei dati per l'algoritmo a BubbleSort
	printf("\nAlgoritmo ordinamento bubble sort");
	printf("\n-------------------------------------------------------");
	printf("\nNumero elementi da ordinare: %d", nNumeri);
	printf("\nTempo di esecuzione: %f", tempoEsecuzione);
	printf("\n-------------------------------------------------------");

	// liberazione della memoria
	free(arrayNumeri);
	free(risultati);
	
	return 0;
}
