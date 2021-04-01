#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include "openfiles.h"

using namespace std;
/*katholikes metablites epeidi xreiazontai se oles tis synartiseis toy arxeioy*/
int metritis;
ifstream myfile;
int value;
int minleveltouse;
string line;
string category;


vector <Weapon> openweapons(){//synartisi gia diabasma twn weapon apto arxeio
	vector <Weapon> weapons;//dimioyrgia vector gia apothikeysi twn weapon
	string weaponname;
	int dmg;
	int amountofhands;
	myfile.open("Weapons.txt");
	metritis=0;
	while (getline(myfile,line)) {
		if(metritis==0){
			weaponname=line;//apothikeytai to onoma
			metritis=1;
		}
		else if(metritis==1){
			value=atoi(line.c_str());//apothikeyetai h aksia
			metritis=2;
		}
		else if(metritis==2){
			minleveltouse=atoi(line.c_str());//apothikeyetai to elaxisto level poy apaiteitai gia na xrisimopoiithei
			metritis=3;
		}
		else if(metritis==3){
			dmg=atoi(line.c_str());//apothikeyetai to damage toy
			metritis=4;
		}
		else if(metritis==4){
			amountofhands=atoi(line.c_str());//apothikeyontai ta xeria poy xreiazontai gia to oplo
			Weapon W(dmg,amountofhands,weaponname,value,minleveltouse);//dimioyrgia toy weapon me tis parapanw info
			weapons.push_back(W);//to oplo mpainei sto vector
			metritis=0;
		}
	}
	myfile.close();
	return weapons;//epistrefetai o vector
}

vector <Armor> openarmors(){//synartisi gia diabasma twn armor apto arxeio
	myfile.open("Armors.txt");
	metritis=0;
	vector <Armor>armors;//dimioyrgia vector poy tha fylaksei ta armor
	string armorname;
	int amountofreduceddmg;
	while (getline(myfile,line)) {
		if(metritis==0){
			armorname=line;//apothikeyetai to onoma toy armor
			metritis=1;
		}
		else if(metritis==1){
			amountofreduceddmg=atoi(line.c_str());//apothikeyetai to damage poy apokroyei
			metritis=2;
		}
		else if(metritis==2){
			value=atoi(line.c_str());//apothikeyetai h aksia toy
			metritis=3;
		}
		else if(metritis==3){
			minleveltouse=atoi(line.c_str());//apothikeyetai to elaxiston epipedo poy apaiteitai gia na xrisimopoiithei
			Armor A(amountofreduceddmg,armorname,value,minleveltouse);//dimioyrgia toy armor me tis parapanw info
			armors.push_back(A);//to armor mpainei sto vector
			metritis=0;
		}
	}
	myfile.close();
	return armors;//epistrefetai to vector
}

vector <Potion> openpotions(){//synartisi gia diabasma twn potion apto arxeio
	myfile.open("Potions.txt");
	metritis=0;
	vector <Potion>potions;//dimiourgia vector poy tha fyllaksei ta potion
	string potionname;
	int increasedrate;
	while (getline(myfile,line)) {
		if(metritis==0){
			potionname=line;//apothikeyetai to onoma toy potion
			metritis=1;
		}
		else if(metritis==1){
			increasedrate=atoi(line.c_str());//apothikeyetai to increased rate toy
			metritis=2;
		}
		else if(metritis==2){
			category=atoi(line.c_str());//apothikeyetai h katigoria toy
			metritis=3;
		}
		else if(metritis==3){
			value=atoi(line.c_str());//apothikeyetai h aksia toy
			metritis=4;
		}
		else if(metritis==4){
			minleveltouse=atoi(line.c_str());//apothikeyetai to elaxiston epipedo poy apaiteitai gia na xrisimopoiithei
			Potion P(increasedrate,category,potionname,value,minleveltouse);//dimioyrgia toy potion me tis parapanw info
			potions.push_back(P);//to potion mpainei sto vector
			metritis=0;
		}
	}
	myfile.close();
	return potions;//epistrefetai o vector
}

vector <Spell> openspells(){
	vector <Spell>spells;//dimioyrgia vector poy tha fyllaksei ta spells
	metritis=0;
	string spellname;
	int mindmg;
	int maxdmg;
	int magicpowerneed;
	int decreased;
	myfile.open("Spells.txt");
	while (getline(myfile,line)) {
		if(metritis==0){
			spellname=line;//apothikeyetai to onoma toy spell
			metritis=1;
		}
		else if(metritis==1){
			value=atoi(line.c_str());//apothikeyetai h aksia toy 
			metritis=2;
		}
		else if(metritis==2){
			minleveltouse=atoi(line.c_str());//apothikeyetai to elaxiston epipedo poy apaiteitai gia na xrisimopoiithei
			metritis=3;
		}
		else if(metritis==3){
			mindmg=atoi(line.c_str());//apothikeyetai to elaxisto damage poy mporei na kanei
			metritis=4;
		}
		else if(metritis==4){
			maxdmg=atoi(line.c_str());//apothikeyetai to megisto damage poy mporei na kanei
			metritis=5;
		}
		else if(metritis==5){
			magicpowerneed=atoi(line.c_str());//apothikeyetai h magiki energeia poy xreiazetai gia na ginei to spell
			metritis=6;
		}
		else if(metritis==6){
			decreased=atoi(line.c_str());//apothikeyetai to amount of reduced
			metritis=7;
		}
		else if(metritis==7){
			category=line;//apothikeyetai h katigoria toy
			Spell S(spellname,value,minleveltouse,mindmg,maxdmg,magicpowerneed,3,decreased,category);//dimioyrgia toy spell me ta parapanw info
			spells.push_back(S);//to spell mpainei sto vector
			metritis=0;
		}
	}
	myfile.close();
	return spells;//epistrefetai to vector
}




