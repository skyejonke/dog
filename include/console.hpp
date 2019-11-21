#ifndef console_h
#define console_h
#include <string>
#include <iostream>
#include <vector>
#include "command.hpp"
#include "dog.hpp"
#include "event.hpp"
#include <map>

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
		int start();
		void ask(std::string trick, std::string nameInpt);
};

#endif
