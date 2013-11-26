#ifndef NODO_H
#define NODO_H

#include<iostream>
    using namespace std;

class Nodo
{
    public:
        Nodo( string simbolo);
        virtual ~Nodo();
        string GetSimbolo() { return simbolo_; }
        void SetSimbolo(string val) { simbolo_ = val; }
        /*
        int GetValor() { return valor_; }
        void SetValor(int val) { valor_ = val; }
        */
    protected:
    private:
        string simbolo_;
        //int valor_;
};

#endif // NODO_H
