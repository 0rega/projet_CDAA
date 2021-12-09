#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QPushButton>
#include <mainwindow.h>
#include <QFormLayout>
#include <QListWidget>
#include <QTableWidget>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QLabel>

class Menu : public QMainWindow
{
    Q_OBJECT
public:
    explicit Menu(QWidget *parent = nullptr);
public slots :
   void afficher_ajout_contact_interface() ;
   void afficher_modification_contact() ;
   void add_in_list(QString &) ;
   void show_BD() ;
   void supprimer_contacts() ;
   void affiche_liste_interaction() ;
   void affiche_liste_todo() ;
   void affiche_recherche() ;

signals:
   void signalopencreation(bool &) ;
   void signalopenupdating(bool &) ;
   void signalc() ;
   void signalm() ;
   void signalid(QString &) ;

private:
    QPushButton *ajouter_contact ;
    QPushButton *modifier_contact ;
    QPushButton *actualiser ;
    QPushButton *supprimer_contact ;
    QPushButton *interaction_button ;
    QPushButton *todo_button ;
    QPushButton *button_recherche_valider;
    QListWidget *LV ;
    QLineEdit *zoneRecherche ;
    QWidget *wx  ;
    QFormLayout *Formlayout ;
    QSqlDatabase db;
    bool d ;
    QString dbPath;
    QLabel *affichephoto ;
    QPainter *painter ;
    QPixmap photox ;

signals:

};

#endif // MENU_H
