#include "interaction.h"
/*!
 * \brief Interaction::Interaction qui permet donner l'interaction lors d'une modification du contact ou d'ajout d'un contact
 *
 */
Interaction::Interaction()
{
    time_t n = time(0) ;
    date = new tm() ;
    this->setDate(*localtime(&n)) ;
}

/** Constructeur
 * @brief Interaction::Interaction
 * @param t
 * @param c
 */
Interaction::Interaction(const tm & t, const string &c) {
    if(date != nullptr)
        date = new tm() ;
    this->setDate(t) ;
    this->setContenu(c) ;
}

/** Destructeur
 * @brief Interaction::~Interaction
 */
Interaction::~Interaction(){
    delete date;
}

//GETTER & SETTER DATE
tm Interaction::getDate() const{
    return *date ;
}

void Interaction::setDate(const tm &t){
    *date = t;
}

//GETTER & SETTER CONTENU
string Interaction::getContenu() const{
    return contenu ;
}

void Interaction::setContenu(const string &c){
    contenu = c ;
}

/**
 * @brief operator <<
 * @param os
 * @param i
 * @return
 */
ostream & operator<<(ostream & os, const Interaction & i)
{
    tm * t = new tm(i.getDate()) ;
    char * d = asctime(t) ;

    os << d << " " << i.getContenu();
    delete t ;
    return os ;
}
