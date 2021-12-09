#ifndef GESTIONTODO_H
#define GESTIONTODO_H

#include "todo.h"
#include <list>
#include <iostream>


class GestionTodo
{
private:
     list<Todo> listTodo ;
public:
    GestionTodo();
    void addTodo(const Todo &) ;
    void setListTodo(const list<Todo> &) ;
    list<Todo> getListTodo() const ;
    void removeTodo(const string &) ;
    void affiche_list_todo() ;
};

#endif // GESTIONTODO_H
