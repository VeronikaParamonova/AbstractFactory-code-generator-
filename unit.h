#ifndef UNIT_H
#define UNIT_H
#include <memory>
#include <vector>
#include <string>
#include <QObject>

class Unit: public QObject
{
    Q_OBJECT
public:
    using Flags = unsigned int; // создание псевдонима для сложного типа
public:
    virtual ~Unit() = default;

    virtual std::string compile( unsigned int level = 0 ) const = 0;
protected:
    virtual std::string generateShift( unsigned int level ) const = 0;
signals:
    void logMessage(const std::string& message); //сигнал для логера

};

#endif // UNIT_H
