#ifndef LEXICO_H
#define LEXICO_H


//Libraries
#include <string>
#include <iostream>
#include <cctype>
    using namespace std;

//Global variables
#define ERROR         -1
#define EXITO          0

#define DELIMITADOR     0
#define ADICION         1
#define MULTIPLICACION  2
#define IDENTIFICADOR   3
#define PARENTESIS_IZQ  4
#define PARENTESIS_DER  5
#define FIN             6


class Lexico
{
    public:

        Lexico( int estado , string cadena );
        virtual ~Lexico( void );

        unsigned int getEstado( void )
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
        string getPalabra( void )
        {
            return palabra_;
        }
        void setPalabra( string  palabra )
        {
            palabra_ = palabra;
        }
        void setTipo( int val )
        {
            tipo_ = val;
        }
        void sigPalabra( void );

        void analizar( string palabra );

    protected:

    private:
        unsigned int estado_;
        int tipo_;
        unsigned int posicion;
        string cadena_;
        string palabra_;
};

#endif // LEXICO_H
