#include <stdio.h>
#include "../header/item.h"
int eq(item e1, item e2){
  return e1 == e2;
}

void inputItem(item *e){
  scanf("%d", e);
}

void outputItem(item e){
  printf("%d\n", e);
}
