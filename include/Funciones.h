#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <cstring>
#include <fstream>
#include <sstream>
#include "TablaSimbolos.h"

#define FIN_ARCHIVO 0
#define TAM         100

string getCadena( char* ruta , char* permisos );
string getPalabra( string cadena , unsigned int *posicion );
bool validaEspacio( char espacio );
/*void escribeSalida( char ruta[] , Lexico lexico );
string convertInt(int number);*/

string getCadena( char* ruta , char* permisos )
{
    FILE * archivo;
    char cadena[TAM];
    char caracter;
    int i = 0;

    archivo = fopen( ruta , permisos );

    if( archivo != NULL )
    {
        while( fread( &caracter , sizeof( char ) , 1 ,archivo ) > FIN_ARCHIVO  )
        {
            cadena[i] = caracter;
            i++;
        }

        cadena[i] = '\0';
    }
    else
    {
        cout << "No se pudo abrir el archivo: " << ruta << endl;
        exit(0);
    }

    fclose( archivo );

    return cadena;
}

string getPalabra( string cadena , unsigned int *posicion )
{
    char palabra[40];
    int contPalabra = 0;
    TablaSimbolos simbolos;
    int valor;

    while( validaEspacio( cadena[*posicion] ) )
    {
        (*posicion)++;
    }

    valor = simbolos.validaUnSimbolo( cadena[*posicion] );

    if( valor != -1 )
    {
        palabra[contPalabra] = cadena[*posicion];
        contPalabra++;
        (*posicion)++;

        if( valor >= 0 && valor <= 5 )
        {

            if( simbolos.validaDosSimbolo( cadena[*posicion-1] , cadena[*posicion] ) )
            {
                palabra[contPalabra] = cadena[*posicion];
                contPalabra++;
                (*posicion)++;
            }
        }
    }

    else
    {

        do
        {

            palabra[contPalabra] = cadena[*posicion];
            contPalabra++;
            (*posicion)++;

        }while( simbolos.validaUnSimbolo( cadena[*posicion] ) == -1  &&
               !validaEspacio( cadena[*posicion] )&& (*posicion) < cadena.length() );

        if( validaEspacio( cadena[*posicion] ) )
           (*posicion)++;
    }


    palabra[contPalabra]='\0';

    return (string)palabra;
}

bool validaEspacio( char espacio )
{
    if( espacio == ' ' || espacio == '\t' || espacio == '\n')
        return true;
    return false;
}

/*void escribeSalida( char ruta[] , Lexico lexico )
{

    ofstream salida;
    salida.open( ruta , ios::out | ios::trunc );

    salida << convertInt(lexico.contIdentificador ) << " ";

    salida << convertInt(lexico.contEntero ) << " ";

    salida << convertInt(lexico.contReal ) << " ";

    salida << convertInt(lexico.contCadena ) << " ";

    salida << convertInt(lexico.contAdicion ) << " ";

    salida << convertInt(lexico.contMultiplicacion ) << " ";

    salida << convertInt(lexico.contAsignacion ) << " ";

    salida << convertInt(lexico.contRelacional ) << " ";

    salida << convertInt(lexico.contLogico )  << " ";

    salida << convertInt(lexico.contParIzq ) << " ";

    salida << convertInt(lexico.contParDer ) << " ";

    salida << convertInt(lexico.contLlaveIzq ) << " ";

    salida << convertInt(lexico.contLlaveDer ) << " ";

    salida << convertInt(lexico.contDelimitador );


    cout << "Archivo salida.txt ha sido creado!" << endl;
    salida.close();
}

string convertInt(int number)
{
   string String = static_cast<ostringstream*>( &(ostringstream() << number) )->str();
   return String;

}*/

#endif // FUNCIONES_H_INCLUDED
