/*
===============================================================================
    Projeto: Super Trunfo (Implementação em C++)
    Disciplina: Estrutura de Dados
    Professor: FELIPE CARVALHO PELLISON
    Autores: NICOLLAS ANDREAS MARQUES BARROS
             MISAEL FLEURI PILHERI
             JOSÉ HENRIQUE BATISTA BORGES
             JOÃO VICTOR MUTTON PIRES
    Grupo: Semestre 4/B - G5

    Descrição Geral:
    ---------------------------------------------------------------------------
    Este programa implementa uma versão digital do clássico jogo "Super Trunfo",
    desenvolvido como exercício prático da disciplina de Estrutura de Dados.
    O objetivo do jogo é simular fielmente as regras originais utilizando
    estruturas de dados básicas (Lista e Fila), sem o uso de bibliotecas STL,
    respeitando restrições de memória e modularidade.

    Estrutura do Projeto:
    ---------------------------------------------------------------------------
    - card.h: define a estrutura de dados que representa cada carta.
    - fullDeck.h/.cpp: implementa a lista estática contendo as 32 cartas originais
      carregadas a partir do arquivo CSV.
    - playerDeck.h/.cpp: implementa a fila estática circular, representando
      o baralho de cada jogador durante a partida.
    - game.h/.cpp: contém a lógica principal do jogo, incluindo distribuição
      das cartas, comparação de atributos e controle de rodadas.
    - driver.cpp: ponto de entrada do programa; inicializa e executa a partida.

    Regras Implementadas:
    ---------------------------------------------------------------------------
    1) As 32 cartas são embaralhadas e distribuídas igualmente (16/16).
    2) Em cada rodada, os jogadores comparam atributos das cartas do topo.
       - Peso bruto e Preço: vence o menor valor.
       - Cilindrada e Potência: vence o maior valor.
    3) O vencedor recebe ambas as cartas, colocando-as no final do seu baralho.
    4) O jogo segue até que um dos jogadores fique sem cartas.

    Observações:
    ---------------------------------------------------------------------------
    - Implementação em C++ puro, sem containers da STL.
    - Uso de arrays estáticos para otimizar memória.
    - Organização modular para facilitar manutenção e compreensão.

===============================================================================
*/
#include "game.h"
int main() {
    Jogo partida;
    partida.iniciar();
    return 0;
}