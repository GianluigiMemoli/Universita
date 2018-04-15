#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/esame.h"


struct esame{
  int voto;
  char corso[20];
  char data[11];
};

esame newEsame(int v, char *c, char *d){
  struct esame *e = malloc(sizeof(struct esame));
  if(e != NULL){
    e->voto = v;
    if(c == NULL || d == NULL || e == NULL) return NULLEXAM;
    strcpy(e->data, d);
    strcpy(e->corso, c);
    return e;
  }
  else return NULLEXAM;
}

char *getCorso(esame e){
  if(e == NULL)
    return NULL;

  char *corso = malloc(20*sizeof(char));

  if(corso != NULL)
    strcpy(corso, e->corso);

  return corso;
}


char *getData(esame e){
  if(e == NULL)
    return NULL;

  char *data = malloc(11*sizeof(char));

  if(data != NULL)
    strcpy(data, e->data);

  return data;
}

esame inputEsame(){
  char corso[20], data[11];
  int voto;
  printf("Inserisci nome del corso:\n");
  scanf("%s",corso);
  printf("Inserisci voto");
  scanf("%d", &voto);
  printf("Inserisci data svolgimento esame nel formato (GG/MM/AAAA)");
  scanf("%s", data);
  if(voto >= 18 && voto <= 31 ) return newEsame(voto, corso, data);
  else return NULLEXAM;
}

void outputEsame(esame e){
  if(e != NULLEXAM) {
    printf("Corso:\t%s\n", e->corso);
    printf("Voto:\t%d\n", e->voto);
    printf("Data:\t%s\n", e->data);
  }
}

esame cloneEsame(esame es){
  struct esame *clone = malloc(sizeof(struct esame));
  if(clone != NULL){
    strcpy(clone->corso, es->corso);
    strcpy(clone->data, es->data);
    clone->voto = es->voto;
    return clone;
  }
  else return NULLEXAM;
}
