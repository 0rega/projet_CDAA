#include "basededonnee.h"

BaseDeDonnee::BaseDeDonnee(QObject *parent) : QObject(parent)
{

}

void BaseDeDonnee::connexionBDD(){

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

void BaseDeDonnee::insertContact(const Contact &c)
{
    /*
    db = QSqlDatabase::addDatabase("QSQLITE") ;
    QSqlQuery query ;
    db.setDatabaseName(dbPath) ;

    if(!db.open()){
            qDebug() << "Pas de connexion  à la BDD"  ;
        }
        else{

               if(!query.exec()){

               }
               else{


               }



               if(!query.exec())
               {
                   qDebug() << "Requête Interaction impossible" ;
               }
               else{
                   qDebug() << "Requête Interaction reussit ! ";
               }
            }
        db.close() ;*/
}

void BaseDeDonnee::updateContact(const Contact &)
{
    /*
    db = QSqlDatabase::addDatabase("QSQLITE") ;
    QSqlQuery query ;
    GestionContact gc ;
    Contact c;
    Interaction inter ;
    inter.setContenu("Modification du compte ") ;
    db.setDatabaseName(dbPath) ;
    if(!db.open()){
        qDebug() << "Pas de connexion  à la BDD"  ;
    }
    else{

           qDebug() <<"Connexion BDD ok ! " ;
           string s ;

           time_t timestamp = time( NULL );
           struct tm * nsx = localtime( & timestamp );
           inter.setDate(*nsx) ;
           c.setNom(nomEdit->text().toStdString()) ;
           c.setPrenom(prenomEdit->text().toStdString()) ;
           c.setEntreprise(entrepriseEdit->text().toStdString()) ;
           c.setUriPhoto(plocate.toStdString()) ;
           c.setMail(mailEdit->text().toStdString()) ;
           c.getInteractions().addInteraction(inter);
           gc.getListContact().push_back(c) ;
           emit signalcontact(gc) ;

           query.prepare("UPDATE Contact SET Nom = ? , Prenom = ? , Entreprise = ? , Mail = ? , Photo = ? , Date_de_creation = ? , Interaction = ? , Todo = ? WHERE idContact = ?");
           query.addBindValue(nomEdit->text());
           query.addBindValue(prenomEdit->text());
           query.addBindValue(entrepriseEdit->text());
           query.addBindValue(mailEdit->text());
           query.addBindValue(plocate);
           s = to_string(nsx->tm_mday) + "/" + to_string(nsx->tm_mon+1) + "/" + to_string(nsx->tm_year+1900) + " " +to_string(nsx->tm_hour) + ":" + to_string(nsx->tm_min) + ":" + to_string(nsx->tm_sec ) ;
           QString x = QString::fromStdString(s) ;
           query.addBindValue(x);
           query.addBindValue("Modification du compte") ;
           query.addBindValue(listTodo->text()) ;
           query.addBindValue(idx);
           if(!query.exec()){
               qDebug() << "Impossible d'executer la requête" ;
               nomEdit->clear() ;
               prenomEdit->clear() ;
               entrepriseEdit->clear() ;
               mailEdit->clear() ;
           }
           else{
               qDebug() << "Requete OK" ;
               qDebug() << "Ajout reussit" ;

               nomEdit->clear() ;
               prenomEdit->clear() ;
               entrepriseEdit->clear() ;
               mailEdit->clear() ;
           }
        }
    db.close() ;*/
}

void BaseDeDonnee::deleteContact(const QString &id)
{
    qDebug() << id ;

    db = QSqlDatabase::addDatabase("QSQLITE") ;
    db.setDatabaseName(dbPath) ;

    QSqlQuery query ;


    if(!db.open()){
        qDebug() << "Pas de connexion  à la BDD" ;
    }
    else {
        qDebug() << "Connexion à la BDD";
        query.prepare("delete from Contact where idContact = ?");
        query.addBindValue(id);
        if (!query.exec()) {
            qDebug() << "La requete ne s'execute pas sur la base de donnée :(";
        } else {
            qDebug() << "Requete reussit dans la base de donnée";
        }
    }
    db.close() ;

}

Contact BaseDeDonnee::selectContact(const QString &id)
{
    qDebug() << id ;

    db = QSqlDatabase::addDatabase("QSQLITE") ;
    db.setDatabaseName(dbPath) ;
    Contact c ;
    QSqlQuery query ;


    if(!db.open()){
        qDebug() << "Pas de connexion  à la BDD" ;
    }
    else {
        qDebug() << "Connexion à la BDD";
        query.prepare("Select * from Contact where idContact = ?");
        query.addBindValue(id);
        if(!query.exec()){
            qDebug() << "Ca ne marche pas la requete" ;
        }
        else{

            while(query.next()){

                c.setNom(query.value(1).toString().toStdString());
                c.setPrenom(query.value(2).toString().toStdString());
                c.setPrenom(query.value(3).toString().toStdString());
                c.setPrenom(query.value(4).toString().toStdString());
                c.setPrenom(query.value(5).toString().toStdString());
                c.setPrenom(query.value(6).toString().toStdString());
            }
        }
    }
    db.close() ;
    return c;
}

void BaseDeDonnee::searchContact(const QString &c)
{
    /*db = QSqlDatabase::addDatabase("QSQLITE") ;
    QSqlQuery query ;
    db.setDatabaseName(dbPath) ;
    if(!db.open()){
        qDebug() << "Pas de connexion  à la BDD"  ;
    }
    else{
        qDebug() << "Connexion à la BDD OK"  ;
        query.prepare("SELECT * from Contact where nom = ?") ;
        query.addBindValue(c) ;
        if(!query.exec()){
            qDebug() << "La requete ne marche pas" ;
        }
        else{
            QString s ;
            ui->ListContacts->clear() ;
            while(query.next()){
                s+=query.value(0).toString() + " " + query.value(1).toString() + " " + query.value(2).toString() + " " + query.value(3).toString() + " "
                   + query.value(4).toString() + " " + query.value(5).toString() + " " +
                   query.value(6).toString() + " " + query.value(7).toString() + " " + query.value(8).toString() + "\n";
                ui->ListContacts->addItem(s) ;
                s = "" ;
            }
        }
    }
    db.close() ;*/
}
