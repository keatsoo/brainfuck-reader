#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<int> memory{1000, 0};
    int ptr{500};

    string filedir;
    ifstream fs;

    string code;

    cout << "What's your file? \n";
    cin >> filedir;

    fs.open(filedir);
    
    while (fs) {
        char myChar = fs.get();
        code += myChar;
    }

    for (int i{0}; i < code.size(); i++) {
        switch (code.at(i)) {
            case '>':
                ++ptr;
                break;
            case '<':
                --ptr;
                break;
            case '+':
                ++memory[ptr];
                break;
            case '-':
                --memory[ptr];
                break;
            case '.':
                cout << static_cast<char>(memory[ptr]);
                break;
            case ',':
                cerr << "INPUT NOT SUPPORTED YET! \n";
                break;
            case '[':
                if (memory[ptr] == '0') {
                    i = code.find(']', i) + 1;
                }
                break;
            case ']':
                i = code.find('[') + 1;
                break;
        }
    }
    return 0;
}
