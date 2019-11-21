#ifndef command_h
#define command_h
#include <string>
#include <iostream>
#include <vector>
#include <map>

class command{
	public:
		command(const std::string nameInpt, const std::string explanationInpt, const std::string matchInpt);
		std::string getName();
		std::string getExplanation();
		std::string getMatch();
	private:
		std::string name = "error";
		std::string explanation = "error";
		std::string match = "error";
};
#endif
