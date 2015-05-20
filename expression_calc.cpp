#include "expression_calc.h"
#include <cmath>

// описана в main
void Error( const QString& report );

/*static QString curExpr;

void SetExpression( const QString& str )
{
    curExpr = str;
}

QString GetExpression()
{
    return curExpr;
}

double EvalExpression( const QVector< QString >& vars, const QVector< double >& vals )
{
    return 0;
}
*/

ExpressionCalc::ExpressionCalc( const QString& str )
{
    m_opPriority.resize( 255 );
    for ( int i = 0; i < m_opPriority.size(); i++ )
        m_opPriority[i] = 0;
    m_opPriority['+'] = m_opPriority['-'] = 1;
    m_opPriority['*'] = m_opPriority['/'] = 2;
    m_opPriority['^'] = 3;
    SetExpression( str );
}

void ExpressionCalc::SetExpression( const QString& str )
{
    m_expr = str;
}

QString ExpressionCalc::GetExpression() const
{
    return m_expr;
}

double ExpressionCalc::Calculate( const QVector< QString >& vars, const QVector< double >& vals )
{
    m_stack.clear();
    m_stackOp.clear();
    m_pos = 0;
    m_vals = vals;
    m_vars = vars;
    while (true)
    {
        double a = ReadOperand();
        m_stack.push( a );
        char op = ReadOperation();
        if ( op == 0 || ( !m_stackOp.empty() && m_opPriority[op] <= m_opPriority[m_stackOp.top()] ) )
            Unwind();
        if ( op == 0 )
            break;
        m_stackOp.push( op );
    };
    return m_stack.top();
}

double ExpressionCalc::ReadOperand()
{
    // TODO
    // трактует часть строки m_expr, начиная с позиции m_pos, как операнд.
    // операндами могут быть
    // вещественное число
    // символьный параметр
    // выражение в скобках
    // перед каждым из таких операндов может стоять унарный минус!

    // после выполнения функции m_pos должен указывать на символ строки m_expr,
    // следующий непосредственно за операндом

    // В исходном выражении m_expr могут стоять пробелы! их необходимо пропускать.
    return 0;
}

char   ExpressionCalc::ReadOperation()
{
    // TODO
    // трактует символ m_expr[m_pos], как операцию. Если это известная операция, то для нее определен
    // приоритет и соответствующий элемент m_opPriority не 0. Если соответствующий элемент m_opPriority равен 0,
    // то следует вызвать функцию Error  с сообщением, мол, неизвестный тип операции.

    // В исходном выражении m_expr могут стоять пробелы! их необходимо пропускать.

    // после выполнения функции m_pos должен указывать на символ строки m_expr,
    // следующий непосредственно за оператором
    return '+';
}

void ExpressionCalc::Unwind()
{
    // "раскрутка" стека операций
    while ( !m_stackOp.empty() )
    {
        double b = m_stack.pop();
        double a = m_stack.pop();
        char op = m_stackOp.pop();
        switch ( op )
        {
        case '+':
            a = a + b;
            break;
        case '-':
            a = a - b;
            break;
        case '*':
            a = a*b; break;
        case '/':
            a = a/b; break;
        case '^':
            a = pow( a, b ); break;
        default:
            Error( QString( "Неизвестная операция '" ) + op + "'" );
        };
        m_stack.push( a );
    };
}
