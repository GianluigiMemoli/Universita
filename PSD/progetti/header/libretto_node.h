/*
  Specifica sintattica:
    Tipo di riferimento: Libretto
    Tipi di dato usati: string, int, esame
  Specifica sintattica operatori:
    -newLibretto(string, string, int) -> libretto
    -addEsame(libretto, esame)->libretto
    -cercaEsame(libretto, string)->esame

  Specifica semantica:
    Libretto è l'insieme di (nome, cognome, matricola, esami), dove
    esami sarà l'insieme degli esami sostenuti dallo studente,
    il resto (nome, cognome, matricola) sono i dati per identificare lo studente univocamente

    Operatori:

      -newLibretto(nom, cogn, mat) -> lib
        POST: lib = (nom, cogn, mat, ø)

      -addEsame(lib, es) -> lib'
        PRE: es non deve appartenere a lib
        POST: il contenuto del campo esami è il risultato dell'operazione unione tra l'insieme esami e l'esame es

      -cercaEsame(lib, corso) -> es
      PRE: lib = (nom, cogn, mat, esami)
      POST: se l'esame è presente nell'insieme allora es sarà uguale
*/
typedef struct libretto *libretto;
libretto newLibretto(char *, char *, int);
int addEsame(libretto, esame);
esame cercaEsame(libretto, char *);
