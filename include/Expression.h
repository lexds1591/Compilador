#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Expression.h"



class Expression
{
    public:
        Expression( int valor );
        Expression( int valor, Expression * izq, Expression * der);
        virtual ~Expression();
        int GetValor() { return valor_; }
        void SetValor( int val ) { valor_ = val; }
        Expression * GetIzq() { return izq_; }
        void SetIzq( Expression * val ) { izq_ = val; }
        Expression * GetDer() { return der_; }
        void SetDer(Expression * val) { der_ = val; }
    protected:
    private:
        int valor_;
        Expression * izq_;
        Expression * der_;
};

#endif // EXPRESSION_H
