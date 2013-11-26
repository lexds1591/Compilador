#ifndef TERMINAL_H
#define TERMINAL_H

#include "Terminal.h"
#include <string>
using namespace std;

class Terminal
{
    public:
        Terminal();
        virtual ~Terminal();
    protected:
    private:
        string tipo;
};

#endif // TERMINAL_H
