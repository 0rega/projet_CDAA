#include <QCoreApplication>
#include <iostream>
#include <QtSql/QtSql>
#include "contact.h"
#include "gestioncontact.h"
#include "interaction.h"

using namespace std;

//declaration des fonctions
/*Contact nouveau_contact() ;
list<unsigned> modifier_telephone(list<unsigned> i, int index);
list<unsigned> insert_telephone(list<unsigned> i, int nb);
Contact modifier_contact(Contact c, string outils);

Contact nouveau_contact(){
    string nom ; cout << "Entrez le nom : " << endl ; cin >> nom ;
    string prenom ; cout << "Entrez le prenom : " << endl ; cin >> prenom;
    string entreprise ; cout << "Entrez l'entreprise: " << endl ; cin >> entreprise ;
    string mail ; cout << "Entrez le mail : " << endl ; cin >> mail  ;
    string uriPhoto; cout << "Entrez l'uri de la photo" << endl ; cin >> uriPhoto ;
    Contact p;
    list<unsigned> telephone ;
    list<Interaction> interaction ;
    p.set_nom(nom) ;
    p.set_prenom(prenom);
    p.set_entreprise(entreprise) ;
    p.set_mail(mail) ;
    p.set_uriPhoto(uriPhoto) ;
    p.set_telephone(telephone) ;
    p.set_linteractions(interaction);
}
list<unsigned> insert_interaction(int nb){

}

list<unsigned> modifier_telephone(list<unsigned> i, int index){
    int number ;
    cout << "Entrez le numero :"
    cin >> number ;
    i[index] = number ;

    return i;
}

list<unsigned> insert_telephone(list<unsigned> i, int nb){
    int number ;
    while(nb--){cin>> number ; i.push_back(number) ; }
    return i ;
}

Contact modifier_contact(Contact c, string outils){
    string nom ;
    string prenom ;
    string entreprise ;
    string mail ;
    string photo ;
    list<unsigned> telephone = c.get_telephone();
    int index ;
    switch (outils) {
        case "nom" : cout << "Entrez le nom : " << endl ; cin >> nom ; c.set_nom(nom) ; break ;
        case "prenom" : cout << "Entrez le prenom : " << endl ; cin >> prenom ; c.set_prenom(prenom) ; break ;
        case "entreprise: " cout << "Entrez l'entreprise" << endl ; cin >> entreprise ; c.set_prenom(entreprise) ; break ;
        case "mail" : cout << "Entrez le mail" << endl ;  cin >> mail ; c.set_mail(mail) ; break ;
        case "photo": cout << "Entrez l'uri de la photo" << endl ; cin >> photo ; c.set_uriPhoto(mail) ; break  ;
        case "telephone" : cout << "Entrez l'index de modification" << endl ;  cin >> index ; modifier_contact(c.get_telephone(), index)  ; break ;
    }
}*/

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Interaction it ;

    GestionContact gc ;
    Contact c ;
    c.setNom("Doe")  ;
    c.setPrenom("John") ;
    c.setEntreprise("oood") ;
    c.setMail("john.doe@gmail.com") ;
    c.setUriPhoto("blabla") ;
    c.addTelephone(0635203277) ;
    it.setContenu("Modification") ;
    c.addInteraction(it) ;
    c.show_list_interaction() ;


    gc.addContact(c) ;
    afficheListeContacts(gc) ;

    return a.exec();
}
