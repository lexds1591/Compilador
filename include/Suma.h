#ifndef SUMA_H
#define SUMA_H

#include "Nodo.h"

class Suma
{
    public:
        Suma(Nodo * izq, Nodo * der);
        virtual ~Suma();
        Nodo * Getder() { return der_; }
        void Setder(Nodo * val) { der_ = val; }
        Nodo * Getizq() { return izq_; }
        void Setizq(Nodo * val) { izq_ = val; }
    protected:
    private:
        Nodo * der_;
        Nodo * izq_;
};

#endif // SUMA_H
