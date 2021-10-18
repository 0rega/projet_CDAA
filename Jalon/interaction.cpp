#include "interaction.h"

Interaction::Interaction()
{
    time_t n = time(0) ;
    date = new tm() ;
    this->setDate(*localtime(&n)) ;
}


Interaction::Interaction(const tm & t, const string &c) {
    if(date != nullptr)
        date = new tm() ;
    this->setDate(t) ;
    this->setContenu(c) ;
}

Interaction::~Interaction(){
    delete date;
}

tm Interaction::getDate() const{
    return *date ;
}

string Interaction::get_Contenu() const{
    return contenu ;
}

void Interaction::setDate(const tm &t){
    *date = t;
}

void Interaction::setContenu(const string &c){
    contenu = c ;
}



ostream & operator<<(ostream & os, const Interaction & i)
{
    tm * t = new tm(i.getDate()) ;
    char * d = asctime(t) ;

    os << d << " " << i.get_Contenu();
    delete t ;
    return os ;
}
