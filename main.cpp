#include <QCoreApplication>
#include <memory>
#include <vector>
#include <iostream>
#include "unit.h"
#include "cplusclassunit.h"
#include "cplusmethodunit.h"
#include "cplusprintoperatorunit.h"
#include "AbstractFactory.h"
#include "CPlusFactory.h"


std::string generateProgram(AbstractFactory& factory)
{
    std::shared_ptr<AbstractClassUnit> myClass = factory.createClassUnit("MyClass");

    std::shared_ptr<AbstractMethodUnit> method1 = factory.createMethodUnit("testFunc1", "void", 2);
    myClass->add(method1, AbstractClassUnit::PUBLIC);

    std::shared_ptr<AbstractMethodUnit> method2 = factory.createMethodUnit("testFunc2", "void", AbstractMethodUnit::STATIC);
    myClass->add(method2, AbstractClassUnit::PRIVATE);

    std::shared_ptr<AbstractMethodUnit> method3 = factory.createMethodUnit("testFunc3", "void", AbstractMethodUnit::CONST|AbstractMethodUnit::VIRTUAL);
    myClass->add(method3, AbstractClassUnit::PUBLIC);

    std::shared_ptr<AbstractMethodUnit> method4 = factory.createMethodUnit("testFunc4", "void", AbstractMethodUnit::STATIC);
    std::shared_ptr<AbstractPrintOperatorUnit> print = factory.createPrintOperatorUnit("Hello, world!\\n");
    method4->add(print);
    myClass->add(method4, AbstractClassUnit::PROTECTED);

    return myClass->compile();

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CPlusFactory factory;

    std::cout << generateProgram(factory) << std::endl;

    //std::cout << generateProgram(factory) << std::endl;

    return a.exec();
}
