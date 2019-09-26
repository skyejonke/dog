#ifndef dog_h
#define dog_h
#include <string>
#include <iostream>
#include <vector>
#include <map>


class dog{
	public:
		dog(std::string inpt);
		void bark();
		bool setBark(std::string inpt);
		std::string getBreed();
		void setRandBreed();
		std::string getAction();
		int getActionNumber();
		bool getBusy();
		void setBusy(bool status);
	private:
		std::string barkSound;
		std::string name;
		std::string breed;
		std::vector<std::string> breeds;
		std::vector<std::string> actions;
		std::string action;
		int actionNumber;
		bool busy;
};

class event{
	public:
		std::vector<dog> getParticipants();
		std::string getDescription();
		event(std::map<std::string, dog*> allDogs);
	private:
		std::string description;
		std::vector<dog*> participants;
};
class command{
	public:
		command(std::string nameInpt, std::string explanationInpt, std::string matchInpt);
		std::string getName();
		std::string getExplanation();
		std::string getMatch();
	private:
		std::string name = "error";
		std::string explanation = "error";
		std::string match = "error";
};

class console{
	private:
		std::vector<command> commands;
		std::map<std::string, dog*> dogs;
	public:
		void interpretor(std::string inpt);
		void addCommand(command inpt);
		void help();
		void look(std::string nameInpt);
		void get(std::string nameInpt);
		command getCommand(int inpt);
		
		

		
};

#endif
