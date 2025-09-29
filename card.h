// Projeto: Super Trunfo (Implementação em C++)
//     Disciplina: Estrutura de Dados
//     Professor: FELIPE CARVALHO PELLISON
//     Autores: NICOLLAS ANDREAS MARQUES BARROS - 2276606
//              MISAEL FLEURI PILHERI - 2280142
//              JOSÉ HENRIQUE BATISTA BORGES - 2298111
//              JOÃO VICTOR MUTTON PIRES - 2266878
//     Grupo: Semestre 4/B - G5
#ifndef CARD_H
#define CARD_H

#include <string>

struct Card{
    std::string modelo;
    int pesoBruto;
    int cilindrada;
    int potencia;
    int preco;
    std::string grupo;
};

#endif // CARD_H
