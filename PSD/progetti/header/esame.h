/*
  Specifica sintattica
    Tipo di riferimento: esame
    Tipi di dato utilizzati: string, int, date

  Specifica sintattica operatori:
    -newEsame(string, int, date) -> esame
    -getCorso(esame) -> string
    -getData(esame) -> date
    -getVoto(esame) -> int

  Specifica semantica esame:
  esame è l'insieme delle triple (corso, voto, data):
  -corso costituisce il nome dell'esame
  -voto è un int e 18 <= voto <= 31, dove 31 cosituisce 30L
  -data è una stringa formata "GG/MM/AAAA"

  Specifica semantica operatori:

  - newEsame(corso, voto, data) -> e
    POST: e = (corso, voto, data)

  - getCorso(e) -> c
    POST e = (corso, voto, data) AND c = corso

  - getData(e) -> d
    POST: e = (corso, voto, data) AND d = data

  - getVoto(e) -> v
    POST: e = (corso, voto, data) AND v = voto

*/
#define CORSO_DIM 20
#define COG_NOM_DIM 20
#define NULLEXAM NULL
typedef struct esame *esame;

esame newEsame(int v, char *c, char *d);
char *getCorso(esame e);
char *getData(esame e);
esame inputEsame();
void outputEsame(esame);
esame cloneEsame(esame);
