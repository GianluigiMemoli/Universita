#include <stdio.h>


int confronta_array(int a[], int b[], int n);


/* INSERISCI ELEMENTO
    Analisi:
      Inserimento di un elemento in un array
    · Input:  Dati un array A di riempimento n, un elemento x da inserire in posizione j
    · Precondizione: 0<= j <= n
    · Output: Array A1, nel quale ogni elemento che era in posizione i >= j, ora sarà di posizione i+1, e A1[j] = x

    Progettazione:
      1) Ogni elemento di posizione i >= j, viene shiftato a destra di una posizione (shift_destra())
      2) Viene assegnata alla posizione A[j] il valore di x e viene incrementata n

*/
void shift_destra(int A[], int j, int n);
void inserisci_elemento(int A[], int j, int x, int *n);
//    ***************************************************************************************************************





/*ELIMINA ELEMENTO
  ELiminazione di un elemento in un array, data la posizione
  Analisi:
    ·Input: Array A, di riempimento n, posizione j dell'elemento da cancellare
    ·Precondizione: 0<=j<=n
    ·Output: Array A1 di riempimento n-1
    ·Postcondizione:
                    ∀ i [0, j-1] A1[i] = A[i] AND
                    ∀ i [j, n] A1[i] = A[i - 1]
                        x ∉ A1
  Progettazione:
      1) Ogni elemento di posizione > j viene spostato nella posizione precedente (shift_sinistra)
      2) Decremento n
*/


int shift_sinistra(int A[], int n, int j);
void elimina_elemento(int A[], int *n, int j);
/*****************************************************************************************************************/

/* RICERCA MINIMO
    Dato un array ricercare il minimo all'interno
    Analisi:
      ·Input: Array A di riempimento n
      ·Precondizione: n>0
      ·Output: intero min che indica la posizione del minimo all'interno dell'array
      ·Postcondizione: 0 <= minpos < n
*/

int ricerca_minimo(int A[], int n);

/*
  RICERCA DI UN ELEMENTO IN ARRAY NON ORDINATO
  Analisi:
      ·Input: Array A di riempimento n, elemento x da ricercare
      ·Precondizione: n>0
      ·Output: intero j che indica la posizione dell'elemento
      ·Postcondizione: 0 <= j < n
*/

int ricerca_no_sorted(int A[], int n, int x);
/*******************************************************************************************************************/

/*
  SOMMA TRA DUE ARRAY
  Analisi:
      ·Input: Array A di riempimento n1 e Array B di riempimento n2
      ·Precondizione: n1 = n2 > 0
      ·Output: Intero sum
      ·Postcondizione: ∀ i [0,n1=n2] sum = A[i] + B[i];
*/
int somma_array(int A[], int B[], int n1, int n2);
/*******************************************************************/

/*
  ARRAY SOMMA
    Dati due array A,B dare in output un array C, dove ogni elemento C[i] = A[i] + B[i]
    Analisi:
      ·Input: Array A,B di riempimento rispettivamente n1 e n2
      ·Precondizione: 0 < n1=n2
      ·Output: Array C di riempimento n1=n2
      ·Postcondizione: ∀i[0,n1] C[i] = A[i] + B[i]
*/

int * array_somma(int A[], int B[], int n1, int n2);
/**********************************************************************************************/

/*
  Prodotto scalare
    Dati due array si sommano su tutte le posizioni "i" i prodotti degli elementi di posizione i
    Analisi:
      ·Input: Array A, B di dimensioni rispettivamente n1 = n2
      ·Precondizione: 0 < n1=n2
      ·Output: Intero C di dimensione n1 V n2
      ·Postcondizione: ∀i[0, n1] C= C[i] + (A[i] * B[i])
*/

int  prodotto_scalare(int A[], int B[], int n1, int n2);

/******************************************************************/
/*
  Bubble sort
    Dato un array, ordinarne gli elementi
    Analisi:
      -Input: Array a di n elementi
      -Precondizione: n > 0
      -Output: Array a' di n elementi
      -Postcondizione: ∀ i [0,n-1] a'[i] < a'[i+1]
*/


void bubble_sort(int a[], int n);

void out_array(int A[], int n);
void random_fill_array(int A[], int n);

void finput_array(FILE *f, int a[], int n);
void foutput_array(FILE *f, int a[], int n);
