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

void Contact::show_interaction(const Interaction &it) {
    cout <<"date: " <<it.getDate().tm_mday << "/" << it.getDate().tm_mon << "/" << it.getDate().tm_year << " " << it.getDate().tm_hour << ":" << it.getDate().tm_min << ":" << it.getDate().tm_sec << endl ;
    cout << it.get_Contenu() << endl ;
}


void Contact::addInteraction(const Interaction &inter) {
    linteractions.push_back(inter) ;
}

void Contact::addTelephone(const unsigned &tele) {
    telephone.push_back(tele) ;
}

void Contact::removeInteraction(const unsigned &index) {
    int i = 0 ;
    for(auto it = linteractions.begin() ; it != linteractions.end(); it++)
    {
        if(index == i)
        {
            linteractions.erase(it) ;
            break ;
        }
        i++ ;
    }
}

void Contact::show_list_interaction(){
    for(auto it = linteractions.begin() ; it != linteractions.end() ; it++){
        show_interaction(*it) ;
        cout << endl ;
    }
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
    for(auto &v: t){
        cout << v << endl ;
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
