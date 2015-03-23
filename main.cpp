#include <QCoreApplication>
#include <QTextStream>
#include <QFile>
#include <QException>
#include <QTextCodec>
#include "mode_functions.h"
#include "calc_tool_exception.h"
#include <QFileInfo>

QTextStream cout(stdout);



void Error( const QString& report )
{
    throw CalcToolException( report );
}

int main(int argc, char *argv[])
{
#ifdef WIN32
    cout.setCodec( QTextCodec::codecForName( "CP866" ) );
#endif
    try {
        if ( argc < 2 )
        {
            QFileInfo fi( argv[0] );
            cout << QString( "Командная строка для " ) + fi.fileName() << ":" << endl
                 << fi.fileName() + " cmdFileName" + " <outputFileName>" << endl
                 << QString( "cmdFileName --- входной файл с командами" ) << endl
                 << QString( "outputFileName --- выходной файл для записи результатов. Если не указан, результат выводится в stdout" ) << endl;
            return 0;
        };
        QFile fileIn( argv[1] );
        if ( !fileIn.open( QIODevice::ReadOnly ) )
            Error( QString( "Не удалось открыть файл '" ) + argv[1] + "'" );
        QTextStream streamIn( &fileIn );

        QString taskType;
        taskType = streamIn.readLine();

        QFile fileOut;
        QTextStream streamOut, *pStreamOut = &cout;
        if ( argc > 2 )
        {
            fileOut.setFileName( argv[2] );
            if ( !fileOut.open( QIODevice::WriteOnly ) )
                Error( QString( "Не удалось открыть выходной файл '" ) + argv[2] + "'" );
            streamOut.setDevice( &fileOut );
            pStreamOut = &streamOut;
        };
        if ( taskType == "itg" )
            Integrate( streamIn, *pStreamOut );
        else if ( taskType == "ode" )
            SolveODE( streamIn, *pStreamOut );
        else if ( taskType == "ale" )
            SolveAlgEqv( streamIn, *pStreamOut );
        else
            Error( "Неизвестный тип задания: '" + taskType + "'" );
    }
    catch ( CalcToolException& ex )
    {
        QString str = QString::fromLocal8Bit( ex.what() );
        cout << QString( "ОШИБКА: " ) << str << endl;
        return 0;
    };

    cout << "Program succeeded." << endl;
    return 0;
}
