/*@Practica #1
 **Alejandro Duarte Sánchez
 **Alfredo Martinez Corona
 */

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

#include "include/Lexico.h"
#include "include/funciones.h"

using namespace std;

int main()
{
    string cadena;
    int inicial = 0;
    unsigned int posicion = 0;
    string palabra;
    char ruta[] = "archivo.txt";
    //char rutaSalida[]="salida.txt";
    char permisos[] = "r";
    cadena = getCadena( ruta ,permisos );

    Lexico lexico( inicial );

    do
    {
        palabra = getPalabra( cadena , & posicion);
        lexico.analizar( palabra );

        //utiliza el entero obtenido para decidir el tipo
        switch( lexico.getTipo() )
        {
            case ERROR:
                    cout << "*** ERROR *** No se conoce : " << palabra << endl;
                    break;
            case IDENTIFICADOR:
                    break;
            case ENTERO:
                    break;
            case REAL:
                    break;
            case CADENA:
                    break;
            case ADICION:
                    break;
            case MULTIPLICACION:
                    break;
            case ASIGNACION:
                    break;
            case RELACIONAL:
                    break;
            case LOGICO:
                    break;
            case PARENTESIS_IZQ:
                    break;
            case PARENTESIS_DER:
                    break;
            case LLAVE_IZQ:
                    break;
            case LLAVE_DER:
                    break;
            case DELIMITADOR:
                    break;
             case RESERVADO:
                    cout << "Reservado";
                    break;
            default :
                    cout << "No debe de entrar en esta opcion!(main_1)" << endl;
                    break;

        }
        lexico.setEstado( inicial );

    } while( posicion < cadena.length() );

    //almacenar resultado
    return EXIT_SUCCESS;
}
