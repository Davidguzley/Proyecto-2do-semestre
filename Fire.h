#ifndef FIRE_H
#define FIRE_H

#include"Attack.h"

class Fire : public Attack{
public:
    Fire();
    Fire(string name,int level);
};

Fire::Fire() : Attack("noname","Fuego",0){
}

Fire::Fire(string name,int level) : Attack(name,"Fuego",level){
}

#endif
