#ifndef SETPROJECT_ARRAYSET_H
#define SETPROJECT_ARRAYSET_H
#include "InSet.h"

class ArraySet : public InSet{
private:
    int* set;
public:
    ArraySet();
    ArraySet(int);
    ArraySet(ArraySet&&) noexcept;
    ArraySet(const ArraySet&);
    ArraySet& operator=(ArraySet&&) noexcept;
    ArraySet& operator=(const ArraySet&);
    ~ArraySet();
};


#endif //SETPROJECT_ARRAYSET_H
