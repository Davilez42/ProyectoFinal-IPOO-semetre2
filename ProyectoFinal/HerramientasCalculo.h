#include <iostream>
#include <math.h>
using namespace std;

///funciones derivadas predeterminadas por el programador para calcular distancia
double F1(double x) {
      return sqrt( 1+pow(4*x,2) );
}
double F2(double x) {
      return sqrt( 1+pow(2*x,2));
}
double F3(double x) {
      return sqrt( 1+pow(1,2) );
}

double F4(double x) {
      return sqrt( 1+ pow(16*pow(x,3)-60*pow(x,2),2) );
}

double F5(double x) {
      return sqrt( 1+pow(x,2) );
}


///Funcion Integral, Recibe como parametro una funcion y calcula la sumatoria mediante un ciclo

void Integral(double f(double)) {
      system("cls");
      int a_inf,b_supe;

      double deltaX,suma=0,n;
      cout<<"Igrese el intervalo inferior:";
      cin>>a_inf;

      cout<<"Ingrese el intervalo Superior:";
      cin>>b_supe;

      n = 10000;

      int rango = b_supe-(a_inf);
      deltaX = rango/n;

      for(double x = a_inf; x<b_supe; x+=deltaX) {
            double funcion = f(x);

            suma += funcion*deltaX;
      }
      cout<<"la distancia del punto "<<a_inf<<" hasta el punto "<<b_supe<<"  es de: "<<suma<<endl;

      system("pause");
}



///funciones #2 se crean las funciones con un paramatreo x y un booleano,
/// si el parametro bool es true retornara la pendiente si es falso retornara el valor de la funcion evaluado en el x dado
double F6(double x,bool obtM) {//1
      if(obtM) {
            return -3;
      } else {
            return -4*x+x;
      }
}

double F7(double x,bool obtM) {//2
      if(obtM) {
            return 2;
      } else {
            return pow(x,2);
      }
}


double F8(double x,bool obtM) {//3
      if(obtM) {
            return 6*(pow(x,2))+x;
      } else {
            return 2*pow(x,3)+3*x;
      }
}

double F9(double x,bool obtM) {//4
      if(obtM) {
            return 2;
      } else {
            return -x+3*x;
      }
}

double F10(double x,bool obtM) {//5
      if(obtM) {
            return 14;
      } else {
            return 6*x+x+8;
      }
}

double F11(double x,bool obtM) { //6
      if(obtM) {
            return 1;
      } else {
            return x-4;
      }
}

double F12(double x,bool obtM) { //7
      if(obtM) {
            return 1;
      } else {
            return x+20;
      }
}

double F13(double x,bool obtM) { //8
      if(obtM) {
            return -1;
      } else {
            return -x;
      }
}




///funcion que valida si dos valores son iguales son iguales
bool comparar(double fx,double gx) {
      float y1=fx,y2=gx;
      if(y1==y2) {
            return true;
      } else {
            return false;
      }
}

///funcion que recibe 2 funciones y sus intervalos y calcula si se interceptan y dice el valor en donde se interceptan
void intercepto(double f(double,bool),int LimInf_f1,int limsuper_f1,double g(double,bool),int LimInf_f2,int limsuper_f2 ) {

      bool bandera = false;
      cout<<"-------------------------------------------"<<endl;
      cout<<"--------------INTERCEPCION-----------------"<<endl;
      for(double i = LimInf_f1; i <=limsuper_f1+0.1; i+=0.1) { //bucle que iterar la funcion1
            if(i>-0.1 && i<0.1) {
                  i=0;
            }
            for(double j = LimInf_f2; j <=limsuper_f2+0.1; j+=0.1) { //bucle que itera la funcion2
                  if(j>-0.1 && j<0.1) {///condicional para que cuando el iterador sea mayor a -0.01 le de el valor de 0 ya que si no se hace el iterador j obtiene un valor basura
                        j=0;
                  }

                  if(comparar(f(i,false),g(j,false)) && comparar(i,j)) {
                        bandera = true;
                        cout<<"X = "<<i<<", Y = "<<f(i,false)<<endl;
                  }

            }



      }

      if(bandera == false) {
            cout<<"Las Funciones NO se interceptan en los intervalos dados"<<endl;
      }

      cout<<"-------------------------------------------"<<endl;

}

///funcion para saber si son paralelas
void paralelas(double f(double,bool),double g(double,bool) ) {

      if(f(1,true) == g(1,true) ) {
            cout<<"Las Funciones SON Paralelas"<<endl;
      } else {
            cout<<"las funciones NO son paralelas"<<endl;
      }
      cout<<"-------------------------------------------"<<endl;
}



void perpendiculares(double f(double,bool),double g(double,bool)) {
      if((f(1,true) * g(1,true)) == -1 ) {
            cout<<"Las Funciones SON perpendiculares"<<endl;
      } else {
            cout<<"Las Funciones NO son perpendiculares"<<endl;
      }
      cout<<"-------------------------------------------"<<endl;

}







