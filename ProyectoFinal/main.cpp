#include <iostream>
#include <vector>
#include "Conjunto.h"
#include "Herramientas.h"
#include "HerramientasCalculo.h"
#include "Matriz.h"
#include <math.h>
#include "HerramientasAlgebra.h"
#include "Triangulo.h"
#include "Funcion.h"
#include "Vector.h"

using namespace std;

//prototipos de funciones principales
void submenuCalculo();
void submenuAlgebra();
void submenuMatematicasDiscretas();
void menuPrincipal();
///-------------------------------------------------------------------------------------------------------------------------
///MATEMATICAS DISCRETAS
//prototipos,atributos funciones matematicas discretas
int n_cojuntos;
Conjunto *arrayConjuntos;
void ingresarConjuntos();
void submenuOperacionesBasicas();
void submenuConjuntos();
void unioncojunt();
void diferenciacojunt();
void intercepcioncojunt();
//definiciones de funciones matematicas discretas
void submenuConjuntos() {
      system("cls");
      int opcion;
      do {
            system("cls");
            cout<<"---------CONJUNTOS-----"<<endl;
            cout<<"1.ingresar cojuntos"<<endl;
            cout<<"2.operaciones basicas cojuntos"<<endl;
            cout<<"0.salir al menu principal"<<endl<<endl;
            cout<<"digite una opcion:";
            cin>>opcion;
            switch(opcion) {
            case 1:
                  ingresarConjuntos();
                  break;
            case 2:
                  submenuOperacionesBasicas();
                  break;

            case 0:break;
            default:
                cout<<"\n-------------------------------"<<endl;
                cout<<"Error,Digite una opcion correcta"<<endl;
                cout<<"---------------------------------"<<endl;
                system("pause");
            }
      } while(opcion !=0);
}
void ingresarConjuntos() {
      fflush(stdin);
      system("cls");
      bool validador = true;
      //BUCLE PARA VALIDAR TAMAÑO DEL ARREGLO
      do {
            cout<<"digite la cantida de conjuntos:";
            cin>>n_cojuntos;
            if(n_cojuntos <2 || n_cojuntos>4) {
                  cout<<"\n--------------------------------------------------------------"<<endl;
                  cout<<"Porfavor digite una cantida mayor o igual  2 y  menor igual a 4"<<endl;
                  cout<<"--------------------------------------------------------------"<<endl;
                  system("pause");
                  system("cls");

                  validador = false;
            } else {
                  validador = true;
            }
      } while(validador == false);




      arrayConjuntos = new Conjunto [n_cojuntos];

      Conjunto obj;
      fflush(stdin);
//creo ciclo para ingresar los conjuntos
      for(int i=0; i<n_cojuntos; i++) {
            system("cls");
            cout<<"Conjunto "<<i+1<<endl;
            obj.setNombre();
            obj.setTamano();
            cout<<endl;
            obj.setDatos();
            arrayConjuntos[i] = obj;
            cout<<endl;
            cout<<"Informacion ingresada"<<endl;
            cout<<obj.getDatos()<<endl<<endl;

            system("pause");

      }


}
void submenuOperacionesBasicas() {
      if(n_cojuntos >0) {
            int opcion;

            do {
                  system("cls");

                  imprirlistaC(arrayConjuntos,n_cojuntos);


                  cout<<endl;
                  cout<<"digite la operacion que desea aplicar a los conjuntos ya ingresados"<<endl;
                  cout<<"1.Intecepcion"<<endl;
                  cout<<"2.Union"<<endl;
                  cout<<"3.diferencia"<<endl;
                  cout<<"0..Volver al menu"<<endl<<endl;

                  cout<<"digite una opcion:";
                  cin>>opcion;

                  switch(opcion) {
                  case 1:
                        intercepcioncojunt();
                        break;
                  case 2:
                        unioncojunt();
                        break;
                  case 3:
                        diferenciacojunt();
                        break;

                   case 0:break;
                   default:
                cout<<"\n-------------------------------"<<endl;
                cout<<"Error,Digite una opcion correcta"<<endl;
                cout<<"---------------------------------"<<endl;
                system("pause");
                  }
            } while(opcion !=0);
      } else {
          system("cls");
          cout<<"\n--------------------------------------"<<endl;
            cout<<"Porfavor Primero ingrese los Conjuntos"<<endl;
            cout<<"--------------------------------------"<<endl;
            system("pause");
      }
}
void unioncojunt() {

      fflush(stdin);
      cout<<endl;
      vector <string> resultadoUnion;
      string c1,c2;
      cout<<"ingrese el nombre del cojunto 1:";
      getline(cin,c1);
      cout<<"ingrese el nombre del cojunto 2:";
      getline(cin,c2);

      for(int i=0; i<n_cojuntos; i++) {

            if(arrayConjuntos[i].getNombre() == c1 || arrayConjuntos[i].getNombre() == c2) {

                  for(int j=0; j<arrayConjuntos[i].getTamano(); j++) {
                        resultadoUnion.push_back ( arrayConjuntos[i].getDato(j) );
                  }
            }
      }



      int n = resultadoUnion.size();
//encuentro los valores que se repiten y los remplazo por la palabra REP
      encontrarRepetidos(resultadoUnion,n);

      //recorre el vector y donde encuentra la palabra REP lo elimina
      eliminarElemento(resultadoUnion);
      //imprime los conjuntos con los que hizo la operacion
      system("cls");
      cout<<"CONJUNTOS"<<endl;
      impriC(arrayConjuntos,c1,c2,n_cojuntos);

          n= resultadoUnion.size();
      string con = "", mensaje = "";
//imprimo el resultado
      for(int i = 0; i<n; i++) {
            con +=resultadoUnion.at(i);
             if(i!=n-1){
                con += ",";
            }
      }
      mensaje = c1+"U"+c2 + "= {" + con + "}";
      cout<<endl;
      cout<<mensaje<<endl<<endl;
      system("pause");
}
void diferenciacojunt() {
      cout<<endl;
      vector <string> resultadodiferencia;
      fflush(stdin);
      string c1,c2;
      int ind1,ind2;
      cout<<"ingrese el nombre del cojunto 1:";
      getline(cin,c1);
      cout<<"ingrese el nombre del cojunto 2:";
      getline(cin,c2);
      ind1 = encontrarindice(arrayConjuntos,c1,n_cojuntos);
      ind2 = encontrarindice(arrayConjuntos,c2,n_cojuntos);
//agrego todos los elementos del cojunto 1 al vector
      for(int i = 0; i<arrayConjuntos[ind1].getTamano(); i++  ) {
            resultadodiferencia.push_back(arrayConjuntos[ind1].getDato(i) );
      }
//analizo si los elementos del  vector estan repetidos en el cojunto2
      int n = resultadodiferencia.size();
      for(int i = 0; i<n; i++) {
            for(int j = 0; j<arrayConjuntos[ind2].getTamano(); j++) {

                  if(resultadodiferencia.at(i) == arrayConjuntos[ind2].getDato(j) ) {
                        resultadodiferencia[i] = "REP";
                  }
            }
      }
//donde encuentra la palabra REP es por que ahi habia un elemento repetido tanto en el cojunto 1 y en el conjunto2
      eliminarElemento(resultadodiferencia);
//imprimir conjuntos
      system("cls");
      cout<<"CONJUNTOS"<<endl;
      impriC(arrayConjuntos,c1,c2,n_cojuntos);
      string con = "", mensaje = "";
n = resultadodiferencia.size();
      for(int i = 0; i<n; i++) {
            con += resultadodiferencia.at(i);
            if(i!=n-1){
                con += ",";}
      }
      mensaje = c1+" - "+c2 + "= {" + con + "}";
      cout<<endl;
      cout<<mensaje<<endl<<endl;
      system("pause");




}
void intercepcioncojunt() {
      cout<<endl;
      fflush(stdin);
      vector <string> resultadointercepcion;
      string c1,c2;
      int ind1,ind2;
      cout<<"ingrese el nombre del cojunto 1:";
      getline(cin,c1);
      cout<<"ingrese el nombre del cojunto 2:";
      getline(cin,c2);

      ind1 = encontrarindice(arrayConjuntos,c1,n_cojuntos);
      ind2 = encontrarindice(arrayConjuntos,c2,n_cojuntos);

//comparo el conjunto 1 con el conjunto 2 y voy guardando en el vector los elementos repetidos
      for(int i = 0; i<arrayConjuntos[ind1].getTamano(); i++  ) {
            for(int j = 0; j<arrayConjuntos[ind2].getTamano(); j++ ) {
                  if(arrayConjuntos[ind1].getDato(i) == arrayConjuntos[ind2].getDato(j) ) {
                        resultadointercepcion.push_back(arrayConjuntos[ind1].getDato(i));
                  }
            }
      }
//elimino elementos repetidos
      int n = resultadointercepcion.size();
      encontrarRepetidos(resultadointercepcion,n);

//donde encuentra la palabra REP es por que ahi habia un elemento repetido tanto en el cojunto 1 y en el conjunto2
      eliminarElemento(resultadointercepcion);
//imprimir conjunto
      system("cls");
      cout<<"CONJUNTOS"<<endl;
      impriC(arrayConjuntos,c1,c2,n_cojuntos);
      string con = "", mensaje = "";
n=resultadointercepcion.size();
      for(int i = 0; i<n; i++) {
            con += resultadointercepcion.at(i);
            if(i!=n-1){
                con += ",";}

      }
      mensaje = c1+" I "+c2 + "= {" + con + "}";
      cout<<endl;
      cout<<mensaje<<endl<<endl;
      system("pause");
}
///menu principal matematicas discretas
void submenuMatematicasDiscretas() {

      system("cls");
      int opcion;

      do {
            system("cls");
            cout<<"---------MATEMATICAS DISCRETAS-----"<<endl;
            cout<<"[1].Operaciones con Conjuntos"<<endl;
            cout<<"[2].Operaciones con sistemas numéricos"<<endl;
            cout<<"[0].salir al menu principal"<<endl<<endl;


            cout<<"digite una opcion:";
            cin>>opcion;

            switch(opcion) {
            case 1:
                  submenuConjuntos();
                  break;


             case 0:break;
              default:
                cout<<"\n-------------------------------"<<endl;
                cout<<"Error,Digite una opcion correcta"<<endl;
                cout<<"---------------------------------"<<endl;
                system("pause");
            }

      } while(opcion !=0);



}


