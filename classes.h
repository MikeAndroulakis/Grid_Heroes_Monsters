#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>


using namespace std;

struct nodespell{//struct gia tis katares twn spell
	string category;
	int rounds;
	int amountofreduce;
};

class Item{
private:
	string name;
	double value;
	int minimum_level;
public:
	Item(string n,double v,int ml);
	~Item();
	string getname();
	virtual double getvalue();
	virtual int getminlvl();
};

class Weapon:public Item{
private:
	int damage;
	int amount_of_hands;
public:
	Weapon(int d,int aoh,string n,double v,int ml);
	~Weapon();
	int getdmg();
	int getamountofhands();
};

class Armor:public Item{
private:
	int amount_of_reduced_damage;
public:
	Armor(int aord,string n,double v,int ml);
	~Armor();
	int getamountofreduceddmg();
};

class Potion:public Item{
private:
	int the_increase_rate;
	string category;
public:
	Potion(int tir,string c,string n,double v,int ml);
	~Potion();
	int getincreasedrate();
	string getcategory();
};

class Spell{
private:
	string name;
	double value;
	int minimum_heroe_level;
	int mindmg;
	int maxdmg;
	int amount_of_magic_power;
	int amount_of_rounds;
	int amount_of_decrease;
	string category;
public:
	Spell(string n,double v,int mhl,int mind,int maxd,int aomp,int aor,int aod,string c);
	~Spell();
	string getname();
	double getvalue();
	int getminlvl();
	int getmindmg();
	int getmaxdmg();
	int getmagicpowerneed();
	int getrounds();
	int getdecreaserate();
	string getcategory();
};

class Living{
private:
	string name;
	int level;
	int health;
public:
	Living(string n);
	virtual ~Living();
	void addlevel();
	void setlevel(int lvl);
	int gethealth();
	void changehealth(int hp);
	int getlvl();
};

class Hero:public Living{
private:
	int magicpower;
	int strength;
	int dexterity;
	int agility;
	int money;
	int experience;
	int thesimikos;
	int thesiplatos;
	int usedhands;
public:
	Hero(int m,int s,int d,int a,string n);
	~Hero();
	int getdmg();
	void addexperience(int xp);
	void addstrength(int amount);
	void addagility(int amount);
	void adddexterity(int amount);
	int getstrength();
	int getagility();
	int getdexterity();
	int getxp();
	int getmoney();
	void resetxp();
	void setthesimikos(int mikos);
	void setthesiplatos(int platos);
	int getthesimikos();
	int getthesiplatos();
	void increasestrength(int dmg);
	void changemagicpower(int ap);
	void increasedexterity(int dex);
	void increaseagility(int ag);
	void changemoney(int cash);
	void setusedhands(int hands);
	int getusedhands();
	int getmagicpower();
};

class Warrior:public Hero{
public:
	Warrior(int m,int s,int d,int a,string n);
	~Warrior();
};

class Sorcerer:public Hero{
public:
	Sorcerer(int m,int s,int d,int a,string n);
	~Sorcerer();
};

class Paladin:public Hero{
public:
	Paladin(int m,int s,int d,int a,string n);
	~Paladin();
};

class Monster:public Living{
private:
	int minimumdamage;
	int maxdamage;
	int defense;
	int chance;
	int rounds;
public:
	Monster(int min,int max,int de,int c,string n);
	~Monster();
	void changedefense(int def);
	void changemindmg(int dmg);
	void changechance(int ch);
	int getdefense();
	int getchance();
	int getmindmg();
	int getmaxdmg();
};

class Dragon:public Monster{
public:
	Dragon(int min,int max,int de,int c,string n);
	~Dragon();
};

class Exoskeleton:public Monster{
public:
	Exoskeleton(int min,int max,int de,int c,string n);
	~Exoskeleton();
};

class Spirit:public Monster{
public:
	Spirit(int min,int max,int de,int c,string n);
	~Spirit();
};

