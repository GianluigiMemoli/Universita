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

*/
int shift_sinistra(int A[], int n, int j);
void elimina_elemento(int A[], int *n, int j);














void out_array(int A[], int n);
void random_fill_array(int A[], int n);
