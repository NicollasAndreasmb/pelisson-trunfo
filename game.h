// Projeto: Super Trunfo (Implementação em C++)
//     Disciplina: Estrutura de Dados
//     Professor: FELIPE CARVALHO PELLISON
//     Autores: NICOLLAS ANDREAS MARQUES BARROS - 2276606
//              MISAEL FLEURI PILHERI - 2280142
//              JOSÉ HENRIQUE BATISTA BORGES - 2298111
//              JOÃO VICTOR MUTTON PIRES - 2266878
//     Grupo: Semestre 4/B - G5
#ifndef GAME_H
#define GAME_H

#include "playerDeck.h"
#include "fullDeck.h"

class Jogo {
    private:
        playerDeck p1, p2;
        fullDeck baralho;

        void distribuirCartas();
        void rodada();
        int compararAtributo(const Card &c1, const Card &c2, int atributo);
        void mostrarSobre();
    public: 
        Jogo();
        void iniciar();
 
};

#endif // GAME_H