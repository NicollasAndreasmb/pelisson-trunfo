#include "fullDeck.h"
#include <iostream>

using namespace std;

int main(){
    fullDeck fullDeck;

    fullDeck.PegaCartas();

    for (int i = 1; i <= 32; i++){
        Card card; 
        fullDeck.Retrive(i, card);

        cout << card.modelo;
        cout << card.grupo;
    }

    return 0;
}