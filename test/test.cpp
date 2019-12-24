#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "dog.hpp"
#include <string>
#include <vector>
#include <iostream>

using namespace std;
TEST_CASE("dogs can be created", "[dog]"){
	dog* testDog = new dog("Bob");
	REQUIRE(testDog->getName() == "Bob");
}
TEST_CASE("events can be created and play nice", "[event]"){
	vector<dog*> dogs;
	dogs.push_back(new dog("Lily"));
	dogs.push_back(new dog("Pico"));
	event* testevent = new event(dogs);
	REQUIRE(testevent->getDescription() != "");
	SECTION("Events have the right description between 2 dogs"){
	for (dog* pup : dogs){
			REQUIRE(pup->getAction()->getDescription() == testevent->getDescription());
		}
	}
	SECTION("Events have the right description between 3 dogs"){

		dogs.push_back(new dog("Augie"));
		testevent = new event(dogs);
		for (dog* pup : dogs){
			REQUIRE(pup->getAction()->getDescription() == testevent->getDescription());
		}
	}

}
