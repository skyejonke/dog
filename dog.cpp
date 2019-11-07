#include <iostream>
#include "skyelib.hpp"
#include "dog.hpp"
#include <string>
#include <vector>
#include <map>
#include <iterator>


using namespace std;

skyelib_h::toolkit toolkit;


//Dog methods
void dog::bark(){
	cout << barkSound << endl;
}
void dog::setBark(string inpt){
	barkSound = inpt;
}
string dog::getBreed(){
	return breed;
}
dog::dog(string inpt){
	name=inpt;
	breeds = {"Pug","German Sheperd", "Pitbull", "Corgie", "Shiba Inu", "Shih Tzu", "Beagle", "Chow Chow", "Husky", "Foxhound", "Labrador Retreiver", "Golden Retriever", "Poodle", "Labradoodle", "Lorkshier Terrier", "Chihuahua", "Mutt", "Pekingese", "Great Dane", "Pointer", "Nova Scotia Duck Tolling Retreiver", "French Bulldog", "English Bulldog", "Australian Shepard", "Collie", "Dalmation", "Cockerspaniel", "King Charles Spaniel", "Dachsuchund", "Saint Bernard", "Portugese Water Dog", "Greyhound", "Bichon Frise", "Papillion", "Maltese", "Cane Corso", "Rottwieler"};
	breed = breeds[toolkit.getRand(0,breeds.size()-1)];
}
void dog::setBusy(bool status){
	busy = status;
}
bool dog::getBusy(){
	return busy;
}
string dog::getName(){
	return name;
}
void dog::setAction(event* eventIn){
//	busy = true;
	action = eventIn;
}
void dog::startEvent(map<string, dog*> allDogs){ //For beginning events
	map<string, dog*>::iterator currentDog = allDogs.begin(); // Create an iterator at the beginning of allDogs
	vector<dog*> participants;
	int maxSize = allDogs.size();
	currentDog = allDogs.begin();
	int nonbusy = 0;
	for (int i = 0; i < maxSize; i++){ //Get the number of dogs that aren't busy
		if (!currentDog->second->getBusy()){
			nonbusy++;
		}
		advance(currentDog,1);
	}
	if (nonbusy > 3){
		nonbusy = 3;
	}
	int random = toolkit.getRand(1,nonbusy);
	for (int i = 0; i < random; i++){	// Get a random number of dogs
		do{
			currentDog = allDogs.begin();
			advance(currentDog, toolkit.getRand(0,allDogs.size()-1)); // Get random dog from allDogs
		}
		while (currentDog->second->getBusy()); // Second gives you the "second" value in the map
		currentDog->second->setBusy(true);
		participants.push_back(currentDog->second);
	}
	event* even = new event(participants);
	for (dog* puppy : participants){
		puppy->setAction(even);
	}
	busy = true;
}
event* dog::getAction(){
	return action;
}
void dog::initDialog(){
	sitDialog = vector<string>();
	sitDialog.push_back("<dog> sits down.");
	sitDialog.push_back("<dog> runs around for a second, then sits down.");
	sitDialog.push_back("<dog> looks confused, but when you put your hand on their back they sit down.");
	sitDialog.push_back("<dog> looks confused.");
	sitDialog.push_back("<dog> proceeds to knock over a case of silverware.");
}
void dog::sit(){
	initDialog();
	int rando = toolkit.getRand(0,sitDialog.size()-1);
	string dia = sitDialog[rando];
	toolkit.replace(dia,"<dog>",name);
	cout << dia << endl;
}


//Command Methods
command::command(string nameInpt, string explanationInpt, string matchInpt){
	name = nameInpt;
	explanation = explanationInpt;
	match = matchInpt;
}
string command::getName(){
	return name;
}
string command::getExplanation(){
	return explanation;
}
string command::getMatch(){
	return match;
}

//Console Methods
void console::addCommand(command inpt){
	commands.push_back(inpt);
}
command console::getCommand(int inpt){
	return commands[inpt];
}
void console::interpretor(string inpt){
	if (inpt != ""){
		vector<string> cmd = toolkit.splitString(inpt);
		if (cmd[0] == "help"){
			help();
		}
		else if (cmd[0] == "get"){
			get(cmd[1]);
		}
		else if (cmd[0] == "look"){
			look(cmd[1]);
		}
		else if (cmd[0] == "tick"){
			tick();
		}
		else if (cmd[0] == "ask" || cmd[0] == "tell"){
			ask(cmd[1],cmd[2]);
		}
	}
}
void console::help(){
	for (unsigned int i = 0; i < commands.size();i++){
		command x = getCommand(i);
		cout << "Name: " << x.getName();
		cout << " | Command: " << x.getMatch() << endl;
		cout << x.getExplanation() << endl;
		cout << "---------------" << endl;
	}
}
void console::get(string nameInpt){
	while (nameInpt == "all"){
		cout << "That's a silly name for a dog! Choose a different one: ";
		cin >> nameInpt;
	}
	dogs[nameInpt] = new dog(nameInpt);
	cout << "Got dog " << nameInpt << "!" << endl;
	cout << "It is a " << dogs[nameInpt]->getBreed() << "." << endl;
	tick();
}
void console::look(string nameInpt){
	cout << "Looking at " << nameInpt << "." << endl;
	if (dogs.count(nameInpt) >0){
		cout << "It is a " << dogs[nameInpt]->getBreed() << "!" << endl;
		cout << dogs[nameInpt]->getAction()->getDescription()<<endl;
	}
	else{
		cout << "No such dog exists!" << endl;
	}
}

