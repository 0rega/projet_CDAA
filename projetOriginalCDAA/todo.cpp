#include "todo.h"
#include <string>
#include <vector>

Todo::Todo()
{

}

Todo::Todo(const string &s){
    string z = "" ;
    string contenutodo = "" ;
    tm date ;
    time_t n = time(0);
    string contenudate = "" ;
    string x ;
    int number ;
    vector<int> v ;
    for(auto it = s.begin() ; it != s.end() ; ++it){
        z+=(*it) ;
        if(z == "@todo"){
            while((*it) != '@' && it != s.end()){
                contenutodo+=(*it);
                it++;
            }
        }
        if((*it) == '@'){
            if(*(it+1) == 'd'){
                it+=5 ;
            }
        }
        if(it == s.end())
            break ;
        contenudate+=(*it) ;
    }

    if(contenudate.empty())
    {
        this->setDate(*localtime(&n)) ;
    }
    for(auto ix = contenudate.begin() ; ix != contenudate.end() ; ix++){
        if((*ix) == '/' || (*ix) == ' ' || (*ix) == ':'){
            //number = std::stoi(x, 0, 10) ;
            v.push_back(number) ;
            x = "" ;
        }
        else{
            x+=(*ix) ;
        }
    }
    for(int i = 0 ; i < v.size(); ++i)
    {
        if(i == 0)
            date.tm_mday = v[i] ;
        if(i == 1)
            date.tm_mon = v[i] ;
        if(i == 2)
            date.tm_year = v[i] ;
    }
    this->setDate(date) ;
    this->setContenu(contenutodo) ;
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

void Todo::setDate(const tm &t){
    date = t ;
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


