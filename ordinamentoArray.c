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
#define nomeFileSelezione "datiSelezione.csv"
#define nomeFileBubble "datiBubble.csv"

#define nMin 1000
#define nMax 10000
#define nIncremento 1000

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
	tempoTotale = (double)(tempoFine - tempoInizio);

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
	tempoTotale = (double)(tempoFine - tempoInizio);

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
	int i;
	int *arrayNumeri;

	Tupla *risultati;
	double tempoEsecuzione;

	// creazione dei fue file per salvare i dati
	FILE *fileSelezione, *fileBubble;

	// apertura dei file per scrivere i dati
	fileSelezione = fopen(nomeFileSelezione, "w");
	fileBubble = fopen(nomeFileBubble, "w");

	fprintf(fileSelezione, "Numero_numeri;Tempo_esecuzione\n");
	fprintf(fileBubble, "Numero_numeri;Tempo_esecuzione\n");

	for (i = nMin; i < nMax; i+=nIncremento)
	{	
		// generazione dell'array di numeri casuali
		arrayNumeri = generaNumeri(i);
		
		// ordinamento dell'array per selezione
		risultati = ordinamentoSelezione(arrayNumeri, i);
		
		tempoEsecuzione = risultati->tempoEsecuzione;

		// scrittura dei dati
		fprintf(fileSelezione, "%d;%f\n", i, tempoEsecuzione / 100);



		// ordinamento dell'array per BubbleSort
		risultati = ordinamentoBubbleSort(arrayNumeri, i);
		
		tempoEsecuzione = risultati->tempoEsecuzione;
		
		// scrittura dei dati su file per bubble sort
		fprintf(fileBubble, "%d;%f\n", i, tempoEsecuzione / 100);

	}

	// chiusura dei file
	fclose(fileSelezione);
	fclose(fileSelezione);

	// liberazione della memoria
	free(arrayNumeri);
	free(risultati);
	
	return 0;
}
