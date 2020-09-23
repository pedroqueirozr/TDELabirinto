//
// Created by peter on 21/09/2020.
//

#ifndef TDELABIRINTO_PILHA_H
#define TDELABIRINTO_PILHA_H


const int MAXPILHA = 128;		// tamanho máximo da pilha

using TipoDado = int;			// tipo de dado armazenado na pilha

class Pilha {
protected:
    TipoDado dados[MAXPILHA];	// dados da pilha
    int topo;           		// topo (índice)
public:
    Pilha();					// construtor
    void push(TipoDado x);		// insere x no topo da pilha
    TipoDado pop();				// remove elemento do topo da pilha
    bool vazia();				// pilha vazia?
    bool cheia();				// pilha cheia?
};

#endif //TDELABIRINTO_PILHA_H
