#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    unordered_map<string, string> dictionary;

    string line;
    while (getline(cin, line) && !line.empty()) {
        size_t space_pos = line.find(' ');
        if (space_pos != string::npos) {
            string english_word = line.substr(0, space_pos);
            string foreign_word = line.substr(space_pos + 1);
            dictionary[foreign_word] = english_word;
        }
    }

    while (getline(cin, line)) {
        if (line.empty()) {
            break; 
        }

        if (dictionary.find(line) != dictionary.end()) {
            cout << dictionary[line] << endl;
        } else {
            cout << "eh" << endl;
        }
    }

    return 0;
}
