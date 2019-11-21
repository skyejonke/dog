#include "main.hpp"
//#include <yaml-cpp.h>


using namespace std;



//Main
int main(int argc, char* argv[]) {
    //Initialization
    console terminal;
    command help = command("Help", "List commands", "help");
    command look = command("Look","Check on a dog", "look <dog>");
    command ask = command("Ask", "Request an action from a dog", "(ask|tell) <dog> <action>");
    command get = command("Get", "Aquire a new dog", "get");
    command tick = command("Tick", "Go forward in time", "tick");
    terminal.addCommand(help);
    terminal.addCommand(get);
    terminal.addCommand(look);
    terminal.addCommand(ask);
    terminal.addCommand(tick);
    bool test = false;
    if (argc >= 1) {
        try {
            if (string(argv[1])=="test") {
                test = true;
            }
        }
        catch(logic_error e) {}
        if (test) {
            terminal.interpretor("get Toby");
            terminal.interpretor("get Bob");
            terminal.interpretor("get Sam");
            terminal.interpretor("get");
            terminal.interpretor("tick");
            terminal.interpretor("look Toby");
            for (int i = 0; i < 50; i++) {
                terminal.interpretor("ask Toby sit");
            }
            return 0;
        }
    }
    return terminal.start();

}
