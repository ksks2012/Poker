#include "game.h" 

GAME::GAME(PARAMETER &para) {

    this->para = para;
    
    deck = vector<CARD>(para.DECK);
    player = vector<PLAYER>(para.NOP);
    
    commonCard = vector<CARD>(5);

    numberRecord = vector<int>(para.NUM+2, 0);
    flowerRecord = vector<int>(para.FLOWER, 0);

    tempCard = vector<CARD>(7);
    
}

GAME::~GAME() {

}


void GAME::initGame() {

    initDeck();

    shuffle();

}

void GAME::initDeck() {

    for(int i = 0; i < para.FLOWER; ++i) {

        for(int j = 2; j < para.NUM + 2; ++j) {
        
            int k = i * para.NUM + (j - 2);
        
            deck[k].flower = i;
            deck[k].number = j;
        
        }

    }
    
    deckIndex = 0;

}

void GAME::shuffle() {

    for(int i = 0; i < para.DECK; ++i) {
    
        int randIndex = rand() % para.DECK;
        
        CARD temp;
        
        temp = deck[i];
        deck[i] = deck[randIndex];
        deck[randIndex] = temp;
        
    }

}

void GAME::startGame() {

    deckIndex = 0;

    //first round
    for(int i = 0; i < para.NOP; ++i) {
    
        //give own card
        for(int j = 0; j < 2; ++j) {
    
            player[i].ownCard[j] = deck[deckIndex];
            ++deckIndex;
    
        }
           
    }
    
    //second round
    //give 3 card
    for(int i = 0; i < 3; ++i) {
    
        commonCard[i] = deck[deckIndex];
        ++deckIndex;
        
    }
    
    //third round
    for(int i = 3; i < 5; ++i) {
    
        commonCard[i] = deck[deckIndex];
        ++deckIndex;
        
    }
    
    if(para.TEST == 2)        
        ownCard_TEST(player);

}

void GAME::winLose() {

    for(int i = 0; i < para.NOP; ++i) {
    
        player[i].cardClass = cardStrength(player[i]);
        cout << GREEN << player[i].cardClass << WHITE << endl;
        
        if(player[i].cardClass > 0) {
            cout << RED << player[i].largeCard.number << " " << player[i].largeCard.flower << WHITE << endl;
            fgetc(stdin);
        }

        
    }

}

int GAME::cardStrength(PLAYER &currentPlayer) {

    //temp
    for(int i = 0; i < 2; ++i) {
    
        tempCard[i] = currentPlayer.ownCard[i];
    
    }
    
    int k = 2;
    
    for(int i = 0; i < 5; ++i) {
    
        tempCard[i + k] = commonCard[i];
    
    }
    
    sort(tempCard.begin(), tempCard.end(), comp);

    if(para.TEST == 4) {
    
        for(int i = 0; i < 7; ++i) {
    
            cout << tempCard[i].number << " " << tempCard[i].flower << endl;
        
        }
    
    }
    
    initRecordTable();
    
    genRecordTable();
    
    //Suited
    if(isSuited()) {
    
        int straight = isStraight(currentPlayer);
        if(straight) {
        
           return straight;
        }
            
        else 
            return 6;
        
    }
    
    switch(countSameNumber(currentPlayer)) {
    
        case 1:
            return 1;
            break;
        case 2:
            //TODO Two pairs or One pair
            return 2;
            break;
        case 3:
            //TODO Full house or Three of a kind
            return 3;
            break;
        case 4:
            return 7;
            break;
        
        default:
            cout << RED << "error" << WHITE << endl;

            break;
    }
    
    return 0;

}

bool GAME::comp(CARD &a, CARD &b) {

    if(a.number > b.number)
        return true;
        
    return false;     
    
}

void GAME::initRecordTable() {

    fill(numberRecord.begin(), numberRecord.end(), 0);
    fill(flowerRecord.begin(), flowerRecord.end(), 0);

}

void GAME::genRecordTable() {

    for(int i = 0; i < 7; ++i) {
    
        ++numberRecord[tempCard[i].number];
        ++flowerRecord[tempCard[i].flower];
        
        if(tempCard[i].number == 14)
            ++numberRecord[1];
        
    }

}

bool GAME::isSuited() {

    for(int i = 0; i < para.FLOWER; ++i) {
    
        if(flowerRecord[i] >= 5)
            return true;
        
    }

    return false;
    
}

int GAME::isStraight(PLAYER &currentPlayer) {

    int countNum = 0;
    int countFlower = 0;
    
    for(int i = 0; i < 6; ++i) {
    
        if(tempCard[i].number == tempCard[i + 1].number + 1) {
        
            ++countNum;
            if(tempCard[i].flower == tempCard[i + 1].flower) {
            
                ++countFlower;   
            
            } else {
            
                countFlower = 0;
            
            }
                        
        } else {
        
            countNum = 0;

        }  
        //cout << RED << countNum << WHITE << endl;
        //cout << RED << countFlower << WHITE << endl << endl;
        if(countNum == 5 && countFlower == 5) {
        
            currentPlayer.largeCard = tempCard[i - 4];
            return 9;
            
        } 
        
        if(countNum == 5) {
        
            currentPlayer.largeCard = tempCard[i - 4];
            return 5;
        
        }
            
    }
    
    return 0;

}

int GAME::countSameNumber(PLAYER &currentPlayer) {

    int maxNumber = 0;
    int maxSameNumber = 0;
    
    for(int i = 14; i > 1; --i) {
    
        if(numberRecord[i] > maxSameNumber) {
        
             maxSameNumber = numberRecord[i];
             currentPlayer.largeCard.number = i;
        
        }
              
    }

    
    //cout << maxSameNumber << endl;
    cout << GREEN << "maxSameNumber " << maxSameNumber << WHITE << endl;
    
    return maxSameNumber;

}

//TEST
void GAME::deck_TEST() {

    for(int i = 0; i < para.FLOWER; ++i) {
    
        for(int j = 2; j < para.NUM + 2; ++j) {
        
            int k = i * para.NUM + (j - 2);
            
            cout << deck[k].number << " " << deck[k].flower << endl;
        
        }
    
    }

}

void GAME::ownCard_TEST(vector<PLAYER> player) {

    for(int i = 0; i < para.NOP; ++i) {
    
        for(int j = 0; j < 2; ++j) {
                    
            cout << player[i].ownCard[j].number << " " << player[i].ownCard[j].flower << endl;
        
        }
    
    }

}


