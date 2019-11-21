#include "dog.hpp"
using namespace std;
//Command Methods
command::command(string nameInpt, string explanationInpt, string matchInpt) {
    name = nameInpt;
    explanation = explanationInpt;
    match = matchInpt;
}
string command::getName() {
    return name;
}
string command::getExplanation() {
    return explanation;
}
string command::getMatch() {
    return match;
}

