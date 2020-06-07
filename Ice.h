#ifndef ICE_H
#define ICE_H

#include"Attack.h"

class Ice : public Attack{
public:
    Ice();
    Ice(string name,int level);
};

Ice::Ice() : Attack("noname","Hielo",0){
}

Ice::Ice(string name,int level) : Attack(name,"Hielo",level){
}

#endif
