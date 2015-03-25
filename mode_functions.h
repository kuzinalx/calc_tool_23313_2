#ifndef MODE_FUNCTIONS_H
#define MODE_FUNCTIONS_H

#include <QTextStream>
#include "expression_calc.h"

double FindRoot( const ExpressionCalc& ec, double x0 );
double FindRoot( const ExpressionCalc& ec, double x1, double x2 );

void Integrate( QTextStream& in, QTextStream& out );
void SolveODE( QTextStream& in, QTextStream& out );
void SolveAlgEqv( QTextStream& in, QTextStream& out );

#endif // MODE_FUNCTIONS_H

