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


std::string generateProgram(AbstractFactory& factory)
{
//    std::shared_ptr<AbstractClassUnit> myClass = factory.createClassUnit("MyClass");

//    std::shared_ptr<AbstractMethodUnit> method1 = factory.createMethodUnit("testFunc1", "void", 2);
//    myClass->add(method1, AbstractClassUnit::PUBLIC);

//    std::shared_ptr<AbstractMethodUnit> method2 = factory.createMethodUnit("testFunc2", "void", AbstractMethodUnit::STATIC);
//    myClass->add(method2, AbstractClassUnit::PRIVATE);

//    std::shared_ptr<AbstractMethodUnit> method3 = factory.createMethodUnit("testFunc3", "void", AbstractMethodUnit::CONST|AbstractMethodUnit::VIRTUAL);
//    myClass->add(method3, AbstractClassUnit::PUBLIC);

//    std::shared_ptr<AbstractMethodUnit> method4 = factory.createMethodUnit("testFunc4", "void", AbstractMethodUnit::STATIC);
//    std::shared_ptr<AbstractPrintOperatorUnit> print = factory.createPrintOperatorUnit("Hello, world!\\n");
//    method4->add(print);
//    myClass->add(method4, AbstractClassUnit::PROTECTED);

//    return myClass->compile();

    // Создаём класс с модификатором INTERNAL для демонстрации (для C# будет internal class)
    std::shared_ptr<AbstractClassUnit> myClass = factory.createClassUnit("MyClass", AbstractClassUnit::INTERNAL);

    // Метод1: обычный
    std::shared_ptr<AbstractMethodUnit> method1 = factory.createMethodUnit("testFunc1", "void", 0);
    myClass->add(method1, AbstractClassUnit::PUBLIC);

    // Метод2: статический
    std::shared_ptr<AbstractMethodUnit> method2 = factory.createMethodUnit("testFunc2", "void", AbstractMethodUnit::STATIC);
    myClass->add(method2, AbstractClassUnit::PRIVATE);

    // Метод3: виртуальный и константный (для C++ const, для C# const игнорируется)
    std::shared_ptr<AbstractMethodUnit> method3 = factory.createMethodUnit("testFunc3", "void",
                                                                       AbstractMethodUnit::VIRTUAL | AbstractMethodUnit::CONST);
    myClass->add(method3, AbstractClassUnit::PUBLIC);

    // Метод4: статический, содержит PrintOperator
    std::shared_ptr<AbstractMethodUnit> method4 = factory.createMethodUnit("testFunc4", "void", AbstractMethodUnit::STATIC);
    std::shared_ptr<AbstractPrintOperatorUnit> print = factory.createPrintOperatorUnit("Hello, world!\\n");
    method4->add(print);
    myClass->add(method4, AbstractClassUnit::PROTECTED);

    return myClass->compile();

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CPlusFactory cplusFactory;
    std::cout << "=== C++ code ===\n" << generateProgram(cplusFactory) << std::endl;

    CSharpFactory csharpFactory;
    std::cout << "=== C# code ===\n" << generateProgram(csharpFactory) << std::endl;

    try
    {
        std::shared_ptr<AbstractMethodUnit> method1 = csharpFactory.createMethodUnit("testFunc1", "void", AbstractMethodUnit::VIRTUAL | AbstractMethodUnit::STATIC );
    } catch (...)
    {
        std::cerr << "Error: " << std::endl;
    }

    return a.exec();
}
