#ifndef BASEDEDONNE_H
#define BASEDEDONNE_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>

class Basededonne
{
public:
    Basededonne();
    ~Basededonne() ;

    void connexionBDD() ;
private:
    QSqlDatabase db ;
};

#endif // BASEDEDONNE_H
