#ifndef GAME_H
#define GAME_H

#include "playerDeck.h"
#include "fullDeck.h"

class Jogo {
    private:
        playerDeck p1, p2;
        fullDeck baralho;

        void distribuirCartas();
        void rodada(int rodadaNum);
        int compararAtributo(Card c1, Card c2, int atributo);
    public: 
        Jogo();
        void iniciar();
 
};

#endif // GAME_H