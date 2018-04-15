#include <stdio.h>
#include <stdlib.h>
#include "../header/esame.h"
#include "../header/libretto.h"

int main(){
  int answ = 1;
  libretto lib;
  esame es;
  char corso[CORSO_DIM], nome[COG_NOM_DIM], cognome[COG_NOM_DIM];
  int matricola;

  printf("Inizializza libretto\n");
  printf("\tNome:");
  scanf("%s", nome);
  printf("\tCognome:");
  scanf("%s", cognome);
  printf("\tMatricola:");
  scanf("%d", &matricola);
  lib = newLibretto(nome, cognome, matricola);
  if(lib == NULL){
    printf("LIBRETTO NON INIZIALIZZATO");
    exit(1);
  }

  while(answ != 0){
    printf("0 per uscire\n 1 addEsame\n 2 cercaEsame");
    scanf("%d",&answ);
    switch (answ) {
      case 1:
        es = inputEsame();
        if(addEsame(lib, es)) printf("Inserimento avvenuto con successo \n");
        else printf("Err\n");
        break;

      case 2:
        printf("Inserisci nome corso:\n");
        scanf("%s",corso );
        es = cercaEsame(lib, corso);
        if(es != NULLEXAM) outputEsame(es);
        else printf("Non presente\n");
        break;
    }
  }
  return 0;
}
