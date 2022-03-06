#include "Vector.h"

Vector::Vector() {
     nombre = "NN";
      tamano = 0;
      vec = new int [tamano];
}

Vector::~Vector() {

}

void Vector::setNombre() {
      fflush(stdin);
      cout<<"Digite el nombre del Vector:";
      getline(cin,nombre);
}

void Vector::setTamano(int n) {
      tamano = n;
      vec =  new int [tamano];
}

void Vector::setDatos() {
      int dato;
      cout<<"INGRESAR COMPONENTES DEL VECTOR:"<<nombre<<endl<<endl;
      for(int i=0; i<tamano; i++) {
            cout<<"componente :"<<i+1<<" ->";
            cin>>dato;

            vec[i] = dato;
      }
}


int Vector::getDato(int ind) {
      return vec[ind];
}

string Vector::getNombre() {
      return nombre;
}
int Vector::getTamano() {
      return tamano;
}

string Vector::getDatos() {


      string mensaje = "";

      for(int i = 0 ; i<tamano; i++) {


            mensaje += to_string(vec[i]);
            if(i!=tamano-1){
                mensaje += ",";
            }



      }


      return nombre + " = (" + mensaje + ")";

}
