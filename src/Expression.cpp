#include "../include/Expression.h"
#include "../include/Nodo.h"

Expression::Expression( int valor )
{
    SetValor( valor );
    izq_=der_=NULL;
}

Expression::Expression( int valor, Expression * izq, Expression * der)
{
    SetValor( valor );
    izq_ = izq;
    der_ = der;
}

Expression::~Expression()
{
    //dtor
}
