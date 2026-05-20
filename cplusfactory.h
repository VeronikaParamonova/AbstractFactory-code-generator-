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

    std::shared_ptr<AbstractClassUnit> createClassUnit(const std::string& name, Unit::Flags mod)
    {
        return std::make_shared<CPlusClassUnit>(name);
    }
    std::shared_ptr<AbstractMethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags)
    {
        return std::make_shared<CPlusMethodUnit>(name, returnType, flags);
    }
    std::shared_ptr<AbstractPrintOperatorUnit> createPrintOperatorUnit(const std::string& text)
    {
        return std::make_shared<CPlusPrintOperatorUnit>(text);
    }
};

#endif // CPLUSFACTORY_H
