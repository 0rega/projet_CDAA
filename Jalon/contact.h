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

    tm * creation ;
    list<Interaction> linteractions ;
public:
    Contact();
    Contact(const string & , const string &, const string & , const string &, const list<unsigned> &, const string &  , const tm & , const list<Interaction> & ) ;
    ~Contact() ;

    string get_nom() const ;
    string get_prenom() const ;
    string get_entreprise() const ;
    string get_mail() const ;
    list<unsigned> get_telephone() const ;
    string get_uriPhone() const ;
    tm get_creation() const;
    list<Interaction> get_linteractions() const ;

    void set_nom(const string &) ;
    void set_prenom(const string &) ;
    void set_entreprise(const string &) ;
    void set_mail(const string &) ;
    void set_telephone(const list<unsigned> &) ;
    void set_uriPhoto(const string &) ;
    void set_creation(const tm &) ;
    void set_linteractions(const list<Interaction> &) ;

    void addInteraction(const Interaction& ) ;
    void addTelephone(const unsigned &) ;
    void removeInteraction(const unsigned &) ;
    void show_interaction(const Interaction& ) ;
    void show_list_interaction() ;

};

void affiche_list_telephone(const list<unsigned> &);
void affiche(const Contact &) ;

#endif // CONTACT_H
