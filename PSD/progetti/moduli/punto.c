/*
  Specifica sintattica:
    Tipo di riferimento: Punto
    Tipi di dati usati: reale
  Specifica semantica:
    Il tipo libro è dato dalla coppia di cordinate x,y, acquisite
    come valori reali

  OPERATORI

  Specifica sintattica
  -creaPunto(reale,reale) = Punto
  -ascissa(punto) = reale
  -ordinata(punto) = reale
  -distanza(punto, punto) = reale

  Specifica semantica
  -creaPunto(x, y) = p
      post: p = (x,y)
  -ascissa(p) = x
      post: p = (x,y)
  -ordinata(p) = y
      post: p = (x,y)
  -distanza(p1,p2) = d
      post: d = sqrt((p1.x - p2.x)² + (p1.y - p2.y)²)

*/

#include "../header/punto.h"
#include <math.h>
#include <stdlib.h>

struct pto{
  float x;
  float y;
};

punto creaPunto(float x, float y){
  punto p = malloc(sizeof(*p));
  p->x = x;
  p->y = y;
  return p;
}


float ascissa(punto p){return p->x;}

float ordinata(punto p){return p->y;}

float distanza(punto p1, punto p2){
    float dx, dy;
    dx = p1->x - p2->x;
    dy = p1->y - p2->y;
    return sqrt((dx*dx) + (dy*dy));
}
