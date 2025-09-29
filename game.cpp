// Projeto: Super Trunfo (Implementação em C++)
//     Disciplina: Estrutura de Dados
//     Professor: FELIPE CARVALHO PELLISON
//     Autores: NICOLLAS ANDREAS MARQUES BARROS - 2276606
//              MISAEL FLEURI PILHERI - 2280142
//              JOSÉ HENRIQUE BATISTA BORGES - 2298111
//              JOÃO VICTOR MUTTON PIRES - 2266878
//     Grupo: Semestre 4/B - G5
// game.cpp
#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

Jogo::Jogo() {
    baralho.PegaCartas();
}

void Jogo::distribuirCartas() {
    baralho.DistribuirCartas(p1, p2);
}

int Jogo::compararAtributo(const Card &a, const Card &b, int atributo) {
    if (a.grupo == "1A") {
        if (b.grupo == "1A") return 0;
        if (b.grupo.find('A') != string::npos) return 2;
        return 1;
    }
    if (b.grupo == "1A") {
        if (a.grupo.find('A') != string::npos) return 1;
        return 2;
    }

    switch (atributo) {
        case 1: // Peso (menor vence)
            if (a.pesoBruto < b.pesoBruto) return 1;
            if (b.pesoBruto < a.pesoBruto) return 2;
            return 0;
        case 2: // Cilindrada (maior vence)
            if (a.cilindrada > b.cilindrada) return 1;
            if (b.cilindrada > a.cilindrada) return 2;
            return 0;
        case 3: // Potencia (maior vence)
            if (a.potencia > b.potencia) return 1;
            if (b.potencia > a.potencia) return 2;
            return 0;
        case 4: // Preco (menor vence)
            if (a.preco < b.preco) return 1;
            if (b.preco < a.preco) return 2;
            return 0;
        default:
            return 3; // atributo inválido
    }
}

void Jogo::rodada() {

    int rodadaNum = 1;

    while(true){
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

        // NOVO: comparação automática quando houver SUPER TRUNFO (1A)
        if (carta1.grupo == "1A" || carta2.grupo == "1A") {
            cout << "\nImportante >> CARTA SUPER TRUNFO detectada! Comparação automática.\n";
            resultado = compararAtributo(carta1, carta2, 1);
        } else {
            do {
                cout << "\nEscolha um atributo para comparar:\n";
                cout << " 1 = Peso (menor vence)\n";
                cout << " 2 = Cilindrada (maior vence)\n";
                cout << " 3 = Potencia (maior vence)\n";
                cout << " 4 = Preco (menor vence)\n";
                cout << "Selecione (1-4): ";
                cin >> atributo;

                if (!cin) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\nEntrada inválida. Digite um número entre 1 e 4.\n";
                    resultado = 3;
                    continue;
                }

                resultado = compararAtributo(carta1, carta2, atributo);
                if (resultado == 0) {
                    cout << "\nEmpate no atributo escolhido. Selecione outro atributo para desempatar.\n";
                } else if (resultado == 3){
                    cout << "\nDigite um valor valido\n";
                }
            } while (resultado == 0 || resultado == 3);
        }

        p1.Serve(carta1);
        p2.Serve(carta2);

        cout << "\nAtributos do adversário revelados:\n";
        cout << "   Modelo: " << carta2.modelo
            << " | Peso: " << carta2.pesoBruto
            << " | Cilindrada: " << carta2.cilindrada
            << " | Potencia: " << carta2.potencia
            << " | Preco: " << carta2.preco
            << " | Grupo: " << carta2.grupo << endl;

        // NOVO: tratamento de empate (inclui 1A vs 1A) -> próxima rodada
        if (resultado == 0) {
            cout << "\nEmpate! Nova rodada.\n";
            p1.Append(carta1);
            p2.Append(carta2);
            rodadaNum++;
            continue;
        }

        if (resultado == 1) {
            cout << "\n>> Você venceu a rodada! As cartas irão para o final do seu deck.\n";
            p1.PegarCartaVencedor(carta1, carta2);
        } else {
            cout << "\n>> Computador venceu a rodada! As cartas irão para o final do deck do computador.\n";
            p2.PegarCartaVencedor(carta2, carta1);
        }
        
        rodadaNum++;
    }
}

void Jogo::mostrarSobre() {
    cout << "\n=== Sobre o jogo ===\n";
    cout << "Objetivo: ganhar todas as cartas do baralho.\n\n";
    cout << "O jogo:\n";
    cout << "- Compare sua carta com a do computador.\n";
    cout << "- Para vencer a rodada, o atributo escolhido deve vencer segundo a regra.\n";
    cout << "- Quem vence ganha a carta do adversario e coloca ambas no fim do seu deck.\n\n";
    cout << "Como jogar:\n";
    cout << "1) Embaralham-se as 32 cartas e dividem-se em dois decks (P1 e P2).\n";
    cout << "2) E retirada a carta do topo de P1 e P2.\n";
    cout << "3) Escolhe-se o atributo para comparar:\n";
    cout << "   - Peso bruto e Preco: menor valor vence.\n";
    cout << "   - Cilindrada e Potencia: maior valor vence.\n";
    cout << "   - Em caso de empate, escolha outro atributo para desempatar.\n";
    cout << "4) As informacoes de ambas as cartas sao exibidas no terminal.\n";
    cout << "5) O vencedor recebe a carta do oponente e a coloca no final do seu deck, seguida da carta vencedora.\n";
    cout << "6) Repita ate que um dos jogadores fique com o deck vazio.\n\n";
    cout << "Importante >> CARTA SUPER TRUNFO:\n";
    cout << "- A carta 1A vence todas, exceto cartas cujo grupo contenha 'A' (2A, 3A, ...).\n";
    cout << "- Quando a 1A aparece, a comparacao e automatica (sem escolher atributo).\n";
    cout << "Vence o jogo quem possuir todas as cartas no deck.\n\n";
}


void Jogo::iniciar() {
    while (true) {
        cout << "\n=== Super Trunfo ===\n";
        cout << "1) Sobre o jogo\n";
        cout << "2) Iniciar partida\n";
        cout << "3) Sair\n";
        cout << "Escolha: ";

        int opc = 0;
        cin >> opc;
        if (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nEntrada invalida.\n";
            continue;
        }

        if (opc == 1) {
            mostrarSobre();
        } else if (opc == 2) {
            // reinicia os decks e redistribui
            p1.Clear();
            p2.Clear();
            distribuirCartas();
            cout << "=== Super Trunfo iniciado! ===\n";
            rodada();
        } else if (opc == 3) {
            cout << "Saindo...\n";
            return;
        } else {
            cout << "Opcao invalida.\n";
        }
    }
}
