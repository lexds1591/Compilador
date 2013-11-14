//Libraries
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>

//Headers
#include "../include/Sintactico.h"


Sintactico::Sintactico( void )
{
    lon[0] = 6;
    lon[1] = 0;
    lon[2] = 6;
    lon[3] = 6;
    lon[4] = 4;
    lon[5] = 6;
    lon[6] = 2;

    inicializa( tabla );
    llenaTabla( tabla );

    pila.push_back( 0 );//primer estado
}

Sintactico::~Sintactico( void )
{
    //dtor
}

int Sintactico::analizar( Lexico lexico , ofstream *acciones )
{
    string accion_valor;
    int accion;

    lexico.sigPalabra();

    if( lexico.getTipo() == ERROR )
        return ERROR;

    do
    {
        accion_valor = tabla[ lexico.getTipo() ][ pila.back() ];

        *acciones << accion_valor << " ";

        if( accion_valor == "Aceptacion" )// si la accion es de aceptacion
        {
            return EXITO;
        }

        else if(  accion_valor != "0" )// verfica que haya caido a una casilla valida
        {
            accion = des_red( accion_valor , lexico.getTipo() );//se realiza la accion ( Desplazamiento/reduccion )

            if( accion == DESPLAZAMIENTO )
            {
              lexico.sigPalabra();
              if( lexico.getTipo() == ERROR )
                return ERROR;

            }

            else if( accion == ERROR )
            {
                return ERROR;
            }
        }

        else
        {
            return ERROR;
        }

    }while( lexico.getPalabra() != "" || !pila.empty() );

    return ERROR;
}

void Sintactico:: inicializa( string tabla[COLUMNAS][FILAS] )
{
    for( int i = 0 ; i < COLUMNAS ; i++)
    {
        for( int j = 0 ; j < FILAS ; j++ )
        {
            tabla[i][j] = "0";
        }
    }
}

void Sintactico:: llenaTabla( string tabla[COLUMNAS][FILAS] )
{
    tabla[ADICION]          [0] = "d3";
    tabla[IDENTIFICADOR]    [0] = "d5";
    tabla[PARENTESIS_IZQ]   [0] = "d4";
    tabla[FIN]              [0] = "r2";
    tabla[S]                [0] = "1";
    tabla[E]                [0] = "2";

    tabla[FIN]              [1] = "Aceptacion";

    tabla[DELIMITADOR]      [2] = "d6";
    tabla[ADICION]          [2] = "d7";
    tabla[MULTIPLICACION]   [2] = "d8";

    tabla[ADICION]          [3] = "d3";
    tabla[IDENTIFICADOR]    [3] = "d5";
    tabla[PARENTESIS_IZQ]   [3] = "d4";
    tabla[E]                [3] = "9";

    tabla[ADICION]          [4] = "d3";
    tabla[IDENTIFICADOR]    [4] = "d5";
    tabla[PARENTESIS_IZQ]   [4] = "d4";
    tabla[E]                [4] = "10";

    tabla[DELIMITADOR]      [5] = "r7";
    tabla[ADICION]          [5] = "r7";
    tabla[MULTIPLICACION]   [5] = "r7";
    tabla[PARENTESIS_DER]   [5] = "r7";
    tabla[FIN]              [5] = "r7";

    tabla[ADICION]          [6] = "d3";
    tabla[IDENTIFICADOR]    [6] = "d5";
    tabla[PARENTESIS_IZQ]   [6] = "d4";
    tabla[FIN]              [6] = "r2";
    tabla[S]                [6] = "11";
    tabla[E]                [6] = "2";

    tabla[ADICION]          [7] = "d3";
    tabla[IDENTIFICADOR]    [7] = "d5";
    tabla[PARENTESIS_IZQ]   [7] = "d4";
    tabla[E]                [7] = "13";

    tabla[ADICION]          [8] = "d3";
    tabla[IDENTIFICADOR]    [8] = "d5";
    tabla[PARENTESIS_IZQ]   [8] = "d4";
    tabla[E]                [8] = "13";

    tabla[DELIMITADOR]      [9] = "r5";
    tabla[ADICION]          [9] = "r5";
    tabla[MULTIPLICACION]   [9] = "r5";
    tabla[PARENTESIS_DER]   [9] = "r5";
    tabla[FIN]              [9] = "r5";

    tabla[ADICION]          [10] = "d7";
    tabla[MULTIPLICACION]   [10] = "d8";
    tabla[PARENTESIS_DER]   [10] = "d14";

    tabla[FIN]              [11] = "r1";

    tabla[DELIMITADOR]      [12] = "r3";
    tabla[ADICION]          [12] = "r3";
    tabla[MULTIPLICACION]   [12] = "d8";
    tabla[PARENTESIS_DER]   [12] = "r3";
    tabla[FIN]              [12] = "r3";

    tabla[DELIMITADOR]      [13] = "r4";
    tabla[ADICION]          [13] = "r4";
    tabla[MULTIPLICACION]   [13] = "r4";
    tabla[PARENTESIS_DER]   [13] = "r4";
    tabla[FIN]              [13] = "r4";

    tabla[DELIMITADOR]      [14] = "r6";
    tabla[ADICION]          [14] = "r6";
    tabla[MULTIPLICACION]   [14] = "r6";
    tabla[PARENTESIS_DER]   [14] = "r6";
    tabla[FIN]              [14] = "r6";
}

int Sintactico::des_red( string accion , int caracter )
{
    //recuperar la posicion
    int regla = atoi( accion.substr(1).c_str() );

    if( accion.at(0) == 'd' )
    {
        pila.push_back( caracter );
        pila.push_back( regla );

        return DESPLAZAMIENTO;

    }

    else if( accion.at(0) == 'r' )
    {
        for( int i = 0 ; i < lon[ regla - 1 ] ; i++ )
        {
            pila.pop_back();
        }
        /*****************************************
        * se decide cual No-terminal se introduce*
        *****************************************/
        int num = pila.back();

        if( regla >= 3 && regla <= 7 )
        {
            pila.push_back( E );
            pila.push_back( atoi( tabla[E][num].c_str() )  );
        }

        else if( regla >= 0 && regla <= 2 )
        {
            pila.push_back( S );
            pila.push_back( atoi( tabla[S][num].c_str() )  );
        }

        return REDUCCION;
    }

    return ERROR;
}
