#ifndef dog_h
#define dog_h
#include <string>
#include <iostream>
#include <vector>
#include <map>

class event;

class dog{
	public:
		dog(std::string inpt);
		void bark();
		void setBark(std::string inpt);
		std::string getBreed();
		void setRandBreed();
		event* getAction();
		void setAction(event* eventIn);
		int getActionNumber();
		bool getBusy();
		void setBusy(bool status);
		std::string getName();
		void startEvent(std::map<std::string, dog*> allDogs);
	private:
		std::string barkSound;
		std::string name;
		std::string breed;
		std::vector<std::string> breeds;
		std::vector<std::string> actions;
		event* action;
		int actionNumber;
		bool busy;
};

class event{
	private:
		std::string description;
		std::vector<std::string> descriptions;
		std::vector<dog*> participants;
		std::vector<std::string> initDescriptions(int s);
	public:
		std::vector<dog*> getParticipants();
		std::string getDescription();
		event(std::vector<dog*> participants);

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
		void tick();




};

#endif
