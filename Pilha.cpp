#include <iostream>
#include "Pilha.h"

using namespace std;

Pilha::Pilha()
{
    topo = -1;
}

void Pilha::push(TipoDado x)
{
    if (!cheia())
        dados[++topo] = x;	// mesmo que: ++topo; dados[topo] = x;
    else
        cout << "stack overflow!" << endl;
}

TipoDado Pilha::pop()
{
    TipoDado aux;
    if (vazia())
        cout << "stack underflow!" << endl;
    else
        aux = dados[topo--];	// mesmo que: aux = dados[topo]; --topo;
    return aux;
}

bool Pilha::vazia()
{
    return (topo == -1);
}

bool Pilha::cheia()
{
    return (topo == MAXPILHA-1);
}
