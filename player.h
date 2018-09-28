#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <vector> 

#include "card.h"

using namespace std;

class PLAYER {

public:

    vector<CARD> ownCard;
    //vector<CARD> commonCard;

    double chip;
    int cardClass;
    
    CARD largeCard;

public:
    
    PLAYER();
    ~PLAYER();
    
};

#endif
