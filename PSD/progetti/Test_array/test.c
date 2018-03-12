#include "../header/vettore.h"
int main(void){
  int A[10] = {1, 2, 3, 3, 4, 5, 6};
  int n = 7;
  elimina_elemento(A, &n, 3);
  out_array(A, n);
  return 0;
}
