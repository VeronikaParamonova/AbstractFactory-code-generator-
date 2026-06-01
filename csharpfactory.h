#ifndef CSHARPFACTORY_H
#define CSHARPFACTORY_H

#include "AbstractFactory.h"
#include "CSharpClassUnit.h"
#include "CSharpMethodUnit.h"
#include "CSharpPrintOperatorUnit.h"

class CSharpFactory: public AbstractFactory
{
public:
    CSharpFactory();

    std::shared_ptr<AbstractClassUnit> createClassUnit(const std::string& name, Unit::Flags flag = 0) override
    {
        return std::make_shared<CSharpClassUnit>(name, flag);
    }
    std::shared_ptr<AbstractMethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) override
    {
        return std::make_shared<CSharpMethodUnit>(name, returnType, flags);
    }
    std::shared_ptr<AbstractPrintOperatorUnit> createPrintOperatorUnit(const std::string& text) override
    {
        return std::make_shared<CSharpPrintOperatorUnit>(text);
    }
};

#endif // CSHARPFACTORY_H
