#ifndef CALC_TOOL_EXCEPTION
#define CALC_TOOL_EXCEPTION

#include <QException>

class CalcToolException : public QException
{
    QByteArray m_data;
public:
    CalcToolException( const QString& str )
    {
        m_data = str.toLocal8Bit();//str.toUtf8();
    }
    void raise() const { throw *this; }
    CalcToolException *clone() const { return new CalcToolException(*this); }
    virtual ~CalcToolException() _GLIBCXX_USE_NOEXCEPT {  }
    virtual const char* what() const _GLIBCXX_USE_NOEXCEPT
    {
        return m_data.data();
    }
};

#endif // CALC_TOOL_EXCEPTION

