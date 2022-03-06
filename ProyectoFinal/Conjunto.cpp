#include <iostream>
using namespace std;
#include "Conjunto.h"



Conjunto::Conjunto() {
      nombre = "NN";
      tamano = 0;
      co_junto = new string [tamano];
}

Conjunto::~Conjunto() {
      //dtor
}
void Conjunto::setNombre(){
cout<<"digite el nombre del conjunto:";
getline(cin,nombre);
}


void Conjunto::setTamano() {

      bool validador = true;
      do {
            cout<<"Digite el tamaño del conjunto:";
            cin>>tamano;
            if(tamano>50 || tamano <1) {
                  cout<<"Fuera Rango,digite el tamaño nuevamente";
                  validador = false;
            }
            else{
                validador = true;
            }

      } while(validador == false);

      co_junto =  new string [tamano];
}

void Conjunto::setDatos() {

string dato;
fflush(stdin);

      cout<<"INGRESAR ELEMENTOS DEL CONJUNTO :"<<nombre<<endl<<endl;
      for(int i=0;i<tamano;i++) {

      cout<<"digite el elemento posicion:"<<i+1<<" ->";
      getline(cin,dato);

      co_junto[i] = dato;

      }


}

int Conjunto::getTamano(){
return tamano;
}


string Conjunto::getNombre(){
return nombre;
}


string Conjunto::getDatos(){

string mensaje = "";

for(int i = 0 ; i<tamano;i++){

    mensaje += co_junto[i];
     if(i!=tamano-1){
                mensaje += ",";
            }
}


return nombre + " = {" + mensaje + "}";
}



string Conjunto::getDato(int ind){
    return co_junto[ind];
}


