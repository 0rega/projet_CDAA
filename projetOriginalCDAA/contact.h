#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>
#include <list>
#include <ctime>
#include "gestioninteraction.h"
#include "gestiontodo.h"


using namespace std;

/*
struct Itodo{
    Interaction *lienInteraction ;
    string contenu ;
    tm *date ;
};
*/
class Contact
{
private:
    string nom ;
    string prenom ;
    string entreprise ;
    string mail ;
    list<unsigned> telephone ;
    string uriPhoto ;

    tm dateCreation ;
    GestionInteraction interactions ;
    GestionTodo todos ;

    string ContenuTodo ;
public:
    Contact();
    Contact(const string & , const string &, const string & , const string &, const list<unsigned> &, const string &  , const tm & , const list<Interaction> & ) ;
    ~Contact() ;

    string getNom() const ;
    string getPrenom() const ;
    string getEntreprise() const ;
    string getMail() const ;
    list<unsigned> getTelephone() const ;
    string getUriPhoto() const ;
    tm getDateCreation() const;

    void setNom(const string &) ;
    void setPrenom(const string &) ;
    void setEntreprise(const string &) ;
    void setMail(const string &) ;
    void setTelephone(const list<unsigned> &) ;
    void setUriPhoto(const string &) ;
    void setDateCreation(const tm &) ;
    GestionInteraction getInteractions();
    GestionTodo getTodos();

    void addTelephone(const unsigned &) ;
    void modifierTelephone(const unsigned &, const unsigned &) ;
    void affiche_list_telephone();

    void affiche_date_de_creation(const tm &);
};


void affiche(Contact) ;

#endif // CONTACT_H
