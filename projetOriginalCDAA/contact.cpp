#include "contact.h"

/** CONSTRUCTEUR
 * @brief Contact::Contact
 * @param n - nom
 * @param p - prenom
 * @param m - mail
 * @param e - entreprise
 * @param tel - telephone
 * @param ur - chemin photo
 * @param cr - date de creation
 * @param lint - liste d'interaction
 */
Contact::Contact(const string &n , const string &p, const string &m , const string &e, const list<unsigned> &tel, const string &ur  , const tm &cr , const list<Interaction> & lint){
    setNom(n) ;
    setPrenom(p)  ;
    setEntreprise(e) ;
    setMail(m) ;
    setTelephone(tel) ;
    setUriPhoto(ur) ;
    setDateCreation(cr) ;
    interactions.setListInteractions(lint) ;
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


//GETTER & SETTER TELEPHONE
list<unsigned> Contact::getTelephone() const{
    return telephone ;
}

void Contact::setTelephone(const list<unsigned int> &t){
    telephone = t ;
}

//GETTER & SETTER DATE CREATION
tm Contact::getDateCreation() const{
    return dateCreation ;
}

void Contact::setDateCreation(const tm &t){
    dateCreation = t;
}

GestionInteraction Contact::getInteractions()
{
    return interactions;
}

GestionTodo Contact::getTodos()
{
    return todos;
}


/**
 * @brief Contact::affiche_date_de_creation
 * @param t
 */
void Contact::affiche_date_de_creation(const tm &t){
    cout << t.tm_mday << "/" << t.tm_mon << "/" << t.tm_year << " " << t.tm_hour << " : " << t.tm_min << " : " << t.tm_sec << endl ;
}


/**
 * @brief Contact::addTelephone
 * @param tele
 */
void Contact::addTelephone(const unsigned &tele) {
    telephone.push_back(tele) ;
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


//Affichage
/** Affichage d'un contact
 * @brief affiche
 * @param c
 */
void affiche(Contact c){
    cout << endl;
    cout << "Nom : "  << c.getNom() << endl ;
    cout << "Prenom : " << c.getPrenom() << endl ;
    cout << "Entreprise :" << c.getEntreprise() << endl ;
    cout << "Mail : " << c.getMail() << endl ;
    cout << "Telephone :" ; c.affiche_list_telephone() ; cout << endl;
    cout << "Photo : " << c.getUriPhoto() << endl ;
    cout << "Date de creation: " ; c.affiche_date_de_creation(c.getDateCreation()); cout << endl ;
    cout << "Interaction: " ; cout << endl; c.getInteractions().affiche_list_interaction() ; cout << endl;
    cout << "Todo" << endl ; c.getTodos().affiche_list_todo() ; cout << endl ;
}
