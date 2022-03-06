#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using namespace std;


class Vector
{
    public:
        string nombre;
        int tamano;
        int *vec;
        Vector();
        virtual ~Vector();

        void setNombre();
        void setTamano(int);
        void setDatos();

        string getNombre();
        int getTamano();
        int getDato(int indice);
        string getDatos();

    protected:

    private:
};

#endif // VECTOR_H
