#ifndef WATER_H
#define WATER_H

#include"Attack.h"

class Water : public Attack{
public:
    Water();
    Water(string name,int level);
};

Water::Water() : Attack("noname","Agua",0){
}

Water::Water(string name,int level) : Attack(name,"Agua",level){
}

#endif
