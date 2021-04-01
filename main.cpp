#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <list>
#include "changeinventory.h"

using namespace std;
void itemsmenu(vector<Weapon>& weapons,vector<Armor>& armors,vector<Potion>& potions,vector<Spell>& spells);//plirofories gia ola ta items
void displayMap(int mikos,int platos,int mikospaixtwn,int platospaixtwn,char **Grind);//emfanizontai plhrofories gia ola ta tetragwna toy plegmatos
void viewinfo(vector <Hero*> heroes);//emfanizontai plhrofories gia olous toys irwes
void displaystats(vector <Monster*> monsters);//emfanizontai plhrofories gia ta terata

int main(int argc,char *argv[]){
	srand(time(NULL));
	int choice;
	string name;
	int i,j;
	unsigned int k,l;
	int random;
	Hero *H1;//deiktis gia to prwto hrwa
	Hero *H2;//deiktis gia to deytero
	Hero *H3;//deiktis gia to trito
	int magicpower,strength,dexterity,agility;
	int tyxaiomikos,tyxaioplatos;
	int mikos,platos;//metablites gia tis tyxaies diastaseis toy grind
	mikos=(rand()%10)+15;
	platos=(rand()%10)+15;
	char **Grind;
	Grind=new char*[mikos];//dimioyrgia toy grind
	vector <Hero *> heroes;//pinakas deiktwn se hero poy tha fylaksei ola ta antikeimena twn hrwwn
	for(i=0;i<mikos;i++){//dhmioyrgeitai dysdiastatos pinakas gia to grind
		Grind[i]=new char[platos];
	}
	for(i=0;i<mikos;i++){//gia kathe tetragwno toy grind epilegetai tyxaia ti tha einai
		for(j=0;j<platos;j++){
			random=rand()%3;
			if((random==0)&&(i%2==0)){
				Grind[i][j]='n';
			}
			else{
				Grind[i][j]='c';
			}
			if(random==1){
				Grind[i][j]='m';
			}
			if(random==2){
				Grind[i][j]='c';
			}
		}
	}
	cout<<"How many heroes do you want?"<<endl;
	cout<<"Press 1 if you want 1,2 if you want 2 and 3 if you want 3"<<endl;
	cin>>choice;
	while(1){
		tyxaiomikos=rand()%mikos;//epilegetai tyxaia se poia grammh tha briskontai oi hrwes
		tyxaioplatos=rand()%platos;//epilegetai tyxaia se poia sthlh tha briskontai oi hrwes
		if(Grind[tyxaiomikos][tyxaioplatos]!='n'){//an to tyxaio shmeio poy epilexthike einai accessible tote break
			break;
		}
	}

	for(i=0;i<choice;i++){//gia osous hrews epileksame
		if(choice==1){//an epilexthike enas  mono hrwes
			cout<<"Please give a name for the hero"<<endl;
		}
		else if(i==0){//an epilexthikan 2 hrwes
			cout<<"Please give a name for the first hero"<<endl;
		}
		if(i==1){
			cout<<"Please give a name for the second hero"<<endl;
		}
		else if(i==2){//an epilexthikan 3 hrwes
			cout<<"Please give a name for the third hero"<<endl;
		}
		cin>>name;//dinetai apti grammi onoma gia ton hrwa
		random=rand()%3;//epilegetai tyxaia an o hrwas tha einai warrior,sorcerer h paladin
		if(random==0){
			strength=(rand()%10)+100;//epilegetai tyxaia h dynamh(o warrior einai eynohmenos edw)
			dexterity=(rand()%1)+1;//epilegetai tyxaia h epideksiotita
			agility=(rand()%2)+2;//epilegetai tyxaia h eykinisia(o warrior einai eynohmenos edw)
			magicpower=(rand()%10)+10;//epilegetai tyxaia h arxikh magikh toy energeia
			if(i==0){//an einai o prwtos hrwas
				H1=new Warrior(magicpower,strength,dexterity,agility,name);//dimioyrgia
				H1->setthesimikos(tyxaiomikos);//apothikeyetai h grammh sthn opoia briskontai
				H1->setthesiplatos(tyxaioplatos);//apothikeyetai h sthlh sthn opoia briskontai
			}
			else if(i==1){//an einai o deyteros
				H2=new Warrior(magicpower,strength,dexterity,agility,name);
			}
			else if(i==2){//an einai o tritos
				H3=new Warrior(magicpower,strength,dexterity,agility,name);
			}
			cout<<"Warrior "<<name<<" has created"<<endl;
		}
		else if(random==1){
			strength=(rand()%10)+80;
			dexterity=(rand()%1)+2;//(eynohmenos sthn epideksiotita)
			agility=(rand()%2)+2;//(eynohmenos stin eykinisia)
			magicpower=(rand()%10)+15;
			if(i==0){
				H1=new Sorcerer(magicpower,strength,dexterity,agility,name);
				H1->setthesimikos(tyxaiomikos);
				H1->setthesiplatos(tyxaioplatos);
			}
			else if(i==1){
				H2=new Sorcerer(magicpower,strength,dexterity,agility,name);
			}
			else if(i==2){
				H3=new Sorcerer(magicpower,strength,dexterity,agility,name);
			}
			cout<<"Sorcerer "<<name<<" has created"<<endl;
		}
		else if(random==2){
			strength=(rand()%10)+100;//(eynoimenos sth dinami)
			dexterity=(rand()%1)+2;//(eynoimenos sthn epideksiotita)
			agility=(rand()%2)+1;
			magicpower=(rand()%10)+10;
			if(i==0){
				H1=new Paladin(magicpower,strength,dexterity,agility,name);
				H1->setthesimikos(tyxaiomikos);
				H1->setthesiplatos(tyxaioplatos);
			}
			else if(i==1){
				H2=new Paladin(magicpower,strength,dexterity,agility,name);
			}
			else if(i==2){
				H3=new Paladin(magicpower,strength,dexterity,agility,name);
			}
			cout<<"Paladin "<<name<<" has created"<<endl;
		}
		if(i==0){//mpainei o prwtos irwas sto vector twn heroes
			heroes.push_back(H1);
		}
		else if(i==1){//mpainei o deyteros irwas sto vector twn heroes
			heroes.push_back(H2);
		}
		else if(i==2){//mpainei o tritos irwas sto vector twn heroes
			heroes.push_back(H3);
		}
	}
	vector <Weapon>weapons;//vector poy fyllaei ta weapons toy market
	weapons=openweapons();//kaleitai h synartisi kai apothikeyontai ta weapons,mazi me tis plirofories toys,sto pinaka
	vector <Armor>armors;//vector poy fyllaei ta armors toy market
	armors=openarmors();//kaleitai h synartisi kai apothikeyontai ta armors,mazi me tis plirofories toys,sto pinaka
	vector <Potion>potions;//vector poy fyllaei ta potions toy market
	potions=openpotions();//kaleitai h synartisi kai apothikeyontai ta potions,mazi me tis plirofories toys,sto pinaka
	vector <Spell>spells;//vector poy fyllaei ta spells toy market
	spells=openspells();//kaleitai h synartisi kai apothikeyontai ta spells,mazi me tis plirofories toys,sto pinaka
	string line;
	string weaponname;
	int value;
	int minleveltouse;
	int dmg;
	int amountofhands;
	ifstream myfile;
	string armorname;
	int amountofreduceddmg;
	string potionname;
	string category;
	int increasedrate;
	string spellname;
	int mindmg;
	int maxdmg;
	int magicpowerneed;
	int decreased;
	
	int move;//metabliti gia th kinisi twn irwwn
	int elegxos=0;
	int epilogi;
	int change=0;
	int itemchoice;
	vector <vector <Weapon> > hweapons;//vector poy fyllaei ta vectors twn oplwn twn irwwn
	Weapon W(100,1,"Avenger",0,0);//oloi oi irwwes ksekinane me ayto to oplo
	vector <Weapon>h1weapons;//vector gia ta weapons toy prwtoy irwa
	h1weapons.push_back(W);//mpainei to W sto vector twn weapons toy prwtoy irwa
	hweapons.push_back(h1weapons);//mpainei to vector twn weapon toy sto vector poy fyllaei ola ta weapon vectors
	if(choice>=2){//an epilexthikan toylaxiston 2 irwes
		vector <Weapon>h2weapons;//dimioyrgia vector weapon
		h2weapons.push_back(W);//to W mpainei sto vector
		hweapons.push_back(h2weapons);//to vector toy 2oy irwa mpainei sto "oliko" vector
	}
	if(choice==3){//an epilexthikan 3 irwes
		vector <Weapon>h3weapons;
		h3weapons.push_back(W);
		hweapons.push_back(h3weapons);
	}

	for(j=0;j<choice;j++){//gia olous toys irwes 
		heroes[j]->setusedhands(1);//desmeyetai to ena apta 2 xeria toys
	}
	vector < vector <Weapon > > useweapons;//vector poy tha fyllaei ta vectors twn weapon twn irwwn poy exoyn sta xeria toys
	vector <Weapon>useweapons1;//vector gia ta opla poy exei ayth th stigmh sta xeria toy o prwtos irwas
	useweapons1.push_back(W);//to W mpainei sto xeri toy
	useweapons.push_back(useweapons1);//to vector me ta opla poy xrisimopoiei mpainei sto "oliko" vector twn oplwn
	if(choice>=2){//an epilexthikan 2 irwes (ta idia)
		vector <Weapon>useweapons2;
		useweapons2.push_back(W);
		useweapons.push_back(useweapons2);
	}
	if(choice==3){//an epilexthikan 3 irwes (ta idia)
		vector <Weapon>useweapons3;
		useweapons3.push_back(W);
		useweapons.push_back(useweapons3);
	}
	
	vector <vector <Armor> > harmors;//vector poy tha fyllaei ta vectors twn armor twn irwwn
	Armor A(2,"Protect Shield",0,0);
	vector <Armor>h1armors;//dimioyrgia vector gia ta armor toy prwtoy irwa
	h1armors.push_back(A);//to A mpainei sto vector toy
	harmors.push_back(h1armors);//to vector me ta armor mpainei sto "oliko" vector
	if(choice>=2){//an epilexthikan panw apo 1 irwes(ta idia)
		vector <Armor>h2armors;
		h2armors.push_back(A);
		harmors.push_back(h2armors);
	}
	if(choice==3){//an epilexthikan panw apo 3 irwes(ta idia)
		vector <Armor>h3armors;
		h3armors.push_back(A);
		harmors.push_back(h3armors);
	}
	vector <vector <Armor> > usearmors;//dimioyrgia vector poy tha fyllaei ta vectors twn armor twn irwwn poy forane ayth ti stigmi
	vector <Armor>usearmors1;//dimioyrgia vector gia ti panoplia poy foraei twra gia to prwto irwa
	usearmors1.push_back(A);//h A mpainei sto swma toy(dld sto vector me tis panoplies poy fora)
	usearmors.push_back(usearmors1);//to vector me tis panoplies poy fora mpainei sto "oliko" vector
	if(choice>=2){//an epilexthikan panw apo 1 irwes(ta idia)
		vector <Armor>usearmors2;
		usearmors2.push_back(A);
		usearmors.push_back(usearmors2);
	}
	if(choice==3){//an epilexthikan 3 irwes(ta idia)
		vector <Armor>usearmors3;
		usearmors3.push_back(A);
		usearmors.push_back(usearmors3);
	}
	Potion P(10,"health","Blessed Gem",0,0);
	vector <vector <Potion> > hpotions;//vector poy fyllaei ta vectors twn potion twn irwwn
	vector <Potion>h1potions;//vector gia ta potion toy prwtoy irwa
	h1potions.push_back(P);//To P mpainei sto vector toy
	hpotions.push_back(h1potions);//to vector me ta potion toy mpainei sto "oliko" vector
	if(choice>=2){//an epilexthikan toylaxiston 2 irwes(ta idia)
		vector <Potion>h2potions;
		h2potions.push_back(P);
		hpotions.push_back(h2potions);
	}
	if(choice==3){//an epilexthikan 3 irwes(ta idia)
		vector <Potion>h3potions;
		h3potions.push_back(P);
		hpotions.push_back(h3potions);
	}
	Spell S("Shock",0,0,30,40,5,3,15,"FireSpell");
	vector <vector <Spell> > hspells;//vector poy tha fyllaei ta vectors twn spell twn irwwn
	vector <Spell> h1spells;//dimioyrgia vector gia ta spell toy prwtoy irwa
	h1spells.push_back(S);//to S mpainei sto vector toy
	hspells.push_back(h1spells);//to vector me ta potion toy mpainei sto "oliko" vector
	if(choice>=2){//an epilexthikan toylaxiston 2 irwes(ta idia)
		vector <Spell> h2spells;
		h2spells.push_back(S);
		hspells.push_back(h2spells);
	}
	if(choice==3){//an epilexthikan 3 irwes(ta idia)
		vector <Spell> h3spells;
		h3spells.push_back(S);
		hspells.push_back(h3spells);
	}
	
	int pithanotita;
	int fight=0;
	string monster1;
	string monster2;
	string monster3;
	int defense;
	int juke;
	Monster *M1;//deiktis gia to prwto teras
	Monster *M2;//deiktis gia to deytero teras
	vector <Monster*> monsters;//pinakas poy fylaei tous deiktes twn teratwn
	vector < vector <struct nodespell> > nodespells;//vector poy fyllaei ta vectors twn struct nodespell(ayta einai gia tis katares twn spell panw sta terata wste na kratoyntai oi allages kai oi plirofories)
	vector < struct nodespell > nodespell1;//dimioyrgia enos vector typoy struct node gia to prwto teras poy tha fyllaei tis katares klp apo ta spells
	vector < struct nodespell > nodespell2;//dimioyrgia enos vector typoy struct node gia to deytero teras poy tha fyllaei tis katares klp apo ta spells
	nodespells.push_back(nodespell1);//to vector mpainei sto "oliko" vector twn katarwn twn spell
	nodespells.push_back(nodespell2);//to vector mpainei sto "oliko" vector twn katarwn twn spell
	int teleiwtiko=0;
	myfile.open("monsternames.txt");//anoigetai to file gia anagnwsi twn onomatwn twn teratwn
	while(teleiwtiko==0){
		elegxos=0;
		change=1;
		while(elegxos==0){
			cout<<"1.If you want to move up press 1"<<endl;
			cout<<"2.If you want to move down press 2"<<endl;
			cout<<"3.If you want to move right press 3"<<endl;
			cout<<"4.If you want to move left press 4"<<endl;
			cout<<"5.If you want to display map press 5"<<endl;
			cin>>move;
			if(move==1){
				if((H1->getthesimikos()==0)||(Grind[H1->getthesimikos()-1][H1->getthesiplatos()]=='n')){//ean eimaste sth prwth grammh h to apo panw koytaki den einai accessible tote de mporoyme na pame panw
					cout<<"This move cannot be done.Please enter another input"<<endl;
					elegxos=0;
				}
				else{//alliws
					H1->setthesimikos(H1->getthesimikos()-1);//allakse ti grammi poy briskontai oi irwes
					elegxos=1;
				}
			}
			else if(move==2){
				if(H1->getthesimikos()==(mikos-1)||(Grind[H1->getthesimikos()+1][H1->getthesiplatos()]=='n')){//ean briskomaste sth teleytaia grammh toy grind h to apo katw koytaki den einai accessible tote de mporoyme na kateboyme
					cout<<"This move cannot be done.Please enter another input"<<endl;
					elegxos=0;
				}
				else{//aliws
					H1->setthesimikos(H1->getthesimikos()+1);//allakse ti grammi poy briskontai oi irwes
					elegxos=1;
				}
			}
			else if(move==3){
				if((H1->getthesiplatos()==(platos-1))||(Grind[H1->getthesimikos()][H1->getthesiplatos()+1]=='n')){//an eimaste sth teleytaia stili toy grind h to deksio koutaki den einai accessible tote de mporoyme na pame deksia
					cout<<"This move cannot be done.Please enter another input"<<endl;
					elegxos=0;	
				}
				else{//alliws
					H1->setthesiplatos(H1->getthesiplatos()+1);//allakse mono ti stili poy briskontai oi irwes
					elegxos=1;
				}
			}
			else if(move==4){
				if((H1->getthesiplatos()==0)||(Grind[H1->getthesimikos()][H1->getthesiplatos()-1]=='n')){//an briskomaste sth prwth stili toy grind h to aristero koytaki den einai accessible tote de mporoyme na pame aristera
					cout<<"This move cannot be done.Please enter another input"<<endl;
					elegxos=0;
				}
				else{//alliws
					H1->setthesiplatos(H1->getthesiplatos()-1);//allakse ti stili poy briskontai oi irwes
					elegxos=1;
				}
			}
			else if(move==5){
				displayMap(mikos,platos,H1->getthesimikos(),H1->getthesiplatos(),Grind);
			}
			else{
				cout<<"Invalid Input.Please try again!"<<endl;
			}
		}
		if(Grind[H1->getthesimikos()][H1->getthesiplatos()]=='c'){//an to koutaki poy pigan einai common
			pithanotita=rand()%6;//ypologizetai mia pithanotita
			if(pithanotita>1){//an ayti einai megalyteri toy 1 tote oi irwes tha polemisoyn me ta terata
				fight=1;//metabliti poy deixnei ti maxi
			}
			else{//alliws tha toys ksefygoyn
				cout<<"The heroes juked the monsters and avoided the fight"<<endl;
				fight=0;
			}
			if(fight==1){
				getline(myfile,line);//diabazetai apo to arxeio onoma gia ta 2 terata
				monster1=line;
				getline(myfile,line);
				monster2=line;
				for(j=0;j<2;j++){//gia ta 2 terata
					random=rand()%3;//tyxaia kathorizetai an tha einai dragon,exoskeleton h spirit
					if(random==0){
						mindmg=rand()%10+40;
						maxdmg=rand()%40+110;//eynohmeno sto eyros zhmias
						defense=rand()%10+20;
						juke=rand()%4;
						if(j==0){//an einai to prwto teras
							M1=new Dragon(mindmg,maxdmg,defense,juke,monster1);
							M1->setlevel(H1->getlvl());//to epipedo toy kathorizetai basi to epipedo toy prwtoy irwa
							cout<<"Dragon "<<monster1<<" has created"<<endl;
						}
						else if(j==1){//an einai to deytero teras
							M2=new Dragon(mindmg,maxdmg,defense,juke,monster2);
							if(choice>=2){//an epilexthikan panw apo 2 paixtes
								M2->setlevel((H1->getlvl()+H2->getlvl())/2);//to epipedo toy kathorizetai basi toy epipedoy twn 2 paixtwn
							}
							else{//alliws
								M2->setlevel(H1->getlvl());//kathorizetai iso me to epipedo toy prwtoy irwa
							}
							cout<<"Dragon "<<monster2<<" has created"<<endl;
						}
					}
					else if(random==1){
						mindmg=rand()%10+50;
						maxdmg=rand()%30+100;
						defense=rand()%20+20;//eynohmeno sthn amyna
						juke=rand()%4;
						if(j==0){
							M1=new Exoskeleton(mindmg,maxdmg,defense,juke,monster1);//dimioyrgia
							M1->setlevel(H1->getlvl());
							cout<<"Exoskleton "<<monster1<<" has created"<<endl;
						}
						else if(j==1){
							M2=new Exoskeleton(mindmg,maxdmg,defense,juke,monster2);//dimioyrgia
							if(choice==3){
								M2->setlevel((H1->getlvl()+H2->getlvl()+H3->getlvl())/3);
							}
							else{
								M2->setlevel(H1->getlvl());
							}
							cout<<"Exoskeleton "<<monster2<<" has created"<<endl;
						}
					}
					else if(random==2){
						mindmg=rand()%10+50;
						maxdmg=rand()%30+100;
						defense=rand()%10+2;
						juke=rand()%5+1;//eynohmeno sth pithanotita apofygis poy diathetei
						if(j==0){
							M1=new Spirit(mindmg,maxdmg,defense,juke,monster1);//dimioyrgia
							M1->setlevel(H1->getlvl());
							cout<<"Spirit "<<monster1<<" has created"<<endl;
						}
						else if(j==1){
							M2=new Spirit(mindmg,maxdmg,defense,juke,monster2);//dimioyrgia
							if(choice>=2){
								M2->setlevel((H1->getlvl()+H2->getlvl())/2);
							}
							else{
								M2->setlevel(H1->getlvl());
							}
							cout<<"Spirit "<<monster2<<" has created"<<endl;
						}
					}
					if(j==0){
						monsters.push_back(M1);//to prwto teras mpainei sto vector twn teratwn
					}
					else if(j==1){
						monsters.push_back(M2);//to deytero teras mpainei sto vector twn teratwn
					}
				}
				int seira=0;
				int lvl;
				int minlvl;
				int mp;
				int herochoice;
				int monsterchoice;
				int elegxosseg;
				cout<<"          THE BATTLE HAS STARTED"<<endl;
				while(1){
					elegxosseg=0;
					if((seira%2)==0){//ean einai h seira twn irwwn
						cout<<"It's heroe's turn"<<endl;
						if(choice>1){//an exoyn epilextei panw apo 1 irwes
							while(1){//dialegoyme poios tha epitethei
								cout<<"Choose which hero you want to play with"<<endl;
								cout<<"If you want the first hero press 1"<<endl;
								cout<<"If you want the second hero press 2"<<endl;
								if(choice>2){
									cout<<"If you want the third hero press 3"<<endl;
								}
								cin>>herochoice;
								if((herochoice>choice)||(herochoice<=0)){//an dothike lathos input epanalipsi
									cout<<"Ivalid Input.Try again!"<<endl;
								}
								else{
									if(heroes[herochoice-1]->gethealth()==0){//an o irwas poy epilexthike exei lipothimisei tote epilexte allon irwa
										cout<<"This hero is already dead";
										cout<<" choose another hero"<<endl;
									}
									else{
										break;
									}
								}
							}
						}
						else{
							herochoice=1;
						}
						cout<<"If you want to add a weapon to your hand or change the weapon you are using";
						cout<<" or you want to change your armor type 1"<<endl;
						cout<<"If you want to attack type 2"<<endl;
						cout<<"If you want to use a spell type 3"<<endl;
						cout<<"If you want to use a potion type 4"<<endl;
						cout<<"If you want to display map type 5"<<endl;
						cout<<"If you want see the infos of your heroes type 6"<<endl;
						cout<<"If you want to display stats for the heroes and the monsters press 7"<<endl;
						cout<<"If you want to quit the game type -1"<<endl;
						cin>>epilogi;
						if(epilogi==1){
							cout<<"If you want to add a weapon to your hand or change the weapon you are using press 1"<<endl;
							cout<<"If you want to change armor press 2"<<endl;
							cin>>itemchoice;
							if((itemchoice!=1)&&(itemchoice!=2)){//an dothike lathos input
								cout<<"Invalid Input.Try again!"<<endl;
							}
							else{//kaleitai h synartisi gia allagi twn weapon h toy armor
								changeinventory(hweapons[herochoice-1],harmors[herochoice-1], &useweapons[herochoice-1],&usearmors[herochoice-1],heroes,H1,mikos,platos,itemchoice,herochoice);
							}
						}
						else if(epilogi==2){//an epilexthike na epitethei o irwas
							if(useweapons[herochoice-1].size()==0){//an de diathetei kapoio oplo sto xeri toy de mporei na epitethei kai xanei ti seira toy
								cout<<"You are not wearing any weapons right now";
								cout<<" you lost your chance to attack"<<endl;
								elegxosseg=1;
							}
							else{//alliws
								cout<<"Choose which weapon you want to use for the attack(starting from 0)"<<endl;
								checkweapons(useweapons[herochoice-1],1);//emfanizontai ta opla poy krataei sta xeria toy
							}
							if(elegxosseg==0){
								cin>>itemchoice;
								if((itemchoice>=useweapons[herochoice-1].size())||(itemchoice<0)){
									cout<<"Invalid Input.You lost your turn"<<endl;
								}
								else{//an dothike swsto input
									dmg=useweapons[herochoice-1][itemchoice].getdmg();//apothikeysi toy damage toy oploy
									dmg=dmg+heroes[herochoice-1]->getdmg();//apothikeysi toy damage(toy strength) toy irwa poy epilexthike gia tin epithesi
									pithanotita=rand()%7;
									while(1){
										cout<<"Chooce which monster you want to get attacked"<<endl;
										cout<<"If you want the first monster type 1"<<endl;
										cout<<"If you want the second monster type 2"<<endl;
										cin>>monsterchoice;
										if((monsterchoice>2)||(monsterchoice<0)){
											cout<<"Invalid Input.Try again!"<<endl;
										}
										else{
											if(monsters[monsterchoice-1]->gethealth()==0){//an to teras poy epilexthike exei pethanei epilexte allo teras
												cout<<"This monster is already dead ";
												cout<<"choose another monster"<<endl;
											}
											else{//alliws
												break;
											}
										}
									}
									if(pithanotita>monsters[monsterchoice-1]->getchance()){//an i pithanotita na petyxei h epithesi einai megaliteri apo ti pithanotita na apofygei thn epithesi to teras
										dmg=dmg-monsters[monsterchoice-1]->getdefense();//to damage meiwnetai kata tin aspida toy teratos
										if(dmg<0){//an to damage bgike arnhtiko shmainei oti to teras aminthike
											dmg=0;
										}
										monsters[monsterchoice-1]->changehealth(-dmg);//meiwnetai i zwh toy teratos kata to damage
										if(dmg>0){
											cout<<"The monster"<<" lost "<<dmg<<" health"<<endl;
										}
										else{
											cout<<"The monster"<<" defended itself"<<endl;
										}
									}
									else{
										cout<<"The monster"<<" juked the attack"<<endl;
									}
								}
							}
						}                                                                                                      
						else if(epilogi==3){
							if(hspells[herochoice-1].size()==0){//an to vector einai keno
								cout<<"You dont have any spells,you lost the chance to attack"<<endl;
								elegxosseg=1;
							}
							else{
								cout<<"Choose which spell you want to use(starting from 0)"<<endl;
								checkspells(hspells[herochoice-1],0);//ektypwnontai ta spells toy irwa
								cin>>itemchoice;
								if((itemchoice>=hspells[herochoice-1].size())||(itemchoice<0)){
									cout<<"Invalid Input.You lost your turn"<<endl;
								}
								else{//an dothike swsto input
									lvl=heroes[herochoice-1]->getlvl();//apothikeytai to trexon level toy irwa
									mp=heroes[herochoice-1]->getmagicpower();//apothikeyetai i magic power toy irwa
									minlvl=hspells[herochoice-1][itemchoice].getminlvl();//apothikeyetai to elaxisto level poy prepei na nai o irwas gia na xrisimopoiithei to spell
									magicpowerneed=hspells[herochoice-1][itemchoice].getmagicpowerneed();//apo thikeyetai h magic power poy xreiazetai to spell
									category=hspells[herochoice-1][itemchoice].getcategory();//apotheikeyetai h katigoria toy
									if(lvl>=minlvl){//an o irwas exei to katallilo level
										if(mp>=magicpowerneed){//ama exei arketi magic power
											heroes[herochoice-1]->changemagicpower(-magicpowerneed);//h magic power poy exei o irwas meiwnetai kata toso oso xreiazetai gia na ginei to spell
											dmg=rand()%hspells[herochoice-1][itemchoice].getmaxdmg()+hspells[herochoice-1][itemchoice].getmindmg();//epilegetai tyxaia posh zhmia tha kanei mesa sto eyros panta
											maxdmg=hspells[herochoice-1][itemchoice].getmaxdmg();
											if(dmg>maxdmg){//an tyxaia epilexthike megalyteri zhmia apo ti maximum toy eyroys tote tha ginei i maximum zhmia poy mporei na ginei
												dmg=hspells[herochoice-1][itemchoice].getmaxdmg();
											}
											pithanotita=rand()%7;
											while(1){
												cout<<"Chooce which monster you want to get the spell"<<endl;
												cout<<"If you want the first monster type 1"<<endl;
												cout<<"If you want the second monster type 2"<<endl;
												cin>>monsterchoice;
												if((monsterchoice>=3)||(monsterchoice<0)){
													cout<<"Invalid Input.Try again!"<<endl;
												}
												else{
													if(monsters[monsterchoice-1]->gethealth()==0){//an to teras poy epilexthike exei pethanei tote prepei na dialextei allo
														cout<<"This monster is already dead ";
														cout<<"choose another monster"<<endl;
													}
													else{
														break;
													}
												}
											}
											if((monsterchoice>2)||(monsterchoice<0)){
												cout<<"Invalid Input.You lost your turn"<<endl;
											}
											else{
												juke=monsters[monsterchoice-1]->getchance();//apothikeyetai h pithanotita na apofygei to teras to spell
												if(pithanotita>juke){//an i pithanotita einai megaliteri simainei oti to teras den epefyge to spell
													dmg=dmg-monsters[monsterchoice-1]->getdefense();//to damage meiwnetai kata thn amyna toy teratos
													if(dmg<0){//an to damage bgike arnhtiko shmainei oti to teras amynthike oloklirwtika
														dmg=0;
													}
													monsters[monsterchoice-1]->changehealth(-dmg);//meiwnetai h zwi toy teratos
													if(dmg>0){
														cout<<"The monster"<<" has lost "<<dmg<<" health"<<endl;
														int reduced;
														reduced=hspells[monsterchoice-1][itemchoice].getdecreaserate();//apothikeyetai to poso meiwsis
														struct nodespell node;//dhmioyrgia enos struct node
														node.amountofreduce=reduced;//apothikeysi toy reduced sto node
														nodespells[monsterchoice-1].push_back(node);//to node mpainei sto vector toy vector toy teratos
														nodespells[monsterchoice-1][nodespells[monsterchoice-1].size()-1].rounds=3;//kathorizontai ta rounds poy tha yparxei h epidrasi toy spell
														if(category=="FireSpell"){//an to spell itan firespell
															nodespells[monsterchoice-1][nodespells[monsterchoice-1].size()-1].category="defense";//tote orizetai i katigoria sto node
															monsters[monsterchoice-1]->changedefense(-reduced);//kai meiwnetai h amyna toy teratos
															cout<<"Monster's defense has decreased by "<<reduced<<" for 3 rounds"<<endl;
														}
														else if(category=="IceSpell"){//an to spell itan icespell
															nodespells[monsterchoice-1][nodespells[monsterchoice-1].size()-1].category="damage";//orizetai i katigoria sto node
															monsters[monsterchoice-1]->changemindmg(reduced);//meiwnetai to eyros zhmias toy teratos
															cout<<"Monster's wide damage has decreased by "<<reduced<<" for 3 rounds"<<endl;
														}
														else if(category=="LightingSpell"){//an i katigoria itan lighting
															nodespells[monsterchoice-1][nodespells[monsterchoice-1].size()-1].category="chance";
															monsters[monsterchoice-1]->changechance(-reduced);//meiwnetai i pithanotita na apofygei mia epithesi to teras
															cout<<"Monster's chance of avoiding an attack has decreased by "<<reduced<<" for 3 rounds"<<endl;
														}
													}
													else{
														cout<<"The monster"<<" defended itself"<<endl;
													}
												}
												else{
													cout<<"The monster juked the spell"<<endl;
												}
											}
										}
										else{
											cout<<"You do not have enough magic power"<<endl;
										}
									}
									else{
										cout<<"You don't have the appropriate level to use it"<<endl;
									}
								}
							}
						}
						else if(epilogi==4){
							if(hpotions[herochoice-1].size()==0){//an den exei potions o irwas
								cout<<"You dont have any potions,you lost your turn"<<endl;
								continue;
							}
							cout<<"Choose the potion you want to use(starting from 0)"<<endl;
							checkpotions(hpotions[herochoice-1],0);//ektypwnontai ta potions mazi me ta infos
							cin>>itemchoice;
							if((itemchoice>=hpotions[herochoice-1].size())||(itemchoice<0)){
								cout<<"Invalid Input.You lost your turn"<<endl;
							}
							else{
								increasedrate=hpotions[herochoice-1][itemchoice].getincreasedrate();//apothikeysi toy increased rate toy potion
								category=hpotions[herochoice-1][itemchoice].getcategory();//apothikeysi tis katigorias toy potion
								if(category=="health"){
									heroes[herochoice-1]->changehealth(increasedrate);//ayksanetai to health toy irwa
									cout<<"Hero's health increased by "<<increasedrate<<endl;
								}
								else if(category=="strength"){
									heroes[herochoice-1]->increasestrength(increasedrate);//ayksanetai i dynami toy irwa
									cout<<"Hero's strength increased by "<<increasedrate<<endl;
								}
								else if(category=="magicpower"){
									heroes[herochoice-1]->changemagicpower(increasedrate);//ayksanetai h magic power toy irwa
									cout<<"Hero's magicpower increased by "<<increasedrate<<endl;
								}
								else if(category=="dexterity"){
									heroes[herochoice-1]->increasedexterity(increasedrate);//ayksanetai h epideksiotita toy irwa
									cout<<"Hero's dexterity increased by "<<increasedrate<<endl;
								}
								else if(category=="agility"){
									heroes[herochoice-1]->increaseagility(increasedrate);//ayksanetai h eykinisia toy irwa
									cout<<"Hero's agility increased by "<<increasedrate<<endl;
								}
								hpotions[herochoice-1].erase(hpotions[herochoice-1].begin()+itemchoice);//to potion afaireitai apo to vector toy irwa
							}
						}
						else if(epilogi==5){
							displayMap(mikos,platos,H1->getthesimikos(),H1->getthesiplatos(),Grind);
						}
						else if(epilogi==6){
							viewinfo(heroes);
						}
						else if(epilogi==7){
							viewinfo(heroes);
							displaystats(monsters);
						}
						else if(epilogi==-1){
							cout<<"The game has terminated"<<endl;
							return 0;
						}
						else{
							cout<<"Invalid Input.You lost your turn"<<endl;
						}
						if((M1->gethealth()==0)&&(M2->gethealth()==0)){//an i zwi kai twn 2 teratwn einai 0
							cout<<"     HEROES WON THE BATTLE"<<endl;
							for(k=0;k<heroes.size();k++){//gia olous tous irwes
								heroes[k]->setlevel(1);//ayksanetai to level
								heroes[k]->addexperience(10*M1->getlvl()+5*M2->getlvl());//ayksanetai to xp
								heroes[k]->changemoney(300+10*M1->getlvl()+5*M2->getlvl());//ayksanontai ta lefta bash twn level twn teratwn
							}
							break;
						}
					}
					if(seira%2!=0){//an einai i seira twn teratwn na paiksoyn
						pithanotita=rand()%7;
						while(1){
							cout<<"Choose which monster you want to play with"<<endl;
							cout<<"If you want monster 1 type 1"<<endl;
							cout<<"If you want monster 2 type 2"<<endl;
							cin>>monsterchoice;
							if((monsterchoice>2)||(monsterchoice<=0)){
								cout<<"Invalid Input.Try again!"<<endl;
							}
							else{
								if(monsters[monsterchoice-1]->gethealth()==0){//an to teras poy epilexthike gia epithesi einai nekro tote epilexte allo
									cout<<"This monster is already dead ";
									cout<<"choose another monster"<<endl;
								}
								else{
									break;
								}
							}
						}
						while(1){
							cout<<"Choose which hero you want to get attacked"<<endl;
							cout<<"If you want hero 1 type 1"<<endl;
							if(choice>=2){
								cout<<"If you want hero 2 type 2"<<endl;
							}
							if(choice==3){
								cout<<"If you want hero 3 type 3"<<endl;
							}
							cin>>herochoice;
							if((herochoice>choice)||(herochoice<=0)){
								cout<<"Invalid Input.Try again!"<<endl;
							}
							else{
								if(heroes[herochoice-1]->gethealth()==0){//an o irwas poy epilexthike na faei thn epithesi einai nekros tote epilexte allon irwa
									cout<<"This hero is already dead ";
									cout<<"choose another hero"<<endl;
								}
								else{
									break;
								}
							}
						}
						dmg=rand()%M1->getmaxdmg()+M1->getmindmg();//to damage tha ginei tyxaia
						if(dmg>monsters[monsterchoice-1]->getmaxdmg()){//an to tyxaio damage bgike panw apo to epitrepto maxdamage tote
							dmg=monsters[monsterchoice-1]->getmaxdmg();//i epithesi tha ginei me maxdamage
						}
						if(pithanotita>heroes[herochoice-1]->getagility()){//an o irwas den apefyge tin epithesi
							dmg=dmg-usearmors[herochoice-1][0].getamountofreduceddmg();//to damage poy dexetai meiwnetai kata to poso tis amynas tis panoplias toy
							if(dmg<=0){//an to damage bgike arnitiko h mhden simainei oti aminthike
								dmg=0;
								cout<<"The hero juked the attack"<<endl;
							}
							else{
								cout<<"The hero lost "<<dmg<<" health"<<endl;
							}
							heroes[herochoice-1]->changehealth(-dmg);//meiwnetai i zwi toy irwa
						}
						else{
							cout<<"The hero juked the attack"<<endl;
						}
						int metritis=0;
						for(k=0;k<heroes.size();k++){//gia oloys toy irwes
							if(heroes[k]->gethealth()==0){//elegxetai an exoyn lypothimisei
								metritis++;
							}
						}
						if(metritis==choice){//an oloi oi irwes exoyn lipothimisei
							cout<<"THE MONSTERS WON THE BATTLE"<<endl;
							for(k=0;k<heroes.size();k++){//oloi oi irwes apoktoun ti mish apo ti max zwh toys
								heroes[k]->changehealth(125);
								heroes[k]->changemoney(-(heroes[k]->getmoney()/2));//xanoyn ta misa lefta toys
							}
							monsters.erase(monsters.begin(),monsters.begin()+2);//ta terata diagrafontai apo to vector twn teratwn
							break;
						}
					}
					for(k=0;k<heroes.size();k++){//se kathe gyro gia olous toys irwes
						if(heroes[k]->gethealth()!=0){//an o irwas einai akoma zwntanos
							heroes[k]->changehealth(5);//kanei restore 5 hp
							heroes[k]->changemagicpower(1);//kai restore 1 magic power
						}
					}
					if(M1->gethealth()!=0){//kai ta 2 terata kanoyn restore 10 hp
						M1->changehealth(10);
					}
					if(M2->gethealth()!=0){
						M2->changehealth(10);
					}
					seira++;//h seira metabibazetai sto allo stratopedo kathe fora
					for(k=0;k<nodespells.size();k++){//gia ola ta vectors
						for(l=0;l<nodespells[k].size();l++){//gia ola ta vectors kathe teratos
							nodespells[k][l].rounds-=1;//meiwnontai oi gyroi poy apomenoyn gia th katara
							if(nodespells[k][l].rounds==0){//an oi gyroi teliwsan
								cout<<"Spell's curse has ended cause 3 rounds have passed,";
								if(nodespells[k][l].category=="defense"){//an to spell itan sto defense
									monsters[k]->changedefense(nodespells[k][l].amountofreduce);//ginetai restore to defense toy teratos
									cout<<"Monster's defense has been restored"<<endl;
								}
								else if(nodespells[k][l].category=="damage"){//an to spell itan sto eyros zhmias
									monsters[k]->changemindmg(-nodespells[k][l].amountofreduce);//ginetai restore to eyros zhmias
									cout<<"Monster's wide damage has been restored"<<endl;
								}
								else if(nodespells[k][l].category=="chance"){//an to spell itan sti pithanotita na apofeygei tis aepitheseis
									monsters[k]->changechance(nodespells[k][l].amountofreduce);//ginetai restore h pithanotita
									cout<<"Monster's chance of avoiding an attack has been restored"<<endl;
								}
								nodespells[k].erase(nodespells[k].begin()+l);//to node diagrafetai apo to vector toy teratos
							}
						}
					}
				}
			}
		}
		int size;
		int xrima;
		for(i=0;i<choice;i++){//gia olous toys irwes
			epilogi=1;
			if((Grind[H1->getthesimikos()][H1->getthesiplatos()]=='m')||(fight==0)){//an epesan se market tetragwno h apefygan ti maxi se ena common tote
				while(epilogi!=0){//mexri na min thelei alles allages o irwas
					if(choice==1){
						cout<<"For your hero:"<<endl;
					}
					else if(i==0){
						cout<<"For the first hero:"<<endl;
					}
					else if(i==1){
						cout<<"For the second hero:"<<endl;
					}
					else if(i==2){
						cout<<"For the third hero:"<<endl;
					}
					cout<<"If you want to check your inventory press 1"<<endl;
					cout<<"If you want to change something from your inventory press 2"<<endl;
					cout<<"If you want to buy something press 3"<<endl;
					cout<<"If you want to sell something press 4"<<endl;
					cout<<"If you want to display map press 5"<<endl;
					cout<<"If you want to see the infos of your heroes press 6"<<endl;
					cout<<"If you want to go on press 0"<<endl;
					cout<<"If you want to quit game press -1"<<endl;
					cin>>epilogi;
					if(epilogi==1){
						checkInventory(hweapons[i],harmors[i],hpotions[i],hspells[i]);//blepei to inventory toy
					}
					else if(epilogi==2){
						change=1;
						while(change!=0){
							cout<<"If you want to change a weapon press 1"<<endl;
							cout<<"If you want to change an armor press 2"<<endl;
							cout<<"If you want to use a potion press 3"<<endl;
							cout<<"If you want to display the map press 4"<<endl;
							cout<<"If you do not want any more changes press 0"<<endl;
							cout<<"If you want to quit game press -1"<<endl;
							cin>>change;
							if((change==1)||(change==2)){
								changeinventory(hweapons[i],harmors[i],&useweapons[i], &usearmors[i],heroes,H1,mikos,platos,change,i+1);//kaleitai h synartisi gia na allaksei opla kai panoplia
							}
							else if(change==3){
								size=hpotions[i].size();
								if(size!=0){
									checkpotions(hpotions[i],0);//ektypwnontai ta potion toy irwa
									cout<<"Please type the number of the potion you want to use(starting from 0)"<<endl;
									cin>>itemchoice;
									if((itemchoice>=hpotions[i].size())||(itemchoice<0)){
										cout<<"Invalid Input.Try again!"<<endl;
									}
									else{
										potionname=hpotions[i][itemchoice].getname();
										increasedrate=hpotions[i][itemchoice].getincreasedrate();
										category=hpotions[i][itemchoice].getcategory();
										hpotions[i].erase(hpotions[i].begin()+itemchoice);//to potion diagrafetai apo to vector toy irwa 
										if(category=="health"){//an einai health potion
											heroes[i]->changehealth(increasedrate);//ayksanetai to health toy irwa
										}
										else if(category=="strength"){//an einai strength potion
											heroes[i]->increasestrength(increasedrate);//ayksanetai to strength toy irwa
										}
										else if(category=="magicpower"){//an einai mp potion
											heroes[i]->changemagicpower(increasedrate);//ayksanetai to mp toy irwa
										}
										else if(category=="dexterity"){//an einai dexterity potion
											heroes[i]->increasedexterity(increasedrate);//ayksanetai to dexterity
										}
										else if(category=="agility"){//an einai agility potion
											heroes[i]->increaseagility(increasedrate);//ayksanetai to agility
										}
										cout<<"You have used "<<potionname<<endl;
									}
								}
								else{
									cout<<"You have no potions"<<endl;
								}
							}
							else if(change==4){
								displayMap(mikos,platos,H1->getthesimikos(),H1->getthesiplatos(),Grind);
							}
							else if(change==-1){
								cout<<"The game has terminated"<<endl;
								return 0;
							}
							else if((change<0)||(change>4)){
								cout<<"Invalid Input.Try again!"<<endl;
							}
						}
					}
					else if(epilogi==3){
						change=1;
						while(change!=0){
							cout<<"If you want to buy weapons press 1"<<endl;
							cout<<"If you want to buy armor press 2"<<endl;
							cout<<"If you want to buy potions press 3"<<endl;
							cout<<"If you want to buy spells press 4"<<endl;
							cout<<"If you want to display the map press 5"<<endl;
							cout<<"If you don't want to anything more to buy press 0"<<endl;
							cout<<"If you want to quit the game press -1"<<endl;
							cin>>change;
							xrima=heroes[i]->getmoney();//apothikeyontai ta leyta poy exei o irwas
							if(change==1){
								checkweapons(weapons,2);//ektypwnontai ta opla tis agoras
								cout<<"Type the number of the weapon you want to buy(starting from 0)"<<endl;
								cin>>itemchoice;
								if((itemchoice>=weapons.size())||(itemchoice<0)){
									cout<<"Invalid Input.Try again!"<<endl;
								}
								else{
									weaponname=weapons[itemchoice].getname();
									value=weapons[itemchoice].getvalue();
									minleveltouse=weapons[itemchoice].getminlvl();
									dmg=weapons[itemchoice].getdmg();
									amountofhands=weapons[itemchoice].getamountofhands();
									Weapon W(dmg,amountofhands,weaponname,value,minleveltouse);
									if(xrima>=value){//an ta leyta toy irwa einai perissotera h i isa me to kostos toy oplou
										hweapons[i].push_back(W);//tote to aplo prostithetai sto vector toy
										heroes[i]->changemoney(-value);//meiwnontai ta leyta toy irwa kata tis aksia toy weapon
										cout<<"You have bought "<<weaponname<<endl;
									}
									else{
										cout<<"You do not have enough money"<<endl;
									}
								}
							}
							else if(change==2){
								checkarmors(armors,1);//ektypwnontai ta armors tis agoras
								cout<<"Type the number of the armor you want to buy(starting from 0)"<<endl;
								cin>>itemchoice;
								if((itemchoice>=armors.size())||(itemchoice<0)){
									cout<<"Invalid Input.Try again!"<<endl;
								}
								else{
									armorname=armors[itemchoice].getname();
									value=armors[itemchoice].getvalue();
									minleveltouse=armors[itemchoice].getminlvl();
									amountofreduceddmg=armors[itemchoice].getamountofreduceddmg();
									Armor A(amountofreduceddmg,armorname,value,minleveltouse);
									if(xrima>=value){//an o irwas exei arketa xrimata
										heroes[i]->changemoney(-value);//meinontai ta lefta toy
										harmors[i].push_back(A);//to armor prostithetai sto vector toy
										cout<<"You have bought "<<armorname<<endl;
									}
									else{
										cout<<"You do not have enough money"<<endl;
									}
								}
							}
							else if(change==3){
								checkpotions(potions,1);//ektypwnontai ta potion tis agoras
								cout<<"Type the number of the potion you want to buy(starting from 0)"<<endl;
								cin>>itemchoice;
								if((itemchoice>=potions.size())||(itemchoice<0)){
									cout<<"Invalid Input.Try again!"<<endl;
								}
								else{
									potionname=potions[itemchoice].getname();
									value=potions[itemchoice].getvalue();
									minleveltouse=potions[itemchoice].getminlvl();
									increasedrate=potions[itemchoice].getincreasedrate();
									category=potions[itemchoice].getcategory();
									Potion P(increasedrate,category,potionname,value,minleveltouse);
									if(xrima>=value){//ean o irwas exei arketa lefta
										heroes[i]->changemoney(-value);//meiwnontai ta lefta toy
										hpotions[i].push_back(P);//prostithetai to potion sto vector toy
										cout<<"You have bought "<<potionname<<endl;
									}
									else{
										cout<<"You do not have enough money"<<endl;
									}
								}
							}
							else if(change==4){
								checkspells(spells,1);//ektypwnontai ta spells tis agoras
								cout<<"Type the number of the spell you want to buy(starting from 0)"<<endl;
								cin>>itemchoice;
								if((itemchoice>=spells.size())||(itemchoice<0)){
									cout<<"Invalid Input.Try again!"<<endl;
								}
								else{
									spellname=spells[itemchoice].getname();
									value=spells[itemchoice].getvalue();
									minleveltouse=spells[itemchoice].getminlvl();
									mindmg=spells[itemchoice].getmindmg();
									maxdmg=spells[itemchoice].getmaxdmg();
									magicpowerneed=spells[itemchoice].getmagicpowerneed();
									decreased=spells[itemchoice].getdecreaserate();
									category=spells[itemchoice].getcategory();
									Spell S(spellname,value,minleveltouse,mindmg,maxdmg,magicpowerneed,3,decreased,category);
									if(xrima>=value){//an exei arketa lefta o irwas
										heroes[i]->changemoney(-value);//meiwnontai ta lefta toy
										hspells[i].push_back(S);//to spell prostithetai sto vector toy
										cout<<"You have bought "<<spellname<<endl;
									}
									else{
										cout<<"You do not have enough money"<<endl;
									}
								}
							}
							else if(change==5){
								displayMap(mikos,platos,H1->getthesimikos(),H1->getthesiplatos(),Grind);
							}
							else if(change==-1){
								cout<<"The game has terminated"<<endl;
							}
							else if((change<0)||(change>5)){
								cout<<"Invalid Input.Try again!"<<endl;
							}
						}
					}
					else if(epilogi==4){
						change=1;
						while(change!=0){
							checkInventory(hweapons[i],harmors[i],hpotions[i],hspells[i]);
							cout<<"If you want to sell weapons press 1"<<endl;
							cout<<"If you want to sell armors press 2"<<endl;
							cout<<"If you want to sell potions press 3"<<endl;
							cout<<"If you want to sell spells press 4"<<endl;
							cout<<"If you want to display map press 5"<<endl;
							cout<<"If you dont want to sell anything more press 0"<<endl;
							cout<<"If you want to quit the game press -1"<<endl;
							cin>>change;
							if(change==1){
								if(hweapons[i].size()==0){
									cout<<"You dont have any more weapons to sell"<<endl;
									continue;
								}
								checkweapons(hweapons[i],0);//ektypwnontai ta weapon toy irwa
								cout<<"Type the number of the weapon you want to sell(starting from 0)"<<endl;
								cin>>itemchoice;
								if((itemchoice>=hweapons[i].size())||(itemchoice<0)){
									cout<<"Invalid Input.Try again!"<<endl;
								}
								else{
									value=hweapons[i][itemchoice].getvalue();//h aksia toy oploy
									heroes[i]->changemoney(value/2.0);//o irwas kerdizei ta misa lefta apo tin aksia toy oploy
									weaponname=hweapons[i][itemchoice].getname();
									amountofhands=hweapons[i][itemchoice].getamountofhands();
									hweapons[i].erase(hweapons[i].begin()+itemchoice);//to oplo diagrafetai apto vector toy irwa
									cout<<"The weapon has removed from your inventory"<<endl;
									size=useweapons[i].size();
									for(j=0;j<size;j++){//elegxetai an to oplo poy poylise yparxei kai sta xeria toy
										if(useweapons[i][j].getname()==weaponname){//an yparxei
											useweapons[i].erase(useweapons[i].begin()+j);//tote afaireitai kai apo ekei
											heroes[i]->setusedhands(-amountofhands);//ta xeria toy apeleytherwnontai
											cout<<"The weapon has removed from";
											cout<<" your hand also"<<endl;
										}
									}
								}
							}
							else if(change==2){
								if(harmors[i].size()==0){
									cout<<"You dont have any more armors to sell"<<endl;
									continue;
								}
								checkarmors(harmors[i],0);//ektypwnontai ta armors toy irwa
								cout<<"Type the number of the armor you want to sell(starting from 0)"<<endl;
								cin>>itemchoice;
								if((itemchoice>=harmors[i].size())||(itemchoice<0)){
									cout<<"Invalid Input.Try again!"<<endl;
								}
								else{
									value=harmors[i][itemchoice].getvalue();
									heroes[i]->changemoney(value/2.0);//o irwas kerdizei ta misa lefta apo thn aksia toy
									armorname=harmors[i][itemchoice].getname();
									harmors[i].erase(harmors[i].begin()+itemchoice);
									cout<<"The armor has removed from your inventory"<<endl;
									size=usearmors[i].size();
									for(j=0;j<size;j++){//elegxetai an to armor to foraei o irwas
										if(usearmors[i][j].getname()==armorname){//an to foraei afaireitai kai apto swma toy
											usearmors[i].erase(usearmors[i].begin()+j);
											cout<<"The armor has removed from your body";
											cout<<" also"<<endl;
										}
									}
								}
							}
							else if(change==3){
								if(hpotions[i].size()==0){
									cout<<"You dont have any more potions to sell"<<endl;
									continue;
								}
								checkpotions(hpotions[i],0);//ektypwnontai ta potion toy irwa
								cout<<"Type the number of the potion you want to sell(starting from 0)"<<endl;
								cin>>itemchoice;
								if((itemchoice>=hpotions[i].size())||(itemchoice<0)){
									cout<<"Invalid Input.Try again!"<<endl;
								}
								else{
									value=hpotions[i][itemchoice].getvalue();
									heroes[i]->changemoney(value/2.0);//o irwas kerdizei ta misa lefta apo tin aksia toy potion
									hpotions[i].erase(hpotions[i].begin()+itemchoice);//to potion sbinetai apo to vector toy irwa
									cout<<"The potion has removed from your inventory"<<endl;
								}
							}
							else if(change==4){
								if(hspells[i].size()==0){
									cout<<"You dont have any more spells to sell"<<endl;
									continue;
								}
								checkspells(hspells[i],0);
								cout<<"Type the number of the spell you want to sell"<<endl;
								cin>>itemchoice;
								if((itemchoice>=hspells[i].size())||(itemchoice<0)){
									cout<<"Invalid Input.Try again!"<<endl;
								}
								else{
									value=hspells[i][itemchoice].getvalue();
									heroes[i]->changemoney(value/2.0);//o irwas kerdizei ta misa lefta apo tin aksia toy spell
									hspells[i].erase(hspells[i].begin()+itemchoice);//to spell afaireitai apo ton irwa
									cout<<"The spell has removed from your inventory"<<endl;
								}
							}
							else if(change==5){
								displayMap(mikos,platos,H1->getthesimikos(),H1->getthesiplatos(),Grind);
							}
							else if(change==-1){
								cout<<"The game has terminated"<<endl;
								return 0;
							}
							else if((change<0)||(change>5)){
								cout<<"Invalid Input.Try again!"<<endl;
							}
						}
					}
					else if(epilogi==5){
						displayMap(mikos,platos,H1->getthesimikos(),H1->getthesiplatos(),Grind);//emfanizetai to plegma
					}
					else if(epilogi==6){
						viewinfo(heroes);//emfanizontai plirofories gia toys irwes
					}
					else if(epilogi==0){
						break;
					}
					else if(epilogi==-1){
						cout<<"The game has terminated"<<endl;
						delete M1;
						delete M2;
						return 0;
					}
					else{
						cout<<"Invalid Input.Try again!"<<endl;
					}
				}
			}
		}

	}	
	myfile.close();
	delete M1;
	delete M2;
	return 0;
}


