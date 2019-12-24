#include "dog.hpp"

using namespace std;
//Dog methods


skyelib_h::toolkit toolkit;

void dog::bark() {
    cout << barkSound << endl;
}
void dog::setBark(string inpt) {
    barkSound = inpt;
}
string dog::getBreed() {
    return breed;
}
dog::dog(string inpt) {
    name=inpt;
    breed = breeds[toolkit.getRand(0,breeds.size()-1)];
}
dog::dog() {
    breed = breeds[toolkit.getRand(0,breeds.size()-1)];
}
void dog::setBusy(bool status) {
    busy = status;
}
bool dog::getBusy() {
    return busy;
}
void dog::setName(string nameIn) {
    name = nameIn;
}
string dog::getName() {
    return name;
}
void dog::setAction(event* eventIn) {
//	busy = true;
    action = eventIn;
}
void dog::startEvent(map<string, dog*> allDogs) { //For beginning events
    map<string, dog*>::iterator currentDog = allDogs.begin(); // Create an iterator at the beginning of allDogs
    vector<dog*> participants;
    int maxSize = allDogs.size();
    currentDog = allDogs.begin();
    int nonbusy = 0;
    for (int i = 0; i < maxSize; i++) { //Get the number of dogs that aren't busy
        if (!currentDog->second->getBusy()) {
            nonbusy++;
        }
        advance(currentDog,1);
    }
    if (nonbusy > 3) {
        nonbusy = 3;
    }
    int random = toolkit.getRand(1,nonbusy);
    for (int i = 0; i < random; i++) {	// Get a random number of dogs
        do {
            currentDog = allDogs.begin();
            advance(currentDog, toolkit.getRand(0,allDogs.size()-1)); // Get random dog from allDogs
        }
        while (currentDog->second->getBusy()); // Second gives you the "second" value in the map
        currentDog->second->setBusy(true);
        participants.push_back(currentDog->second);
    }
    event* even = new event(participants);
    for (dog* puppy : participants) {
        puppy->setAction(even);
    }
    busy = true;
}
event* dog::getAction() {
    return action;
}
void dog::initDialog() {
    sitDialog = vector<string>();
    sitDialog.push_back("<dog> sits down.");
    sitDialog.push_back("<dog> runs around for a second, then sits down.");
    sitDialog.push_back("<dog> looks confused, but when you put your hand on their back they sit down.");
    sitDialog.push_back("<dog> looks confused.");
    sitDialog.push_back("<dog> proceeds to knock over a case of silverware.");
}
void dog::sit() {
    initDialog();
    int rando = toolkit.getRand(0,sitDialog.size()-1);
    string dia = sitDialog[rando];
    toolkit.replace(dia,"<dog>",name);
    cout << dia << endl;
}


