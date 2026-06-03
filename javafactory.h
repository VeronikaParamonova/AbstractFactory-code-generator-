#ifndef JAVAFACTORY_H
#define JAVAFACTORY_H

#include "AbstractFactory.h"
#include "JavaClassUnit.h"
#include "logtoconsole.h"
#include "JavaMethodUnit.h"
#include "JavaPrintOperatorUnit.h"
#include "ilog.h"

class JavaFactory: public AbstractFactory
{
public:
    JavaFactory(ILog* logger) : m_logger(logger){};

    std::shared_ptr<AbstractClassUnit> createClassUnit(const std::string& name, Unit::Flags flag = 0) override
    {
        auto myclass = std::make_shared<JavaClassUnit>(name, flag);
        QObject::connect(myclass.get(), &Unit::logMessage,&m_logger, &LogToConsole::printLogSlot);

        return myclass;
    }
    std::shared_ptr<AbstractMethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) override
    {
        auto mymethod = std::make_shared<JavaMethodUnit>(name, returnType, flags);
        QObject::connect(mymethod.get(), &Unit::logMessage,&m_logger, &LogToConsole::printLogSlot);

        return mymethod;
    }
    std::shared_ptr<AbstractPrintOperatorUnit> createPrintOperatorUnit(const std::string& text) override
    {
        auto myprintoperator = std::make_shared<JavaPrintOperatorUnit>(text);
        QObject::connect(myprintoperator.get(), &Unit::logMessage,&m_logger, &LogToConsole::printLogSlot);

        return myprintoperator;
    }
private:
    ILog* m_logger;
};
#endif // JAVAFACTORY_H
