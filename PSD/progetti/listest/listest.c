#include <stdio.h>
#include "../header/item.h"
#include "../header/list.h"

int main(){
  list l, lout;
  item in, out;
  l=newList();
  int answ = -1;
  int stopinp = 0;
  int pos;
  while(answ != 0){
    printf("1 riempire lista\n2 sizeList\n3 outputlist\n4 posItem\n5 searchItem\n6 reverseList\n7 removeList \n\n\n\n");
    scanf("%d", &answ);
    switch(answ){
      case 1:
        printf("Inserisci elementi");
        while(!stopinp){
            inputItem(&in);
            l=consList(in, l);
            printf("1/0\n");
            scanf("%d", &stopinp);
        }
      break;

      case 2:
        printf("%d\n", sizeList(l));
      break;

      case 3:
        lout = l;
        while(!emptyList(lout)){
          printf("\t%d\n", getFirst(lout));
          lout = tailList(lout);
        }
      break;

      case 4:
        printf("Inserisci valore item da cercare\n");
        inputItem(&in);
        printf("Item:%d Pos:%d\n", in, posItem(in, l));
      break;

      case 5:
        printf("Inserisci valore item da cercare\n");
        inputItem(&in);
        if(searchItem(l, in)) printf("Trovato\n");
        else printf("Non trovato\n");
      break;

      case 6:
        l=reverseList(l);
      break;

      case 7:
        printf("Inserisci posizione item da eliminare\n");
        scanf("%d", &pos);
        l = removeList(l, pos);
      break;

      case 8:
        printf("Inserisci posizione e valore da aggiungere \n");
        scanf("%d", &pos);
        inputItem(&in);
        l = insertList(l, pos, in);
      break;
  }
}
  return 0;
}
