// game.cpp
#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Jogo::Jogo() {
    srand((unsigned) time(NULL));
    baralho.PegaCartas();
    distribuirCartas();
}

void Jogo::distribuirCartas() {
    baralho.DistribuirCartas(p1, p2);
}

int Jogo::compararAtributo(const Card &a, const Card &b, int atributo) {
    if (a.grupo == "1A" && b.grupo.find('A')) return 2;
    if (b.grupo == "1A" && a.grupo.find('A')) return 1;

    switch (atributo) {
        case 1:
            if (a.pesoBruto < b.pesoBruto) return 1;
            if (b.pesoBruto < a.pesoBruto) return 2;
            break;
        case 2:
            if (a.cilindrada > b.cilindrada) return 1;
            if (b.cilindrada > a.cilindrada) return 2;
            break;
        case 3:
            if (a.potencia > b.potencia) return 1;
            if (b.potencia > a.potencia) return 2;
            break;
        case 4: 
            if (a.preco < b.preco) return 1;
            if (b.preco < a.preco) return 2;
            break;
        default:
            return 3;
    }
    return 0; 
}

void Jogo::rodada(int rodadaNum) {
    if (p1.Empty()) {
        cout << "\n=== O computador venceu o jogo! ===\n";
        return;
    }
    if (p2.Empty()) {
        cout << "\n=== Parabéns — você venceu o jogo! ===\n";
        return;
    }

    cout << "\n===== Rodada " << rodadaNum << " =====\n";

    Card carta1, carta2;
    p1.GetFront(carta1);
    p2.GetFront(carta2);

    cout << "\nSua carta:\n";
    cout << "  Modelo: " << carta1.modelo << " | Grupo: " << carta1.grupo << "\n";
    cout << "  Peso: " << carta1.pesoBruto
         << " | Cilindrada: " << carta1.cilindrada
         << " | Potencia: " << carta1.potencia
         << " | Preco: " << carta1.preco << "\n";

    int atributo = 0;
    int resultado = 0;
    do {
        cout << "\nEscolha um atributo para comparar:\n";
        cout << " 1 = Peso (menor vence)\n";
        cout << " 2 = Cilindrada (maior vence)\n";
        cout << " 3 = Potencia (maior vence)\n";
        cout << " 4 = Preco (menor vence)\n";
        cout << "Selecione (1-4): ";
        cin >> atributo;

        resultado = compararAtributo(carta1, carta2, atributo);
        if (resultado == 0) {
            cout << "\nEmpate no atributo escolhido. Selecione outro atributo para desempatar.\n";
        } else if (resultado == 3){
            cout << "\nDigite um valor valido\n";
        }
    } while (resultado == 0 || resultado == 3);

    p1.Serve(carta1);
    p2.Serve(carta2);

    cout << "\nAtributos do adversário revelados:\n";
    cout << "   Modelo: " << carta2.modelo
         << " | Peso: " << carta2.pesoBruto
         << " | Cilindrada: " << carta2.cilindrada
         << " | Potencia: " << carta2.potencia
         << " | Preco: " << carta2.preco
         << " | Grupo: " << carta2.grupo << endl;

    if (resultado == 1) {
        cout << "\n>> Você venceu a rodada! As cartas irão para o final do seu deck.\n";
        p1.PegarCartaVencedor(carta1, carta2);
    } else {
        cout << "\n>> Computador venceu a rodada! As cartas irão para o final do deck do computador.\n";
        p2.PegarCartaVencedor(carta2, carta1);
    }

    rodada(rodadaNum + 1);
}

void Jogo::iniciar() {
    cout << "=== Super Trunfo — Iniciando partida ===\n";
    rodada(1);
}
