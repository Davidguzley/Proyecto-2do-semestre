#ifndef ATTACK_H
#define ATTACK_H

#include <iostream>
#include <string>

using namespace std;

class Attack{
protected:
    string attackName;
    string damageType;
    int levelAttack;
public:
    Attack();
    Attack(string name,string type,int level);
    string getAttackName() const;
    string getDamageType() const;
    int getLevelAtack() const;
};

Attack::Attack(){
    attackName= "noname";
    damageType= "none";
    levelAttack= 0;
}

Attack::Attack(string name,string type,int level){
    attackName= name;
    damageType= type;
    levelAttack= level;
}

string Attack::getAttackName() const{
    return attackName;
}
string Attack::getDamageType() const{
    return damageType;
}

int Attack::getLevelAtack() const{
    return levelAttack;
}

#endif
