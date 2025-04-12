#include <iostream>
#include <fstream>
#include <sstream>
#include "PlaylistManager.h"

using namespace std;

int main() {
    PlaylistManager pm;

    ifstream input("songs.txt");
    ofstream output("output.txt"); 
    
    if (!input.is_open()) {
        cerr << "Error opening input file" << endl;
        return 1;
    }
    
    if (!output.is_open()) {
        cerr << "Error opening output file" << endl;
        return 1;
    }
    
    string line;
    while (getline(input, line)) {
        if (line.empty() || line[0] == '/' || line[0] == ' ') // Skip comments or empty lines
            continue;
            
        istringstream iss(line);
        string command;
        iss >> command;

        if (command == "ADD") {
            int preference, duration;
            string name;
            iss >> preference >> duration >> name;
            Song song{preference, duration, name};
            pm.addSong(song);
        } else if (command == "PLAY") {
            pm.play(output);
        } else if (command == "SKIP") {
            int seconds;
            iss >> seconds;
            pm.skip(seconds, output);
        } else if (command == "REPLAY") {
            pm.replay(output);
        } else if (command == "REMOVE") {
            string name;
            iss >> name;
            Song song{0, 0, name};  
            pm.removeSong(song, output);
        } else if (command == "SHOW") {
            pm.show(output);
        } else if (command == "HISTORY") {
            pm.displayHistory(output);
        }
    }
    
    input.close();
    output.close();
    return 0;
}
