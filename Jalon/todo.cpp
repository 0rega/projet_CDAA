#include "todo.h"

Todo::Todo()
{

}

/** DESTRUCTEUR
 * @brief Todo::~Todo
 */
Todo::~Todo(){
    delete lienInteraction ;
}

//GETTER & SETTER CONTENU
std::string Todo::getContenu() const{
    return this->contenu ;
}

void Todo::setContenu(const std::string &s)
{
    this->contenu = s ;
}

//GETTER & SETTER LIEN INTERACTION
Interaction Todo::getLienInteraction() const{
    return *this->lienInteraction ;
}

void Todo::setLienInteraction(const Interaction *inter){
       this->lienInteraction->setDate(inter->getDate());
    this->lienInteraction->setContenu(inter->getContenu()) ;
}

//GETTER DATE
tm Todo::getDate() const{
    return date ;
}


