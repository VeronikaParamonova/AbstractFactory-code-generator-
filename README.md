# Постановка задачи
  В рамках второй лабораторной работы предоставлялась программа для генерации кода на языке C++. Требовалось после его освоения модернизировать программу таким образом, чтобы программа имела возможность генерировать код также на языках C# и Java. Важным уточнением является то, что результатом работы должна стать программа, открытая для лёгкого масштабирования.\
# Предлагаемое решение
  После анализа предоставленной программы стало понятным, что в ней генерация кода происходит за счёт создания семейства взаимосвязанных объектов. Таким образом предлагаемое решение состоит в применении паттерна "Абстрактная фабрика", благодаря которому программа станет способна создавать непересекающиеся семейства объектов. А система в свою очередь останется независимой как от процесса создания новых объектов, так и от их типа. \
  UML диаграмма выполнена с помощью drawio.\
  Для применения паттерна в предоставленном изначально коде были созданы общие интерфейсы для каждого типа продуктов (AbstractClassUnit, AbstractMethodUnit, AbstractPrintOperatorUnit), наследниками которых и стали классы ClassUnit, MethodUnit, PrintOperatorUnit. В последствии они были переименованы в соответствии с тем, что они создают объекты коды С++. Создан полиморфный базовый класс AbstractFactory для объявления интерфейса фабричных методов. Далее оставалось лишь создать "конкретные" фабрики для каждого языка с определением фабричных методов и "конкретные" типы продуктов для C# и Java\
  Перечисления для типов доступа и модификаторов методов предлагается поместить в реализацию "конкретных" продуктов каждого языка, для простой масштабируемости и независимости клиентского кода от типа языка.\
# Инструкция пользователя
  Так как нашей главной целью была лёгкая масштабируемость и независимость клиентского кода, то без инструкции для пользователя не обойтись. Далее представлен "словарь" типов доступа и модификаторов методов для каждого языка. Это требуется для написания клиентского кода:\
