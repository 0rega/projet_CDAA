#include "basededonne.h"

Basededonne::Basededonne()
{
    connexionBDD() ;
}

Basededonne::~Basededonne()
{

}
void Basededonne::connexionBDD(){

    db = QSqlDatabase::addDatabase("QSQLITE")  ;
    db.setDatabaseName("base.sqlite")  ;
    QSqlQuery query ;


    if(!db.open()){
        qDebug() << "Pas de Connexion BDD" ;
    }
    else{
        qDebug() << "Connexion BDD ok" ;
        query.prepare("CREATE TABLE IF NOT EXIST Contact (idContact INTEGER NOT NULL PRIMARY KEY , Nom varchar(20) , prenom varchar(20) , entreprise varchar(20) , mail varchar(20), telephone integer , uriPhoto varchar(20), interactions varchar(50) , todo varchar(50)") ;
        if(!query.exec()){
            qDebug() << "Impossible d'executer la requete" ;
        }
        else{
            qDebug() << "Requete Ok !" ;
            qDebug() << "Base de donnée créer" ;

        }
    }
}
