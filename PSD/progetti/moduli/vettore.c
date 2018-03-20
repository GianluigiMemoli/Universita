#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../header/utile.h"
void shift_destra(int A[], int j, int n){
  int i;
  if(j > n){printf("SHIFT A DESTRA NON POSSIBILE j > n !!\n\n");}
  for(i = n-1; i >= j; i--){
    A[i+1] = A[i];
  }
}

void inserisci_elemento(int A[], int j, int x, int *n){
    shift_destra(A, j, *(n));
    A[j] = x;
    *(n)++;
}

void out_array(int A[], int n){
  int i;
  for(i = 0; i < n; i++) printf("%d\t",A[i]);
  printf("\n");
}

void random_fill_array(int A[], int n){
  int i;
  srand(time(NULL));
  for(i = 0; i < n; i++) A[i] = rand() % 20;
}

int shift_sinistra(int A[], int n, int j){
  int i;
  for(i = j; i < n; i++){
    A[i] = A[i+1];
  }
  return n-1;
}

void elimina_elemento(int A[], int *n, int j){
  *n = shift_sinistra(A, *n, j);
}

/*
Ricerca minimo
Progettazione:
  1) Viene posta una variabile min uguale al primo elemento dell'array
  2) si scorre l'array, confrontando ogni elemento con minpos, se A[min] > A[i], allora min=i e
*/


int ricerca_minimo(int A[], int n){
  int minpos = 0 ;
  int i;
  for(i=1; i < n; i++){
    if(A[minpos] > A[i]) minpos = i;
  }
  return minpos;
}

/* ***************************************************************************************************** */

/*
Ricerca non ordinata
Progettazione:
    1) Si scorre l'array, confrontando l'uguaglianza degli elementi con x fino a quando non è soddisfatta o non termina l'array
    2) Se l'elemento non c'è, viene ritornato -1, altrimenti la posizione dell'elemento
*/

int ricerca_no_sorted(int A[], int n, int x){
  int i = 0;
  for(i = 0; (i < n); i++){
    if(x == A[i]) return i;
  }
  return -1;
}
/***********************************************************************************************************************************/

/*
  Somma array
  Progettazione:
    1) Se n1 e n2 sono diversi viene stampato un messaggio d'errore e si interrompe l'esecuzione
    2) Altrimenti in un ciclo da 0 a n1=n2, vengono sommati gli elementi, partendo dall'ultima posizione in modo da poter scorrere l'array decrementando n1, senza dichiarare altre variabili contatori
*/
int somma_array(int A[], int B[], int n1, int n2){
  if (n1 != n2){
    printf("Array di dimensioni differenti, impossibile sommarli \n");
    exit(1);
  }
  int sum = 0;

  for(n1--; n1 >= 0; n1--)
    sum += A[n1] + B[n1];

  return sum;
}

/* Array somma
    Progettazione:
      1) Se n1!=n2 si esce con errore
      2) Altrimenti si alloca dinamicamente l'array C, e scorrendo gli array A e B si determinano gli elementi C[i] = A[i] + B[i]
      3) Si ritorna il puntatore dell'array C
*/

int * array_somma(int A[], int B[], int n1, int n2){
  if (n1 != n2){
    printf("Dimensioni array non combaciano");
    exit(1);
  }
  int *C;
  int i;
  C = calloc(n1, sizeof(int));
  for(i = 0; i < n1; i++) C[i] = A[i] + B[i];
  return C;
}

/*
  Prodotto scalare
    Progettazione:
      1) Se n1 != n2 esce dal programma con errore
      2) Altrimenti in un ciclo da 0 a n, con  n2 che decrementa C += A[n2] * B[n2]
*/

int  prodotto_scalare(int A[], int B[], int n1, int n2){
  if(n1 != n2) {
    printf("Dimensioni diverse");
    exit(1);
  }
  int C=0;
  for(n2--; n2 >= 0; n2--) C += A[n2] * B[n2];
  return C;
}

/* Bubble sort
    Progettazione:
    1) Se n > 0:
      · Si setta una variabile ordinato a 1 ed un contatore i a 0
      · Si itera, con condizione (ordinato != 0 && i < n), lo scorrimento dell'array
          Nell'iterazione si controlla se l'elemento a[i] < a[i+1], nel caso sia vera si mette ordinato a 0 e si scambiano gli elementi
      ·Quando la condizione del while è falsa l'array risulta ORDINATO
*/
void bubble_sort(int a[], int n){
  if(n > 0){
    int ordinato = 0;
    int i = 0;
    while((!ordinato) && (i < n)){
      ordinato = 1;
      for(i = 0; i < n-1; i++)
        if(a[i] > a[i+1]){
          ordinato = 0;
          scambia(&a[i], &a[i+1]);
        }
      }
    }
  }
/********************************************************************************************************/

/* Confronta array */
int confronta_array(int a[], int b[], int n){
  int i;
  for(i = 0; i < n; i++)
    if(a[i] != b[i]) return 0;
  return 1;
}

/* Array in input da file */
void finput_array(FILE *f, int a[], int n){
  int i;
  for(i = 0; i < n; i++){
    fscanf(f, "%d\n", &a[i]);
  }
}

/* Array output su file */
void foutput_array(FILE *f, int a[], int n){
  int i;
  for(i = 0; i < n; i++) fprintf(f, "%d\n", a[i]);
}
