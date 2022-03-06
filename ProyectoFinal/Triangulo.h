#ifndef TRIANGULO_H
#define TRIANGULO_H
#include <math.h>

class Triangulo {
public:
      float hipotenusa,catetoOpuesto,catetoAdyacente,angulo;
      Triangulo();
      virtual ~Triangulo();
      void setCatetoOpuesto(float);
      void setCatetoAdyacente(float);
      void setAngulo(float);

      float getHipotenusa();
      float getCatetoOpuesto();
      float getCatetoAdyacente();
      float getAngulo();
      float CalcularDistancia();
protected:

private:
};

#endif // TRIANGULO_H

