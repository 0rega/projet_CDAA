#ifndef GESTIONINTERACTION_H
#define GESTIONINTERACTION_H
#include "interaction.h"
#include <list>
#include <iostream>

class GestionInteraction
{
private:
     list<Interaction> listInteraction ;
public:
    GestionInteraction();

    void setListInteractions(const list<Interaction> &) ;
    list<Interaction> getListInteractions() const;

    void addInteraction(const Interaction& ) ;
    void modifierTelephone(const unsigned &, const unsigned &) ;
    void removeInteraction(const unsigned &) ;
    void show_interaction(const Interaction& ) ;
    void affiche_list_interaction() ;
};

#endif // GESTIONINTERACTION_H
