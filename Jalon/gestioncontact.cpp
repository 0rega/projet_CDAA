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
        if((*it).get_nom() == s)
        {
            found = true ;
            ListContact.erase(it) ;
        }
    }
}

list<Contact> GestionContact::get_ListContact() const{
    return ListContact ;
}

void GestionContact::set_ListContact(const list<Contact> &l) {
    ListContact = l ;
}

Contact GestionContact::found_contact(const string &s){
    for(auto it = ListContact.begin() ; it != ListContact.end() ; it++){
        if((*it).get_nom() == s)
            return (*it) ;
    }
    cout << "Non Disponible dans contact" << endl ;
}

void GestionContact::modifierContact(const string &s, const char &c , const string &sm){
    switch(c){
        case 'n': found_contact(s).set_nom(sm) ; break ;
    case 'p': found_contact(s).set_prenom(sm) ; break ;
    case 'm': found_contact(s).set_mail(sm) ; break ;
    case 'e': found_contact(s).set_entreprise(sm) ; break ;
    case 'u': found_contact(s).set_uriPhoto(sm) ; break ;
    default : cout << "option non disponible" ; break ;
    }
}


void affiche_gestion(const GestionContact &gp){
    for(auto &v: gp.get_ListContact()){
        affiche(v) ;
        cout << endl ;
    }
}
