/*
ID: 
PROB: dualpal 
LANG: C++
*/

#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string decimalToBase(int number, int B);
bool isPalindrome(string str);
string reverseStr(string str);
char intToCharBase(int integer);
bool isDualpal(int number);

int main() {
    // Input
    ifstream fin("dualpal.in");
    int N, S;
    fin >> N >> S;
    fin.close();
    
    // Output
    ofstream fout("dualpal.out");
    int count = 0;
    for (int currentNum = S + 1; count < N; currentNum++) {
        if (isDualpal(currentNum)) {
            count++;
            fout << currentNum << std::endl;
        }
    }
    fout.close();
    
    return 0;
}

string decimalToBase(int number, int B) {
    /* Converts the decimal number to base B */
    
    string converted = "";
    
    if (B == 10) {
        stringstream ss;
        ss << number;
        ss >> converted;
    }
    else {
        int remainder;
        int quotient = number;
        do {
            remainder = quotient % B;
            quotient = quotient / B;
            converted += intToCharBase(remainder);
        } while (quotient);
        converted = reverseStr(converted); 
    }
    
    return converted;
}

bool isPalindrome(string str) {
    /* Judges whether the given string is a palindrome */
    
    int length = str.length();
    int middle = length / 2;
    for (int i = 0; i < middle; i++) {
        if (str[i] - str[length - 1 - i]) {
            return false;
        }
    }
    return true;
}

string reverseStr(string str) {
    /* Reverses a given string */
    
    int length = str.length();
    int middle = length / 2;
    for (int i = 0; i < middle; i++) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
    return str;
}

char intToCharBase(int integer) {
    /* Returns the converted integer to char */
    
    if (integer < 10) {
        return '0' + integer;
    }
    else {
        return 'A' + integer - 10;
    }
}

bool isDualpal(int number) {
    /* Judges whether the given number is palindromic when written in
    ** two or more number bases (2 <= base <= 10)
    */
    
    int count = 0;
    for (int base = 2; base <= 10; base++) {
        if (isPalindrome(decimalToBase(number, base))) {
            count++;
        }
        if (count == 2) {
            return true;
        }
    }
    return false;
}
