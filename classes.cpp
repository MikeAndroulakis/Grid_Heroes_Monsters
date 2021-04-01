#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "classes.h"

using namespace std;



Item::Item(string n,double v,int ml)
:name(n),value(v),minimum_level(ml){}
Item::~Item(){}
string Item::getname(){
	return name;
}
double Item::getvalue(){
	return value;
}
int Item::getminlvl(){
	return minimum_level;
}

Weapon::Weapon(int d,int aoh,string n,double v,int ml)
:Item(n,v,ml),damage(d),amount_of_hands(aoh){}
Weapon::~Weapon(){}
int Weapon::getdmg(){
	return damage;
}
int Weapon::getamountofhands(){
	return amount_of_hands;
}

Armor::Armor(int aord,string n,double v,int ml)
:Item(n,v,ml),amount_of_reduced_damage(aord){}
Armor::~Armor(){}
int Armor::getamountofreduceddmg(){
	return amount_of_reduced_damage;
}

Potion::Potion(int tir,string c,string n,double v,int ml)
:Item(n,v,ml),the_increase_rate(tir),category(c){}
Potion::~Potion(){}
int Potion::getincreasedrate(){
	return the_increase_rate;
}
string Potion::getcategory(){
	return category;
}

Spell::Spell(string n,double v,int mhl,int mind,int maxd,int aomp,int aor,int aod,string c)
:name(n),value(v),minimum_heroe_level(mhl),mindmg(mind),maxdmg(maxd),amount_of_magic_power(aomp),amount_of_rounds(aor),
amount_of_decrease(aod),category(c){}
Spell::~Spell(){}
string Spell::getname(){
	return name;
}
double Spell::getvalue(){
	return value;
}
int Spell::getminlvl(){
	return  minimum_heroe_level;
}
int Spell::getmindmg(){
	return mindmg;
}
int Spell::getmaxdmg(){
	return maxdmg;
}
int Spell::getmagicpowerneed(){
	return amount_of_magic_power;
}
int Spell::getrounds(){
	return amount_of_rounds;
}
int Spell::getdecreaserate(){
	return amount_of_decrease;
}
string Spell::getcategory(){
	return category;
}

Living::Living(string n)
:name(n),level(0),health(250){}
Living::~Living(){}
void Living::addlevel(){
	level+=1;
}
void Living::setlevel(int lvl){
	level=lvl;
}
int Living::gethealth(){
	return health;
}
void Living::changehealth(int hp){
	health+=hp;
	if(health<0){//to hp de mporei na einai <0
		health=0;
	}
	if(health>250){//to hp de mporei na einai >0
		health=250;
	}
}
int Living::getlvl(){
	return level;
}

Hero::Hero(int m,int s,int d,int a,string n)
:Living(n),magicpower(m),strength(s),dexterity(d),agility(a){
	experience=0;
	money=500;
	usedhands=0;
}
Hero::~Hero(){}
int Hero::getdmg(){
	return strength;
}
void Hero::addexperience(int xp){
	experience+=xp;
	if(experience>=100){//an to xp einai toulaxiston 100
		experience=0;//mhdenizetai
		setlevel(1);//ayksanetai to level toy irwa
		addstrength(2);
		adddexterity(1);
	}
}
void Hero::addstrength(int amount){
	strength+=amount;
}
void Hero::addagility(int amount){
	agility+=amount;
}
void Hero::adddexterity(int amount){
	dexterity+=amount;
}
int Hero::getstrength(){
	return strength;
}
int Hero::getagility(){
	return agility;
}
int Hero::getdexterity(){
	return dexterity;
}
int Hero::getxp(){
	return experience;
}
int Hero::getmoney(){
	return money;
}
void Hero::resetxp(){
	experience=0;
}
void Hero::setthesimikos(int mikos){
	thesimikos=mikos;
}
void Hero::setthesiplatos(int platos){
	thesiplatos=platos;
}
int Hero::getthesimikos(){
	return thesimikos;
}
int Hero::getthesiplatos(){
	return thesiplatos;
}
void Hero::increasestrength(int dmg){
	strength+=dmg;
}
void Hero::changemagicpower(int ap){
	magicpower+=ap;
}
void Hero::increasedexterity(int dex){
	dexterity+=dex;
}
void Hero::increaseagility(int ag){
	agility+=ag;
}
void Hero::changemoney(int cash){
	money+=cash;
}
void Hero::setusedhands(int hands){
	usedhands+=hands;
}
int Hero::getusedhands(){
	return usedhands;
}
int Hero::getmagicpower(){
	return magicpower;
}

Warrior::Warrior(int m,int s,int d,int a,string n)
:Hero(m,s,d,a,n){}
Warrior::~Warrior(){}

Sorcerer::Sorcerer(int m,int s,int d,int a,string n)
:Hero(m,s,d,a,n){}
Sorcerer::~Sorcerer(){}

Paladin::Paladin(int m,int s,int d,int a,string n)
:Hero(m,s,d,a,n){}
Paladin::~Paladin(){}

Monster::Monster(int min,int max,int de,int c,string n)
:Living(n),minimumdamage(min),maxdamage(max),defense(de),chance(c){}
Monster::~Monster(){}
int Monster::getdefense(){
	return defense;
}
int Monster::getchance(){
	return chance;
}
int Monster::getmindmg(){
	return minimumdamage;
}
int Monster::getmaxdmg(){
	return maxdamage;
}
void Monster::changedefense(int def){
	defense+=def;
	rounds=3;
}
void Monster::changemindmg(int dmg){
	minimumdamage+=dmg;
}
void Monster::changechance(int ch){
	chance+=ch;
}

Dragon::Dragon(int min,int max,int de,int c,string n)
:Monster(min,max,de,c,n){}
Dragon::~Dragon(){}

Exoskeleton::Exoskeleton(int min,int max,int de,int c,string n)
:Monster(min,max,de,c,n){}
Exoskeleton::~Exoskeleton(){}

Spirit::Spirit(int min,int max,int de,int c,string n)
:Monster(min,max,de,c,n){}
Spirit::~Spirit(){}


