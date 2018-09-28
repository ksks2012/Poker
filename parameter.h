#ifndef __PARAMETER_H__
#define __PARAMETER_H__

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define WHITE "\033[1;37m"

class PARAMETER {

public:

    const static int NUM = 13;
    const static int FLOWER = 4;
    const static int DECK = NUM * FLOWER;
    
    //const static char flower_table[FLOWER] = {'\5','\4','\3','\6'};

    const static double blind = 5;

    int TEST;

    int NOP;

public:
    
    PARAMETER();
    ~PARAMETER();
    
    void setTEST(int );
    
    void setNOP(int );
    
};

#endif
