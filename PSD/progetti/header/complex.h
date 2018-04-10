
typedef struct comp *complex;

complex CreaComplex(float x, char *y);

float ParteReale(complex c);
char * ParteImmaginaria(complex c);

int getImmCoeff(char *imm);

complex SommaComplex(complex c1, complex c2);
