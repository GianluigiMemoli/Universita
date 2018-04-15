#include <stdlib.h>
#include <stdio.h>
#include "../header/item.h"
#include "../header/list.h"

/*

  PROGETTAZIONE:
    Una lista è una sequenza concatenata di nodi, di conseguenza è stata
    dichiarata una struttura node che costituisce il record ed il puntatore al
    record successivo.
    Con newList viene creata una nuova lista, che ritorna appunto NULL
    che rappresenta una lista vuota.
    Per quanto riguarda L'INSERIMENTO si utilizza la funzione consList(item, list),
    la quale appunto prende in input la lista e il valore da aggiungervi.

    Per poter aggiungere un nodo alla lista si:
      1) Crea un nuovo nodo
      2) Alloca memoria al nodo
      3) Assegnare il valore di item al campo value del nuovo nodo
      4) Si fa puntare il campo next del nuovo nodo all'ancora attuale primo nodo della lista
      5) Si fa puntare quello che non è più il primo nodo, al nuovo

    Per ottenere il primo valore della lista getFirst(l):
      1)Si crea una variabile di tipo item, che conterrà il primo elemento della lista
      2)Se l è diverso da NULL:
         Si assegna ad e il valore contenuto da l
      2.1) altrimenti:
          Si assegna ad e il valore NULLITEM
      3) si ritorna e

    Per cancellare il primo elemento della lista si è definita la funzione tailList(l):
      1)Si crea una variabile list 'tmp'  ausiliaria
      2)Si fa puntare tmp a l->next (se l != NULL)
      3)Si ritorna tmp

    Per calcolare la size della lista int sizeList(l):
      1)Si inizializza e instanzia una variabile contatore
      2)Itero finchè while(!emptyList(l)) e incremento il contatore
      3)Uscito dal ciclo ritorno il contatore

    Per ricavare la posizione di un item in lista int posItem(e, l):
      1)Si utilizza una variabile contatore e un flag trovato settato a -1 e si itera while(!emptyList(l) && !trovato)
      2)Nel ciclo si confronta e con gli item che scorriamo nella lista e se ne troviamo uno uguale trovato=1
      3)Si ritorna il valore del contatore se trovato==1 altrimenti -1

    Per vedere se un elemento è presente in lista int searchItem(l, item):
      1)Si itera while(!emptyList(l) && !trovato)
      2)Si scorrono e confrontano con e gli item della lista e se l'uguaglianza è soddisfatta si setta un flag trovato=1
      3)Si ritorna trovato

    Per ottenere una versione della lista con gli elementi in ordine inverso list reverseList(l):
      1)Si alloca una seconda lista l2
      2)Si itera con condizione while(!emptyList(l))
      3)Nel ciclo si effettua un consList(l2) di getFirst(l), dopodichè un tailList(l)
      4) Al termine del ciclo si avrà la lista in ordine inverso

    Per aggiungere un elemento si usa list insertList(l, pos, e):
    1)Se pos == o e l!= null si effettua il consList(e, l)
    2)Altrimenti si inizializza una variabile list prec che servirà a scandire la lista
        e un list new a cui si assegna il valore di e
    3)Si itera con while((i<pos-1) && (prec != NULL)) per arrivare all'elemento precedente a pos
    4)Uscito dal ciclo se prec != null e prec->next != null allora
      -si inizializza un list succ = prec->next
      -prec next punta a new
      -new->next punta a succ
    5) si ritorna l

    Per rimuovere un elemento list removeList(l, pos){
      1)Si inizializza una variabile l1 che punterà al nodo in posizione pos da eliminare
      2)Se pos==0 e l!=NULL il nodo da eliminare è quello puntato da l, quindi l1=l,
        si fa puntare poi l al nodo successivo l=l->next e si dealloca l1 free(l1)
      3) altrimenti se pos != 0 si istanzia un contatore i e una lista temporanea prec a cui si assegna l
      4) Si itera fino a quando prec punta al nodo precedente a quello in posizione pos
          while(i < pos-1 && prec!=NULL)
      5) Finito il ciclo se (prec!=NULL) && (prec->next!=NULL) allora
          -Assegno l1 = prec->next
          -Faccio puntare prec->next al nodo successivo di l1 prec->next = l1->next
          -Dealloco l1: free(l1)
      6) ritorno l
  }
 */



struct node{
  item value;
  struct node *next;
};


list newList(){return NULL;}

list consList(item e, list l){
  struct node *new_node;
  new_node = malloc(sizeof(struct node));
  if(new_node != NULL){
    new_node -> value = e;
    new_node -> next = l;
    l = new_node;
  } else printf("NULL ERROR\n");
  return l;
}


item getFirst(list l){
  item e;
  if(l != NULL)
    e=l->value;
  else
    e = NULLITEM;
  return e;
}

list tailList(list l){
  list tmp;
  if(l != NULL)
    tmp = l->next;
  else
    tmp = NULL;
  return tmp;
}

int emptyList(list l){return l==NULL;}

int sizeList(list l){
  int n=0;
  while(!emptyList(l)){
    l = tailList(l);
    n++;
  }
  return n;
}

int posItem(item e, list l){
  int n=0;
  int trovato=0;
  while(!emptyList(l) && !trovato){
    if (eq(e, getFirst(l)))
        trovato = 1 ;
    else{
        l = tailList(l);
        n++;
  }
}
  if(trovato) return n;
  else return -1;
}


int searchItem(list l, item e){
  int trovato = 0;
  while(!emptyList(l) && !trovato){
    if(eq(e, getFirst(l)))
      trovato = 1;
    else
      l = tailList(l);
  }
  return trovato;
}

list removeList(list l, int pos){
  list l1;
  if((pos == 0) && (l != NULL)){
    l1 = l;
    l = l->next;
    free(l1);
  } else{
    int i=0;
    list prec = l;
    while((i<pos-1) && (prec!=NULL)){
      prec = prec->next;
      i++;
    }
    if((prec != NULL) && (prec->next != NULL)){
      l1 = prec->next;
      prec->next = l1->next;
      free(l1);
    }
  }
  return l;
}

list insertList(list l, int pos, item e){

  if((pos == 0) && (l!=NULL)){
    l = consList(e, l);
  }
  else{
    list new = newList();
    new = consList(e, new);
    list prec = l;
    int i = 0;
    while((i < pos-1) && (prec != NULL)){
      prec = prec->next;
      i++;
    }
    if(prec != NULL && prec->next != NULL){
      list succ = prec->next;
      prec->next = new;
      new->next = succ;
    }
  }
  return l;
}

list reverseList(list l){
  list lrev = newList();
  item  val;
  while(!emptyList(l)){
    val = getFirst(l);
    lrev = consList(val, lrev);
    l = tailList(l);
  }
  return lrev;
}
