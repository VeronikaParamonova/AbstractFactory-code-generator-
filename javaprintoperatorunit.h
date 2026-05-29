#ifndef JAVAPRINTOPERATORUNIT_H
#define JAVAPRINTOPERATORUNIT_H

#include "abstractprintoperatorunit.h"

class JavaPrintOperatorUnit : public AbstractPrintOperatorUnit
{
public:
    explicit JavaPrintOperatorUnit( const std::string& text ) : m_text( text ) { }
    std::string compile( unsigned int level = 0 ) const override
    {
        return generateShift( level ) + "System.out.println( \"" + m_text + "\" );\n";
    }
protected:
    std::string generateShift( unsigned int level ) const override
    {
        static const auto DEFAULT_SHIFT = "    ";
        std::string result;
        for( unsigned int i = 0; i < level; ++i )
        {
            result += DEFAULT_SHIFT;
        }
        return result;
    }
private:
    std::string m_text;
};

#endif // JAVAPRINTOPERATORUNIT_H
