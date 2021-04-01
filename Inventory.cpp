#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "Inventory.h"

using namespace std;
void checkInventory(vector<Weapon>& weapons,vector<Armor>& armors,vector<Potion>& potions,vector<Spell>& spells){
	unsigned int i;
	cout<<endl;
	cout<<endl;
	cout<<"                             /Your Items are\\"<<endl;
	cout<<endl;
	cout<<"WEAPONS:"<<endl;
	for(i=0;i<weapons.size();i++){//ektypwnontai ola ta opla toy irwa mazi me ta info toys
		cout<<"Name:"<<weapons[i].getname()<<endl;
		cout<<"Value:"<<weapons[i].getvalue()<<endl;
		cout<<"Minimum level to use:"<<weapons[i].getminlvl()<<endl;
		cout<<"Damage:"<<weapons[i].getdmg()<<endl;
		cout<<"Amount of hands:"<<weapons[i].getamountofhands()<<endl;
	}
	
	cout<<"ARMORS:"<<endl;
	for(i=0;i<armors.size();i++){//ektypwnontai ola ta armors toy irwa mazi me ta info toys
		cout<<"Name:"<<armors[i].getname()<<endl;
		cout<<"Value:"<<armors[i].getvalue()<<endl;
		cout<<"Minimum level to use:"<<armors[i].getminlvl()<<endl;
		cout<<"Amount of reduced damage:"<<armors[i].getamountofreduceddmg()<<endl;
	}
	cout<<"POTIONS:"<<endl;
	for(i=0;i<potions.size();i++){//ektypwnontai ola ta potion toy irwa mazi me ta info toys
		cout<<"Name:"<<potions[i].getname()<<endl;
		cout<<"Value:"<<potions[i].getvalue()<<endl;
		cout<<"Minimum level to use:"<<potions[i].getminlvl()<<endl;
		cout<<"The increase rate is:"<<potions[i].getincreasedrate()<<endl;
		cout<<"The category is:"<<potions[i].getcategory()<<endl;
	}
	cout<<"SPELLS:"<<endl;
	for(i=0;i<spells.size();i++){//ektypwnontai ola ta spell toy irwa mazi me ta info toys
		cout<<"Name:"<<spells[i].getname()<<endl;
		cout<<"Value:"<<spells[i].getvalue()<<endl;
		cout<<"Minimum heroe level to use:"<<spells[i].getminlvl()<<endl;
		cout<<"Minimum damage:"<<spells[i].getmindmg()<<endl;
		cout<<"Maximum damage:"<<spells[i].getmaxdmg()<<endl;
		cout<<"Magic power needed:"<<spells[i].getmagicpowerneed()<<endl;
		cout<<"Amount of rounds:"<<spells[i].getrounds()<<endl;
		cout<<"The decrease rate:"<<spells[i].getdecreaserate()<<endl;
		cout<<"The Spell decrease ";
		if(spells[i].getcategory()=="IceSpell"){
			cout<<"enemy's strength"<<endl;
		}
		else if(spells[i].getcategory()=="FireSpell"){
			cout<<"enemys armor"<<endl;
		}
		else if(spells[i].getcategory()=="LightingSpell"){
			cout<<"enemy's juke rate"<<endl;
		}
	}
	cout<<endl;




}

void checkweapons(vector<Weapon>& weapons,int elegxos){//synartisi poy ektypwnei ta weapons toy irwa
	unsigned int i;
	if(elegxos==0){
		cout<<"YOUR WEAPONS ARE:"<<endl;
	}
	else if(elegxos==1){
		cout<<"THE WEAPONS THAT YOU ARE WEARING RIGHT NOW ARE:"<<endl;
	}
	else if(elegxos==2){
		cout<<"THE WEAPONS OF THE MARKET ARE:"<<endl;
	}
	for(i=0;i<weapons.size();i++){
		cout<<i<<": Name:"<<weapons[i].getname()<<endl;
		cout<<"   Value:"<<weapons[i].getvalue()<<endl;
		cout<<"   Minimum level to use:"<<weapons[i].getminlvl()<<endl;
		cout<<"   Damage:"<<weapons[i].getdmg()<<endl;
		cout<<"   Amount of hands:"<<weapons[i].getamountofhands()<<endl;
	}
	cout<<endl;
}

void checkarmors(vector<Armor>& armors,int elegxos){//synartisi poy ektypwnei ta armors toy irwa
	unsigned int i;
	if(elegxos==0){
		cout<<"YOUR ARMORS ARE:"<<endl;
	}
	else if(elegxos==1){
		cout<<"THE ARMORS OF THE MARKET ARE:"<<endl;
	}
	for(i=0;i<armors.size();i++){
		cout<<i<<": Name:"<<armors[i].getname()<<endl;
		cout<<"   Value:"<<armors[i].getvalue()<<endl;
		cout<<"   Minimum level to use:"<<armors[i].getminlvl()<<endl;
		cout<<"   Amount of reduced damage:"<<armors[i].getamountofreduceddmg()<<endl;
	}
	cout<<endl;
}

void checkpotions(vector<Potion>& potions,int elegxos){//synartisi poy ektypwnei ta potions toy irwa
	unsigned int i;
	if(elegxos==0){
		cout<<"YOUR POTIONS ARE:"<<endl;
	}
	else if(elegxos==1){
		cout<<"THE POTIONS OF THE MARKET ARE:"<<endl;
	}
	for(i=0;i<potions.size();i++){
		cout<<i<<": Name:"<<potions[i].getname()<<endl;
		cout<<"   Value:"<<potions[i].getvalue()<<endl;
		cout<<"   Minimum level to use:"<<potions[i].getminlvl()<<endl;
		cout<<"   The increase rate is:"<<potions[i].getincreasedrate()<<endl;
		cout<<"   The category is:"<<potions[i].getcategory()<<endl;
	}
	cout<<endl;
}

void checkspells(vector<Spell>& spells,int elegxos){//synartisi poy ektypwnei ta spells toy irwa
	unsigned int i;
	if(elegxos==0){
		cout<<"YOUR SPELLS ARE:"<<endl;
	}
	else if(elegxos==1){
		cout<<"THE SPELLS OF THE MARKET ARE:"<<endl;
	}
	for(i=0;i<spells.size();i++){
		cout<<i<<": Name:"<<spells[i].getname()<<endl;
		cout<<"   Value:"<<spells[i].getvalue()<<endl;
		cout<<"   Minimum level to use:"<<spells[i].getminlvl()<<endl;
		cout<<"   Minimum damage:"<<spells[i].getmindmg()<<endl;
		cout<<"   Maximum damage:"<<spells[i].getmaxdmg()<<endl;
		cout<<"   Amount of magic power needed:"<<spells[i].getmagicpowerneed()<<endl;
		cout<<"   Amount of rounds that influence the enemy"<<spells[i].getrounds()<<endl;
		cout<<"   Amount of decrease:"<<spells[i].getdecreaserate()<<endl;
		cout<<"   Type of spell:"<<spells[i].getcategory()<<endl;
	}
	cout<<endl;
}
