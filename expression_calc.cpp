#include "expression_calc.h"

static QString curExpr;

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


