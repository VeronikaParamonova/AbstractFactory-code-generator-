#ifndef CSHARPMETHODUNIT_H
#define CSHARPMETHODUNIT_H

#include "abstractmethodunit.h"
#include <memory>
#include <vector>
#include <stdexcept>
#include <string>

class CSharpMethodUnit : public AbstractMethodUnit
{
public:
    enum Modifier {
        STATIC   = 1 << 0,
        VIRTUAL    = 1 << 1,
        ABSTRACT  = 1 << 2,
        SEALED = 1 << 3,

    };

    CSharpMethodUnit( const std::string& name, const std::string& returnType, Unit::Flags flags ) : m_name( name ), m_returnType( returnType ), m_flags( flags )
    {
        if ((flags & STATIC) && (flags & VIRTUAL))
        {
            //std::cout<<"method "<< name << " C# cannot be static AND virtual"<<std::endl;
            std::string message = "method " + name + " C# cannot be static AND virtual";
            emit logMessage(message);
            m_flags = 0;
        }
        if ((flags & ABSTRACT) && (flags & VIRTUAL))
        {
            //std::cout<<"method "<< name << " C# cannot be abstract AND virtual"<<std::endl;
            std::string message = "method " + name + " C# cannot be abstract AND virtual";
            emit logMessage(message);
            m_flags = 0;
        }
        if ((flags & ABSTRACT) && (flags & SEALED))
        {
            //std::cout<<"method "<< name << " C# cannot be abstract AND sealed"<<std::endl;
            std::string message = "method " + name + " C# cannot be abstract AND sealed";
            emit logMessage(message);
            m_flags = 0;
        }
        if ((flags & ABSTRACT) && (flags & STATIC))
        {
            //std::cout<<"method "<< name << " C# cannot be abstract AND static"<<std::endl;
            std::string message = "method " + name + " C# cannot be abstract AND static";
            emit logMessage(message);
            m_flags = 0;
        }

    }
    void add( const std::shared_ptr< Unit >& unit, Flags /* flags */ = 0 ) override
    {   
        m_body.push_back( unit );
    }
    std::string compile( unsigned int level = 0 ) const override
    {
        std::string result ;
        if( m_flags & STATIC )
        {
            result += "static ";
        }
        if( m_flags & VIRTUAL )
        {
            result += "virtual ";
        }
        if( m_flags & ABSTRACT )
        {
            result += "abstract ";
        }
        if( m_flags & SEALED )
        {
            result += "sealed ";
        }
        result += m_returnType + " ";
        result += m_name + "()";

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

#endif // CSHARPMETHODUNIT_H
