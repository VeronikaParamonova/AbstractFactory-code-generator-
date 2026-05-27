#ifndef ABSTRACTCLASSUNIT_H
#define ABSTRACTCLASSUNIT_H
#include "unit.h"

class AbstractClassUnit: public Unit
{
public:
    enum AccessModifier {
                PUBLIC,
                PROTECTED,
                PRIVATE,
                INTERNAL,//для C#
                FILE, //для C#
                ABSTRACT,//для java
                FINAL //для java
                //STATIC для java и только вложенные классы, c которыми мы не работаем
            };

    virtual void add( const std::shared_ptr< Unit >& , Flags ) = 0;
    virtual ~AbstractClassUnit() = default;
};

#endif // ABSTRACTCLASSUNIT_H
