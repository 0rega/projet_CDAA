#ifndef FICHECONTACT_H
#define FICHECONTACT_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtDebug>

namespace Ui {
class FicheContact;
}

class FicheContact : public QMainWindow
{
    Q_OBJECT

public:
    explicit FicheContact(QWidget *parent = nullptr);
    ~FicheContact();

private slots:
    void on_bValidate_clicked();

    void on_bCanceled_clicked();

private:
    Ui::FicheContact *ui;
    QString dbPath;
};

#endif // FICHECONTACT_H
