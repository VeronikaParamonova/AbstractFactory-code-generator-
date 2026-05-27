#ifndef JAVACLASSUNIT_H
#define JAVACLASSUNIT_H

#include "abstractclassunit.h"
#include <memory>
#include <vector>
#include <string>

class JavaClassUnit : public AbstractClassUnit
{
public:

    static const std::vector< std::string > ACCESS_MODIFIERS;

    explicit JavaClassUnit( const std::string& name, Flags flag = PUBLIC) : m_name( name ), m_flag(flag)
    {
        m_fields.resize( ACCESS_MODIFIERS.size() );

        if ((flag & ABSTRACT) && (flag & FINAL))
        {
            throw std::invalid_argument("class Java cannot be abstract AND final");
        }
    }
    void add( const std::shared_ptr< Unit >& unit, Flags flags ) override
    {
        int accessModifier = PRIVATE;
        if( flags < ACCESS_MODIFIERS.size() ) {
            accessModifier = flags;
        }
        m_fields[ accessModifier ].push_back( unit );
    }
    std::string compile( unsigned int level = 0 ) const override
    {
        std::string result = generateShift( level );
        if(m_flag >= 0 && m_flag  < ACCESS_MODIFIERS.size() ) {
            result += ACCESS_MODIFIERS[ m_flag ] + " ";
        }

        result += "class " + m_name + " {\n";
        for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ) {
            if( m_fields[ i ].empty() ) {
                continue;
            }
            for( const auto& f : m_fields[ i ] ) {
                result += generateShift(level + 1) + ACCESS_MODIFIERS[i] + " " + f->compile(level + 1);
            }
            result += "\n";
        }
        result += generateShift( level ) + "}\n";

        return result;
    }
protected:
    std::string generateShift( unsigned int level ) const override
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
    Flags m_flag; //у класса в си шарп тоже есть модификатор доступа

};

#endif // JAVACLASSUNIT_H
