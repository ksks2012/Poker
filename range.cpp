#include "range.h"

RANGE::RANGE(PARAMETER &para) {

    this->para = para;

    bet = vector< vector<double> >(para.NUM + 2, vector<double>(para.NUM + 2, 0));
          
}

RANGE::~RANGE() {

}

void RANGE::randInit() {

    for(int i = 2; i < para.NUM + 2; ++i) {
    
        for(int j = i; j < para.NUM + 2; ++j) {
    
            bet[i][j] = (double)rand() / RAND_MAX;
            bet[j][i] = bet[i][j];

        }

    }

    if(para.TEST == 3) {
    
        for(int i = 2; i < para.NUM + 2; ++i) {
        
            for(int j = 2; j < para.NUM + 2; ++j) {

                cout << bet[i][j] << " ";
            }
            cout << endl;
        }
     
    }
        
}
