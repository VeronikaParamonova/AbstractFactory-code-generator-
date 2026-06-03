#ifndef ABSTRACTCLASSUNIT_H
#define ABSTRACTCLASSUNIT_H
#include "unit.h"

class AbstractClassUnit: public Unit
{
public:

    virtual void add( const std::shared_ptr< Unit >& , Flags ) = 0;
    virtual ~AbstractClassUnit() = default;
};

#endif // ABSTRACTCLASSUNIT_H
