/*
ID: 
PROB: combo
LANG: C++
*/

#include <fstream>

using namespace std;


struct Combination {
    int first;
    int second;
    int third;
    
    bool isDigitCloseEnoughTo(int digit1, int digit2, int N) {
        int bigger, smaller;
        if (digit1 < digit2) {
            bigger = digit2;
            smaller = digit1;
        }
        else {
            bigger = digit1;
            smaller = digit2;
        }
        
        if (bigger - smaller <= 2) {
            return true;
        }
        else {
            if (bigger == N) {
                if ((smaller == 1) || (smaller == 2)) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else if (bigger == N - 1) {
                if (smaller == 1) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
    }
    
    bool isCloseEnoughTo(Combination combination, int N) {
        return isDigitCloseEnoughTo(this->first, combination.first, N) 
            && isDigitCloseEnoughTo(this->second, combination.second, N) 
            && isDigitCloseEnoughTo(this->third, combination.third, N);
    }
};

bool next_combination(Combination &combination, int N);

int main() {
    // Input
    ifstream fin("combo.in");
    int N;
    fin >> N;
    Combination farmerCombination, masterCombination;
    fin >> farmerCombination.first >> farmerCombination.second >> farmerCombination.third;
    fin >> masterCombination.first >> masterCombination.second >> masterCombination.third;
    fin.close();
    
    // Count the number of all the feasible solutions
    Combination currentCombination = { first: 1, second: 1, third: 1 };
    int count = 0;
    do {
        if (currentCombination.isCloseEnoughTo(farmerCombination, N) || currentCombination.isCloseEnoughTo(masterCombination, N)) {
            count++;
        }
    } while (next_combination(currentCombination, N));
    
    // Output
    ofstream fout("combo.out");
    fout << count << endl;
    fout.close();
    
    return 0;
}

bool next_combination(Combination &combination, int N) {
    if (combination.third == N) {
        if (combination.second == N) {
            if (combination.first == N) {
                combination.first = combination.second = combination.third = 1;
                return false;
            }
            else {
                combination.first++;
                combination.second = combination.third = 1;
            }
        }
        else {
            combination.second++;
            combination.third = 1;
        }
    }
    else {
        combination.third++;
    }
    
    return true;
}
