#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H
#include "Abstractclassunit.h"
#include "AbstractMethodUnit.h"
#include "AbstractPrintOperatorUnit.h"
#include <memory>
#include <string>


class AbstractFactory
{
public:
    AbstractFactory();

    virtual AbstractClassUnit* createClassUnit(const std::string& name) = 0;
    virtual AbstractMethodUnit* createMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) = 0;
    virtual AbstractPrintOperatorUnit* createPrintOperatorUnit(const std::string& text) = 0;

    virtual ~AbstractFactory() = default;
};

#endif // ABSTRACTFACTORY_H
