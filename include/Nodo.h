#ifndef NODO_H
#define NODO_H

#include<iostream>
    using namespace std;

class Nodo
{
    public:
        Nodo( string valor);
        virtual ~Nodo();

        int GetValor() { return valor_; }
        void SetValor(int val) { valor_ = val; }

    protected:
    private:
        int valor_;
};

#endif // NODO_H
