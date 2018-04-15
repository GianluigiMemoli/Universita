/*
  SPECIFICA ADT LISTA
      SPECIFICA SINTATTICA:
        Tipo di riferimento: list
        Tipi usati: item, boolean, integer
        (item è un elemento generico che viene utilizzato per rendere la lista utilizzabile con qualsiasi tipo di dato)
      OPERATORI:
        -newList()->list
        -emptyList(list)->boolean
        -getFirst(list)->item
        -consList(list, item)->list
        -tailList(list)->list
        -sizeList(list)->integer
        -posItem(list, item)->integer
        -searchItem(list, integer)->boolean
        -reverseList(list)->list
        -removeItem(list, item)->list
        -getItem(list, integer, item)->list
        -insertList(list, integer, item)->list
        -removeList(list, integer)->list
        -cloneList(list)->list
    SPECIFICA SEMANTICA:

    -newList() -> l
      PRE: //
      POST: l = nil

    -emptyList(l) -> b
      PRE: //
      POST: se l=nil, allora b=true, altrimenti b=false

    -getFirst(l)->e
      PRE: l = <a1,a2,...,an>, n>0
      POST: e=a1

    -consList(e, l)->l'
      PRE://
      POST: l=<a1, a2, ..., an> AND l' = <e, a1, a2, ..., an>

    -tailList(l) -> l'
      PRE: l = <a1, a2, ..., an> n>0
      POST: l' = <a2, a3, ..., an>

    -sizeList(l) -> n
      POST: l=<a1, a2, ---, an> AND n>=0

    -posItem(l, e) -> j
      POST: se e è contenuto in l, allora j conterrà la posizione
            della prima occorrenza altrimenti j=-1

    -searchItem(l, e) -> b
      POST: se e è contenuto in l, allora b=true altrimenti b=false

    -reverseList(l1) -> l2
      POST: l1=<a1, a2, ..., an> AND l2 = <an, ..., a2, a1>

    -getItem(l, pos) -> e
      PRE= l=<a1, a2, ..., an> AND 0<= pos <= n
      POST= se e è contenuto in l, allora e conterrà l'elemento in posizione pos della lista
              altrimenti e=NULLITEM

    -insertList(l, pos, e) -> l'
      PRE: l=<a1, a2, ..., an> AND 0<=pos<=n
      POST: l' conterrà e in posizione pos AND n=n+1

    -removeList(l, pos) -> l'
      PRE: l=<a1, a2, ..., an> AND pos 0<=pos<=n
      POST: l' non conterrà il valore in posizione pos AND n--

    -cloneList(l) -> l_clone
      POST: l_clone = l = <a1,a2, ..., an>

    -deleteList(l)->l'
      POST: l = <a1, a2, ..., an> AND l' = nil

    -reverseList2(l)-> l',b
      POST: l = <a1, a2, .., an> AND l' = <an, ..., a2, a1>

    -inputList(n) -> l
      POST: l = <a1, a2, ..., an>
*/

typedef struct c_list *list;

list newList(); // x
int emptyList(list); /*x Nonostante quanto scritto nella specifica si utilizza int come ritorno non esistendo in C un tipo "boolean"*/
int sizeList(list); //x
int posItem(item, list); //x
int searchItem(list, item); //x
list reverseList(list); //x
item getItem(list, int); //x
int insertList(list, int, item); //
int removeList(list, int); //x
int reverseList2(list);
list cloneList(list);
int deleteList(list);
list inputList(int n);
int outputList(list);
