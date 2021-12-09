#include "menu.h"

Menu::Menu(QWidget *parent) : QMainWindow(parent) {
    dbPath = "D:/GitHub/projet_CDAA/projetOriginalCDAA/base.sqlite";
    /*
    wx = new QWidget(this);
    this->resize(500, 500);
    wx->resize(500, 500);
    Formlayout = new QFormLayout(wx);
    LV = new QListWidget(this);

    ajouter_contact = new QPushButton("Ajouter Nouveau Contact", this);
    modifier_contact = new QPushButton("Modifier Contact", this);
    supprimer_contact = new QPushButton("Supprimer Contact", this);
    actualiser = new QPushButton("Actualiser", this);
    interaction_button = new QPushButton("Liste d'interaction", this);
    todo_button = new QPushButton("Liste todo", this);
    button_recherche_valider = new QPushButton("Valider", this);
    zoneRecherche = new QLineEdit(this);
    //affichephoto = new QLabel("Label Photo", this);


    Formlayout->setWidget(0, QFormLayout::FieldRole, ajouter_contact);
    Formlayout->setWidget(0, QFormLayout::LabelRole, zoneRecherche);
    Formlayout->setWidget(1, QFormLayout::FieldRole, modifier_contact);
    Formlayout->setWidget(1, QFormLayout::LabelRole, button_recherche_valider);
    Formlayout->setWidget(2, QFormLayout::FieldRole, supprimer_contact);
    Formlayout->setWidget(3, QFormLayout::FieldRole, actualiser);
    //Formlayout->setWidget(4, QFormLayout::LabelRole, affichephoto);
    Formlayout->setWidget(4, QFormLayout::FieldRole, LV);
    Formlayout->setWidget(5, QFormLayout::FieldRole, interaction_button);
    Formlayout->setWidget(6, QFormLayout::FieldRole, todo_button);
    setLayout(Formlayout);
    db = QSqlDatabase::addDatabase("QSQLITE");
    connect(ajouter_contact, SIGNAL(clicked()), this, SLOT(afficher_ajout_contact_interface()));
    connect(modifier_contact, SIGNAL(clicked()), this, SLOT(afficher_modification_contact()));
    connect(supprimer_contact, SIGNAL(clicked()), this, SLOT(supprimer_contacts()));
    connect(actualiser, SIGNAL(clicked()), this, SLOT(show_BD()));
    connect(interaction_button, SIGNAL(clicked()), this, SLOT(affiche_liste_interaction()));
    connect(todo_button, SIGNAL(clicked()), this, SLOT(affiche_liste_todo()));
    connect(button_recherche_valider, SIGNAL(clicked()), this, SLOT(affiche_recherche()));
    */

}

void Menu::show_BD(){
    db = QSqlDatabase::addDatabase("QSQLITE") ;
    QSqlQuery query ;
    db.setDatabaseName(dbPath) ;
    if(!db.open()){
        qDebug() << "Pas de connexion  à la BDD"  ;
    }
    else{
        qDebug() << "Connexion à la BDD OK"  ;
        query.prepare("SELECT * from Contact") ;
        if(!query.exec()){
            qDebug() << "Ca ne marche pas la requete" ;
        }
        else{
            QString s ;
            LV->clear() ;
            while(query.next()){
                s+=query.value(0).toString() + " " + query.value(1).toString() + " " + query.value(2).toString() + " " + query.value(3).toString() + " "
                        + query.value(4).toString() + " " + query.value(5).toString() + " " +
                        query.value(6).toString() + " " + query.value(7).toString() + " " + query.value(8).toString() + "\n";
                LV->addItem(s) ;
                s = "" ;
            }
        }
    }
    db.close() ;
}

void Menu::affiche_recherche(){

    db = QSqlDatabase::addDatabase("QSQLITE") ;
    QSqlQuery query ;
    db.setDatabaseName(dbPath) ;
    if(!db.open()){
        qDebug() << "Pas de connexion  à la BDD"  ;
    }
    else{
        qDebug() << "Connexion à la BDD OK"  ;
        query.prepare("SELECT * from Contact where nom = ?") ;
        query.addBindValue(zoneRecherche->text()) ;
        if(!query.exec()){
            qDebug() << "Ca ne marche pas la requete" ;
        }
        else{
            QString s ;
            LV->clear() ;
            while(query.next()){
                s+=query.value(0).toString() + " " + query.value(1).toString() + " " + query.value(2).toString() + " " + query.value(3).toString() + " "
                   + query.value(4).toString() + " " + query.value(5).toString() + " " +
                   query.value(6).toString() + " " + query.value(7).toString() + " " + query.value(8).toString() + "\n";
                LV->addItem(s) ;
                s = "" ;
            }
        }
    }
    db.close() ;
}

void Menu::supprimer_contacts(){
    QString sx = LV->currentItem()->text() ;
    QString id =  QString(sx[0]) ;
    qDebug() << id ;
    LV->takeItem(LV->currentRow()) ;
    db = QSqlDatabase::addDatabase("QSQLITE") ;
    GestionContact gc ;
    QSqlQuery query ;
    Contact c;
    db.setDatabaseName(dbPath) ;
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

void Menu::afficher_ajout_contact_interface(){
    d = true ;
    emit signalopencreation(d) ;
    emit signalc() ;
}

void Menu::add_in_list(QString &s){
    LV->addItem(s) ;
}

void Menu::affiche_liste_interaction() {
    QString idq = LV->currentItem()->text()  ;
    QString id = QString(idq[0]) ;
    QListWidget *liste_interaction = new QListWidget();
    QMainWindow *w = new QMainWindow();
    QWidget *m = new QWidget(w);
    QFormLayout *layout = new QFormLayout(m);

    w->resize( 500 ,500 ) ;
    m->resize(400 , 400 ) ;

    db = QSqlDatabase::addDatabase("QSQLITE") ;
    QSqlQuery query ;
    db.setDatabaseName(dbPath) ;
    if(!db.open()) {
        qDebug() << "Pas de connexion à la BDD" ;
    }
    else{
        qDebug() << "Connexion à la BDD reussit ! " ;
        query.prepare("SELECT * from Interaction idInteraction = ?") ;
        query.addBindValue(id) ;
        QString s ;
        if(!query.exec()){
            qDebug() << "Impossible d'executer la requete" ;
        }
        else{
            qDebug() << "Requête reussit !" ;
            while(query.next()){
                s += query.value(0).toString() + " " + query.value(1).toString() + " " + query.value(2).toString() + "\n";
                liste_interaction->addItem(s) ;
                s = "" ;
            }

        }

    }
    layout->setWidget(0, QFormLayout::FieldRole, liste_interaction) ;
    w->show() ;
    db.close() ;
}

void Menu::affiche_liste_todo() {
    QString idq = LV->currentItem()->text() ;
    QString id =  QString(idq[0]) ;
    QMainWindow *x = new QMainWindow() ;
    x->resize(400, 400) ;
    x->show() ;
}

void Menu::afficher_modification_contact(){
    QString s = LV->currentItem()->text() ;
    d = false ;
    QString id =  QString(s[0]) ;
    emit signalid(id) ;
    emit signalopenupdating(d) ;
    emit signalm() ;
}

