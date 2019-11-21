#ifndef event_h
#define event_h
#include <string>
#include <iostream>
#include <vector>
#include "command.hpp"
#include "dog.hpp"
#include <map>
class dog;

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

#endif // event_h
