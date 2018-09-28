#include <vector>
#include <iostream>

#include "parameter.h"
#include "game.h"
#include "range.h"

using namespace std;

int main(int argc, char** argv) {

    srand(time(NULL));

    PARAMETER para;
    
    para.setTEST(atoi(argv[1]));
    para.setNOP(atoi(argv[2]));
    
    GAME game(para);
    
    game.initGame();
    if(para.TEST == 1)
        game.deck_TEST();
    
    while(1) {
    
        game.startGame();

        RANGE range(para);

        range.randInit();
        
        game.winLose();
        
        game.shuffle();
        
    }
    return 0;
    
}
