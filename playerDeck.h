// Projeto: Super Trunfo (Implementação em C++)
//     Disciplina: Estrutura de Dados
//     Professor: FELIPE CARVALHO PELLISON
//     Autores: NICOLLAS ANDREAS MARQUES BARROS - 2276606
//              MISAEL FLEURI PILHERI - 2280142
//              JOSÉ HENRIQUE BATISTA BORGES - 2298111
//              JOÃO VICTOR MUTTON PIRES - 2266878
//     Grupo: Semestre 4/B - G5
// playerDeck.h
#ifndef PLAYERDECK_H
#define PLAYERDECK_H

#include "card.h"

/*
 * Classe playerDeck:
 * Representa o baralho do jogador (Fila circular).
 * 
 * - Capacidade fixa de 32 cartas.
 * - Indexação 1-based (primeira posição = 1).
 * - Suporta operações de Fila: Append, Serve, GetFront, GetRear.
 * - Posições de head e tail para somente andar os indices
 * - PegarCartaVencedor: adiciona as cartas vencedoras da rodada no final do deck
 *   na ordem correta (primeiro a carta do adversário, depois a do jogador),
 *   mantendo o fluxo da fila circular do Super Trunfo.
 */
class playerDeck{
    private:
        static const int maxCard = 32;
        Card entry[maxCard + 1];
        int count;
        int head;
        int tail;
    public:
        playerDeck();
        ~playerDeck();

        //Estado do Deck
        bool Full();
        bool Empty();
        int Size();
        void Clear();

        //Operações da fila
        void Append(Card x);
        void Serve(Card &x);
        void GetFront(Card &x);
        void GetRear(Card &x);

        //Adicionar as cartas vencedoras da rodada no fim do deck
        void PegarCartaVencedor(Card minhaCarta, Card cartaOponente);
};

#endif // PLAYERDECK_H