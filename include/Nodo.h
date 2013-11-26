#ifndef NODO_H
#define NODO_H

#include<iostream>
    using namespace std;

class Nodo
{
    public:
        Nodo( int simbolo);
        virtual ~Nodo();

        int getSimbolo() { return simbolo_; }
        void setSimbolo(int simbolo) { simbolo_ = simbolo; }
        Nodo* getSig() { return sig_; }
        void setSig(Nodo *sig) { sig_ = sig; }

    protected:
    private:
        int simbolo_;
        Nodo * sig_;

};

#endif // NODO_H
