/*
ID: 
PROB: skidesign 
LANG: C++
*/

#include <fstream>
#include <algorithm> // For std::sort

using namespace std;

int main() {
    // Input
    ifstream fin("skidesign.in");
    int N, hills[1000];
    fin >> N;
    for (int i = 0; i < N; i++) {
        fin >> hills[i];
    }
    fin.close();
    
    // Output
    ofstream fout("skidesign.out");
    int initialHills[1000];
    for (int i = 0; i < N; i++) {
        initialHills[i] = hills[i];
    }
    sort(initialHills, initialHills + N);
    
    int maxDiff = 17;
    sort(hills, hills + N);
    int min = hills[0];
    int max = hills[N - 1];
    int minimalTotalCost = 0;
    if (max - min > maxDiff) {
        for (int i = 0; i < max - min - maxDiff; i++) {
            // Make the current crop
            int modifiedMin = min + i;
            int modifiedMax = modifiedMin + maxDiff;
            for (int j = 0; j < N; j++) {
                if (hills[j] < modifiedMin) {
                    hills[j] = modifiedMin;
                }
                else if (hills[j] > modifiedMax) {
                    hills[j] = modifiedMax;
                }
            }
            
            // Calculate the total cost of this crop
            int totalCost = 0;
            for (int i = 0; i < N; i++) {
                totalCost += (initialHills[i] - hills[i]) * (initialHills[i] - hills[i]);
            }
        
            // Recover the hills
            for (int i = 0; i < N; i++) {
                hills[i] = initialHills[i];
            }
        
            if (minimalTotalCost == 0) {
                minimalTotalCost = totalCost; 
            }
            else if (minimalTotalCost > totalCost) {
                minimalTotalCost = totalCost;
            }
        }
    }
    fout << minimalTotalCost << endl;
    fout.close();
    
    return 0;
}

