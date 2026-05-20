#ifndef CPLUSMETHODUNIT_H
#define CPLUSMETHODUNIT_H
#include "AbstractMethodUnit.h"
#include <memory>
#include <vector>
#include <string>


class CPlusMethodUnit : public AbstractMethodUnit
{
public:
    enum Modifier {
                STATIC = 1,
                CONST = 1 << 1,
                VIRTUAL = 1 << 2
            };
    CPlusMethodUnit( const std::string& name, const std::string& returnType, Unit::Flags flags ) : m_name( name ), m_returnType( returnType ), m_flags( flags ) { }
    void add( const std::shared_ptr< Unit >& unit, Flags /* flags */ = 0 )
    {
        m_body.push_back( unit );
    }
    std::string compile( unsigned int level = 0 ) const {
        std::string result = generateShift( level );
        if( m_flags & STATIC ) {
            result += "static ";
        } else if( m_flags & VIRTUAL ) {
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
    std::string generateShift( unsigned int level ) const
    {
        static const auto DEFAULT_SHIFT = " ";
        std::string result;
        for( unsigned int i = 0; i < level; ++i ) {
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
