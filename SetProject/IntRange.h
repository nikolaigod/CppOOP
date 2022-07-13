#ifndef SETPROJECT_INTRANGE_H
#define SETPROJECT_INTRANGE_H
#include "InSet.h"

class IntRange : public InSet{
private:
    int start;
    int end;
public:
    IntRange();
    IntRange(int, int);
};


#endif //SETPROJECT_INTRANGE_H
