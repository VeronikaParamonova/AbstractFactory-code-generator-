#ifndef ABSTRACTMETHODUNIT_H
#define ABSTRACTMETHODUNIT_H
#include "unit.h"

class AbstractMethodUnit: public Unit
{
public:

    virtual ~AbstractMethodUnit() = default;
    virtual void add( const std::shared_ptr< Unit >& , Flags = 0 ) =0;
};

#endif // ABSTRACTMETHODUNIT_H
