#include <string.h>

void scambia (int *x, int *y){
  int z = *(x);
  *x = *y;
  *y = z;
}
