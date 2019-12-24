#ifndef dog_h
#define dog_h
#include <string>
#include <iostream>
#include <vector>
#include "command.hpp"
#include "skyelib.hpp"
#include "event.hpp"
#include <map>


class dog{
	public:
		dog(std::string inpt);
		dog();
		void bark();
		void setBark(std::string inpt);
		std::string getBreed();
		void setRandBreed();
		event* getAction();
		void setAction(event* eventIn);
		bool getBusy();
		void setBusy(bool status);
		void setName(std::string nameIn);
		std::string getName();
		void startEvent(std::map<std::string, dog*> allDogs);
		void sit();
		void initDialog();
	private:

		std::vector<std::string> breeds = {"Pug","German Sheperd", "Pitbull",
		"Corgie", "Shiba Inu", "Shih Tzu", "Beagle", "Chow Chow", "Husky",
		"Foxhound", "Labrador Retreiver", "Golden Retriever", "Poodle",
		"Labradoodle", "Lorkshier Terrier", "Chihuahua", "Mutt", "Pekingese",
		"Great Dane", "Pointer", "Nova Scotia Duck Tolling Retreiver", "French Bulldog",
		"English Bulldog", "Australian Shepard", "Collie", "Dalmation",
		"Cockerspaniel", "King Charles Spaniel", "Dachsuchund", "Saint Bernard",
		"Portugese Water Dog", "Greyhound", "Bichon Frise", "Papillion", "Maltese",
		"Cane Corso", "Rottwieler"}; 

		std::string barkSound;
		std::string name;
		std::string breed;
		std::vector<std::string> actions;
		event* action;
		bool busy;
		std::vector<std::string> sitDialog;
};






#endif
