#ifndef CPLUSFACTORY_H
#define CPLUSFACTORY_H
#include "AbstractFactory.h"
#include "CPlusClassUnit.h"
#include "CPlusMethodUnit.h"
#include "logtoconsole.h"
#include "CPlusPrintOperatorUnit.h"
#include "ilog.h"

class CPlusFactory: public AbstractFactory
{
public:
    CPlusFactory(ILog* logger) : m_logger(logger){};

    std::shared_ptr<AbstractClassUnit> createClassUnit(const std::string& name, Unit::Flags = 0) override
    {
        auto myclass = std::make_shared<CPlusClassUnit>(name);
        QObject::connect(myclass.get(), &Unit::logMessage,&m_logger, &LogToConsole::printLogSlot);

        return myclass;

    }
    std::shared_ptr<AbstractMethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) override
    {
        auto mymethod = std::make_shared<CPlusMethodUnit>(name, returnType, flags);
        QObject::connect(mymethod.get(), &Unit::logMessage,&m_logger, &LogToConsole::printLogSlot);

        return mymethod;
    }
    std::shared_ptr<AbstractPrintOperatorUnit> createPrintOperatorUnit(const std::string& text) override
    {
        auto myprintoperator =std::make_shared<CPlusPrintOperatorUnit>(text);
        QObject::connect(myprintoperator.get(), &Unit::logMessage,&m_logger, &LogToConsole::printLogSlot);

        return myprintoperator;
    }
private:
    ILog* m_logger;
};

#endif // CPLUSFACTORY_H
