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
#include "CSharpFactory.h"
#include "CSharpclassunit.h"
#include "CSharpmethodunit.h"
#include "CSharpprintoperatorunit.h"
#include "JavaFactory.h"
#include "Javaclassunit.h"
#include "Javamethodunit.h"
#include "Javaprintoperatorunit.h"




std::string generateProgramTEST1(AbstractFactory& factory)
{
    std::shared_ptr<AbstractClassUnit> myClass = factory.createClassUnit("MyClass", 0);

    std::shared_ptr<AbstractMethodUnit> method1 = factory.createMethodUnit("testFunc1", "void", 0);
    myClass->add(method1, 0);

    std::shared_ptr<AbstractMethodUnit> method2 = factory.createMethodUnit("testFunc2", "void", 1 << 0);
    myClass->add(method2, 2);

    std::shared_ptr<AbstractMethodUnit> method3 = factory.createMethodUnit("testFunc3", "void", 1 << 1 | 1 << 2);
    myClass->add(method3, 0);

    std::shared_ptr<AbstractMethodUnit> method4 = factory.createMethodUnit("testFunc4", "void", 1 << 0);
    std::shared_ptr<AbstractPrintOperatorUnit> print = factory.createPrintOperatorUnit("Hello, world!\\n");
    method4->add(print);
    myClass->add(method4, 2);

    return myClass->compile();
}

std::string generateProgramTEST2(AbstractFactory& factory)
{
    std::shared_ptr<AbstractClassUnit> myClass = factory.createClassUnit("MyClass", 4);

    std::shared_ptr<AbstractMethodUnit> method1 = factory.createMethodUnit("testFunc1", "void", 0);
    myClass->add(method1, 0);

    std::shared_ptr<AbstractMethodUnit> method2 = factory.createMethodUnit("testFunc2", "void", 1 << 2);
    myClass->add(method2, 6);

    std::shared_ptr<AbstractMethodUnit> method3 = factory.createMethodUnit("testFunc3", "void", 1 << 0 | 1 << 3);
    myClass->add(method3, 5);

    std::shared_ptr<AbstractMethodUnit> method4 = factory.createMethodUnit("testFunc4", "void", 1 << 1);
    std::shared_ptr<AbstractPrintOperatorUnit> print = factory.createPrintOperatorUnit("Hello, world!\\n");
    method4->add(print);
    myClass->add(method4, 7);

    return myClass->compile();
}

std::string generateProgramTEST3(AbstractFactory& factory)
{
    std::shared_ptr<AbstractClassUnit> myClass = factory.createClassUnit("MyClass", 1);

    std::shared_ptr<AbstractMethodUnit> method1 = factory.createMethodUnit("testFunc1", "void", 0);
    myClass->add(method1, 0);

    std::shared_ptr<AbstractMethodUnit> method2 = factory.createMethodUnit("testFunc2", "bool", 1 << 1);
    myClass->add(method2, 5);

    std::shared_ptr<AbstractMethodUnit> method3 = factory.createMethodUnit("testFunc3", "void", 1 << 0 | 1 << 2);
    myClass->add(method3, 4);

    std::shared_ptr<AbstractMethodUnit> method4 = factory.createMethodUnit("testFunc4", "void", 1 << 0);
    std::shared_ptr<AbstractPrintOperatorUnit> print = factory.createPrintOperatorUnit("Hello, world!\\n");
    method4->add(print);
    myClass->add(method4, 2);

    return myClass->compile();
}

std::string generateProgramTEST4(AbstractFactory& factory)
{
    std::shared_ptr<AbstractClassUnit> myClass = factory.createClassUnit("MyClass", 3);

    std::shared_ptr<AbstractMethodUnit> method1 = factory.createMethodUnit("testFunc1", "int", 1 << 5);
    myClass->add(method1, 2);

    std::shared_ptr<AbstractMethodUnit> method2 = factory.createMethodUnit("testFunc2", "void", 1 << 2);
    myClass->add(method2, 5);

    std::shared_ptr<AbstractMethodUnit> method3 = factory.createMethodUnit("testFunc3", "void", 1 << 4 | 1 << 5);
    myClass->add(method3, 7);

    std::shared_ptr<AbstractMethodUnit> method4 = factory.createMethodUnit("testFunc4", "void", 1 << 0);
    std::shared_ptr<AbstractPrintOperatorUnit> print = factory.createPrintOperatorUnit("Hello, world!\\n");
    method4->add(print);
    myClass->add(method4, 1);

    return myClass->compile();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CPlusFactory cplusFactory;
    CSharpFactory csharpFactory;
    JavaFactory javaFactory;

    std::cout << "ProgrammTEST1" << std::endl;
    std::cout << std::endl;


    std::cout << "C++ code:\n" << generateProgramTEST1(cplusFactory) << std::endl;
    std::cout << "C# code:\n" << generateProgramTEST1(csharpFactory) << std::endl;
    std::cout << "Java code:\n" << generateProgramTEST1(javaFactory) << std::endl;

    std::cout << std::endl;
    std::cout << "ProgrammTEST2" << std::endl;
    std::cout << std::endl;


    std::cout << "C++ code:\n" << generateProgramTEST2(cplusFactory) << std::endl;
    std::cout << "C# code:\n" << generateProgramTEST2(csharpFactory) << std::endl;
    std::cout << "Java code:\n" << generateProgramTEST2(javaFactory) << std::endl;

    std::cout << std::endl;
    std::cout << "ProgrammTEST3" << std::endl;
    std::cout << std::endl;


    std::cout << "C++ code:\n" << generateProgramTEST3(cplusFactory) << std::endl;
    std::cout << "C# code:\n" << generateProgramTEST3(csharpFactory) << std::endl;
    std::cout << "Java code:\n" << generateProgramTEST3(javaFactory) << std::endl;

    std::cout << std::endl;
    std::cout << "ProgrammTEST4" << std::endl;
    std::cout << std::endl;


    std::cout << "C++ code:\n" << generateProgramTEST4(cplusFactory) << std::endl;
    std::cout << "C# code:\n" << generateProgramTEST4(csharpFactory) << std::endl;
    std::cout << "Java code:\n" << generateProgramTEST4(javaFactory) << std::endl;


    return a.exec();
}
