#include <iostream>
#include "contact.h"
#include "gestioncontact.h"
#include "interaction.h"

using namespace std;



int main(int argc, char *argv[])
{

    Interaction it ;
    time_t n = time(0) ; 
    Todo t ;
    tm date ;

    GestionContact gc ;
    Contact c ;
    Contact c2 ;
    c.setNom("Doe")  ;
    c.setPrenom("John") ;
    c.setEntreprise("oood") ;
    c.setMail("john.doe@gmail.com") ;
    c.setUriPhoto("blabla") ;
    c.addTelephone(0635203277) ; 
    c.setDateCreation(*localtime(&n)) ; 
    it.setContenu("Modification du contenu") ;
    t.setContenu("Rappeler") ;
    c.addInteraction(it) ;
    //c.affiche_list_interaction() ;

    c2.setNom("Phil") ;
    c2.setPrenom("John") ;
    c2.setMail("get@mail.fr") ;
    c2.setEntreprise("Odd") ;
    c2.setUriPhoto("blabla");
    c2.setDateCreation(*localtime(&n)) ; 
    c2.addTelephone(2934952)  ;
    c2.addInteraction(it) ;
    //c2.affiche_list_interaction() ;


    gc.addContact(c) ;
    gc.addContact(c2);
    gc.modifierContact(c.getMail() , "Prenom"  ,"Alvine");
    gc.removeContact(c2.getNom()) ;
    gc.afficheListeContacts();

    return 0 ; 
}
