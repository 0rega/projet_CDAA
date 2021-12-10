#include "fichecontact.h"
#include "contact.h"
#include "ui_fichecontact.h"

FicheContact::FicheContact(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::FicheContact)
{
    ui->setupUi(this);
    dbPath = "D:/GitHub/projet_CDAA/projetOriginalCDAA/base.sqlite";
}

FicheContact::~FicheContact()
{
    delete ui;
}

void FicheContact::on_bValidate_clicked()
{


}


void FicheContact::on_bCanceled_clicked()
{
    close();
}

