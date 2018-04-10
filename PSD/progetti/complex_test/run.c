#include <stdio.h>
#include "../header/complex.h"

int main(){
  complex c1 = CreaComplex(2, "i");
  printf("%2.f+%s\n", ParteReale(c1), ParteImmaginaria(c1));
  complex c2 = CreaComplex(2, "i");
  printf("%2.f+%s\n", ParteReale(c2), ParteImmaginaria(c2));
  complex c3 = SommaComplex(c1,c2);
  printf("%2.f+%s\n", ParteReale(c3), ParteImmaginaria(c3));

  return 0;
}