///-------------------------------------------------------------------------------------------------------------------------
///CALCULO
//prototipos funciones, atributos
void problemaMatematico();
void dada2funciones();
//definicion de funciones
void calcDistanciaFunciones() {
      int opcion;
      do {
            system("cls");
            cout<<"FUNCIONES"<<endl;
            cout<<"1.F(x) = 2x^2 +1"<<endl;
            cout<<"2.F(x) = x^2"<<endl;
            cout<<"3.F(x) = x + 1"<<endl;
            cout<<"4.F(x) = 4x^4-20x^3+3"<<endl;
            cout<<"5.F(x) = x^2/2"<<endl;
            cout<<"0.Volver al Submenu Calculo"<<endl;
            cout<<"digite una opcion:";
            cin>>opcion;
            switch(opcion) {
            case 1:
                  Integral(F1);
                  break;
            case 2:
                  Integral(F2);
                  break;
            case 3:
                  Integral(F3);
                  break;
            case 4:
                  Integral(F4);
                  break;
            case 5:
                  Integral(F5);
                  break;

            case 0:break;
             default:
                cout<<"\n-------------------------------"<<endl;
                cout<<"Error,Digite una opcion correcta"<<endl;
                cout<<"---------------------------------"<<endl;
                system("pause");


            }

      } while(opcion != 0);
}

