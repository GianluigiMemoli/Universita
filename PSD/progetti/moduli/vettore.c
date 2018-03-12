#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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
