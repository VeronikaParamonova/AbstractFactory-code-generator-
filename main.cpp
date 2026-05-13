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


std::string generateProgram(AbstractFactory& factory) {

    std::unique_ptr<AbstractClassUnit> myClass(factory.createClassUnit("MyClass"));

    std::shared_ptr<Unit> method1(factory.createMethodUnit("testFunc1", "void", 0));
    myClass->add(method1, AbstractClassUnit::PUBLIC);

    std::shared_ptr<Unit> method2(factory.createMethodUnit("testFunc2", "void", AbstractMethodUnit::STATIC));
    myClass->add(method2, AbstractClassUnit::PRIVATE);

    std::shared_ptr<Unit> method3(factory.createMethodUnit("testFunc3", "void", AbstractMethodUnit::VIRTUAL | AbstractMethodUnit::CONST));
    myClass->add(method3, AbstractClassUnit::PROTECTED);

//    std::shared_ptr<Unit> method4(factory.createMethodUnit("testFunc4", "void", AbstractMethodUnit::STATIC));
//    std::shared_ptr<Unit> print = factory.createPrintOperatorUnit("Hello, world!\\n");
//    method4->add(print);
//    myClass->add(method3, AbstractClassUnit::PROTECTED);

//    CPlusClassUnit myClass( "MyClass" );
//    myClass.add(
//        std::make_shared< CPlusMethodUnit >( "testFunc1", "void", 0 ),
//        CPlusClassUnit::PUBLIC
//        );
//    myClass.add(
//        std::make_shared< CPlusMethodUnit >( "testFunc2", "void", CPlusMethodUnit::STATIC ),
//        CPlusClassUnit::PRIVATE
//        );
//    myClass.add(
//        std::make_shared< CPlusMethodUnit >( "testFunc3", "void", CPlusMethodUnit::VIRTUAL | CPlusMethodUnit::CONST ),
//        CPlusClassUnit::PUBLIC
//        );
//    auto method = std::make_shared< CPlusMethodUnit >( "testFunc4", "void", CPlusMethodUnit::STATIC );
//    method->add( std::make_shared< CPlusPrintOperatorUnit >( R"(Hello, world!\n)" ) );
//    myClass.add( method, CPlusClassUnit::PROTECTED );
//    return myClass.compile();
    return myClass->compile();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CPlusFactory factory;

    std::cout << generateProgram(factory) << std::endl;

    return a.exec();
}