void dada2funciones(){


  system("cls");

int opc1,lim_inf1,lim_supe1,opc2,lim_inf2,lim_supe2;
bool validador1= true,validador2 = true;




do{
        validador1 = true;
        system("cls");
        cout<<"Calcular Interceptos, si son paralelas o perpendiculares dada 2 FUNCIONES"<<endl;
            cout<<"1.F(x) = -4x+x"<<endl;//F6
            cout<<"2.F(x) = x^2"<<endl;//F7
            cout<<"3.F(x) = 2x^3+3x"<<endl;//F8
            cout<<"4.F(x) = -x+3x"<<endl;//F9
            cout<<"5.F(x) = 6x+x+8"<<endl;//F10
            cout<<"6.F(x) = x-4"<<endl;//F11
            cout<<"7.F(x) = x+20"<<endl;//F12
            cout<<"8.F(x) = -x"<<endl;//F13
            cout<<"0.Volver al Submenu Calculo"<<endl<<endl;

            cout<<"digite la primer funcion:";
            cin>>opc1;
            if(opc1==0 || opc1<0 || opc1>8){
                 cout<<"\n----------------------"<<endl;
                    cout<<"Error,opcion incorrecta"<<endl;
                    cout<<"-------------------------"<<endl;
                    system("pause");
                validador1 = false;
            }
            else{
                validador1 = true;
            }
}while(validador1 == false);


            cout<<"Digite el intervalo inferior:";
            cin>>lim_inf1;
            cout<<"Digite el intervalo superior:";
            cin>>lim_supe1;
            cout<<endl;



 do{
        validador2 = true;
        system("cls");
        cout<<"Calcular Interceptos, si son paralelas o perpendiculares dada 2 FUNCIONES"<<endl;
            cout<<"1.F(x) = -4x+x"<<endl;//F6
            cout<<"2.F(x) = x^2"<<endl;//F7
            cout<<"3.F(x) = 2x^3+3x"<<endl;//F8
            cout<<"4.F(x) = -x+3x"<<endl;//F9
            cout<<"5.F(x) = 6x+x+8"<<endl;//F10
            cout<<"6.F(x) = x-4"<<endl;//F11
            cout<<"7.F(x) = x+20"<<endl;//F12
            cout<<"8.F(x) = -x"<<endl;//F13
            cout<<"0.Volver al Submenu Calculo"<<endl<<endl;
            cout<<"digite la segunda funcion:";
            cin>>opc2;
            if(opc2==0 || opc2<0 || opc2>8){
                    cout<<"\n----------------------"<<endl;
                    cout<<"Error,opcion incorrecta"<<endl;
                    cout<<"-------------------------"<<endl;
                    system("pause");
                validador2 = false;
            }
            else{
                    if(opc2==opc1){
                            cout<<"NO se puede comparar la misma funcione"<<endl;
                            validador2 = false;


                    }else{
                    validador2 = true;
                    }
            }
}while(validador2 == false);

            cout<<"Digite el intervalo inferior:";
            cin>>lim_inf2;
            cout<<"Digite el intervalo superior:";
            cin>>lim_supe2;

system("cls");
///compara todos los casos posibles de las funciones que el usuario escoja utilizando switches anidados
switch(opc1){
case 1:
       switch(opc2){
       case 2:intercepto(F6,lim_inf1,lim_supe1,F7,lim_inf2,lim_supe2);paralelas(F6,F7);perpendiculares(F6,F7);break;
       case 3:intercepto(F6,lim_inf1,lim_supe1,F8,lim_inf2,lim_supe2);paralelas(F6,F8);perpendiculares(F6,F8);break;
       case 4:intercepto(F6,lim_inf1,lim_supe1,F9,lim_inf2,lim_supe2);paralelas(F6,F9);perpendiculares(F6,F9);break;
       case 5:intercepto(F6,lim_inf1,lim_supe1,F10,lim_inf2,lim_supe2);paralelas(F6,F10);perpendiculares(F6,F10);break;
       case 6:intercepto(F6,lim_inf1,lim_supe1,F11,lim_inf2,lim_supe2);paralelas(F6,F11);perpendiculares(F6,F11);break;
       case 7:intercepto(F6,lim_inf1,lim_supe1,F12,lim_inf2,lim_supe2);paralelas(F6,F12);perpendiculares(F6,F12);break;
       case 8:intercepto(F6,lim_inf1,lim_supe1,F13,lim_inf2,lim_supe2);paralelas(F6,F13);perpendiculares(F6,F13);break;
       };break;
case 2:switch(opc2){
       case 1:intercepto(F7,lim_inf1,lim_supe1,F6,lim_inf2,lim_supe2);paralelas(F7,F6);perpendiculares(F7,F6);break;
       case 3:intercepto(F7,lim_inf1,lim_supe1,F8,lim_inf2,lim_supe2);paralelas(F7,F8);perpendiculares(F7,F8);break;
       case 4:intercepto(F7,lim_inf1,lim_supe1,F9,lim_inf2,lim_supe2);paralelas(F7,F9);perpendiculares(F7,F9);break;
       case 5:intercepto(F7,lim_inf1,lim_supe1,F10,lim_inf2,lim_supe2);paralelas(F7,F10);perpendiculares(F7,F10);break;
       case 6:intercepto(F7,lim_inf1,lim_supe1,F11,lim_inf2,lim_supe2);paralelas(F7,F11);perpendiculares(F7,F11);break;
       case 7:intercepto(F7,lim_inf1,lim_supe1,F12,lim_inf2,lim_supe2);paralelas(F7,F12);perpendiculares(F7,F12);break;
       case 8:intercepto(F7,lim_inf1,lim_supe1,F13,lim_inf2,lim_supe2);paralelas(F7,F13);perpendiculares(F7,F13);break;
       };break;

case 3:switch(opc2){
       case 1:intercepto(F8,lim_inf1,lim_supe1,F6,lim_inf2,lim_supe2);paralelas(F8,F6);perpendiculares(F8,F6);break;
       case 2:intercepto(F8,lim_inf1,lim_supe1,F7,lim_inf2,lim_supe2);paralelas(F8,F7);perpendiculares(F8,F7);break;
       case 4:intercepto(F8,lim_inf1,lim_supe1,F9,lim_inf2,lim_supe2);paralelas(F8,F9);perpendiculares(F8,F9);break;
       case 5:intercepto(F8,lim_inf1,lim_supe1,F10,lim_inf2,lim_supe2);paralelas(F8,F10);perpendiculares(F8,F10);break;
       case 6:intercepto(F8,lim_inf1,lim_supe1,F11,lim_inf2,lim_supe2);paralelas(F8,F11);perpendiculares(F8,F11);break;
       case 7:intercepto(F8,lim_inf1,lim_supe1,F12,lim_inf2,lim_supe2);paralelas(F8,F12);perpendiculares(F8,F12);break;
       case 8:intercepto(F8,lim_inf1,lim_supe1,F13,lim_inf2,lim_supe2);paralelas(F8,F13);perpendiculares(F8,F13);break;
       };break;

case 4:switch(opc2){
       case 1:intercepto(F9,lim_inf1,lim_supe1,F6,lim_inf2,lim_supe2);paralelas(F9,F6);perpendiculares(F9,F6);break;
       case 2:intercepto(F9,lim_inf1,lim_supe1,F7,lim_inf2,lim_supe2);paralelas(F9,F7);perpendiculares(F9,F7);break;
       case 3:intercepto(F9,lim_inf1,lim_supe1,F8,lim_inf2,lim_supe2);paralelas(F9,F8);perpendiculares(F9,F8);break;
       case 5:intercepto(F9,lim_inf1,lim_supe1,F10,lim_inf2,lim_supe2);paralelas(F9,F10);perpendiculares(F9,F10);break;
       case 6:intercepto(F9,lim_inf1,lim_supe1,F11,lim_inf2,lim_supe2);paralelas(F9,F11);perpendiculares(F9,F11);break;
       case 7:intercepto(F9,lim_inf1,lim_supe1,F12,lim_inf2,lim_supe2);paralelas(F9,F12);perpendiculares(F9,F12);break;
       case 8:intercepto(F9,lim_inf1,lim_supe1,F13,lim_inf2,lim_supe2);paralelas(F9,F13);perpendiculares(F9,F13);break;
       };break;

case 5:switch(opc2){
       case 1:intercepto(F10,lim_inf1,lim_supe1,F6,lim_inf2,lim_supe2);paralelas(F10,F6);perpendiculares(F10,F6);break;
       case 2:intercepto(F10,lim_inf1,lim_supe1,F7,lim_inf2,lim_supe2);paralelas(F10,F7);perpendiculares(F10,F7);break;
       case 3:intercepto(F10,lim_inf1,lim_supe1,F8,lim_inf2,lim_supe2);paralelas(F10,F8);perpendiculares(F10,F8);break;
       case 4:intercepto(F10,lim_inf1,lim_supe1,F9,lim_inf2,lim_supe2);paralelas(F10,F9);perpendiculares(F10,F9);break;
       case 6:intercepto(F10,lim_inf1,lim_supe1,F11,lim_inf2,lim_supe2);paralelas(F10,F11);perpendiculares(F10,F11);break;
       case 7:intercepto(F10,lim_inf1,lim_supe1,F12,lim_inf2,lim_supe2);paralelas(F10,F12);perpendiculares(F10,F12);break;
       case 8:intercepto(F10,lim_inf1,lim_supe1,F13,lim_inf2,lim_supe2);paralelas(F10,F13);perpendiculares(F10,F13);break;
       };break;

case 6:switch(opc2){
       case 1:intercepto(F11,lim_inf1,lim_supe1,F6,lim_inf2,lim_supe2);paralelas(F11,F6);perpendiculares(F11,F6);break;
       case 2:intercepto(F11,lim_inf1,lim_supe1,F7,lim_inf2,lim_supe2);paralelas(F11,F7);perpendiculares(F11,F7);break;
       case 3:intercepto(F11,lim_inf1,lim_supe1,F8,lim_inf2,lim_supe2);paralelas(F11,F8);perpendiculares(F11,F8);break;
       case 4:intercepto(F11,lim_inf1,lim_supe1,F9,lim_inf2,lim_supe2);paralelas(F11,F9);perpendiculares(F11,F9);break;
       case 5:intercepto(F11,lim_inf1,lim_supe1,F10,lim_inf2,lim_supe2);paralelas(F11,F10);perpendiculares(F11,F10);break;
       case 7:intercepto(F11,lim_inf1,lim_supe1,F12,lim_inf2,lim_supe2);paralelas(F11,F12);perpendiculares(F11,F12);break;
       case 8:intercepto(F11,lim_inf1,lim_supe1,F13,lim_inf2,lim_supe2);paralelas(F11,F13);perpendiculares(F11,F13);break;
       };break;


case 7:switch(opc2){
       case 1:intercepto(F12,lim_inf1,lim_supe1,F6,lim_inf2,lim_supe2);paralelas(F12,F6);perpendiculares(F12,F6);break;
       case 2:intercepto(F12,lim_inf1,lim_supe1,F7,lim_inf2,lim_supe2);paralelas(F12,F7);perpendiculares(F12,F7);break;
       case 3:intercepto(F12,lim_inf1,lim_supe1,F8,lim_inf2,lim_supe2);paralelas(F12,F8);perpendiculares(F12,F8);break;
       case 4:intercepto(F12,lim_inf1,lim_supe1,F9,lim_inf2,lim_supe2);paralelas(F12,F9);perpendiculares(F12,F9);break;
       case 5:intercepto(F12,lim_inf1,lim_supe1,F10,lim_inf2,lim_supe2);paralelas(F12,F10);perpendiculares(F12,F10);break;
       case 6:intercepto(F12,lim_inf1,lim_supe1,F11,lim_inf2,lim_supe2);paralelas(F12,F11);perpendiculares(F12,F11);break;
       case 8:intercepto(F12,lim_inf1,lim_supe1,F13,lim_inf2,lim_supe2);paralelas(F12,F13);perpendiculares(F12,F13);break;
        };break;
case 8:switch(opc2){
       case 1:intercepto(F13,lim_inf1,lim_supe1,F6,lim_inf2,lim_supe2);paralelas(F13,F6);perpendiculares(F13,F6);break;
       case 2:intercepto(F13,lim_inf1,lim_supe1,F7,lim_inf2,lim_supe2);paralelas(F13,F7);perpendiculares(F13,F7);break;
       case 3:intercepto(F13,lim_inf1,lim_supe1,F8,lim_inf2,lim_supe2);paralelas(F13,F8);perpendiculares(F13,F8);break;
       case 4:intercepto(F13,lim_inf1,lim_supe1,F9,lim_inf2,lim_supe2);paralelas(F13,F9);perpendiculares(F13,F9);break;
       case 5:intercepto(F13,lim_inf1,lim_supe1,F10,lim_inf2,lim_supe2);paralelas(F13,F10);perpendiculares(F13,F10);break;
       case 6:intercepto(F13,lim_inf1,lim_supe1,F11,lim_inf2,lim_supe2);paralelas(F13,F11);perpendiculares(F13,F11);break;
       case 7:intercepto(F13,lim_inf1,lim_supe1,F12,lim_inf2,lim_supe2);paralelas(F13,F12);perpendiculares(F13,F12);break;
        };break;
}
cout<<endl<<endl;
system("pause");




}