void itemsmenu(vector<Weapon>& weapons,vector<Armor>& armors,vector<Potion>& potions,vector<Spell>& spells){
	unsigned int i;
	cout<<endl;
	cout<<endl;
	cout<<"ITEM'S MENU:"<<endl;
	cout<<endl;
	cout<<"The Weapons are:"<<endl;
	for(i=0;i<weapons.size();i++){//gia ola ta opla tis agoras ektypwnontai oi plirofories toys
		cout<<"Name:"<<weapons[i].getname()<<endl;
		cout<<"Value:"<<weapons[i].getvalue()<<endl;
		cout<<"Minimum level to use:"<<weapons[i].getminlvl()<<endl;
		cout<<"Damage:"<<weapons[i].getdmg()<<endl;
		cout<<"Amount of hands:"<<weapons[i].getamountofhands()<<endl;
	}
	cout<<endl;
	cout<<"The armors are:"<<endl;
	for(i=0;i<armors.size();i++){//gia ola ta armors ektypwnontai ta infos toys
		cout<<"Name:"<<armors[i].getname()<<endl;
		cout<<"Value:"<<armors[i].getvalue()<<endl;
		cout<<"Minimum level to use:"<<armors[i].getminlvl()<<endl;
		cout<<"Amount of reduced damage:"<<armors[i].getamountofreduceddmg()<<endl;
	}
	cout<<endl;
	cout<<"The potions are:"<<endl;
	for(i=0;i<potions.size();i++){//gia ola ta potion ektypwnontai ta infos toys
		cout<<"Name:"<<potions[i].getname()<<endl;
		cout<<"Value:"<<potions[i].getvalue()<<endl;
		cout<<"Minimum level to use:"<<potions[i].getminlvl()<<endl;
		cout<<"The increase rate is:"<<potions[i].getincreasedrate()<<endl;
		cout<<"The category is:"<<potions[i].getcategory()<<endl;
	}
	cout<<endl;
	cout<<"The Spells are:"<<endl;//gia ola ta spell ektypwnontai ta infos toys
	for(i=0;i<spells.size();i++){
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

void displayMap(int mikos,int platos,int mikospaixtwn,int platospaixtwn,char **Grind){//emfanisi toy plegmatos
	int i,j;
	cout<<endl;
	for(i=0;i<mikos;i++){//gia kathe grammi
		for(j=0;j<platos;j++){//gia kathe sthlh ektypwnontai oi plhrofories toy tetragwnoy
			cout<<"To tetragwno sth grammh "<<i<<" kai sthlh "<<j<<" einai ";
			if(Grind[i][j]=='n'){
				cout<<"nonAccessible"<<endl;
			}
			else if(Grind[i][j]=='m'){
				cout<<"market"<<endl;
			}
			else if(Grind[i][j]=='c'){
				cout<<"common"<<endl;
			}
			if((mikospaixtwn==i)&&(platospaixtwn==j)){//an oi irwes briskontai se ayto to tetragwno tote ektypwnetai
				cout<<"OI IRWES BRISKONTAI SE AYTO TO TETRAGWNO"<<endl;
			}
		}
	}
	
}

void viewinfo(vector <Hero*> heroes){
	unsigned int i;
	for(i=0;i<heroes.size();i++){
		cout<<"FOR THE ";
		if(i==0){
			cout<<"FIRST HERO:"<<endl;
		}
		else if(i==1){
			cout<<"SECOND HERO:"<<endl;
		}
		else if(i==2){
			cout<<"THIRD HERO:"<<endl;;
		}
		cout<<"Health is:"<<heroes[i]->gethealth()<<endl;
		cout<<"Strength is:"<<heroes[i]->getstrength()<<endl;
		cout<<"Magic power is:"<<heroes[i]->getmagicpower()<<endl;
		cout<<"Dexterity is:"<<heroes[i]->getdexterity()<<endl;
		cout<<"Agility is:"<<heroes[i]->getagility()<<endl;
		cout<<"Money are:"<<heroes[i]->getmoney()<<endl;
		cout<<"Current amount of used hands are:"<<heroes[i]->getusedhands()<<endl;
		cout<<"Current experience is:"<<heroes[i]->getxp()<<endl;
	}
	cout<<endl;
}

void displaystats(vector <Monster*> monsters){
	unsigned int i;
	for(i=0;i<2;i++){
		cout<<"FOR THE ";
		if(i==0){
			cout<<"FIRST MONSTER:"<<endl;
		}
		else if(i==1){
			cout<<"SECOND MONSTER:"<<endl;
		}
		cout<<"Health is:"<<monsters[i]->gethealth()<<endl;
	}
	cout<<endl;
}



