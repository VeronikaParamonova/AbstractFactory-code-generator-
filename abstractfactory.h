#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H
#include "Abstractclassunit.h"
#include "AbstractMethodUnit.h"
#include "AbstractPrintOperatorUnit.h"
#include "Unit.h"
#include <memory>
#include <string>


class AbstractFactory
{
public:
    virtual std::shared_ptr<AbstractClassUnit> createClassUnit(const std::string& name, Unit::Flags mod = 0) = 0;
    virtual  std::shared_ptr<AbstractMethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) = 0;
    virtual  std::shared_ptr<AbstractPrintOperatorUnit> createPrintOperatorUnit(const std::string& text) = 0;

    virtual ~AbstractFactory() = default;
};

#endif // ABSTRACTFACTORY_H
