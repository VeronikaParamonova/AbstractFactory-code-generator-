#ifndef JAVACLASSUNIT_H
#define JAVACLASSUNIT_H

#include "abstractclassunit.h"
#include <memory>
#include <vector>
#include <string>
#include <iostream>

class JavaClassUnit : public AbstractClassUnit
{
public:

    enum AccessModifier
    {
                NON = 0,
                PUBLIC = 1,
                PROTECTED = 2,
                PRIVATE = 3,
                FINAL = 4,
                ABSTRACT = 5
            };

    static const std::vector< std::string > ACCESS_MODIFIERS;

    explicit JavaClassUnit( const std::string& name, Flags flag = PUBLIC) : m_name( name ), m_flag(flag)
    {
        m_fields.resize( ACCESS_MODIFIERS.size() );

        int accessModifier;
        if( flag == PUBLIC)
        {
            accessModifier = PUBLIC;
        }
        else if( flag == ABSTRACT)
        {
            int accessModifier = ABSTRACT;
        }
        else if( flag == FINAL)
        {
            int accessModifier = FINAL;
        }
        else if( flag == NON)
        {
            int accessModifier = NON;
        }
        else
        {
            std::cout<<"class "<< name << " Java can be also public or abstract or final"<<std::endl;
            int accessModifier = NON;
        }
        m_flag = accessModifier;
    }
    void add( const std::shared_ptr< Unit >& unit, Flags flags ) override
    {
        int accessModifier = NON;
        if( flags < ACCESS_MODIFIERS.size() ) {
            accessModifier = flags;
        }
        m_fields[ accessModifier ].push_back( unit );
    }
    std::string compile( unsigned int level = 0 ) const override
    {
        std::string result = generateShift( level );
        if( m_flag  < ACCESS_MODIFIERS.size() ) {
            if(m_flag == NON)
            {
                result += ACCESS_MODIFIERS[ m_flag ];
            }
            else
            {
                result += ACCESS_MODIFIERS[ m_flag ] + " ";
            }
        }

        result += "class " + m_name + " {\n";
        for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ) {
            if( m_fields[ i ].empty() ) {
                continue;
            }
            for( const auto& f : m_fields[ i ] )
            {
                if(i == 5 || i == 0 || i == 4)
                {
                    result += generateShift(level + 1) + f->compile(level + 1);
                }
                else
                {
                    result += generateShift(level + 1) + ACCESS_MODIFIERS[i] + " " + f->compile(level + 1);
                }
            }
            result += "\n";
        }
        result += generateShift( level ) + "}\n";

        return result;
    }
protected:
    std::string generateShift( unsigned int level ) const override
    {
        static const auto DEFAULT_SHIFT = "    ";
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
