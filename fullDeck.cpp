#include "fullDeck.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

fullDeck::fullDeck(){
    count = 0;
}

fullDeck::~fullDeck(){
    cout << "Deck destruido... " << endl;
}

bool fullDeck::Full(){
    return count == maxCard;
}

bool fullDeck::Empty(){
    return count == 0;
} 

void fullDeck::Clear(){
    count = 0;
}

int fullDeck::Size(){
    return count;
}

void fullDeck::Insert(int p, Card x){
    if (Full()){
        cout << "O deck esta cheio..." << endl;
        abort();
    }

    if (p <= 0 || p > count + 1){
        cout << "Posicao invalida" << endl;
        abort();
    }

    for (int i = count; i >= p; i--){
        entry[i + 1] = entry[i];
    }
    
    entry[p] = x;
    count++;
}

void fullDeck::Remove(int p, Card &x){
    if (Empty()){
        cout << "O deck esta vazio..." << endl;
        abort();
    }

    if (p <= 0 || p > count){
        cout << "Posicao invalida" << endl;
        abort();
    }

    x = entry[p];

    for(int i = p; i < count; i++){
        entry[i] = entry[i + 1];
    }

    count--;
}

void fullDeck::Retrive(int p, Card &x){
    if (Empty()){
        cout << "O deck esta vazio..." << endl;
        abort();
    }

    if (p <= 0 || p > count){
        cout << "Posicao invalida" << endl;
        abort();
    }
    
    x = entry[p];
}

void fullDeck::Replace(int p, Card x){
    if (Empty()){
        cout << "O deck esta vazio..." << endl;
        abort();
    }

    if (p <= 0 || p > count + 1){
        cout << "Posicao invalida" << endl;
        abort();
    }

    entry[p] = x;
}

void fullDeck::PegaCartas(){
    ifstream file("cards.csv");

    if (!file.is_open()){
        cout << "Nao foi possivel abrir o arquivo" << endl;
        abort();
    }

    string line;
    getline(file, line); //Ignora primeira linha

    while (getline(file, line)){
        Card card;
        string token;
        stringstream ss(line);
        
        if (!getline(ss, token, ',')) continue;
        card.modelo = token;

        if (!getline(ss, token, ',')) continue;
        card.pesoBruto = stoi(token);

        if (!getline(ss, token, ',')) continue;
        card.cilindrada = stoi(token);

        if (!getline(ss, token, ',')) continue;
        card.potencia = stoi(token);

        if (!getline(ss, token, ',')) continue;
        card.preco = stoi(token);

        if (!getline(ss, token, ',')) continue;
        card.grupo = token;

        Insert(count + 1, card);
    }

    file.close();
}