#ifndef SINTACTICO_H
#define SINTACTICO_H


//Libraries
#include <iostream>
#include <string>
#include <vector>
    using namespace std;

//Headers
#include "Lexico.h"
#include "Nodo.h"

//Global variables
#define COLUMNAS        9
#define FILAS           15
#define REGLAS          7

#define S               7
#define E               8

#define DESPLAZAMIENTO  0
#define REDUCCION       1


class Sintactico
{
    public:
        Sintactico( void );
        virtual ~Sintactico( void );
        int analizar( Lexico lexico , ofstream *acciones );

    protected:

    private:
        int termino( Lexico *lexico );
        void inicializa( string tabla[COLUMNAS][FILAS] );
        void llenaTabla( string tabla[COLUMNAS][FILAS] );
        int des_red( string accion , int caracter );

        string tabla[COLUMNAS][FILAS];
        vector <int> pila;
        //vector <Nodo> pila;
        int lon[REGLAS];
};

#endif // SINTACTICO_H
\
