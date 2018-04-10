#include <stdlib.h>
#include <stdio.h>

void test_file(FILE *f, char *fname){
  if(!f){
    printf("Errore durante apertura %s", fname);
    exit(1);
  }
}
