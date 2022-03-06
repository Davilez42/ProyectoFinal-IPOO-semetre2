#ifndef CONJUNTO_H
#define CONJUNTO_H
#include <iostream>
#include <locale.h>
using namespace std;


class Conjunto
{

    public:
        string nombre;
        int tamano;
        string *co_junto;

        //prototipos funciones

        Conjunto();
        virtual ~Conjunto();

               void setNombre();
               void setTamano();
               void setDatos();


        //geters
        string getNombre();
        int getTamano();
        string getDato(int indice);
        string getDatos();

    protected:

    private:
};

#endif // CONJUNTO_H
