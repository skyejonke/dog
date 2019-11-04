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
	busy = true;
	action = eventIn;
}
void dog::startEvent(map<string, dog*> allDogs){
	map<string, dog*>::iterator currentDog = allDogs.begin(); // Create an iterator at the beginning of allDogs
	vector<dog*> participants;
	int maxSize = allDogs.size();
	if (maxSize > 3){
		maxSize = 3;
	}
	int random = toolkit.getRand(1,maxSize);
	for (int i = 0; i < random; i++){	// Get a random number of dogs

		do{
			currentDog = allDogs.begin();
			advance(currentDog, toolkit.getRand(0,allDogs.size()-1)); // Get random dog from allDogs
			cout << currentDog->second->getName() << endl;
		}
		while (currentDog->second->getBusy()); // Second gives you the "second" value in the map
		currentDog->second->setBusy(true);
		wait 10;
		participants.push_back(currentDog->second);
	}
	action = new event(participants);
	busy = true;
}

event* dog::getAction(){
	return action;
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
	}
}
void console::help(){
	for (int i = 0; i < commands.size();i++){
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
void console::makeEvent(map<string, dog*> allDogs){
	map<string, dog*>::iterator currentDog = allDogs.begin(); // Create an iterator at the beginning of allDogs
	vector<dog*> participants;
	int maxSize = allDogs.size();
	if (maxSize > 3){
		maxSize = 3;
	}
	for (int i = 0; i < toolkit.getRand(1,maxSize); i++){	// Get a random number of dogs
		do{
			currentDog = allDogs.begin();
			advance(currentDog, toolkit.getRand(0,allDogs.size()-1)); // Get random dog from allDogs
		}
		while (!currentDog->second->getBusy()); // Second gives you the "second" value in the map
		participants.push_back(currentDog->second);
	}
}
void console::tick(){
	map<string, dog*>::iterator currentDog = dogs.begin();
	for (int i = 0; i < dogs.size();i++){
		currentDog->second->setBusy(false);
		advance(currentDog, 1);
	}
	currentDog = dogs.begin();
	for (int i = 0; i < dogs.size();i++){
		if (!currentDog->second->getBusy()){
			currentDog->second->startEvent(dogs);
		}
		advance(currentDog, 1);
	}
}


// Event Methods
vector<string> event::initDescriptions(int s){
	vector<string> ldescriptions;
	if (s == 0){
		ldescriptions.push_back("<dog1> is frolicking in the garden.");
	}
	else if (s == 1){
		ldescriptions.push_back("<dog1> is frolicking in the garden with <dog2>.");
	}
	else if (s == 2){
	//	ldescriptions[0].push_back("<dog1>, <dog2>, and <dog> are frolicking in the graden.");
	}
	return ldescriptions;
}
event::event(vector<dog*> participantsIn){
	participants = participantsIn;
	int s = participants.size()-1;
	string replacements[3] =  {"<dog1>","<dog2>","<dog3>"};
	descriptions = initDescriptions(s);
	description = descriptions[0];//toolkit.getRand(0,descriptions.size())];
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
int main(){
	//Initialization
	console terminal;
	command help = command("Help","List commands", "help");
	command ask = command("Ask", "Request an action from a dog", "ask <dog> <action>");
	command get = command("Get", "Aquire a new dog", "get <name>");
	terminal.addCommand(help);
	terminal.addCommand(ask);
	terminal.addCommand(get);
	terminal.interpretor("get Toby");
	terminal.interpretor("get Bob");
	terminal.interpretor("tick");
	terminal.interpretor("look Toby");

/*
	while (1 == 1){
		cout << ">";
		string cmd;
		getline(cin,cmd);
		if (cmd == "done"){
			cout << "Have a good day!" << endl;
			return 0;
		}
		terminal.interpretor(cmd);
	}
	*/
}
