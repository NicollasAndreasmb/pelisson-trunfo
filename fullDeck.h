// fulldeck.h
// Projeto: Super Trunfo (Implementação em C++)
//     Disciplina: Estrutura de Dados
//     Professor: FELIPE CARVALHO PELLISON
//     Autores: NICOLLAS ANDREAS MARQUES BARROS - 2276606
//              MISAEL FLEURI PILHERI - 2280142
//              JOSÉ HENRIQUE BATISTA BORGES - 2298111
//              JOÃO VICTOR MUTTON PIRES - 2266878
//     Grupo: Semestre 4/B - G5
#ifndef FULLDECK_H
#define FULLDECK_H

#include "card.h"
#include "playerDeck.h"

/*
 * Classe fullDeck:
 * Representa o baralho completo (lista estática).
 * 
 * - Capacidade fixa de 32 cartas.
 * - Indexação 1-based (primeira posição = 1).
 * - Suporta operações de Lista: Insert, Remove, Retrieve, Replace.
 * - Método PegaCartas(): carrega do arquivo cards.csv.
 */
class fullDeck{
private:
    static const int maxCard = 32; 
    Card entry[maxCard + 1];
    int count;

public:
    fullDeck();
    ~fullDeck();

    //Estado do Deck
    bool Full();
    bool Empty();
    int Size();
    void Clear();

    // Operações Básicas
    void Insert(int p, Card x);
    void Remove(int p, Card &x);
    void Retrive(int p, Card &x);
    void Replace(int p, Card x);

    // Leitura do CSV e Preenchimento de Deck
    void PegaCartas();

    // Embaralha e distribui cartas igualmente ao jogadores
    void DistribuirCartas(playerDeck &jogador, playerDeck &maquina);
};

#endif // FULLDECK_H
