#ifndef ABSTRACTCLASSUNIT_H
#define ABSTRACTCLASSUNIT_H
#include "unit.h"

class AbstractClassUnit: public Unit
{
public:
    enum AccessModifier {
                PUBLIC,
                PROTECTED,
                PRIVATE
            };
    AbstractClassUnit();
    virtual void add( const std::shared_ptr< Unit >& , Flags ) = 0;

};

#endif // ABSTRACTCLASSUNIT_H
