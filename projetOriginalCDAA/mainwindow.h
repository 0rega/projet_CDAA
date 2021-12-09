#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QFormLayout>
#include <QLineEdit>
#include <QWidget>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QLabel>
#include <QPixmap>
#include <QTextEdit>
#include <QLayout>
#include <QRect>
#include <QPainter>
#include <QImage>
#include <QFileDialog>
#include <QDateTimeEdit>
#include <contact.h>
#include <interaction.h>
#include <todo.h>
#include <gestioncontact.h>
#include <QDebug>
#include <sstream>

#include "fichecontact.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void ajouter_BD() ;
    void ajouter_UP() ;
    void update_DB() ;
    void show_in_list(GestionContact &);
    void decision(bool &) ;
    void ls(int&) ;
    void char_dec(bool&) ;
    void qstringid(QString &) ;
signals:
    void signalcontact(GestionContact&) ;
    void listqstring(QString &) ;
    void signalimage(QString &) ;

private slots:
    void on_bRecherche_clicked();

    void on_bModifier_clicked();

    void on_bSupprimer_clicked();

    void on_bAjouter_clicked();

private:
    QWidget *w1 ;
    QPushButton *valider ;
    QPushButton *effacer_contact ;
    QPushButton *ajouter_contact ;
    QPushButton *ajouter_photo ;
    QFormLayout *Flayout ;
    QLabel *nom ;
    QLabel *prenom ;
    QLabel *entreprise ;
    QLabel *mail ;
    QPixmap photo ;
    QLabel *lphoto ;
    QLabel *lInteraction ;
    QLabel *ltodo ;
    QLabel *lAfficheListContact ;
    QLabel *lienphoto ;
    QLabel *interactionlabel ;
    QLineEdit *interactionEdit ;
    QSqlDatabase db ;
    QLineEdit *nomEdit ;
    QLineEdit *prenomEdit ;
    QLineEdit *entrepriseEdit ;
    QLineEdit *mailEdit ;
    QLineEdit *listeInteraction ;
    QLineEdit *listTodo ;
    QLineEdit *zoneUriphotoEdit ;
    QPainter *Painter ;
    QString plocate ;
    bool dec ;
    QString idx ;
    int ligne_selectionner;
    QTextEdit *AfficheListeContact ;
    bool value ;
    QString dbPath;
    FicheContact *myNewWindow;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
