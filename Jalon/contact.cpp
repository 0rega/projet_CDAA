#include "contact.h"

Contact::Contact()
{

}

Contact::~Contact(){
    //telephone.clear() ;
    //linteractions.clear() ;
    //delete creation ;
}

string Contact::get_nom() const{
    return nom ;
}
intern
string Contact::get_prenom() const{
    return prenom ;
}

string Contact::get_entreprise() const{
    return entreprise ;
}

string Contact::get_mail() const{
    return mail ;
}

string Contact::get_uriPhone() const{
    return uriPhoto ;
}

list<Interaction> Contact::get_linteractions() const{
    return linteractions ;
}

list<unsigned> Contact::get_telephone() const{
    return telephone ;
}

tm Contact::get_creation() const{
    return *creation ;
}

void Contact::set_nom(const string &n){
    nom = n;
}

void Contact::set_prenom(const string &p) {
    prenom = p ;
}

void Contact::set_mail(const string &m){
    mail = m ;
}

void Contact::set_entreprise(const string &e){
    entreprise = e ;
}

void Contact::set_uriPhoto(const string &ur){
    uriPhoto = ur ;
}

void Contact::set_linteractions(const list<Interaction> &lint){
    linteractions = lint ;
}

void Contact::set_telephone(const list<unsigned int> &t){
    telephone = t ;
}

void Contact::set_creation(const tm &t){
    *creation = t;
}

Contact::Contact(const string &n , const string &p, const string &m , const string &e, const list<unsigned> &tel, const string &ur  , const tm &cr , const list<Interaction> & lint){
    set_nom(n) ;
    set_prenom(p)  ;
    set_entreprise(e) ;
    set_mail(m) ;
    set_telephone(tel) ;
    set_uriPhoto(ur) ;
    set_creation(cr) ;
    set_linteractions(lint) ;
}

void affiche_list_telephone(const list<unsigned> &t){
    for(auto it = t.begin() ; it != t.end() ; it++)
    {
        cout << *it << " " ;
    }
}


void affiche(const Contact &c){
    cout << "Nom : "  << c.get_nom() << endl ;
    cout << "Prenom : " << c.get_prenom() << endl ;
    cout << "Entreprise :" << c.get_entreprise() << endl ;
    cout << "Mail : " << c.get_mail() << endl ;
    cout << "Telephone :" ; affiche_list_telephone(c.get_telephone()) ; cout << endl;
    cout << "Photo : " << c.get_uriPhone() << endl ;
}
