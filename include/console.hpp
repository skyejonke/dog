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
		bool interpretor(std::string inpt);
		void addCommand(command inpt);
		void help();
		bool look(std::string nameInpt);
		void get(std::string nameInpt);
		command getCommand(int inpt);
		void tick();
		int start();
		void ask(std::string trick, std::string nameInpt);
		void feed(std::string nameInpt);
};

#endif
