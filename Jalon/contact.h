#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>
#include <list>
#include <ctime>
#include "interaction.h"

using namespace std;

struct Itodo{
    Interaction *lienInteraction ;
    string contenu ;
    tm *date ;
};

class Contact
{
private:
    string nom ;
    string prenom ;
    string entreprise ;
    string mail ;
    list<unsigned> telephone ;
    string uriPhoto ;

    tm * dateCreation ;
    list<Interaction> listInteractions ;
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
    list<Interaction> getListInteractions() const ;

    void setNom(const string &) ;
    void setPrenom(const string &) ;
    void setEntreprise(const string &) ;
    void setMail(const string &) ;
    void setTelephone(const list<unsigned> &) ;
    void setUriPhoto(const string &) ;
    void setDateCreation(const tm &) ;
    void setListInteractions(const list<Interaction> &) ;

    void addInteraction(const Interaction& ) ;
    void addTelephone(const unsigned &) ;
    void removeInteraction(const unsigned &) ;
    void show_interaction(const Interaction& ) ;
    void affiche_list_interaction() ;

};

void affiche_list_telephone(const list<unsigned> &);
void affiche(const Contact &) ;

#endif // CONTACT_H
