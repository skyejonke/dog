#include <iostream>
#include "skyelib/skyelib.h"
#include "dog.h"
#include <string>
#include <vector>
#include <map>
using namespace std;
skyelib_h::toolkit toolkit;
//Dog methods
void dog::bark(){
cout << barkSound << endl;
}
bool dog::setBark(string inpt){
barkSound = inpt;
}
string dog::getBreed(){
	return breed;
}
dog::dog(string inpt){
	name=inpt;
	breeds = {"Pug","German Sheperd", "Pitbull", "Corgie", "Shiba Inu", "Shih Tzu", "Beagle", "Chow Chow", "Husky", "Foxhound", "Labrador Retreiver", "Golden Retriever", "Poodle", "Labradoodle", "Lorkshier Terrier", "Chihuahua", "Mutt", "Pekingese", "Great Dane", "Pointer", "Nova Scotia Duck Tolling Retreiver", "French Bulldog", "English Bulldog", "Australian Shepard", "Collie", "Dalmation", "Cockerspaniel", "King Charles Spaniel", "Dachsuchund", "Saint Bernard", "Portugese Water Dog", "Greyhound", "Bichon Frise", "Papillion", "Maltese", "Cane Corso", "Rottwieler"};
	breed = breeds[toolkit.getRand(0,breeds.size()-1)];
	actions = {"barking","running"};
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
	dogs[nameInpt] = new dog(nameInpt);
	cout << "Got dog " << nameInpt << "!" << endl;
	cout << "It is a " << dogs[nameInpt]->getBreed() << "." << endl;
}
void console::look(string nameInpt){
	cout << "Looking at " << nameInpt << "." << endl;
	if (dogs.count(nameInpt) >0){
		cout << "It is a " << dogs[nameInpt]->getBreed() << "!" << endl;
	}
	else{
		cout << "No such dog exists!" << endl;
	}
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

	while (1 == 1){
		cout << ">";
		string cmd;
		getline(cin,cmd);
		if (cmd == "done"){
			cout << "Have a good day!" << endl;
			break;
		}
		terminal.interpretor(cmd);
	}
}
