  #include "../header/vettore.h"
  #include "../header/file_utils.h"
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #define LEN 20

  int main(int argc, char *argv[]){
    FILE *test_suite, *input, *oracle, *output, *result;
    char tc_name [3], tmp[30];
    char
    int *a,*b, n;
    /* il nome del file che contiene i TCn viene dato da linea di comando */
    test_suite = fopen(argv[1], "r");
    test_file(test_suite, argv[1]);

    result = fopen("result.txt", "w");
    test_file(result, argv[1]);
    strcpy(tmp, tc_name);
    while(!feof(test_suite)){
      fscanf(test_suite, "%s %d", tc_name, &n);
      a = (int *) calloc(n, sizeof(int));
      strcpy(tmp, tc_name);
      printf("tmp: %s\ntc: %s\n", tmp, tc_name);

      input = fopen(strcat(tmp, "_input.txt"), "r");                             //  Creo i collegamenti con i file a partire dal TCx
      test_file(input, strcat(tmp, "_input.txt"));                              //   e testo la corretta apertura di essi
      strcpy(tmp, tc_name);
      printf("tmp: %s\ntc: %s\n", tmp, tc_name);

      oracle = fopen(strcat(tmp, "_oracle.txt"),"r");
      test_file(input, tmp);
      strcpy(tmp, tc_name);
      printf("tmp: %s\ntc: %s\n", tmp, tc_name);

      output = fopen(strcat(tmp, "_output.txt"), "w");
      test_file(input, tmp);                           // *******************************************************
      strcpy(tmp, tc_name);
      printf("tmp: %s\ntc: %s\n", tmp, tc_name);

      finput_array(input, a, n);
      out_array(a, n);
      bubble_sort(a,n);
      foutput_array(output, a, n);
      b = calloc(n, sizeof(int));

      finput_array(oracle, b, n);
      out_array(b, n);
      printf("^^b\n\n\n");
      if(confronta_array(a,b,n)){
        fprintf(result, "%s %s\n", tc_name, "Pass");
      }
      else{
        fprintf(result, "%s %s\n", tc_name, "Fail");
      }
       fclose(input);
       fclose(output);
       fclose(oracle);
       free(a);
       free(b);
    }
    fclose(result);
    fclose(test_suite);

    return 0;
  }
