#include "Triangulo.h"
#include <math.h>
#define PI 3.1415926536

Triangulo::Triangulo() {
      angulo = 0;
      catetoAdyacente = 0;
      catetoOpuesto = 0;
      hipotenusa = 0;
}

Triangulo::~Triangulo() {
      //dtor
}


void Triangulo::setCatetoOpuesto(float cat_o){
catetoOpuesto = cat_o;
}

void Triangulo::setAngulo(float ang){
angulo = ang*PI/180;
}

float Triangulo::getHipotenusa(){return hipotenusa;}
float Triangulo::getCatetoOpuesto(){return catetoOpuesto;}
float Triangulo::getAngulo(){return angulo;}

float Triangulo:: CalcularDistancia(){

float operacion;
operacion = catetoOpuesto/sin(angulo);

hipotenusa = operacion;

return hipotenusa;
}
