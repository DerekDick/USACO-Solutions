/*
ID: 
PROB: namenum
LANG: C++
*/

#include <fstream>
#include <map>
#include <string>

using namespace std;

char letterMappedToNumber(char letter);

int main() {
    // Input
    ifstream fin("namenum.in");
    string numStr;
    fin >> numStr;
    fin.close();
    
    // Output
    ofstream fout("namenum.out");
    // Input the dictionary
    map<string, string> dict = map<string, string>();
    ifstream dictFile("dict.txt");
    string currentName = "";
    bool isExisting = false;
    while (dictFile >> currentName) {
        int length = currentName.length();
        if (length == numStr.length()) {
            string currentNum = "";
            for (int i = 0; i < length; i++) {
                currentNum += letterMappedToNumber(currentName[i]);
            }
            if (currentNum == numStr) {
                fout << currentName << endl;
                isExisting = true;
            }
        }
    }
    dictFile.close();
    if (!isExisting) {
        fout << "NONE" << endl;
    }
    fout.close();
    
    return 0;
} 

char letterMappedToNumber(char letter) {
    /* Returns the number mapped from the given letter */
    
    switch (letter) {
        case 'A': case 'B': case 'C':
            return '2';
            break;
            
        case 'D': case 'E': case 'F':
            return '3';
            break;
            
        case 'G': case 'H': case 'I':
            return '4';
            break;
            
        case 'J': case 'K': case 'L':
            return '5';
            break;
            
        case 'M': case 'N': case 'O':
            return '6';
            break;
            
        case 'P': case 'R': case 'S':
            return '7';
            break;
            
        case 'T': case 'U': case 'V':
            return '8';
            break;
            
        case 'W': case 'X': case 'Y':
            return '9';
            break;
            
        default:
            return '\0';
            break;
    }
}
