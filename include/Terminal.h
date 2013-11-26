#ifndef TERMINAL_H
#define TERMINAL_H

#include <Nodo.h>


class Terminal : public Nodo
{
    public:
        Terminal();
        virtual ~Terminal();
    protected:
    private:
        string tipo;
};

#endif // TERMINAL_H
