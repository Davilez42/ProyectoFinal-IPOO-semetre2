
#include <iostream>
#include <vector>
#include "math.h"
#include "Vector.h"
#define PI 3.1415926536
using namespace std;


//calcula el producto punto dado dos vectores y retorna la operacion
int productoPunto(Vector vec1,Vector vec2) {
      int n = vec1.getTamano();
      int resultado=0;

      for(int i = 0; i<n; i++) {
            resultado += vec1.getDato(i)*vec2.getDato(i);
      }
      return resultado;
}

double calcularModulo(Vector vec) {
    double resultado;
    int sumacuadrados = 0;
    int n = vec.getTamano();
      for(int i = 0;i<n;i++){
        sumacuadrados += pow(vec.getDato(i),2 );
      }
resultado = sqrt(sumacuadrados);
      return resultado;
}


double calcularAnguloVectores(Vector vec1,Vector vec2){
double operacion;
operacion = (productoPunto(vec1,vec2))/(calcularModulo(vec1)*calcularModulo(vec2));
return acos(operacion)*180/PI;
}
