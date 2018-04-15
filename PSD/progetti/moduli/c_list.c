#include <stdlib.h>
#include <stdio.h>
#include "../header/item.h"
#include "../header/c_list.h"

/*

PROGETTAZIONE:
Una lista è una sequenza concatenata di nodi, di conseguenza è stata
dichiarata una struttura node che costituisce il record ed il puntatore al
record successivo.
Con newList viene creata una nuova lista, che ritorna appunto NULL
che rappresenta un valore non definito, in c_list lista vuota viene indicato dalla variabile size, quando size=0.
Per quanto riguarda L'INSERIMENTO si utilizza insertList(list, pos, item)
la quale appunto prende in input la lista e il valore da aggiungervi.


Per calcolare la size della lista int sizeList(l):
1)Se (l!=NULL) si ritorna l->size altrimenti ritorna -1

Per ricavare un item dalla lista avendo la posizione item getItem(list, item):
1)Se la precondizione non è soddisfatta si ritorna NULLITEM
2)Altrimenti si assegna ad un nodo temporaneo tmpnode = l->first
3)Si itera usando tmpnode per scorrere la lista fino a pos
4)Si ritorna tmpnode->value

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
1)Se al precondizione non è soddisfatta si ritorna 0
2)Se è soddisfatta si crea un puntatore a nodo temporaneo, al quale
si assegna il valore di ritorno di insertNode(l->first, pos, e),
il cui valore ritornato non è altro che la lista puntata da l->first compresa di elemento e in posizione pos
3)Se il valore ritornato non è NULL allora si assegna a l->first = tmp e si incrementa l->size, si ritorna 1

Un'altra implementazione di reverseList è int reverseList2(l) la quale modifica la lista passata come parametro:
1) Se l == NULL si ritorna 0, Altrimenti
2) Si instanziano 3 nodi, prec, n, succ dove:
    n serve a scandire la lista
    prec punta all'elemento precedente a n
    succ punta all'elemento successivo a n
  All'inizio avremo che n = l->first, prec=NULL
3)Si itera con condizione n!=NULL e durante l'iterazione:
  Si assegna a succ n->next
  Si assegna a n->next prec
  Si assegna a prec n
  Infine si assegna ad n succ
4)Al termine si assegna ad l->first prec e si ritorna 1

Per la duplicazione di una list si utilizza list cloneList(l):
1)Se l == NULL si ritorna NULL
2)Se è vuota si ritorna newList()
3)Si istanzia un nodo tmp per scorrere l
4)Si istanzia la lista l1 che conterrà il duplicato
5)Si assegna a l1->first il valore del primo nodo di l con makeNode
6)Si itera finchè tmp != NULL
7)Con makeNode si copiano man mano i nodi di l in l1
6)All'uscita del ciclo si ritorna l1

Per svuotare la lista si utilizza int deleteList(l):
1) Se l == NULL si ritorna 0
2) Si istanziano due puntatori a nodo, tmp per scorrere e tmpdel per eliminare il nodo
3) Durante un ciclo while(tmp != NULL) si itera:
  tmpdel = tmp;
  tmp = tmp->next;
  free(tmpdel);
4)All'uscita si azzera la size e si mette l->first=NULL
5)Ritorna 1

Per inserire n elementi in una lista si utilizza list inputList(n):
1)Se n <= 0 si ritorna newList() Altrimenti
2)Si opera come cloneList per l'inserimento, si crea una list l = newList() e una variabile item e che costituirà i valori dei nodi
3)Si richiede all'utente di inserire il primo elemento inputItem(&e), si crea il primo nodo l->first = makeNode(e, NULL)
4)Si crea un nodo tmp per scorrere la lista a cui si fa puntare l->first
5)in un for(int i=1; i < pos; i++) si itera inputItem(&e); tmp->next = makeNode(e, NULL); tmp = tmp->next;
6)all'uscita si setta la size = n e si ritorna l
*/

struct c_list{
  item value;
  int size;
  struct node *first;
};


struct node{
  item value;
  struct node *next;
};

static struct node* insertNode(struct node *n, int pos, item e);
static struct node* makeNode(item e, struct node *nxt);
static struct node* removeNode(struct node *n, int pos);


static struct node* insertNode(struct node *n, int pos, item e){
  if(pos == 0)
  return makeNode(e, n);

  struct node *prec = n; // prec serve per scorrere la lista fino a puntare l'elemento prima di pos
  int i = 0;

  while(i < pos-1){
    prec = prec->next;
    i++;
  }
  struct node *n1;
  n1 = makeNode(e, prec->next);

  if(n1 == NULL)
  return NULL;

  prec->next = n1;

  return n;
}

static struct node* makeNode(item e, struct node *nxt){
  struct node *new = malloc(sizeof(struct node));
  if(new != NULL){
    new->value = e;
    new->next = nxt;
  }
  return new;
}

