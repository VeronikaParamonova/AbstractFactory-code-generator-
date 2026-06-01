#ifndef ABSTRACTMETHODUNIT_H
#define ABSTRACTMETHODUNIT_H
#include "unit.h"

class AbstractMethodUnit: public Unit
{
public:
//    enum Modifier {
//        STATIC   = 1 << 0,
//        CONST    = 1 << 1,   // для C++
//        VIRTUAL  = 1 << 2,   // для C++ и C#
//        ABSTRACT = 1 << 5,   // для Java
//        FINAL    = 1 << 6    // для Java
//    };
    virtual ~AbstractMethodUnit() = default;
    virtual void add( const std::shared_ptr< Unit >& , Flags = 0 ) =0;
};

#endif // ABSTRACTMETHODUNIT_H
