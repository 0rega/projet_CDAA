#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "contact.h"

#include "menu.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "projetOriginalCDAA_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();
    /*Menu m;

    m.show() ;
    QObject::connect(&m , SIGNAL(signalopencreation(bool&)) , &w , SLOT(char_dec(bool&))) ; // envoie le signal pour transformer le booleen dec , decider si c'est une ajout ou une modification
    QObject::connect(&m , SIGNAL(signalopenupdating(bool&)) , &w, SLOT(char_dec(bool&))) ; // Pareil
    QObject::connect(&m , SIGNAL(signalid(QString&)), &w , SLOT(qstringid(QString&)))  ; //envoie le signal de l'id pour la liaison avec la base de donnée
    QObject::connect(&m, SIGNAL(signalc()) , &w , SLOT(show())) ;
    QObject::connect(&m, SIGNAL(signalm()) , &w , SLOT(show())) ; // à modifier pour un widget de modification
    */QObject::connect(&w , SIGNAL(signalcontact(GestionContact&)) , &w, SLOT(show_in_list(GestionContact&))) ;
    //QObject::connect(&w , SIGNAL(listqstring(QString&)) , &m , SLOT(add_in_list(QString&))) ;
    return a.exec()  ;
}
