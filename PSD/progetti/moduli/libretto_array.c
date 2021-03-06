/* Progettazione:
    La ADT libretto è composta dei seguenti campi:
    nome, cognome, matricola, esami; dove nome e cognome sono stringhe, matricola un intero ed esami un array di elementi di tipo esame

    Per inizializzare un libretto si è disposta una funzione newLibretto,
    alla quale si passano nome, cognome e matricola, allocherà spazio per la struttura e ne ritornerà il puntatore.

    Per aggiungere esami al libretto è stato predisposto l'operatore int addEsame(libretto lib, esame es):
    1)se lib == NULL o es == NULLEXAM allora si ritorna 0
    2)Altrimenti se num_esami < MAX_ESAMI allora:
      -esami[num_esami] = es
      -num_esami ++
      e si ritorna 1

    Per cercare un esame ed averne i dettagli si utilizza esame cercaEsame(libretto lib, char *corso)
    1)Se lib o corso sono NULL si ritorna NULLEXAM altrimenti
    2)Si predispone una flag trovato = 0, un contatore i per memorizzare la posizione e per uscire dal ciclo se i >=num_esami
    3)Si scorrono gli esami e si confronta il nome con corso, se l'uguaglianza è vera trovato = 1 e si esce, altrimenti si itera incrementando i
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/esame.h"
#include "../header/libretto.h"
#define MAXESAMI 25

struct libretto{
  char nome[20];
  char cognome[20];
  int matricola;
  esame esami[MAXESAMI];
  int num_esami;
};

libretto newLibretto(char *nom, char *cogn, int mat){
  struct libretto *new;
  new = malloc(sizeof(struct libretto));
  if(new != NULL){
    strcpy(new->nome,nom);
    strcpy(new->cognome, cogn);
    new->matricola = mat;
    new->num_esami = 0;
  }
  return new;
}

int addEsame(libretto lib, esame es){
  if(lib == NULL || es == NULLEXAM)
   return 0;
  if(cercaEsame(lib, getCorso(es)) != NULLEXAM) return 0; //controllo che l'esame non sia già presente

  else{
    if(lib->num_esami < MAXESAMI){       // clono es per evitare che nel caso in cui venga modificato nel main porti a delle incongruenze
      esame clone = cloneEsame(es);       //o dangling references
      lib->esami[lib->num_esami] = clone;
      lib->num_esami++;
      return 1;
    }
    else
        return 0;
  }
}

esame cercaEsame(libretto lib, char *corso){
  if(lib == NULL || corso == NULL)
    return NULLEXAM;

  int i = 0;
  int trovato = 0;
  while(i < lib->num_esami && !trovato){
    if(strcmp(getCorso(lib->esami[i]), corso) == 0) trovato = 1;
    else
      i++;
  }
  if(trovato)
    return cloneEsame(lib->esami[i]);
  else
    return NULLEXAM;
}
