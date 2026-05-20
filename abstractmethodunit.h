#ifndef ABSTRACTMETHODUNIT_H
#define ABSTRACTMETHODUNIT_H
#include "unit.h"

class AbstractMethodUnit: public Unit
{
public:
//    enum Modifier {
//        STATIC = 1,
//        CONST = 1 << 1,
//        VIRTUAL = 1 << 2
//    };
    virtual ~AbstractMethodUnit() = default;
    virtual void add( const std::shared_ptr< Unit >& , Flags = 0 ) =0;
};

#endif // ABSTRACTMETHODUNIT_H
