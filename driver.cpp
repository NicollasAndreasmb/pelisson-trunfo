#include "fullDeck.h"
#include "playerDeck.h"
#include <iostream>

using namespace std;

int main(){
    fullDeck deckPrincipal;
    playerDeck jogador, maquina;

    deckPrincipal.PegaCartas();

    deckPrincipal.DistribuirCartas(jogador,maquina);

    cout<< "Cartas do Jogador:" << endl;
    for(int i = 0; i < jogador.Size(); i++){
        Card carta;
        jogador.GetFront(carta);
        cout << carta.modelo << "|"
             << carta.grupo << "|"
             << "Peso: " << carta.pesoBruto << "|"
             << "Cilindrada: " << carta.cilindrada << "|"
             << "Potencia: " << carta.potencia << "|"
             << "Preco: " << carta.preco << endl;

             jogador.Serve(carta);
             jogador.Append(carta);
    }
    
    cout << "\nCartas da Máquina:" << endl;
    for (int i = 0; i < maquina.Size(); i++){
        Card carta;
        maquina.GetFront(carta);
        cout << carta.modelo << "|"
             << carta.grupo << "|"
             << "Peso: " << carta.pesoBruto << "|"
             << "Cilindrada: " << carta.cilindrada << "|"
             << "Potencia: " << carta.potencia << "|"
             << "Preco: " << carta.preco << endl;

        maquina.Serve(carta);
        maquina.Append(carta);
    }

    return 0;
}