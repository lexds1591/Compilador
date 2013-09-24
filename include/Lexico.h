#ifndef LEXICO_H
#define LEXICO_H

#include <string>
#include <iostream>
#include <cctype>

#define ERROR          -1
#define IDENTIFICADOR  1
#define ENTERO         2
#define REAL           3
#define CADENA         4
#define ADICION        5
#define MULTIPLICACION 6
#define ASIGNACION     7
#define RELACIONAL     8
#define LOGICO         9
#define PARENTESIS_IZQ 10
#define PARENTESIS_DER 11
#define LLAVE_IZQ      12
#define LLAVE_DER      13
#define DELIMITADOR    14
#define RESERVADO      15

#define MAXIMO 10

using namespace std;

class Lexico {

    public:
        Lexico( int estado );
        virtual ~Lexico();

        unsigned int getEstado()
        {
            return estado_;
        }

        void setEstado( unsigned int val )
        {
            estado_ = val;
        }

        int getTipo()
        {
            return tipo_;
        }

        void setTipo( int val )
        {
            tipo_ = val;
        }

        void analizar( string palabra );
        bool esReservada( string palabra);

    protected:
    private:
        unsigned int estado_;
        int tipo_;
        string palabrasReservadas_[MAXIMO];
};

#endif // LEXICO_H
