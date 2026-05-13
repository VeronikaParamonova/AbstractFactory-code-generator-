#ifndef UNIT_H
#define UNIT_H
#include <memory>
#include <vector>
#include <string>

class Unit
{
public:
    using Flags = unsigned int;
public:
    virtual ~Unit() = default;

    virtual std::string compile( unsigned int level = 0 ) const = 0;
protected:
    virtual std::string generateShift( unsigned int level ) const = 0;
};

#endif // UNIT_H