static struct node* removeNode(struct node *n, int pos){
  struct node *ndel; // nodo da cancellare
  if(pos == 0){
    ndel = n;
    n = n->next;
    free(ndel);
    return n;
  }

  int i = 0;
  struct node *prec = n;
  while((i < pos-1)){
    prec = prec->next;
    i++;
  }
  ndel = prec->next;
  prec->next = ndel->next;
  free(ndel);
  return n;
}

// Le funzioni che precedono il commento sono funzioni nascoste perchè necessarie alla realizzazione degli operatori
// ma non hanno un utilizzo pratico o sicuro per il client


list newList(){
  struct c_list *l = malloc(sizeof(struct c_list));
  if(l != NULL){
    l->value = NULL;
    l->size = 0;
  }
  return l;
}


int emptyList(list l){
  if(l == NULL) return -1;
  return l->size == 0;
}


int sizeList(list l){
  if(l == NULL) return -1;
  return l->size;
}

item getItem(list l, int pos){
  if(l == NULL) return NULLITEM;
  if(pos < 0 || pos > l->size) return NULLITEM;
  struct node *tmpnode = l->first;
  int i = 0;
  while(i<pos){
    tmpnode = tmpnode->next;
    i++;
  }
  return tmpnode->value;
}

int posItem(item e, list l){
  if(l == NULL) return -1;
  int trovato = 0;
  int i = 0;
  struct node *tmp = l->first;
  while(tmp != NULL && !trovato){
    if(eq(e, tmp->value)){
      trovato = 1;
    }
    else{
      i++;
      tmp = tmp->next;
    }
  }
  if(!trovato) i=-1;
  return i;
}




int searchItem(list l, item e){
  if(l == NULL) return 0;
  int trovato = 0;
  struct node *tmp = l->first;
  while(tmp != NULL && !trovato){
    if(eq(e, tmp->value)) trovato = 1;
    else{
      tmp = tmp->next;
    }
  }
  return trovato;
}

int removeList(list l, int pos){
  if( l == NULL )
    return 0;
  if(pos < 0 || pos >= l->size)
    return 0;
  /* PRECONDIZIONI */
  l->first = removeNode(l->first, pos);
  l->size--;
  return 1;

}


int insertList(list l, int pos, item e){
  if(l == NULL)
  return 0;
  if(pos < 0 || pos > l->size)
  return 0; /* precondizione */

  struct node *tmp = insertNode(l->first, pos, e);

  if(tmp == NULL)
  return 0;
  l->first = tmp;
  l->size ++;
  return 1;
}

list reverseList(list l){
  if(l == NULL)
    return NULL;

  list lrev = newList();
  struct node *temp = l->first;
  while(temp != NULL){
    lrev->first = makeNode(temp->value, lrev->first);
    temp = temp->next;
  }
  if(lrev != NULL)
    lrev->size = l->size;

  return lrev;
}

int reverseList2(list l){
  if(l == NULL)
    return 0;

  struct node *prec = NULL;
  struct node *n=l->first;
  struct node *succ;

  while (n != NULL) {
    succ = n->next;
    n->next = prec;
    prec = n;
    n = succ;
  }
  l->first = prec;
  return 1;
}

list cloneList(list l){
  if(l == NULL) return NULL;
  if(emptyList(l)) return newList();

  struct node *tmp = l->first;
  list l1 = newList();
  l1->first = makeNode(tmp->value, NULL);
  struct node *tmp1 = l1->first;

  while(tmp != NULL){
    tmp1->next = makeNode(tmp->next->value, NULL);
    tmp = tmp->next;
    tmp1 = tmp1->next;
  }
  l1->size = l->size;
  return l1;
}


int deleteList(list l){
  if(l == NULL)
    return 0;

  struct node *tmp = l->first;
  struct node *tmpdel;

  while(tmp != NULL){
    tmpdel = tmp;
    tmp = tmp->next;
    free(tmpdel);
  }
  l->size = 0;
  l->first = NULL;
  return 1;
}

list inputList(int n){
  if(n <= 0) return newList();
  list l = newList();
  item e;
  printf("Inserire elemento pos 0\n");
  inputItem(&e);
  l->first = makeNode(e, NULL);
  struct node *tmp = l->first;
  for(int i=1; i < n; i++){
    printf("Elemento in pos:%d\n", i);
    inputItem(&e);
    tmp->next = makeNode(e, NULL);
    tmp = tmp->next;
  }
  l->size = n;
  return l;
}

int outputList(list l){
  if(l == NULL) return 0;
  struct node *tmp = l->first;
  for(int i=0; i < l->size; i++){
    outputItem(tmp->value);
    printf("\n");
    tmp = tmp->next;
  }
  return 1;
}
