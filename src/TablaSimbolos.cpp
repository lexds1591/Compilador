//Libraries / Headers
#include "../include/TablaSimbolos.h"
#include <iostream>
    using namespace std;

TablaSimbolos::TablaSimbolos()
{
    simbolos_="><!=|&+-*/(){};,";
}

TablaSimbolos::~TablaSimbolos()
{
    //dtor
}

int TablaSimbolos::validaUnSimbolo( char simbolo )
{
    unsigned int valor;

    valor = simbolos_.find(simbolo);

    if( valor != string::npos )
        return valor;
    else
        return -1;
}

bool TablaSimbolos::validaDosSimbolo( char anterior , char actual )
{
    if( ( anterior == '>' || anterior == '<' || anterior == '=' || anterior == '!') &&
       actual == '=' )
            return true;

    else if( ( anterior == '|' && actual =='|' ) ||
            ( anterior == '&' && actual == '&' ) )
                return true;
    return false;
}
