/*
ID: 
PROB: crypt1
LANG: C++
*/

#include <fstream>
#include <algorithm> // For std::fill, std::find

using namespace std;

bool next_enumeration(int* p_begin, int* p_end, int* digit_begin, int* digit_end);

int main() {
    // Input
    ifstream fin("crypt1.in");
    int N, availableDigits[9];
    fin >> N;
    for (int i = 0; i < N; i++) {
        fin >> availableDigits[i];
    }
    fin.close();
    
    // Traverse all the possible situations and count the feasible solutions
    int count = 0;
    int currentEnumeration[5];
    fill(currentEnumeration, currentEnumeration + 5, availableDigits[0]);
    // The first partial product p1, the second partial product p2, the final product p
    int p1[3], p2[3], p[4];
    do {
        // Translate the current enumeration into the form of abc * de
        int a = currentEnumeration[0];
        int b = currentEnumeration[1];
        int c = currentEnumeration[2];
        int d = currentEnumeration[3];
        int e = currentEnumeration[4];
        
        if ((a * e + (b * e + (c * e) / 10) / 10) / 10) {
            continue;
        }
        if ((a * d + (b * d + (c * d) / 10) / 10) / 10) {
            continue;
        }
        p1[2] = (c * e) % 10;
        p1[1] = (b * e + (c * e) / 10) % 10;
        p1[0] = (a * e + (b * e + (c * e) / 10) / 10) % 10;
        p2[2] = (c * d) % 10;
        p2[1] = (b * d + (c * d) / 10) % 10;
        p2[0] = (a * d + (b * d + (c * d) / 10) / 10) % 10;
        if ((p2[0] + ((p1[0] + p2[1]) + (p1[1] + p2[2]) / 10) / 10) / 10) {
            continue;
        }
        else {
            p[0] = (p2[0] + ((p1[0] + p2[1]) + (p1[1] + p2[2]) / 10) / 10) % 10;
            p[1] = ((p1[0] + p2[1]) + (p1[1] + p2[2]) / 10) % 10;
            p[2] = (p1[1] + p2[2]) % 10;
            p[3] = p1[2];
            int usedDigits[15] = { a, b, c, d, e, p1[0], p1[1], p1[2], p2[0], p2[1], p2[2], p[0], p[1], p[2], p[3] };
            bool isSolution = true;
            for (int i = 0; i < 15; i++) {
                if (find(availableDigits, availableDigits + N, usedDigits[i]) == availableDigits + N) {
                    isSolution = false;
                    break;
                }
            } 
            if (isSolution) {
                count++;
            }
        }
    } while (next_enumeration(currentEnumeration, currentEnumeration + 5, availableDigits, availableDigits + N));
    
    // Output
    ofstream fout("crypt1.out");
    fout << count << endl;
    fout.close();
    
    return 0;
}

bool next_enumeration(int* p_begin, int* p_end, int* digit_begin, int* digit_end) {
    int* pointer = p_end - 1;
    while (true) {
        if (find(digit_begin, digit_end, *pointer) != digit_end - 1) {
            *pointer = *(find(digit_begin, digit_end, *pointer) + 1); 
            
            return true;
        }
        else {
            if (pointer == p_begin) {
                fill(p_begin, p_end, *digit_begin);
                
                return false;
            }
            else {
                *pointer = *digit_begin;
                pointer--;
            }
        }
    }
    
    return false;
}
