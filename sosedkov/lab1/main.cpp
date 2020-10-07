#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isBrackets(string s);
char readNextChar(string s);
int input();


// скобки::= А | B | ( скобки скобки )

int main() {
    int type = input();

    std::string line;   

    //File
    if(type == 1) {
        cin.ignore();
        ifstream infile ("file.txt");
        std::getline(infile, line);
    }
    //Terminal
    else if(type == 2) {
        cout << "Input string: \n"; 
        cin.ignore();
        getline(std::cin, line);
    }

    cout << "Current string: " << line << std::endl;
    bool result = isBrackets(line);

    if(result && ((int)readNextChar(line)==0)) {
        cout << line << " is a bracket\n";
    }

    else {
        cout << line << " is not a bracket\n";
    }
    
    return 0;
}

int input() { 
    cout << "Lab 1(16) -> скобки::= А | B | ( скобки скобки )\n";
    cout << "1) Input from file ('file.txt' by default)\n";
    cout << "2) Terminal input\n"; 
    cout << "Input type (1, 2): " << endl;
    
    int type = 0;
    do {
        cin >> type;
        if (cin.fail()) {
            cout << "Please enter an integer (1, 2)\n";
            cin.clear();
            cin.ignore();
        }     
    } while(type != 1 && type != 2);

    return type;
}

char readNextChar(string s) {
    static int str_size = s.size();
    static int index = 0;
    static string last_string = s;
    if(last_string != s) {
        str_size = s.size();
        index = 0;
        last_string = s;
    }

    while(s[index] == ' ' && index < str_size) {
        index++;
    }
    index++;
    return s[index-1];
}

bool isBrackets(string s) {
    char symbol;
    symbol = readNextChar(s);
    cout << "Read char: " << symbol << std::endl;
    if(symbol == 'A' || symbol == 'B') {
        cout << "Current char is " << symbol << ". Return true\n";
        return true;
    }
    else if(symbol == '(') {
        cout << "Current char == '('\n";
        cout << "Read first bracket\n";\

        bool firstBracket = isBrackets(s);

        cout << "Read second bracket\n";

        bool secondBracket = isBrackets(s);
        symbol = readNextChar(s);

        if(!firstBracket) {
            cout << "First bracket read error. Return false\n"; 
            return false;
        }
        if(!secondBracket) {
            cout << "Second bracket read error. Return false\n"; 
            return false;
        }
        if(symbol != ')') {
            cout << symbol << " Last char is not ')'. Return false\n"; 
            return false;
        }
        cout << "OK\n";
        return true;
    }
    cout << "Current char != 'A', 'B', '('. Return false\n";
    return false;
}