## С++
### Модификаторы классов
0 - PUBLIC\
1 - PROTECTED\
2 - PRIVATE\
### Модификаторы методов
1 << 0 - STATIC\
1 << 1 - CONST\
1 << 2 - VIRTUAL\
## С#
### Модификаторы классов
0 - NON\
1 - PUBLIC\
2 - PROTECTED\
3 - PRIVATE\
4 - INTERNAL\
5 - FILE\
6 - PRIVATE PROTECTED\
7 - PROTECTED INTERNAL\
### Модификаторы методов
1 << 0 - STATIC\
1 << 1 - CONST\
1 << 2 - VIRTUAL\
1 << 3 SEALED\
## Java
### Модификаторы классов
0 - NON\
1 - PUBLIC\
2 - PROTECTED\
3 - PRIVATE\
4 - FINAL\
5 - ABSTRACT\
### Модификаторы методов
1 << 0 - STATIC\
1 << 1 - ABSTRACT\
1 << 2 - FINAL\
# Тестирование
  Тестирование происходит засчёт написания клиентских кодов, внутри которых создаются семейства объектов. На вход такого кода приходит фабрика "конкретного типа". И в зависимости от типа фабрики один и тот же клиентский код может создать различные, но корректные коды для каждого языка.(различие связано с тем, что, например 1 на языке C++ обозначает тип доступа PROTECTED, а на языке Java - PUBLIC) 
  ## Case1
  ```
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

    return a.exec();
}

ВЫВОД:

ProgrammTEST1

C++ code:
class MyClass {
public:
    void testFunc1() {
    }
    virtual void testFunc3() const {
    }

private:
    static void testFunc2() {
    }
    static void testFunc4() {
        printf( "Hello, world!\n" );
    }

};

C# code:
method testFunc3 C# cannot be abstract AND virtual
class MyClass {
    void testFunc1() {
    }
    void testFunc3() {
    }

    protected static void testFunc2() {
    }
    protected static void testFunc4() {
        Console.WriteLine( "Hello, world!\n" );
    }

}

Java code:
method testFunc3 Java cannot be abstract AND final
class MyClass {
    void testFunc1() {
    }
    void testFunc3() {
    }

    protected static void testFunc2() {
    }
    protected static void testFunc4() {
        System.out.println( "Hello, world!\n" );
    }

}
```
## Case 2
```
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

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CPlusFactory cplusFactory;
    CSharpFactory csharpFactory;
    JavaFactory javaFactory;

    std::cout << "ProgrammTEST2" << std::endl;
    std::cout << std::endl;


    std::cout << "C++ code:\n" << generateProgramTEST2(cplusFactory) << std::endl;
    std::cout << "C# code:\n" << generateProgramTEST2(csharpFactory) << std::endl;
    std::cout << "Java code:\n" << generateProgramTEST2(javaFactory) << std::endl;

    return a.exec();
}

ВЫВОД
ProgrammTEST2

C++ code:
class MyClass {
public:
    void testFunc1() {
    }

private:
    virtual void testFunc2() {
    }
    static void testFunc3() {
    }
    void testFunc4() const {
        printf( "Hello, world!\n" );
    }

};

C# code:
internal class MyClass {
    void testFunc1() {
    }

    file static sealed void testFunc3() {
    }

    private protected abstract void testFunc2() {
    }

    protected internal virtual void testFunc4() {
        Console.WriteLine( "Hello, world!\n" );
    }

}

Java code:
class MyClass {
    void testFunc1() {
    }
    final void testFunc2() {
    }
    abstract void testFunc4();

    static void testFunc3() {
    }

}
```
## Case 3
```
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

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CPlusFactory cplusFactory;
    CSharpFactory csharpFactory;
    JavaFactory javaFactory;

    std::cout << "ProgrammTEST3" << std::endl;
    std::cout << std::endl;


    std::cout << "C++ code:\n" << generateProgramTEST3(cplusFactory) << std::endl;
    std::cout << "C# code:\n" << generateProgramTEST3(csharpFactory) << std::endl;
    std::cout << "Java code:\n" << generateProgramTEST3(javaFactory) << std::endl;

    return a.exec();
}

ВЫВОД

ProgrammTEST3

C++ code:
method testFunc3 C++ cannot be static AND virtual
class MyClass {
public:
    void testFunc1() {
    }

private:
    bool testFunc2() const {
    }
    void testFunc3() {
    }
    static void testFunc4() {
        printf( "Hello, world!\n" );
    }

};

C# code:
method testFunc3 C# cannot be abstract AND static
public class MyClass {
    void testFunc1() {
    }

    protected static void testFunc4() {
        Console.WriteLine( "Hello, world!\n" );
    }

    internal void testFunc3() {
    }

    file virtual bool testFunc2() {
    }

}

Java code:
public class MyClass {
    void testFunc1() {
    }

    protected static void testFunc4() {
        System.out.println( "Hello, world!\n" );
    }

    static final void testFunc3() {
    }

    abstract bool testFunc2();

}
```
## Case 4
```
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

    std::cout << "ProgrammTEST4" << std::endl;
    std::cout << std::endl;


    std::cout << "C++ code:\n" << generateProgramTEST4(cplusFactory) << std::endl;
    std::cout << "C# code:\n" << generateProgramTEST4(csharpFactory) << std::endl;
    std::cout << "Java code:\n" << generateProgramTEST4(javaFactory) << std::endl;


    return a.exec();
}

ВЫВОД

ProgrammTEST4

C++ code:
class MyClass {
protected:
    static void testFunc4() {
        printf( "Hello, world!\n" );
    }

private:
    int testFunc1() {
    }
    virtual void testFunc2() {
    }
    void testFunc3() {
    }

};

C# code:
class MyClass C# can be also public or internal or file
class MyClass {
    public static void testFunc4() {
        Console.WriteLine( "Hello, world!\n" );
    }

    protected int testFunc1() {
    }

    file abstract void testFunc2() {
    }

    protected internal void testFunc3() {
    }

}

Java code:
class MyClass Java can be also public or abstract or final
class MyClass {
    void testFunc3() {
    }

    public static void testFunc4() {
        System.out.println( "Hello, world!\n" );
    }

    protected int testFunc1() {
    }

    final void testFunc2() {
    }

}
```