void problemaMatematico(){
    system("cls");
    Triangulo t1;
    float altura,angulo;
cout<<"Ingrese la altura del avion | metros: ";
cin>>altura;
cout<<"Ingrese el angulo de depresion: ";
cin>>angulo;

t1.setCatetoOpuesto(altura);
t1.setAngulo(angulo);


cout<<"la distancia del avion caza hacia el barco enemigo es de: "<<t1.CalcularDistancia()<<"m"<<endl;
system("pause");


}
void submenuCalculo() {
      system("cls");
      int opcion;

      do {
            system("cls");
            cout<<"---------CALCULO-----"<<endl;
            cout<<"1.Calcular distancia entre un intervalo de una funcion"<<endl;
            cout<<"2.dada 2 funciones saber si son:paralelas,perpendiculares y saber si se interceptan"<<endl;
            cout<<"3.Encotrar Distancia entre un avion caza y un barco enemigo"<<endl;
            cout<<"0.salir al menu principal"<<endl<<endl;


            cout<<"digite una opcion:";
            cin>>opcion;

            switch(opcion) {
            case 1:
                  calcDistanciaFunciones();
                  break;
            case 2: dada2funciones();break;

            case 3:problemaMatematico();break;
            case 0:break;

             default:
                cout<<"\n-------------------------------"<<endl;
                cout<<"Error,Digite una opcion correcta"<<endl;
                cout<<"---------------------------------"<<endl;
                system("pause");


            }

      } while(opcion !=0);

}