void console::tick(){
	map<string, dog*>::iterator currentDog = dogs.begin();
	for (unsigned int i = 0; i < dogs.size();i++){
		currentDog->second->setBusy(false);
		advance(currentDog, 1);
	}
	currentDog = dogs.begin();
	for (unsigned int i = 0; i < dogs.size();i++){
		if (!currentDog->second->getBusy()){
			currentDog->second->startEvent(dogs);
		}
		advance(currentDog, 1);
	}
}
void console::ask(string nameInpt, string trick){
	if (dogs.count(nameInpt) > 0){
		if (trick == "sit"){
			dogs[nameInpt]->sit();
		}
	}
	else{
		cout << "No such dog exists!" << endl;
	}
}

int console::start(){
	while (1 == 1){
		cout << ">";
		string cmd;
		getline(cin,cmd);
		if (cmd == "done"){
			cout << "Have a good day!" << endl;
			return 0;
		}
		interpretor(cmd);
	}
}


// Event Methods
vector<string> event::initDescriptions(int s){
	vector<string> ldescriptions;
	if (s == 0){
		ldescriptions.push_back("<dog1> is frolicking in the garden.");
		ldescriptions.push_back("<dog1> is chasing it's tail.");
		ldescriptions.push_back("<dog1> is barking.");
		ldescriptions.push_back("<dog1> is on your lap.");
		ldescriptions.push_back("<dog1> is wagging it's tail.");
		ldescriptions.push_back("<dog1> is licking it's balls.");
		ldescriptions.push_back("<dog1> is knocking over a wine glass with it's tail, spilling wine all over the floor.");
		ldescriptions.push_back("<dog1> is eating some dog food.");
		ldescriptions.push_back("<dog1> is eating your sandwich.");
		ldescriptions.push_back("<dog1> is swimming in the pool");
		ldescriptions.push_back("<dog1> is swimming in the pool");
	}
	else if (s == 1){
		ldescriptions.push_back("<dog1> is frolicking in the garden with <dog2>.");
		ldescriptions.push_back("<dog1> and <dog2> are barking at each other.");
		ldescriptions.push_back("<dog1> is chasing <dog2>'s tail.");
	}
	else if (s == 2){
		ldescriptions.push_back("<dog1>, <dog2>, and <dog3> are frolicking in the graden.");
		ldescriptions.push_back("<dog1>, <dog2>, and <dog3> are all barking at each other.");
		ldescriptions.push_back("<dog1> and <dog2> and pplaying with a ball while <dog3> looks sad.");
	}
	return ldescriptions;
}
event::event(vector<dog*> participantsIn){
	participants = participantsIn;
	int s = participants.size()-1;
	string replacements[3] =  {"<dog1>","<dog2>","<dog3>"};
	descriptions = initDescriptions(s);
	description = descriptions[toolkit.getRand(0,descriptions.size()-1)];
	for (int i = 0; i <= s; i++){
		toolkit.replace(description,replacements[i],participants[i]->getName());
	}
	for (int f = 0; f < s; f++){
		participants[f]->setAction(this);
	}
}


string event::getDescription(){
	return description;
}

//Main
int main(int argc, char* argv[]){
	//Initialization
	console terminal;
	command help = command("Help", "List commands", "help");
	command look = command("Look","Check on a dog", "look <dog>");
	command ask = command("Ask", "Request an action from a dog", "(ask|tell) <dog> <action>");
	command get = command("Get", "Aquire a new dog", "get <name>");
	command tick = command("Tick", "Go forward in time", "tick");
	terminal.addCommand(help);
	terminal.addCommand(get);
	terminal.addCommand(look);
	terminal.addCommand(ask);
	terminal.addCommand(tick);
	bool test = false;
	if (argc >= 1){
		try{
			if (string(argv[1])=="test"){
				test = true;
			}
		}
		catch(logic_error e){}
		if (test){
			terminal.interpretor("get Toby");
			terminal.interpretor("get Bob");
			terminal.interpretor("get Sam");
			terminal.interpretor("tick");
			terminal.interpretor("look Toby");
			for (int i = 0; i < 50; i++){
				terminal.interpretor("ask Toby sit");
			}
			return 0;
		}
	}
	return terminal.start();

}
