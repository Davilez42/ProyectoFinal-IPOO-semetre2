#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
using namespace std;


class Matriz
{
    public:

         string nombre;
        int **matriz;
        int filas,columnas;

        Matriz();
        virtual ~Matriz();
        //seters

       //Funciones
       void limpiarMatriz();
       void ingresarElementos();

        void setDatosMatriz();
        //geters
        string getNombre();
        int getFilas();
        int getColumnas();
        void getDatosMatriz();


    protected:

    private:
};

#endif // MATRIZ_H