///Algebra lineal-----------------------------------------------------------------------------------
//prototipos funcioenes algebra
void multiplicacionMatrices();
void calcularangulo();

//definicion de funciones
void multiplicacionMatrices() {
      system("cls");
      Matriz M1,M2;
      cout<<"ingrese la primer matriz"<<endl;
      M1.setDatosMatriz();

      system("pause");
      system("cls");

      cout<<"Ingrese la segunda matriz"<<endl;
      M2.setDatosMatriz();
      system("pause");
      system("cls");
      bool validador = false;
      if(M1.getColumnas()!= M2.getColumnas() && M1.getFilas() != M2.getFilas()) {
            if(M1.getColumnas() != M2.getFilas()) {

                  cout<<" ------------------------------------------------------------------------------"<<endl;
                  cout<<"|Las Matrices no se pueden multiplciar,Porfavor ingrese nuevamente las matrices|"<<endl;
                  cout<<" ------------------------------------------------------------------------------"<<endl;

                  system("pause");
                  multiplicacionMatrices();
            } else {
                  validador = true;
            }
      } else {
            validador = true;
      }



      if(validador) {
            int matrizResultado[M1.getFilas()][M2.getColumnas()];
            for (int i = 0; i < M1.getFilas(); i++) {
                  for (int j = 0; j < M2.getColumnas(); j++) {
                        matrizResultado[i][j] = 0;
                  }
            }
            for (int i = 0; i < M1.getFilas(); i++) {
                  for (int j = 0; j < M2.getColumnas(); j++) {
                        matrizResultado[i][j] = 0;
                        for (int k = 0; k < M1.getColumnas(); k++) {
                              matrizResultado[i][j] +=  M1.matriz[i][k] * M2.matriz[k][j];
                        }
                  }
            }
            cout<<"MATRIZ : "<<M1.getNombre()<<endl;
            M1.getDatosMatriz();
            cout<<endl;
            cout<<"MATRIZ : "<<M2.getNombre()<<endl;
            M2.getDatosMatriz();
            cout<<endl;
            cout<<"RESULTADO"<<endl<<endl;
            for(int i = 0; i<M1.getFilas(); i++) {

                  for(int j=0; j<M2.getColumnas(); j++) {
                        cout<<matrizResultado[i][j];
                        cout<<"  ";
                  }
                  cout<<endl;
            }

      }



      system("pause");

}

