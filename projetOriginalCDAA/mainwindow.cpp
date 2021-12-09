#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    dbPath = "D:/GitHub/projet_CDAA/projetOriginalCDAA/base.sqlite";
    ui->setupUi(this);

    /*this->resize(500, 250)  ;
    w1 = new QWidget(this) ;
    w1->resize(200, 200) ;
    Flayout = new QFormLayout(w1) ;
    valider = new QPushButton(tr("Valider"), this) ;
    //effacer_contact = new QPushButton(tr("Effacer Contact"), this ) ;
    //ajouter_contact = new QPushButton(tr("Ajouter Contact") , this ) ;
    ajouter_photo = new QPushButton(tr("Ajouter Photo") , this) ;


    nom = new QLabel("Nom" , this) ;
    prenom = new QLabel("Prenom" , this) ;
    entreprise = new QLabel("Entreprise" , this) ;
    mail = new QLabel("Mail" , this);
    Painter = new QPainter(w1) ;
    photo.load("D:/GitHub/projet_CDAA/projetOriginalCDAA/personnage.png") ;
    Painter->drawPixmap(200 , 50 , photo) ;
    lphoto = new QLabel("Ajouter Photo" , this) ;
    interactionlabel = new QLabel("Interaction", this) ;
    lphoto->setGeometry(300 , 50 , 100 , 100 ) ;
    //lInteraction = new QLabel("Interaction" , this) ;
    //ltodo = new QLabel("Todo" , this) ;
    nomEdit = new QLineEdit(this);
    prenomEdit = new QLineEdit(this) ;
    entrepriseEdit = new QLineEdit(this) ;
    mailEdit = new QLineEdit(this)  ;
    interactionEdit = new QLineEdit(this) ;


    //listeInteraction = new QLineEdit(this) ;
    //listTodo = new QLineEdit(this) ;

    Flayout->setWidget(0 , QFormLayout::LabelRole , nom) ;
    Flayout->setWidget(0, QFormLayout::FieldRole , nomEdit) ;
    Flayout->setWidget(1 , QFormLayout::LabelRole , prenom) ;
    Flayout->setWidget(1, QFormLayout::FieldRole ,prenomEdit) ;
    Flayout->setWidget(2 , QFormLayout::LabelRole , entreprise) ;
    Flayout->setWidget(2, QFormLayout::FieldRole , entrepriseEdit) ;
    Flayout->setWidget(3 , QFormLayout::LabelRole , mail) ;
    Flayout->setWidget(3, QFormLayout::FieldRole ,mailEdit) ;
    Flayout->setWidget(4 ,QFormLayout::FieldRole, ajouter_photo) ;
    Flayout->setWidget(5 , QFormLayout::LabelRole , interactionlabel) ;
    Flayout->setWidget(5 , QFormLayout::FieldRole , interactionEdit) ;
    //Flayout->setWidget(6 , QFormLayout::LabelRole , ltodo) ;
    //Flayout->setWidget(6 , QFormLayout::FieldRole , listTodo) ;

    Flayout->setWidget(6 , QFormLayout::FieldRole , valider ) ;

    connect(valider, SIGNAL(clicked()) , this, SLOT(ajouter_BD())) ;
    //connect(valider , SIGNAL(clicked()) , this , SLOT(update_DB())) ;
    connect(valider, SIGNAL(clicked()) , this , SLOT(close())) ;
    connect(ajouter_photo, SIGNAL(clicked()) , this , SLOT(ajouter_UP())) ;
    */

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
    db.close() ;
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
    QString s;
    string sx ;
    for(auto &v:l.getListContact()){
        sx+=v.getNom()+" "+v.getPrenom()+" "+v.getEntreprise()+" "+v.getMail() + " " + v.getUriPhoto() ;
    }
    s = QString::fromStdString(sx) ;
    emit listqstring(s) ;
}

void MainWindow::decision(bool &d){
    dec = d  ;
}

void MainWindow::update_DB(){
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
    db.close() ;
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
    QString sx = ui->ListContacts->currentItem()->text();
    QString id =  QString(sx[0]) ;
    qDebug() << id ;

    ui->ListContacts->takeItem(ui->ListContacts->currentRow()) ;
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

//On ajoute un contact
void MainWindow::on_bAjouter_clicked()
{
    myNewWindow = new FicheContact();
    myNewWindow->show();
}

