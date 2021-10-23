#include "todo.h"

Todo::Todo()
{

}

Todo::~Todo(){
    delete lienInteraction ;
}

void Todo::setContenu(const std::string &s)
{
    this->contenu = s ;
}

void Todo::setLienInteraction(const Interaction *inter){
       this->lienInteraction->setDate(inter->getDate());
    this->lienInteraction->setContenu(inter->getContenu()) ;
}

std::string Todo::getContenu() const{
    return this->contenu ;
}

Interaction Todo::getLienInteraction() const{
    return *this->lienInteraction ;
}

tm Todo::getDate() const{
    return date ;
}


