/*----------------------------------
 *
 * Proyecto: Juego Avatar
 * Fecha: 29-Mayo-2020
 * Autor: A01706417 David Guzman Leyva
 *
 *----------------------------------*/

#include "Attack.h"
#include "Fire.h"
#include "Ice.h"
#include "Water.h"
#include "Avatar.h"

int main(int argc, char* argv[]){
    string continuar;
    const int damage= 20;

    //INICIAMOS LOS DOS JUGADORES
    string J1nombre, J2nombre;

    cout<<"JUGADOR 1 "<<endl;
    cout<<"¿Cual es tu nombre joven Avatar? ";
    cin>>J1nombre;
    Avatar a(J1nombre);

    cout<<"JUGADOR 2 "<<endl;
    cout<<"¿Cual es tu nombre joven Avatar? ";
    cin>>J2nombre;
    Avatar b(J2nombre);


    //CADA AVATAR ESCOGE 3 ATAQUES
    //Escoge Jugador 1
    cout<<"JUGADOR 1 "<<endl;
    cout<<"Presiona cualquier letra y da enter para escoger tus elementos"<<endl;
    cin>>continuar;
    int J1high, J1medium, J1low;
    cout<<"Escribe el numero de tu elemento fuerte "<<endl;
    cout<<"1. Fuego"<<endl;
    cout<<"2. Agua"<<endl;
    cout<<"3. Hielo"<<endl;
    cin>>J1high;
    switch(J1high){
    case 1: a.addAttack(new Fire("Tornado de fuego",3));
    break;
    case 2: a.addAttack(new Water("Tsunami",3));
    break;
    case 3: a.addAttack(new Ice("Tormenta de hielo",3));
    break;
    default: cout << "Usted ha ingresado una opción incorrecta";
    }
    cout<<"Escribe el numero de tu elemento medio "<<endl;
    cout<<"1. Fuego"<<endl;
    cout<<"2. Agua"<<endl;
    cout<<"3. Hielo"<<endl;
    cin>>J1medium;
    switch(J1medium){
    case 1: a.addAttack(new Fire("Incinerar",2));
    break;
    case 2: a.addAttack(new Water("Torpedo de agua",2));
    break;
    case 3: a.addAttack(new Ice("Congelar",2));
    break;
    default: cout << "Usted ha ingresado una opción incorrecta";
    }
    cout<<"Escribe el numero de tu elemento debil "<<endl;
    cout<<"1. Fuego"<<endl;
    cout<<"2. Agua"<<endl;
    cout<<"3. Hielo"<<endl;
    cin>>J1low;
    switch(J1low){
    case 1: a.addAttack(new Fire("Bola de fuego",1));
    break;
    case 2: a.addAttack(new Water("Chorro de agua",1));
    break;
    case 3: a.addAttack(new Ice("Bola de nieve",1));
    break;
    default: cout << "Usted ha ingresado una opción incorrecta";
    }
    a.finish();

    //Escoge Jugador 2
    cout<<"JUGADOR 2 "<<endl;
    cout<<"Presiona cualquier letra y da enter para escoger tus elementos"<<endl;
    cin>>continuar;
    int J2high, J2medium, J2low;
    cout<<"Escribe el numero de tu elemento fuerte "<<endl;
    cout<<"1. Fuego"<<endl;
    cout<<"2. Agua"<<endl;
    cout<<"3. Hielo"<<endl;
    cin>>J2high;
    switch(J2high){
    case 1: b.addAttack(new Fire("Tornado de fuego",3));
    break;
    case 2: b.addAttack(new Water("Tsunami",3));
    break;
    case 3: b.addAttack(new Ice("Tormenta de hielo",3));
    break;
    default: cout << "Usted ha ingresado una opción incorrecta";
    }
    cout<<"Escribe el numero de tu elemento medio "<<endl;
    cout<<"1. Fuego"<<endl;
    cout<<"2. Agua"<<endl;
    cout<<"3. Hielo"<<endl;
    cin>>J2medium;
    switch(J2medium){
    case 1: b.addAttack(new Fire("Incinerar",2));
    break;
    case 2: b.addAttack(new Water("Torpedo de agua",2));
    break;
    case 3: b.addAttack(new Ice("Congelar",2));
    break;
    default: cout << "Usted ha ingresado una opción incorrecta";
    }
    cout<<"Escribe el numero de tu elemento debil "<<endl;
    cout<<"1. Fuego"<<endl;
    cout<<"2. Agua"<<endl;
    cout<<"3. Hielo"<<endl;
    cin>>J2low;
    switch(J2low){
    case 1: b.addAttack(new Fire("Bola de fuego",1));
    break;
    case 2: b.addAttack(new Water("Chorro de agua",1));
    break;
    case 3: b.addAttack(new Ice("Bola de nieve",1));
    break;
    default: cout << "Usted ha ingresado una opción incorrecta";
    }
    b.finish();


    //COMENZAMOS LA PELEA
    cout<<"\nINICIA LA BATALLA!!!!"<<endl;
    while(a.status()=="Vivo" && b.status()=="Vivo"){
      //Selecciona ataque Jugador 1
      cout<<"TURNO JUGADOR 1 "<<endl;
      cout<<"Presiona cualquier letra y da enter para continuar"<<endl;
      cin>>continuar;
      cout<<"Elige tu ataque"<<endl;
      int J1opcion; Attack *J1attack;
      a.showAttacks();
      cin>>J1opcion;
      J1attack= a.getAttack(J1opcion);
      a.finish();

      //Selecciona ataque Jugador 2
      cout<<"TURNO JUGADOR 2 "<<endl;
      cout<<"Presiona cualquier letra y da enter para continuar"<<endl;
      cin>>continuar;
      cout<<"Elige tu ataque"<<endl;
      int J2opcion; Attack *J2attack;
      b.showAttacks();
      cin>>J2opcion;
      J2attack= b.getAttack(J2opcion);
      b.finish();

      //Luchan

      // Cuando el elemento es el mismo
      if( J1attack->getDamageType() == J2attack->getDamageType() ){

        //Cuando el J1attack tiene mas poder
        if( J1attack->getLevelAtack() > J2attack->getLevelAtack() ){
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<a.getName()<<" -> "<<J1attack->getAttackName()<<endl;
        cout<<b.getName()<<" -> "<<J2attack->getAttackName()<<endl;
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<J1attack->getAttackName()<<" tiene mayor poder que "<<J2attack->getAttackName()<<endl;
        cout<<a.getName()<<" -> GANA ESTA RONDA"<<endl;
        b.setHealth(b.getHealth()-damage);
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<a.getName()<<" -> tienes "<<a.getHealth()<<" de vida"<<endl;
        cout<<b.getName()<<" -> tienes "<<b.getHealth()<<" de vida"<<endl;
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<"Presiona cualquier letra y da enter para continuar"<<endl;
        cin>>continuar;
        }
        //Cuando el J2attack tiene mas poder
        else if( J2attack->getLevelAtack() > J1attack->getLevelAtack() ){
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<a.getName()<<" -> "<<J1attack->getAttackName()<<endl;
        cout<<b.getName()<<" -> "<<J2attack->getAttackName()<<endl;
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<J2attack->getAttackName()<<" tiene mayor poder que "<<J1attack->getAttackName()<<endl;
        cout<<b.getName()<<" GANA ESTA RONDA"<<endl;
        a.setHealth(a.getHealth()-damage);
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<a.getName()<<" -> tienes "<<a.getHealth()<<" de vida"<<endl;
        cout<<b.getName()<<" -> tienes "<<b.getHealth()<<" de vida"<<endl;
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<"Presiona cualquier letra y da enter para continuar"<<endl;
        cin>>continuar;
        }
        //Cuando los ataques son los mismos
        else{
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<a.getName()<<" -> "<<J1attack->getAttackName()<<endl;
        cout<<b.getName()<<" -> "<<J2attack->getAttackName()<<endl;
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<" NADIE GANA ESTA RONDA"<<endl;
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<a.getName()<<" -> tienes "<<a.getHealth()<<" de vida"<<endl;
        cout<<b.getName()<<" -> tienes "<<b.getHealth()<<" de vida"<<endl;
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<"Presiona cualquier letra y da enter para continuar"<<endl;
        cin>>continuar;
        }

      }

      //Cuando el elemento es distinto
      else{

        //Cuando el jugador uno gana por elemento
        if((J1attack->getDamageType()=="Agua" && J2attack->getDamageType()=="Fuego")||(J1attack->getDamageType()=="Fuego" && J2attack->getDamageType()=="Hielo")||(J1attack->getDamageType()=="Hielo" && J2attack->getDamageType()=="Agua")){
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<a.getName()<<" -> "<<J1attack->getAttackName()<<endl;
        cout<<b.getName()<<" -> "<<J2attack->getAttackName()<<endl;
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<J1attack->getDamageType()<<" vence a "<<J2attack->getDamageType()<<endl;
        cout<<a.getName()<<" GANA ESTA RONDA"<<endl;
        b.setHealth(b.getHealth()-damage);
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<a.getName()<<" -> tienes "<<a.getHealth()<<" de vida"<<endl;
        cout<<b.getName()<<" -> tienes "<<b.getHealth()<<" de vida"<<endl;
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<"Presiona cualquier letra y da enter para continuar"<<endl;
        cin>>continuar;
        }
        //Cuando no
        else{
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<a.getName()<<" -> "<<J1attack->getAttackName()<<endl;
        cout<<b.getName()<<" -> "<<J2attack->getAttackName()<<endl;
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<J2attack->getDamageType()<<" vence a "<<J1attack->getDamageType()<<endl;
        cout<<b.getName()<<" GANA ESTA RONDA"<<endl;
        a.setHealth(a.getHealth()-damage);
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<a.getName()<<" -> tienes "<<a.getHealth()<<" de vida"<<endl;
        cout<<b.getName()<<" -> tienes "<<b.getHealth()<<" de vida"<<endl;
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<"Presiona cualquier letra y da enter para continuar"<<endl;
        cin>>continuar;
        }

      }

    }


    //GANADOR
    if(a.status()=="Vivo"){
    cout<<"//////////////////////////////////////////////////////////////////////"<<endl;
    cout<<" GANASTE!!! Eres el mejor, Avatar "<<a.getName()<<endl;
    cout<<"//////////////////////////////////////////////////////////////////////"<<endl;
    }
    else{
    cout<<"//////////////////////////////////////////////////////////////////////"<<endl;
    cout<<" GANASTE!!! Eres el mejor, Avatar "<<b.getName()<<endl;
    cout<<"//////////////////////////////////////////////////////////////////////"<<endl;
    }

    return 0;
}
