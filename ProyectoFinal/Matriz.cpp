#include "Matriz.h"
#include <iostream>
using namespace std;
Matriz::Matriz() {
      nombre = "nn";
      filas = 2;
      columnas = 2;

      matriz = new int *[filas];

      for(int i = 0; i<filas; i++) {
            matriz[i] = new int [columnas];
      }

      limpiarMatriz();

}

Matriz::~Matriz() {
      //dtor
}


void Matriz::limpiarMatriz() {
      for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                  matriz[i][j] = 0;
            }
      }

}

void Matriz::ingresarElementos() {
      for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                  cout<<"Ingresar Elemento fila["<<i+1<<"]"<<"columna["<<j+1<<"]->";
                  cin>>matriz[i][j];
            }
            cout<<endl;
      }


}

void Matriz::setDatosMatriz() {
      fflush(stdin);
      cout<<"Digite el nombre de la matriz:";
      getline(cin,nombre);

      cout <<"Digite las filas:";
      cin>>filas;

      cout<<"Digite las columnas:";
      cin>>columnas;


      matriz = new int *[filas];
      for(int i = 0; i<filas; i++) {
            matriz[i] = new int [columnas];
      }

      limpiarMatriz();

      ingresarElementos();


}





string Matriz::getNombre(){return nombre;}
int Matriz::getFilas(){return filas;}
int Matriz::getColumnas(){return columnas;}
void Matriz::getDatosMatriz(){

for(int i = 0;i<filas;i++){

    for(int j=0;j<columnas;j++){
        cout<<matriz[i][j];
        cout<<" ";
    }
    cout<<endl;
}





}
