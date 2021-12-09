#ifndef INTERACTION_H
#define INTERACTION_H
#include <iostream>
#include <ctime>
#include <string>
using namespace std ;


/*!
 * \brief The Interaction class
 */

class Interaction
{
private:
    tm * date;
    string contenu ;
public:
    Interaction();
    Interaction(const tm &, const std::string &) ;
    ~Interaction() ;

    /*!
     *  \brief permet d'obtenir la date
     *  \param cette fonction renvoie la date de l'interation
     * @return
     */

    tm getDate() const ;

    /*!
     * \brief permet d'obtenir le contenu
     * \param cette fonction renvoie le contenu dans interaction
     */
    string getContenu() const ;

    /*!
     * \brief permet modifier la date d'interaction
     * \param prend un const tm en argument pour remplacer la valeurde la date
     *
     */

    void setDate(const tm &) ;

    /*!
     * \brief permet modifier le contenu de l'interaction
     * \param prend un std::string en argument pour remplacer la valeur le contenu de l'interaction
     */

    void setContenu(const string &) ;

    friend ostream& operator<<(std::ostream& , const Interaction &) ;
};

#endif // INTERACTION_H
