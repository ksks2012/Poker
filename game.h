#ifndef __GAME_H__
#define __GAME_H__

#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <algorithm>

#include "parameter.h"
#include "card.h"
#include "player.h"

using namespace std;

class GAME {

public:

    vector<CARD> deck;
    
    vector<CARD> commonCard;
    
    int deckIndex;
    
private:

    PARAMETER para;
    vector<PLAYER> player;

    vector<int> numberRecord;
    vector<int> flowerRecord;
    
    vector<CARD> tempCard;

public:
    
    GAME(PARAMETER &);
    ~GAME();

    void initGame();  
        void initDeck();  
        void shuffle();
        
    void startGame();
    
    void winLose();
        int cardStrength(PLAYER &);
            static bool comp(CARD &, CARD &);
            void initRecordTable();
            void genRecordTable();
            //decide
            bool isSuited();
            int isStraight(PLAYER &);
            //int isSuitedStraight(PLAYER &);
            int countSameNumber(PLAYER &);
//TEST
    void deck_TEST();
    void ownCard_TEST(vector<PLAYER>);
    
};

#endif
