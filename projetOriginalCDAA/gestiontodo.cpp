#include "gestiontodo.h"

GestionTodo::GestionTodo()
{

}

//GETTER & SETTER LIST TODO
/**
 * @brief Contact::getListTodo
 * @return
 */
list<Todo> GestionTodo::getListTodo() const {
    return listTodo ;
}

/**
 * @brief Contact::setListTodo
 * @param t
 */
void GestionTodo::setListTodo(const list<Todo> &t) {
    listTodo = t ;
}

//AFFICHAGE
/** Affichage list todo
 * @brief Contact::affiche_list_todo
 */
void GestionTodo::affiche_list_todo() {
    for(auto &v: listTodo){
        cout << "@todo " << v.getContenu() << " @date " ;
        //affiche_date_de_creation(v.getDate()) ;
        cout << endl ;
        // v.getLienInteraction()
    }
}


void GestionTodo::addTodo(const Todo &t){
    listTodo.push_back(t) ;
}

void GestionTodo::removeTodo(const string &t){
    for(auto it = listTodo.begin()  ; it != listTodo.end() ; ++it){
        if((*it).getContenu() == t)
            listTodo.erase(it) ;
    }
}