void calcularangulo(){
    system("cls");
Vector vec1,vec2;

int n;
cout<<"Digite la dimension del vector R^n / n=";
cin>>n;
vec1.setTamano(n);
vec2.setTamano(n);
system("pause");
system("cls");
cout<<"--------------------DATOS VECTOR 1-----------------------"<<endl;
vec1.setNombre();
vec1.setDatos();
cout<<vec1.getDatos()<<endl<<endl;
system("pause");
system("cls");
cout<<"--------------------DATOS VECTOR 2-----------------------"<<endl;
vec2.setNombre();
vec2.setDatos();
cout<<vec2.getDatos()<<endl<<endl;
system("pause");
system("cls");

cout<<"El angulo de los vectores: |"+vec1.getDatos() + " | " + vec2.getDatos() + "| es de: "<<calcularAnguloVectores(vec1,vec2)<<" grados"<<endl<<endl;


system("pause");

}

void submenuAlgebra() {

      system("cls");
      int opcion;

      do {
            system("cls");
            cout<<"---------ALGEBRA LINEAL-----"<<endl;
            cout<<"1.Multiplicacion de matrices"<<endl;
            cout<<"2.Calcular angulo dado 2 vectores"<<endl;
            cout<<"0.salir al menu principal"<<endl<<endl;


            cout<<"digite una opcion:";
            cin>>opcion;

            switch(opcion) {
            case 1:
                  multiplicacionMatrices();
                  break;
            case 2: calcularangulo();break;


            }

      } while(opcion !=0);

}

void menuPrincipal() {

      int opcion;
      do {
            system("cls");

            cout<<"------------CALCULADORA MATEMATICAS-----------"<<endl<<endl;

            cout<<"[1].Calculo"<<endl;
            cout<<"[2].Algebra lineal"<<endl;
            cout<<"[3].Matematicas Discretas"<<endl;
            cout<<"[0].Salir del Programa"<<endl<<endl;
            cout<<"Digite una opcion";
            cin>>opcion;

            switch(opcion) {
            case 1:
                  submenuCalculo();
                  break;
            case 2:
                  submenuAlgebra();
                  break;
            case 3:
                  submenuMatematicasDiscretas();
                  break;
            case 0:
                  cout<<"Muchas Gracias por Usar la Calculadora, Adios....";
                  break;
            default:
                cout<<"\n-------------------------------"<<endl;
                cout<<"Error,Digite una opcion correcta"<<endl;
                cout<<"---------------------------------"<<endl;
                system("pause");
            }

      } while(opcion != 0);

}

int main() {

      menuPrincipal();
      return 0;
}



