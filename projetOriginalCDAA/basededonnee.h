#ifndef BASEDEDONNEE_H
#define BASEDEDONNEE_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>

#include "gestioncontact.h"
#include "gestioninteraction.h"
#include "gestiontodo.h"
#include <QObject>

class BaseDeDonnee : public QObject
{
    Q_OBJECT
public:
    explicit BaseDeDonnee(QObject *parent = nullptr);

    void connexionBDD() ;
    void insertContact(const Contact &);
    void updateContact(const Contact &);
    void searchContact(const QString &);

public slots:
    void deleteContact(const QString &);
    Contact selectContact(const QString &);

private:
    QSqlDatabase db ;
    QString dbPath;
    GestionContact gc;
    GestionContact gi;
    GestionContact gt;


};

#endif // BASEDEDONNEE_H
