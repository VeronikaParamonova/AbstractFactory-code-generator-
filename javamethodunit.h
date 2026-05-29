#ifndef JAVAMETHODUNIT_H
#define JAVAMETHODUNIT_H

#include "abstractmethodunit.h"
#include <memory>
#include <vector>
#include <stdexcept>
#include <string>
#include <iostream>

class JavaMethodUnit : public AbstractMethodUnit
{
public:

    enum Modifier {
            STATIC   = 1 << 0,
            ABSTRACT = 1 << 1,
            FINAL    = 1 << 2
        };

    JavaMethodUnit( const std::string& name, const std::string& returnType, Unit::Flags flags ) : m_name( name ), m_returnType( returnType ), m_flags( flags )
    {
        if ((flags & STATIC) && (flags & ABSTRACT))
        {
            std::cout<<"method "<< name << " Java cannot be static AND abstract"<<std::endl;
            m_flags = 0;
        }
        if ((flags & ABSTRACT) && (flags & FINAL))
        {
            std::cout<<"method "<< name << " Java cannot be abstract AND final"<<std::endl;
            m_flags = 0;
        }
    }
    void add( const std::shared_ptr< Unit >& unit, Flags /* flags */ = 0 ) override
    {

        m_body.push_back( unit );

    }
    std::string compile( unsigned int level = 0 ) const override
    {
        std::string result;
        if( m_flags & STATIC ) {
            result += "static ";
        }
        if( m_flags & FINAL ) {
            result += "final ";
        }
        if( m_flags & ABSTRACT ) {
            result += "abstract ";
        }

        result += m_returnType + " ";
        result += m_name + "()";

        if (m_flags & ABSTRACT)
        {
            result += ";\n";
        }
        else
        {
        result += " {\n";
        for( const auto& b : m_body ) {
            result += b->compile( level + 1 );
        }
        result += generateShift( level ) + "}\n";
        }
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
    std::string m_returnType;
    Flags m_flags;
    std::vector< std::shared_ptr< Unit > > m_body;
};

#endif // JAVAMETHODUNIT_H
