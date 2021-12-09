#include "gestioninteraction.h"

GestionInteraction::GestionInteraction()
{

}

//GETTER & SETTER LIST INTERACTION
list<Interaction> GestionInteraction::getListInteractions() const{
    return listInteraction ;
}

void GestionInteraction::setListInteractions(const list<Interaction> &lint){
    listInteraction = lint ;
}

/**
 * @brief GestionInteraction::show_interaction
 * @param it
 */
void GestionInteraction::show_interaction(const Interaction &it) {
    cout <<"date: " <<it.getDate().tm_mday << "/" << it.getDate().tm_mon << "/" << it.getDate().tm_year << " " << it.getDate().tm_hour << ":" << it.getDate().tm_min << ":" << it.getDate().tm_sec << endl ;
    cout << it.getContenu() << endl ;
}

/**
 * @brief GestionInteraction::addInteraction
 * @param inter
 */
void GestionInteraction::addInteraction(const Interaction &inter) {
    listInteraction.push_back(inter) ;
}

/**
 * @brief Contact::removeInteraction
 * @param index
 */
void GestionInteraction::removeInteraction(const unsigned &index) {
    int i = 0 ;
    for(auto it = listInteraction.begin() ; it != listInteraction.end(); it++)
    {
        if((int)index == i)
        {
            listInteraction.erase(it) ;
            break ;
        }
        i++ ;
    }
}

void GestionInteraction::affiche_list_interaction(){
    for(auto it = listInteraction.begin() ; it != listInteraction.end() ; it++){
        show_interaction(*it) ;
        cout << endl ;
    }
}
