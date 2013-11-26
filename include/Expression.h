#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <Nodo.h>


class Expression : public Nodo
{
    public:
        Expression( valor );
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
