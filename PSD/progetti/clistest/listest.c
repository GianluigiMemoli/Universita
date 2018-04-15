#include <stdio.h>
#include "../header/item.h"
#include "../header/c_list.h"

int main(){
  list l,l1;
  int answ;
  do{
    int n;
    item e;
    int pos;

    printf("1 inputList\n2 outputList\n3 sizeList\n4 reverse1 \n5 reverse2 \n6 removeList \n7 searchItem\n8 insertList ");
    scanf("%d", &answ);
    switch (answ) {
      case 1:
        printf("Quanti elementi inserire\n");
        scanf("%d", &n);
        l = inputList(n);
      break;

      case 2:
        if(!outputList(l)) printf("Errore outputList \n");
      break;

      case 3:
        printf("size: %d", sizeList(l));
      break;

      case 4:
        l1 = reverseList(l);
        if(!outputList(l1)) printf("Errore outputList \n");
      break;

      case 5:
        reverseList2(l);
        if(!outputList(l)) printf("Errore outputList \n");
      break;

      case 6:
        printf("Posizione:");
        scanf("%d", &pos);
        if(!removeList(l, pos)) printf("Errore rimozione \n");
      break;

      case 7:
        printf("Elemento da cercare:");
        inputItem(&e);
        if(searchItem(l, e)) printf("presente \n");
        else printf("non presente n");
      break;

      case 8:
        printf("Inserisci posizione elemento: ");
        scanf("%d", &pos);
        printf("Inserisci val elemento: ");
        inputItem(&e);
        if(insertList(l, pos, e)) printf("Inserimento ok!");
        else printf("Err inserimento\n");
        if(!outputList(l)) printf("Errore outputList \n");
      break;
    }
  }while(answ != 0);

  return 0;
}
