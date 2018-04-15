/* SPECIFICA SINTATTICA OPERATORI
    -eq(item, item)->boolean
    -inputItem(item)->void
    -outputItem(item)->void

   SPECIFICA SEMANTICA
    -eq(item1, item2) -> b
      PRE: //
      POST: se item1 è uguale a item2 allora b=1, altrimenti b=0

    gli altri operatori non necessitano di condizioni
    */
#define NULLITEM 0
typedef int item;

int eq(item, item);
void inputItem(item *);
void outputItem(item);
