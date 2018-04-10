#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "../header/complex.h"
#define MAX  10
struct comp{
  float reale;
  char imm[10];
};

complex CreaComplex(float x, char y[]){
  complex tmp = malloc(sizeof(*tmp));
  tmp->reale = x;
  strcpy(tmp->imm, y);
  return tmp;
}

float ParteReale(complex c){return c->reale;}
char * ParteImmaginaria(complex c){return c->imm;}

int getImmCoeff(char *imm){
  int coeff = 1;
  char strcoeff[MAX];
  int len = strlen(imm);
  if(len == 1)
   return coeff;
  else{
    strncpy(strcoeff, imm, len-1);
    printf("%s\n", imm-2);
  }
  return atoi(strcoeff);
}

complex SommaComplex(complex c1, complex c2){
  complex sum = malloc(sizeof(*sum));
  sum->reale = c1->reale + c2->reale;
 int coeff = 0;
  coeff = getImmCoeff(c1->imm) + getImmCoeff(c2->imm);
  sprintf(sum->imm, "%d%s", coeff, "i");
  return sum;
}
