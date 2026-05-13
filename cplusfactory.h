#ifndef CPLUSFACTORY_H
#define CPLUSFACTORY_H
#include "AbstractFactory.h"
#include "CPlusClassUnit.h"
#include "CPlusMethodUnit.h"
#include "CPlusPrintOperatorUnit.h"

class CPlusFactory: public AbstractFactory
{
public:
    CPlusFactory();

    AbstractClassUnit* createClassUnit(const std::string& name)
    {
        return new CPlusClassUnit(name);
    }
    AbstractMethodUnit* createMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags)
    {
        return new CPlusMethodUnit(name, returnType, flags);
    }
    AbstractPrintOperatorUnit* createPrintOperatorUnit(const std::string& text)
    {
        return new CPlusPrintOperatorUnit(text);
    }
};

#endif // CPLUSFACTORY_H
