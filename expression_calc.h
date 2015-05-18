#ifndef EXPRESSION_CALC
#define EXPRESSION_CALC

#include <QVector>
#include <QString>
#include <QStack>

/*void SetExpression( const QString& str );
QString GetExpression();
double EvalExpression( const QVector< QString >& vars, const QVector< double >& vals );
*/

class ExpressionCalc
{
    QStack<double> m_stack;
    QStack<char>   m_stackOp;
    QString        m_expr;
    int            m_pos;
    QVector<int>   m_opPriority;
    mutable QVector< QString > m_vars;
    mutable QVector< double >  m_vals;
    double ReadOperand();
    char   ReadOperation();
    void Unwind();

public:
    ExpressionCalc( const QString& str = "" );
    void SetExpression( const QString& str );
    QString GetExpression() const;
    double Calculate( const QVector< QString >& vars, const QVector< double >& vals );
};


#endif // EXPRESSION_CALC

