#ifndef CPLUSMETHODUNIT_H
#define CPLUSMETHODUNIT_H
#include "AbstractMethodUnit.h"
#include <memory>
#include <vector>
#include <stdexcept>
#include <string>


class CPlusMethodUnit : public AbstractMethodUnit
{
public:

    CPlusMethodUnit( const std::string& name, const std::string& returnType, Unit::Flags flags ) : m_name( name ), m_returnType( returnType ), m_flags( flags )
    {
        if ((flags & STATIC) && (flags & VIRTUAL))
        {
            throw std::invalid_argument("method C++ cannot be static AND virtual");
        }
    }
    void add( const std::shared_ptr< Unit >& unit, Flags /* flags */ = 0 ) override
    {
        m_body.push_back( unit );
    }
    std::string compile( unsigned int level = 0 ) const override
    {
        std::string result = generateShift( level );
        if( m_flags & STATIC )
        {
            result += "static ";
        }
        else if( m_flags & VIRTUAL )
        {
            result += "virtual ";
        }
        result += m_returnType + " ";
        result += m_name + "()";
        if( m_flags & CONST ) {
            result += " const";
        }
        result += " {\n";
        for( const auto& b : m_body ) {
            result += b->compile( level + 1 );
        }
        result += generateShift( level ) + "}\n";
        return result;
    }
protected:
    std::string generateShift( unsigned int level ) const override
    {
        static const auto DEFAULT_SHIFT = " ";
        std::string result;
        for( unsigned int i = 0; i < level; ++i )
        {
            result += DEFAULT_SHIFT;
        }
        return result;
    }
private:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector< std::shared_ptr< Unit > > m_body;
};

#endif // CPLUSMETHODUNIT_H
