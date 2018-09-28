#include "player.h"

PLAYER::PLAYER() {

    ownCard = vector<CARD>(2);
    
    largeCard.number = -1;
    largeCard.flower = -1;

}

PLAYER::~PLAYER() {

}
