#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Jogo::Jogo(){
    srand(time(NULL));
    baralho.PegaCartas();
    distribuirCartas();
}


void Jogo::distribuirCartas(){
    for (int i = 1; i <= baralho.Size(); i++){
        Card temp;
        baralho.Retrive(i, temp);
        if (i % 2 == 1) p1.Append(temp);
        else p2.Append(temp);
    }
}

int Jogo::compararAtributo(Card c1, Card c2, int atributo){
    switch (atributo){
        case 1: if (c1.pesoBruto < c2.pesoBruto) return 1; if (c2.pesoBruto < c1.pesoBruto) return 2; break;
        case 2: if (c1.cilindrada > c2.cilindrada) return 1; if (c2.cilindrada > c1.cilindrada) return 2; break;
        case 3: if (c1.potencia > c2.potencia) return 1; if (c2.potencia > c1.potencia) return 2; break;
        case 4: if (c1.preco < c2.preco) return 1; if (c2.preco < c1.preco) return 2; break;
    }
    return 0;
}

void Jogo::rodada(int rodadaNum){
    if (p1.Empty()) {
        cout << "\n=== O Computador Venceu! ===" << endl;
        return;
    }
     if (p2.Empty()) {
        cout << "\n=== O Computador Venceu! ===" << endl;
        return;
    }

    cout << "\n===== Rodada " << rodadaNum << " =====" << endl;

    Card carta1, carta2;
    p1.GetFront(carta1);
    p2.GetFront(carta2);


    cout << "\nSua carta: " << carta1.modelo
         << " | Peso: " << carta1.pesoBruto
         << " | Cilindrada: " << carta1.cilindrada
         << " | Potencia: " << carta1.potencia
         << " | Preco: " << carta1.preco
         << " | Grupo: " << carta1.grupo << endl;

    cout << "Carta do adversario: " << carta2.modelo << " | Grupo: " << carta2.grupo << endl;

    int atributo;
    cout << "\nEscolha um atributo (1=Peso | 2=Cilindrada | 3=Potencia | 4=Preco): ";
    cin >> atributo;

    p1.Serve(carta1);
    p2.Serve(carta2);

    int vencedor = compararAtributo(carta1, carta2, atributo);


    if (vencedor == 0) {
        cout << "\nEmpate! Nova rodada." << endl;
        p1.Append(carta1);
        p2.Append(carta2);
        rodada(rodadaNum + 1);
        return;
    }

    cout << "\nCarta adversaria revelada: " << carta2.modelo
         << " | Peso: " << carta2.pesoBruto
         << " | Cilindrada: " << carta2.cilindrada
         << " | Potencia: " << carta2.potencia
         << " | Preco: " << carta2.preco
         << " | Grupo: " << carta2.grupo << endl;

    if (vencedor == 1) {
        cout << "\n>> Voce venceu a rodada!" << endl;
        p1.Append(carta2);
        p1.Append(carta1);
    } else {
        cout << "\n>> Computador venceu a rodada!" << endl;
        p2.Append(carta1);
        p2.Append(carta2);
    }

    rodada(rodadaNum + 1);
}

void Jogo::iniciar() {
    cout << "=== Super Trunfo iniciado! ===" << endl;
    rodada(1);
}