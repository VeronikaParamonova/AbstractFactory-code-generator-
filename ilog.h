#ifndef ILOG_H
#define ILOG_H
#include <string>
#include <QObject>



class ILog
{
public:
    //конструктор не определяем, так как класс абстрактный, и м не сможем создать объект этого класса, только указатель на него. Компилятор автоматически сгенерирует конструктор по умолчанию, он будет недоступен для создания объектов
    virtual ~ILog() = default;
    virtual void printLog(const std::string& message) = 0;

};

#endif // ILOG_H
