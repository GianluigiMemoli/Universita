#include "../header/vettore.h"
#include "../header/file_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 20
int run_test_case(char *tc_id, int n){
  char fn_oracle[LEN];
  char fn_input[LEN];
  char fn_output[LEN];
  int *a, *oracle, esito;
  FILE *f_input, *f_output, *f_oracle;
  /* Costruisco i filename */
  sprintf(fn_oracle, "%s_oracle.txt", tc_id);
  sprintf(fn_output, "%s_output.txt", tc_id);
  sprintf(fn_input, "%s_input.txt", tc_id);
  /* Apro e testo i file */
  f_input = fopen(fn_input, "r");
  test_file(f_input, fn_input);
  f_output = fopen(fn_output, "w");
  test_file(f_output, fn_output);
  f_oracle = fopen(fn_oracle, "r");
  test_file(f_oracle, fn_oracle);

  /* Alloco e carico gli array */
  a = (int *) calloc(n, sizeof(int));
  oracle = (int *) calloc(n, sizeof(int));
  finput_array(f_input, a, n);
  finput_array(f_oracle, oracle, n);
  bubble_sort(a, n);
  foutput_array(f_output, a, n);
  fclose(f_input);
  fclose(f_output);
  fclose(f_oracle);
  /* ritorno il valore del confronto tra a e oracle */
  esito = confronta_array(a, oracle, n);
  free(a);
  free(oracle);

  return esito;
}

int main(int argc, char *argv[]){
  if(argc < 3){
    printf("numero parametri errato");
    exit(1);
  }
  int n;
  char tc_id[LEN];
  FILE *suite, *result;
  suite = fopen(argv[1], "r");
  test_file(suite, argv[1]);
  result = fopen(argv[2], "w");
  test_file(result, argv[2]);

  while(fscanf(suite, "%s %d", tc_id, &n) != EOF){
    if(run_test_case(tc_id, n)){
      fprintf(result, "%s PASS\n",tc_id );
    }
    else{
      fprintf(result, "%s FAIL\n",tc_id );
    }
  }
  fclose(suite);
  fclose(result);
}
