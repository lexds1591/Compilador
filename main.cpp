/*
 *@subject: Taller de Compiladores
 *
 *@author:  Alejandro Duarte Sánchez
 *@author:  Alfredo Martinez Corona
 */


/*************************** TO DO *********************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/


//Libraries
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;

//Headers
#include "include/Lexico.h"
#include "include/Sintactico.h"
#include "include/ArchivoIO.h"


int main()
{
    string cadena;
    int estado = 0;
    string palabra;
    char ruta[] = "entrada.txt";
    char rutaSalida[]="salida.txt";
    char permisos[] = "r";

    ofstream acciones;
    acciones.open( "acciones.txt" , ios::out | ios::trunc );

    cadena = leerArchivo( ruta ,permisos );//se obtiene toda la cadena del archivo

    Lexico lexico( estado , cadena );
    Sintactico sintactico;

    if( sintactico.analizar( lexico , &acciones ) == EXITO )//se realiza analisis sintactico
    {
        escribeSalida( rutaSalida , 1 );
    }

    else
    {
        escribeSalida( rutaSalida , 0 );
        acciones << "ERROR";
        cout << "************** SE ENCONTRARON ERRORES **************" << endl;
    }

    return EXIT_SUCCESS;
}
