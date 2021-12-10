#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    dbPath = "D:/GitHub/projet_CDAA/projetOriginalCDAA/base.sqlite";



    //ui->listContacts->setHorizontalHeader()
    ui->setupUi(this);

    connect(this, SIGNAL(signalDelete(QString&)), db, SLOT(deleteContact(QString&))) ;

}

/*fonction d'ajout dans la BD*/

void extraction_tags(QString s , QString  *dates, QString *contenus){
    string n = s.toStdString() ;
    istringstream ss(n) ;
    string date, contenu ;
    int comptetodo = 0 , comptedate = 0 ;

    do{
        string subs ;
        ss >> subs;
        if(comptetodo){
            contenu = subs ;
            comptetodo = 0 ;
        }
        if(comptedate){
            comptedate = 0 ;
            date = subs ;
        }
        if(subs == "@todo"){
            comptetodo = 1 ;
        }
        if(subs == "@date"){
            comptedate = 1 ;
        }
    }while(ss) ;

    *dates = QString::fromStdString(date) ;
    *contenus = QString::fromStdString(contenu) ;
}


void MainWindow::ajouter_BD(){
    /*
    db = QSqlDatabase::addDatabase("QSQLITE") ;
    qDebug() << "affiche BD" ;
    QSqlQuery query ;
    GestionContact gc ;
    Contact c;
    Interaction inter;
    QString contenuinteraction = interactionEdit->text()  ;
    QString datetodo ;
    QString contenutodo ;
    inter.setContenu(contenuinteraction.toStdString()) ;
    db.setDatabaseName(dbPath) ;
    extraction_tags(contenuinteraction ,&datetodo , &contenutodo) ;
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
           c.getInteractions().addInteraction(inter) ;
           gc.getListContact().push_back(c) ;
           emit signalcontact(gc) ;

           query.prepare("INSERT INTO Contact (Nom, Prenom ,Entreprise, Mail, Photo , Date_de_creation , Interaction , Todo )"
                         "VALUES (?, ?, ?, ?, ?, ? , ?, ?)");
           query.addBindValue(nomEdit->text());
           query.addBindValue(prenomEdit->text());
           query.addBindValue(entrepriseEdit->text());
           query.addBindValue(mailEdit->text());
           query.addBindValue(plocate) ;
           s = to_string(nsx->tm_mday) + "/" + to_string(nsx->tm_mon+1) + "/" + to_string(nsx->tm_year+1900) + " " +to_string(nsx->tm_hour) + ":" + to_string(nsx->tm_min) + ":" + to_string(nsx->tm_sec ) ;
           QString x = QString::fromStdString(s) ;
           query.addBindValue(x);
           query.addBindValue(contenuinteraction) ;
           query.addBindValue(contenutodo) ;
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

           query.prepare("INSERT INTO Interaction (Date, Contenu) VALUES ( ? , ?) ") ;
           string z ;
           z = to_string(inter.getDate().tm_mday) + "/" + to_string(inter.getDate().tm_mon+1) + "/" + to_string(inter.getDate().tm_year+1900) + " " + to_string(inter.getDate().tm_hour) + ":" + to_string(inter.getDate().tm_min) + ":" + to_string(inter.getDate().tm_sec) ;
           QString m = QString::fromStdString(z) ;
           query.addBindValue(m) ;
           query.addBindValue("Creation du compte") ;

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

/*Ajout de la photo*/


void MainWindow::ajouter_UP(){
  qDebug()  << "Ajout de photo" ;

  QString filename = QFileDialog::getOpenFileName(this , tr("Choisir") , "" , tr("Images(*.png *.jpg *.jpeg *.bmp *.gif)")) ;
  if(QString::compare(filename, QString()) != 0){
      QImage image ;
      bool valide = image.load(filename) ;
      if(valide){
          image = image.scaledToWidth(50 , Qt::SmoothTransformation);
          lphoto->setPixmap(QPixmap::fromImage(image)) ;
      }
      else{
          // erreur de la mise en photo ;
      }

  }
    plocate = filename ;
}

void MainWindow::show_in_list(GestionContact &l){
    /*
    QString s;
    string sx ;
    for(auto &v:l.getListContact()){
        sx+=v.getNom()+" "+v.getPrenom()+" "+v.getEntreprise()+" "+v.getMail() + " " + v.getUriPhoto() ;
    }
    s = QString::fromStdString(sx) ;
    emit liststring(s) ;
    */
}

void MainWindow::decision(bool &d){
    dec = d  ;
}

void MainWindow::update_DB(){
    /*db = QSqlDatabase::addDatabase("QSQLITE") ;
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
void MainWindow::ls(int &l){
    ligne_selectionner = l ;
}

void MainWindow::char_dec(bool&b){
    value = b  ;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::qstringid(QString &id) {
    idx = id ;
}

//On recherche un contact
void MainWindow::on_bRecherche_clicked()
{
    //db.searchContact(ui->tbRecherche->text());
}

//On modifie un contact
void MainWindow::on_bModifier_clicked()
{
    /****INIT LES INFOS ---- PREREMPLIR****/

    myNewWindow = new FicheContact();
    myNewWindow->show();
}

//On supprime un contact
void MainWindow::on_bSupprimer_clicked()
{
    QString sx = ui->listContact->currentItem()->text();
    QString id =  QString(sx[0]) ;

    emit this->signalDelete(id);
}

//On ajoute un contact
void MainWindow::on_bAjouter_clicked()
{
    myNewWindow = new FicheContact();
    myNewWindow->show();
}

