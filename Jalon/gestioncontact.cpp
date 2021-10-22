#include "gestioncontact.h"

GestionContact::GestionContact()
{

}


GestionContact::~GestionContact(){
    ListContact.clear() ;
}

void GestionContact::addContact(const Contact &c){
    ListContact.push_back(c) ;
}

void GestionContact::removeContact(const string &s){
    bool found = false;

    for(auto it = ListContact.begin() ; it != ListContact.end() && found != true; it++)
    {
        if((*it).getNom() == s)
        {
            found = true ;
            ListContact.erase(it) ;
        }
    }
}

list<Contact> GestionContact::getListContact() const{
    return ListContact ;
}

void GestionContact::setListContact(const list<Contact> &l) {
    ListContact = l ;
}

Contact GestionContact::foundContact(const string &s){
    Contact res;

    for(auto it = ListContact.begin() ; it != ListContact.end() ; it++){
        if((*it).getNom() == s)
            res = (*it) ;
    }

    return res;

    cout << "Non Disponible dans contact" << endl ;
}



void GestionContact::modifierContact(const string &s, const char &c , const string &sm){
    switch(c){
        case 'n': foundContact(s).setNom(sm) ; break ;
        case 'p': foundContact(s).setPrenom(sm) ; break ;
        case 'm': foundContact(s).setMail(sm) ; break ;
        case 'e': foundContact(s).setEntreprise(sm) ; break ;
        case 'u': foundContact(s).setUriPhoto(sm) ; break ;
        default : cout << "option non disponible" ; break ;
    }
}


void GestionContact::afficheListeContacts(){
    for(auto &v: ListContact){
        affiche(v) ;
        cout << " "  ;
    }
    cout << endl ;
}
