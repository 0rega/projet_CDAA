#include "contact.h"

Contact::Contact()
{

}

Contact::~Contact(){
    //telephone.clear() ;
    //linteractions.clear() ;
    //delete creation ;
}

string Contact::getNom() const{
    return nom ;
}

string Contact::getPrenom() const{
    return prenom ;
}

string Contact::getEntreprise() const{
    return entreprise ;
}

string Contact::getMail() const{
    return mail ;
}

string Contact::getUriPhoto() const{
    return uriPhoto ;
}

list<Interaction> Contact::getListInteractions() const{
    return listInteractions ;
}

list<unsigned> Contact::getTelephone() const{
    return telephone ;
}

tm Contact::getDateCreation() const{
    return *dateCreation ;
}

void Contact::setNom(const string &n){
    nom = n;
}

void Contact::setPrenom(const string &p) {
    prenom = p ;
}

void Contact::setMail(const string &m){
    mail = m ;
}

void Contact::setEntreprise(const string &e){
    entreprise = e ;
}

void Contact::setUriPhoto(const string &ur){
    uriPhoto = ur ;
}

void Contact::setListInteractions(const list<Interaction> &lint){
    listInteractions = lint ;
}

void Contact::setTelephone(const list<unsigned int> &t){
    telephone = t ;
}

void Contact::setDateCreation(const tm &t){
    *dateCreation = t;
}

void Contact::show_interaction(const Interaction &it) {
    cout <<"date: " <<it.getDate().tm_mday << "/" << it.getDate().tm_mon << "/" << it.getDate().tm_year << " " << it.getDate().tm_hour << ":" << it.getDate().tm_min << ":" << it.getDate().tm_sec << endl ;
    cout << it.get_Contenu() << endl ;
}


void Contact::addInteraction(const Interaction &inter) {
    listInteractions.push_back(inter) ;
}

void Contact::addTelephone(const unsigned &tele) {
    telephone.push_back(tele) ;
}

void Contact::removeInteraction(const unsigned &index) {
    int i = 0 ;
    for(auto it = listInteractions.begin() ; it != listInteractions.end(); it++)
    {
        if((int)index == i)
        {
            listInteractions.erase(it) ;
            break ;
        }
        i++ ;
    }
}

void Contact::show_list_interaction(){
    for(auto it = listInteractions.begin() ; it != listInteractions.end() ; it++){
        show_interaction(*it) ;
        cout << endl ;
    }
}



Contact::Contact(const string &n , const string &p, const string &m , const string &e, const list<unsigned> &tel, const string &ur  , const tm &cr , const list<Interaction> & lint){
    setNom(n) ;
    setPrenom(p)  ;
    setEntreprise(e) ;
    setMail(m) ;
    setTelephone(tel) ;
    setUriPhoto(ur) ;
    setDateCreation(cr) ;
    setListInteractions(lint) ;
}

void affiche_list_telephone(const list<unsigned> &t){
    for(auto &v: t){
        cout << v << endl ;
    }
}


void affiche(const Contact &c){
    cout << "Nom : "  << c.getNom() << endl ;
    cout << "Prenom : " << c.getPrenom() << endl ;
    cout << "Entreprise :" << c.getEntreprise() << endl ;
    cout << "Mail : " << c.getMail() << endl ;
    cout << "Telephone :" ; affiche_list_telephone(c.getTelephone()) ; cout << endl;
    cout << "Photo : " << c.getUriPhoto() << endl ;
}
