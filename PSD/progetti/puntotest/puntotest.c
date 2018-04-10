#include "../header/punto.h"
#include <stdio.h>

int main(){
  punto p;
  p = creaPunto(2, 2);
  printf("x:%f\n", ascissa(p));
  printf("y:%f\n", ordinata(p));
}
