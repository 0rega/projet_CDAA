#ifndef TODO_H
#define TODO_H

#include <iostream>

#include "interaction.h"

class Todo
{
private:
    Interaction *lienInteraction ;
    std::string contenu ;
    tm date ;

public:
    Todo();
    Todo(const Interaction *, const std::string & , const tm & ) ;
    Todo(const string &)  ;
    ~Todo() ;

    void setLienInteraction(const Interaction * ) ;
    void setContenu(const std::string &) ;
    void setDate(const tm &)  ;

    Interaction getLienInteraction() const ;
    std::string getContenu() const ;
    tm getDate() const ;

};

#endif // TODO_H
