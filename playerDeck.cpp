// Projeto: Super Trunfo (Implementação em C++)
//     Disciplina: Estrutura de Dados
//     Professor: FELIPE CARVALHO PELLISON
//     Autores: NICOLLAS ANDREAS MARQUES BARROS - 2276606
//              MISAEL FLEURI PILHERI - 2280142
//              JOSÉ HENRIQUE BATISTA BORGES - 2298111
//              JOÃO VICTOR MUTTON PIRES - 2266878
//     Grupo: Semestre 4/B - G5
// playerDeck.cpp
#include "playerDeck.h"
#include <iostream>

using namespace std;

/*playerDeck.cpp
* -Implementação da classe playerDeck
* -Representa o baralho do jogador como fila circular com capacidade fixa de 32 cartas.
* -Operações: Append, Serve, GetFront, GetRear, PegarCartaVencedor
* -Verificação se o baralho está cheio, vazio
* -Retorno da quantidade de Cartas do Deck
* -Limpa o Deck
* -Adição de cartas ao final do Deck
* -Remoção de cartas do topo e retorna via referência
* -Pega a carta do topo sem remover
* -Pega a carta do final sem remover
*/
playerDeck::playerDeck() {
    count = 0;
    head = 1; //Indexação 1-based
    tail = 0;
}

playerDeck::~playerDeck(){
    cout<< "Deck do jogador destruído..." << endl;
}

bool playerDeck::Full(){
    return count == maxCard; 
}

bool playerDeck::Empty(){
    return count == 0;
}

int playerDeck::Size(){
    return count;
}

void playerDeck::Clear(){
    count = 0;
    head = 1;
    tail = 0;
}

void playerDeck::Append(Card x){
    if(!Full()){
        tail = (tail % maxCard) + 1;
        entry[tail] = x;
        count++;
    } else{
        cout << "Deck cheio! Não é possivel adicionar carta." << endl;
    }
}

void playerDeck::Serve(Card &x){
    if(!Empty()){
        x = entry[head];
        head = (head % maxCard) + 1;
        count--;
    }else {
        cout << "Deck vazio! Não foi possivel remover carta." << endl;
    }
}

void playerDeck::GetFront(Card &x){
    if (!Empty()){
        x = entry[head];
    } else{
        cout<< "Deck vazio! Não há cartas no topo." << endl;
    }
}

void playerDeck::GetRear(Card &x){
    if (!Empty()){
        x = entry[tail];
    } else{
        cout<< "Deck vazio! Não há cartas no final." << endl;
    }
}

/*PegarCartaVencedor
* -Adiciona as cartas vencedoras da rodada no final do Deck.
* -Ordem: primeiro a carta do adversário, depois a carta do jogador.
* -Mantém o fluxo da fila circular, essencial para o Super Trunfo.
*/
void playerDeck::PegarCartaVencedor(Card minhaCarta, Card cartaOponente){
    Append(cartaOponente);
    Append(minhaCarta);
}