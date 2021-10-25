#include "gestioncontact.h"
#include <QDebug>

GestionContact::GestionContact()
{

}
/*!
 * \brief le destructeur de GestionContact qui supprime tous les contacts se trouvant dans la liste de contact
 * \brief addContact pour ajouter un contact
 * \brief removeContact pour supprimer un contact
 * \brief foundContact pour rechercher un contact selon un email donnée au paramètre et retourne le contact
 * \brief modifierContact pour modifier un contact
 */

/** DESTRUCTEUR
 * @brief GestionContact::~GestionContact
 */
GestionContact::~GestionContact(){
    ListContact.clear() ;
}

/** Ajout d'un contact
 * @brief GestionContact::addContact
 * @param c
 */
void GestionContact::addContact(const Contact &c){
    ListContact.push_back(c) ;
}

/** Suppression d'un contact
 * @brief GestionContact::removeContact
 * @param s
 */
void GestionContact::removeContact(const string &s){
    bool found = false;

    for(auto it = ListContact.begin() ; it != ListContact.end() && found != true; it++)
    {
        if((*it).getMail() == s)
        {
            found = true ;
            ListContact.erase(it) ;
        }
    }
}

//GETTER & SETTER LIST CONTACTS
list<Contact> GestionContact::getListContact() const{
    return ListContact ;
}

void GestionContact::setListContact(const list<Contact> &l) {
    ListContact = l ;
}

/** Trouver un contact
 * @brief GestionContact::foundContact
 * @param s
 * @return
 */
Contact GestionContact::foundContact(const string &s){

    for(auto &v: ListContact){
        if(v.getMail() == s)
            return v;
    }
    cout << "Non Disponible dans contact" << endl ;
}


/** Modification d'un contact
 * @brief GestionContact::modifierContact
 * @param s
 * @param opt
 * @param sm
 */
void GestionContact::modifierContact(const string &s, const string &opt, const string &sm){
    Interaction it;
    time_t n = time(0) ;

    Contact c = foundContact(s);
    removeContact(s);

    unsigned tel, telm ;
    if(opt == "Nom"){
        c.setNom(sm) ;
        it.setContenu("Modification du nom") ;
        it.setDate(*localtime(&n)) ;
        c.addInteraction(it) ;
    }
    if(opt == "Prenom")
    {
        c.setPrenom(sm) ;
        it.setContenu("Modification du prenom") ;
        it.setDate(*localtime(&n)) ;
        c.addInteraction(it);
    }
    if(opt =="Entreprise"){
        c.setEntreprise(sm) ;
        it.setContenu("Modification de l'entreprise") ;
        it.setDate(*localtime(&n)) ;
        c.addInteraction(it) ;
    }
    if(opt == "Photo")
    {
        c.setUriPhoto(sm)  ;
        it.setContenu("Modification de la photo") ;
        it.setDate(*localtime(&n)) ;
        c.addInteraction(it) ;
    }
    if(opt == "Mail")
    {
        c.setMail(sm)  ;
        it.setContenu("Modification du mail") ;
        it.setDate(*localtime(&n)) ;
        c.addInteraction(it) ;
    }
    if(opt == "Telephone")
    {
        cin >> tel >> telm ;
        c.modifierTelephone(tel, telm) ;
        it.setContenu("Modification du telephone") ;
        it.setDate(*localtime(&n)) ;
        c.addInteraction(it) ;
    }
    addContact(c);
}

/** Affichage liste contact
 * @brief GestionContact::afficheListeContacts
 */
void GestionContact::afficheListeContacts(){
    for(auto &v: ListContact){
        affiche(v) ;
        cout << " "  ;
    }
    cout << endl ;
}
