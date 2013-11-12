#ifndef SINTACTICO_H
#define SINTACTICO_H

#include <iostream>
#include <string>
#include "Lexico.h"
#include <vector>

#define COLUMNAS 9
#define FILAS    15
#define REGLAS   7

#define S               7
#define E               8

#define DESPLAZAMIENTO  0
#define REDUCCION       1


using namespace std;

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
        int lon[REGLAS];
};

#endif // SINTACTICO_H
