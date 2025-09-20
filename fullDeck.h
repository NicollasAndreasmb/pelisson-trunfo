#include "card.h"
#ifndef FULLDECK_H
#define FULLDECK_H

class fullDeck{
private:
    static const int maxCard = 32;
    Card entry[maxCard + 1];
    int count;

public:
    fullDeck();
    ~fullDeck();
    bool Full();
    bool Empty();
    int Size();
    void Clear();
    void Insert(int p, Card x);
    void Remove(int p, Card &x);
    void Retrive(int p, Card &x);
    void Replace(int p, Card x);
    void PegaCartas();
};

#endif
