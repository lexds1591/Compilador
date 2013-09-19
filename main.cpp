/*@Practica #1
 **Alejandro Duarte Sánchez
 *Seccion:D02
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
                    //lexico.contIdentificador++;
                    break;
            case ENTERO:
                    //lexico.contEntero++;
                    break;
            case REAL:
                    //lexico.contReal++;
                    break;
            case CADENA:
                    //lexico.contCadena++;
                    break;
            case ADICION:
                    //lexico.contAdicion++;
                    break;
            case MULTIPLICACION:
                    //lexico.contMultiplicacion++;
                    break;
            case ASIGNACION:
                    //lexico.contAsignacion++;
                    break;
            case RELACIONAL:
                    //lexico.contRelacional++;
                    break;
            case LOGICO:
                    //lexico.contLogico++;
                    break;
            case PARENTESIS_IZQ:
                    //lexico.contParIzq++;
                    break;
            case PARENTESIS_DER:
                    //lexico.contParDer++;
                    break;
            case LLAVE_IZQ:
                    //lexico.contLlaveIzq++;
                    break;
            case LLAVE_DER:
                    //lexico.contLlaveDer++;
                    break;
            case DELIMITADOR:
                    //lexico.contDelimitador++;
                    break;
             case RESERVADO:
                    //lexico.contDelimitador++;
                    cout << "Reservado";
                    break;
            default :
                    cout << "No debe de entrar en esta opcion!(main_1)" << endl;
                    break;

        }
        lexico.setEstado( inicial );

    }while( posicion < cadena.length() );

    //almacenar resultado
    //escribeSalida( rutaSalida , lexico );

    return EXIT_SUCCESS;
}
