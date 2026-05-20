#ifndef CSHARPCLASSUNIT_H
#define CSHARPCLASSUNIT_H

#include "abstractclassunit.h"
#include <memory>
#include <vector>
#include <string>

class CSharpClassUnit : public AbstractClassUnit
{
public:
    enum AccessModifier {
        NOT,
        PUBLIC,
        INTERNAL,
        PROTECTED,
        PRIVATE
    };

    static const std::vector< std::string > ACCESS_MODIFIERS;

    explicit CSharpClassUnit( const std::string& name, Flags flag) : m_name( name ), m_flag(flag) {
        m_fields.resize( ACCESS_MODIFIERS.size() );
    }
    void add( const std::shared_ptr< Unit >& unit, Flags flags ) {
        int accessModifier = NOT;
        if( flags < ACCESS_MODIFIERS.size() ) {
            accessModifier = flags;
        }
        m_fields[ accessModifier ].push_back( unit );
    }
    std::string compile( unsigned int level = 0 ) const
    {
        std::string result = generateShift( level ) + ACCESS_MODIFIERS[ m_flag ] + "class " + m_name + " {\n";
        for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ) {
            if( m_fields[ i ].empty() ) {
                continue;
            }
            for( const auto& f : m_fields[ i ] ) {
                result += ACCESS_MODIFIERS[ i ] + " ";
                result += f->compile( level + 1 );
            }
            result += "\n";
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
    using Fields = std::vector< std::shared_ptr< Unit > >;
    std::vector< Fields > m_fields;
    Flags m_flag; //у класса в си шарп тоже может быть модификатор доступа

};

#endif // CSHARPCLASSUNIT_H
