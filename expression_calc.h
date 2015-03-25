#ifndef EXPRESSION_CALC
#define EXPRESSION_CALC

#include <QVector>
#include <QString>

/*void SetExpression( const QString& str );
QString GetExpression();
double EvalExpression( const QVector< QString >& vars, const QVector< double >& vals );
*/

class ExpressionCalc
{
public:
    ExpressionCalc( const QString& str = "" );
    void SetExpression( const QString& str );
    QString GetExpression() const;
    double Calculate( const QVector< QString >& vars, const QVector< double >& vals );
};


#endif // EXPRESSION_CALC

