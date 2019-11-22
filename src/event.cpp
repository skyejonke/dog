#include "dog.hpp"
using namespace std;
skyelib_h::toolkit toolkit2;
// Event Methods
vector<string> event::initDescriptions(int s) {
    vector<string> ldescriptions;
    if (s == 0) {
        ldescriptions.push_back("<dog1> is frolicking in the garden.");
        ldescriptions.push_back("<dog1> is chasing it's tail.");
        ldescriptions.push_back("<dog1> is barking.");
        ldescriptions.push_back("<dog1> is on your lap.");
        ldescriptions.push_back("<dog1> is wagging it's tail.");
        ldescriptions.push_back("<dog1> is licking it's balls.");
        ldescriptions.push_back("<dog1> is knocking over a wine glass with it's tail, spilling wine all over the floor.");
        ldescriptions.push_back("<dog1> is eating some dog food.");
        ldescriptions.push_back("<dog1> is eating your sandwich.");
        ldescriptions.push_back("<dog1> is swimming in the pool");
        ldescriptions.push_back("<dog1> is swimming in the pool");
    }
    else if (s == 1) {
        ldescriptions.push_back("<dog1> is frolicking in the garden with <dog2>.");
        ldescriptions.push_back("<dog1> and <dog2> are barking at each other.");
        ldescriptions.push_back("<dog1> is chasing <dog2>'s tail.");
    }
    else if (s == 2) {
        ldescriptions.push_back("<dog1>, <dog2>, and <dog3> are frolicking in the graden.");
        ldescriptions.push_back("<dog1>, <dog2>, and <dog3> are all barking at each other.");
        ldescriptions.push_back("<dog1> and <dog2> and pplaying with a ball while <dog3> looks sad.");
    }
    return ldescriptions;
}
event::event(vector<dog*> participantsIn) {
    participants = participantsIn;
    int s = participants.size()-1;
    string replacements[3] =  {"<dog1>","<dog2>","<dog3>"};
    descriptions = initDescriptions(s);
    description = descriptions[toolkit2.getRand(0,descriptions.size()-1)];
    for (int i = 0; i <= s; i++) {
        toolkit2.replace(description,replacements[i],participants[i]->getName());
    }
    for (int f = 0; f < s+1; f++) {
        participants[f]->setAction(this);
    }
}


string event::getDescription() {
    return description;
}

