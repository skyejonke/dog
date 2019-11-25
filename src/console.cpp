#include "console.hpp"
using namespace std;


skyelib_h::toolkit toolkit3;
//Console Methods
void console::addCommand(command inpt) {
    commands.push_back(inpt);
}
command console::getCommand(int inpt) {
    return commands[inpt];
}
void console::interpretor(string inpt) {
    if (inpt != "") {
        vector<string> cmd = toolkit3.splitString(inpt);
        if (cmd[0] == "help") {
            help();
        }
        else if (cmd[0] == "get") {
            try {
                get(cmd[1]);
            }
            catch(logic_error) {
                get("");
            }
        }
        else if (cmd[0] == "look") {
            look(cmd[1]);
        }
        else if (cmd[0] == "tick") {
            tick();
        }
        else if (cmd[0] == "ask" || cmd[0] == "tell") {
            if (cmd.size() < 3) {
                cout << "Not enough arguments"
                     << endl;
            }
            else {
                ask(cmd[1],cmd[2]);
            }
        }
    }
}
void console::help() {
    for (unsigned int i = 0; i < commands.size(); i++) {
        command x = getCommand(i);
        cout << "Name: " << x.getName();
        cout << " | Command: " << x.getMatch() << endl;
        cout << x.getExplanation() << endl;
        cout << "---------------" << endl;
    }
}
void console::get(string nameInpt) {
    string newInpt = nameInpt;
    dog* doggie = new dog();
    if (newInpt == "") {
        doggie = new dog();
        cout << "Their breed is " << doggie->getBreed() << endl;
        cout << "What do you want to call it?" << endl;
        cin>>newInpt;
        cin.ignore(256, '\n');
    }
    while (newInpt == "all") {
        cout << "That's a silly name for a dog! Choose a different one: ";
        cin >> newInpt;
        cin.ignore(256, '\n');
    }
    doggie->setName(newInpt);
    dogs[newInpt] = doggie;

    cout << "Got dog " << newInpt << "!" << endl;
    cout << "It is a " << dogs[newInpt]->getBreed() << "." << endl;
    tick();
}
void console::look(string nameInpt) {
    cout << "Looking at " << nameInpt << "." << endl;
    if (dogs.count(nameInpt) >0) {
        cout << "It is a " << dogs[nameInpt]->getBreed() << "!" << endl;
        cout << dogs[nameInpt]->getAction()->getDescription()<<endl;
    }
    else {
        cout << "No such dog exists!" << endl;
    }
}

void console::tick() {
    map<string, dog*>::iterator currentDog = dogs.begin();
    for (unsigned int i = 0; i < dogs.size(); i++) {
        currentDog->second->setBusy(false);
        advance(currentDog, 1);
    }
    currentDog = dogs.begin();
    for (unsigned int i = 0; i < dogs.size(); i++) {
        if (!currentDog->second->getBusy()) {
            currentDog->second->startEvent(dogs);
        }
        advance(currentDog, 1);
    }
}
void console::ask(string nameInpt, string trick) {
    if (dogs.count(nameInpt) > 0) {
        if (trick == "sit") {
            dogs[nameInpt]->sit();
        }
    }
    else {
        cout << "No such dog exists!" << endl;
    }
}

int console::start() {
    while (1 == 1) {
        cout << ">";
        string cmd;
        getline(cin,cmd);
        if (cmd == "done") {
            cout << "Have a good day!" << endl;
            return 0;
        }
        interpretor(cmd);
    }
}

