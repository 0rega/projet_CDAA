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
     *  \brief This function does something
     *  \param parameter - integer to do something with
     * @return
     */

    tm getDate() const ;
    string get_Contenu() const ;

    void setDate(const tm &) ;
    void setContenu(const string &) ;

    friend ostream& operator<<(std::ostream& , const Interaction &) ;
};

#endif // INTERACTION_H
