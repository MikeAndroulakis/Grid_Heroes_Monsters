#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "changeinventory.h"

void changeinventory(vector <Weapon> hweapons,vector <Armor> harmors,vector <Weapon> *useweapons,vector <Armor> *usearmors,vector <Hero *> heroes,Hero *H1,int mikos,int platos,int change,int herochoice){
	int size;
	int itemchoice;
	string weaponname;
	int value;
	int minleveltouse;
	int dmg;
	int amountofhands;
	string armorname;
	int amountofreduceddmg;
	string category;
	int hands;
	int elegxos=0;
	if(change==1){
		size=hweapons.size();//to megethos toy vector
		if(size==0){
			cout<<"You dont have any weapons right now so you cant change weapons"<<endl;
			elegxos=1;
		}
		if((size!=1)&&(elegxos==0)){//an yparxoyn toylaxiston 2 opla sto inventory
			checkweapons(hweapons,0);//ektypwnontai ta opla toy irwa mazi me tis info toys
			cout<<"Please type the number of the weapon you want(starting from 0)"<<endl;
			cin>>itemchoice;
			if((itemchoice>=hweapons.size())||(itemchoice<0)){
				cout<<"Invalid Input.Try again!"<<endl;
			}
			else{
				weaponname=hweapons[itemchoice].getname();
				value=hweapons[itemchoice].getvalue();
				minleveltouse=hweapons[itemchoice].getminlvl();
				dmg=hweapons[itemchoice].getdmg();
				amountofhands=hweapons[itemchoice].getamountofhands();
				Weapon W(dmg,amountofhands,weaponname,value,minleveltouse);
				cout<<"If you want to remove your previous weapons press 1"<<endl;
				cout<<"If you want to add to your previous weapons press 2"<<endl;
				cin>>itemchoice;
				if((itemchoice!=1)&&(itemchoice!=2)){
					cout<<"Invalid Input.Try again!"<<endl;
				}
				else{
					if(itemchoice==1){//an epilexthike oti o irwas thelei na allaksei oplo
						checkweapons(*useweapons,1);//ektypwnontai ta opla poy exei sto xeri toy o irwas
						cout<<"Please type the number of the weapon you dont want to(starting from 0)";
						cout<<" use"<<endl;
						cin>>itemchoice;
						useweapons->erase(useweapons->begin()+itemchoice);//to oplo sbinetai apo to vector(feygei apo to xeri toy)
						useweapons->push_back(W);//to neo oplo poy epilexthike topotheteitai sto xeri toy		
					}
					else if(itemchoice==2){//an epilexthike oti thelei na balei kai ayto to oplo sto xeri toy
						hands=heroes[herochoice-1]->getusedhands();//apothikeyontai ta xeria poy xrisimopoiei o irwas
						if((amountofhands+hands)<=2){//an to athroisma twn xeriwn poy apaitoyn ta 2 opla den yperbenei ta 2 xeria tote to oplo topotheteitai sto xeri toy
							useweapons->push_back(W);//to oplo mpainei sto xeri toy
							cout<<"The "<<weaponname<<" has been added";
							cout<<" to your hand"<<endl;
						}
						else{
							cout<<"You do not have so many hands"<<endl;
						}
					}
				}
			}
		}
		else{
			cout<<"You have only one weapon in your inventory"<<endl;
		}
	}
	else if(change==2){//an epilexthike oti thelei na allaksei panoplia
		size=harmors.size();
		if(size==0){//an den exei katholoy panoplies
			cout<<"You dont have any armors right now so you cant change armors"<<endl;
			elegxos=1;
		}
		if((size!=1)&&(elegxos==0)){//an exei perissoteres apo mia panoplies
			checkarmors(harmors,0);//ektypwnontai oi panoplies toy irwa kai epilegei poia thelei
			cout<<"Please type the number of the armor you want(starting from 0)"<<endl;
			cin>>itemchoice;
			if((itemchoice>=harmors.size())||(itemchoice<0)){
				cout<<"Invalid Input.Try again!"<<endl;
			}
			else{
				armorname=harmors[itemchoice].getname();
				value=harmors[itemchoice].getvalue();
				minleveltouse=harmors[itemchoice].getminlvl();
				amountofreduceddmg=harmors[itemchoice].getamountofreduceddmg();
				Armor A(amountofreduceddmg,armorname,value,minleveltouse);
				usearmors->erase(usearmors->begin());//h proigoymeni panoplia feygey apo to swma toy
				usearmors->push_back(A);//h kainoyria panoplia topotheteitai sto swma toy
				cout<<"You are now wearing "<<armorname<<endl;
			}
		}
		else{//an exei mono mia panoplia
			cout<<"You have only one armor"<<endl;
		}
	}
}



