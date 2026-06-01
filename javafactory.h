#ifndef JAVAFACTORY_H
#define JAVAFACTORY_H

#include "AbstractFactory.h"
#include "JavaClassUnit.h"
#include "JavaMethodUnit.h"
#include "JavaPrintOperatorUnit.h"

class JavaFactory: public AbstractFactory
{
public:
    JavaFactory();

    std::shared_ptr<AbstractClassUnit> createClassUnit(const std::string& name, Unit::Flags flag = 0) override
    {
        return std::make_shared<JavaClassUnit>(name, flag);
    }
    std::shared_ptr<AbstractMethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) override
    {
        return std::make_shared<JavaMethodUnit>(name, returnType, flags);
    }
    std::shared_ptr<AbstractPrintOperatorUnit> createPrintOperatorUnit(const std::string& text) override
    {
        return std::make_shared<JavaPrintOperatorUnit>(text);
    }
};
#endif // JAVAFACTORY_H
