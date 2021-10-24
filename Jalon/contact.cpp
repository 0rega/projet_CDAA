#include "contact.h"

/** CONSTRUCTEUR
 * @brief Contact::Contact
 * @param n
 * @param p
 * @param m
 * @param e
 * @param tel
 * @param ur
 * @param cr
 * @param lint
 */
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

/** DESTRUCTEUR
 * @brief Contact::~Contact
 */
Contact::~Contact(){
    //telephone.clear() ;
    //linteractions.clear() ;
    //delete creation ;
}

Contact::Contact()
{

}

//GETTER & SETTER NOM
string Contact::getNom() const{
    return nom ;
}

void Contact::setNom(const string &n){
    nom = n;
}

//GETTER & SETTER PRENOM
string Contact::getPrenom() const{
    return prenom ;
}

void Contact::setPrenom(const string &p) {
    prenom = p ;
}

//GETTER & SETTER ENTREPRISE
string Contact::getEntreprise() const{
    return entreprise ;
}

void Contact::setEntreprise(const string &e){
    entreprise = e ;
}

//GETTER & SETTER MAIL
string Contact::getMail() const{
    return mail ;
}

void Contact::setMail(const string &m){
    mail = m ;
}

//GETTER & SETTER PHOTO
string Contact::getUriPhoto() const{
    return uriPhoto ;
}

void Contact::setUriPhoto(const string &ur){
    uriPhoto = ur ;
}

//GETTER & SETTER LIST INTERACTION
list<Interaction> Contact::getListInteractions() const{
    return listInteractions ;
}

void Contact::setListInteractions(const list<Interaction> &lint){
    listInteractions = lint ;
}

//GETTER & SETTER TELEPHONE
list<unsigned> Contact::getTelephone() const{
    return telephone ;
}

void Contact::setTelephone(const list<unsigned int> &t){
    telephone = t ;
}

//GETTER & SETTER DATE CREATION
tm Contact::getDateCreation() const{
    return *dateCreation ;
}

void Contact::setDateCreation(const tm &t){
    *dateCreation = t;
}

/**
 * @brief Contact::show_interaction
 * @param it
 */
void Contact::show_interaction(const Interaction &it) {
    cout <<"date: " <<it.getDate().tm_mday << "/" << it.getDate().tm_mon << "/" << it.getDate().tm_year << " " << it.getDate().tm_hour << ":" << it.getDate().tm_min << ":" << it.getDate().tm_sec << endl ;
    cout << it.getContenu() << endl ;
}

/**
 * @brief Contact::affiche_date_de_creation
 * @param t
 */
void Contact::affiche_date_de_creation(const tm &t){
    cout << t.tm_mday << "/" << t.tm_mon << "/" << t.tm_year << " " << t.tm_hour << " : " << t.tm_min << " : " << t.tm_sec << endl ;
}

/**
 * @brief Contact::addInteraction
 * @param inter
 */
void Contact::addInteraction(const Interaction &inter) {
    listInteractions.push_back(inter) ;
}

/**
 * @brief Contact::removeInteraction
 * @param index
 */
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

/**
 * @brief Contact::addTelephone
 * @param tele
 */
void Contact::addTelephone(const unsigned &tele) {
    telephone.push_back(tele) ;
}

void Contact::affiche_list_interaction(){
    for(auto it = listInteractions.begin() ; it != listInteractions.end() ; it++){
        show_interaction(*it) ;
        cout << endl ;
    }
}

/**
 * @brief Contact::affiche_list_telephone
 */
void Contact::affiche_list_telephone(){
    for(auto &v: telephone){
        cout << v << endl ;
    }
}

/**
 * @brief Contact::modifierTelephone
 * @param tel
 * @param telm
 */
void Contact::modifierTelephone(const unsigned &tel, const unsigned &telm) {
    for(auto &v: telephone){
        if(v == tel){
            v = telm ;
        }
    }
}

//GETTER & SETTER LIST TODO
/**
 * @brief Contact::getListTodo
 * @return
 */
list<Todo> Contact::getListTodo() const {
    return listTodo ;
}

/**
 * @brief Contact::setListTodo
 * @param t
 */
void Contact::setListTodo(const list<Todo> &t) {
    listTodo = t ;
}

//AFFICHAGE
/** Affichage list todo
 * @brief Contact::affiche_list_todo
 */
void Contact::affiche_list_todo() {
    for(auto &v: listTodo){
        cout << v.getContenu() << endl ;
        affiche_date_de_creation(v.getDate()) ;
        // v.getLienInteraction()
    }
}

/** Affichage d'un contact
 * @brief affiche
 * @param c
 */
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
