#ifndef __RANGE_H__
#define __RANGE_H__

#include <vector> 
#include <cstdlib>
#include <iostream>

#include "card.h"
#include "parameter.h"

using namespace std;

class RANGE {

public:

    vector< vector<double> > bet;
//    DD 

private:

    PARAMETER para;

public:
    
    RANGE(PARAMETER &);
    ~RANGE();
    
    void randInit();
    
};

#endif
