#ifndef CPLUSPRINTOPERATORUNIT_H
#define CPLUSPRINTOPERATORUNIT_H
#include "AbstractPrintOperatorUnit.h"
#include <memory>
#include <vector>
#include <string>

class CPlusPrintOperatorUnit : public AbstractPrintOperatorUnit
{
public:
    explicit CPlusPrintOperatorUnit( const std::string& text ) : m_text( text ) { }
    std::string compile( unsigned int level = 0 ) const {
        return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
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
    std::string m_text;
};

#endif // CPLUSPRINTOPERATORUNIT_H
