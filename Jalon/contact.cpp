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
    cout << it.getContenu() << endl ;
}

void Contact::affiche_date_de_creation(const tm &t){
    cout << t.tm_mday << "/" << t.tm_mon << "/" << t.tm_year << " " << t.tm_hour << " : " << t.tm_min << " : " << t.tm_sec << endl ;
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

void Contact::affiche_list_interaction(){
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


void Contact::affiche_list_telephone(){
    for(auto &v: telephone){
        cout << v << endl ;
    }
}

void Contact::modifierTelephone(const unsigned &tel, const unsigned &telm) {
    for(auto &v: telephone){
        if(v == tel){
            v = telm ;
        }
    }
}

list<Todo> Contact::getListTodo() const {
    return listTodo ;
}

void Contact::setListTodo(const list<Todo> &t) {
    listTodo = t ;
}

void Contact::affiche_list_todo() {
    for(auto &v: listTodo){
        cout << v.getContenu() << endl ;
        affiche_date_de_creation(v.getDate()) ;
        // v.getLienInteraction()
    }
}


void affiche(Contact c){
    cout << "Nom : "  << c.getNom() << endl ;
    cout << "Prenom : " << c.getPrenom() << endl ;
    cout << "Entreprise :" << c.getEntreprise() << endl ;
    cout << "Mail : " << c.getMail() << endl ;
    cout << "Telephone :" ; c.affiche_list_telephone() ; cout << endl;
    cout << "Photo : " << c.getUriPhoto() << endl ;
    cout << "Interaction: " ; c.affiche_list_interaction() ; cout << endl;
    cout << "Date de creation: " ; c.affiche_date_de_creation(c.getDateCreation()); cout << endl ;
    cout << "Todo" ; c.affiche_list_todo() ; cout << endl ; 
}
