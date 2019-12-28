#include "dog.hpp"

using namespace std;
//Dog methods


skyelib_h::toolkit toolkit;

string dog::bark(bool capital) {
    string capsBarkSound = barkSound;
    capsBarkSound[0] = toupper(barkSound[0]);
    return (capital ? barkSound : capsBarkSound);
}
void dog::setBark(string inpt) {
    barkSound = inpt;
}
string dog::getBreed() {
    return breed;
}
float dog::getHunger() {
    return hunger;
}
dog::dog(string inpt, map<string,dog*> dogsInpt) {
    name=inpt;
    breed = breeds[toolkit.getRand(0,breeds.size()-1)];
    barkSound = barks[toolkit.getRand(0,barks.size()-1)];
    hunger = 100.0;
    dogs = dogsInpt;
}
dog::dog(string inpt) {
    name=inpt;
    breed = breeds[toolkit.getRand(0,breeds.size()-1)];
    barkSound = barks[toolkit.getRand(0,barks.size()-1)];
    hunger = 100.0;
}
dog::dog(map<string,dog*> dogsInpt) {
    breed = breeds[toolkit.getRand(0,breeds.size()-1)];
    barkSound = barks[toolkit.getRand(0,barks.size()-1)];
    hunger = 100.0;
    dogs = dogsInpt;
}
dog::dog() {
    breed = breeds[toolkit.getRand(0,breeds.size()-1)];
    barkSound = barks[toolkit.getRand(0,barks.size()-1)];
    hunger = 100.0;
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

void dog::hungry() {
    float val = hungerValues[toolkit.getRand(0,hungerValues.size()-1)];
    //float val = hungerValues[0];
    hunger -= val;
    if (hunger <= 0){
        cout << name << " is completely still!";
    }
    else if (hunger < 10){
        cout << name << " is lying next to it's food bowl" << endl;
    }
    else if (hunger < 30){
        cout << name << " is starting to whine." << endl;
    }
    else if (hunger < 50){
        cout << name << " is looking at you hopefully." << endl;
    }
}

void dog::feed() {
    float val;
    if (dogs.size() != 0){
        val = foodValues[
            toolkit.getRand(0,foodValues.size()-1)]
            * dogs.size();
    }
    else{
        val = foodValues[
            toolkit.getRand(0,foodValues.size()-1)];
    }
    if ((hunger + val ) >= 100){
        cout << name << " eats a bit, but is disinterested." << endl;
    }
    hunger = ((hunger + val > 100) ? 100 : (hunger + val));

    if (hunger <= 0){
        cout << name << " eats heartily and pines for more!" << endl;
    }
    else if (hunger <= 30){
        cout << name << " quickly eats the dog food looks at you hopefully" << endl;
    }
    else if (hunger <= 50){
        cout << name << " takes their time with the dog food and barks a bit." << endl;
    }
    else if (hunger <= 80){
        cout << name << " eats happily and looks content." << endl;
    }
    else if (hunger < 100 && val >= 5){
        cout << name << " considers for a bit, and then eats the food happily." << endl;
    }
    else if (hunger < 100 && val < 5){
        cout << name << " considers for a bit, and eats a small amount of food.";
    }
}

