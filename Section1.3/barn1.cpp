/*
ID: 
PROB: barn1 
LANG: C++
*/

#include <fstream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    // Input
    ifstream fin("barn1.in");
    int M, S, C;
    fin >> M >> S >> C;
    int occupiedStalls[200];
    for (int i = 0; i < C; i++) {
        fin >> occupiedStalls[i];
    }
    fin.close();
    
    // Output
    ofstream fout("barn1.out");
    int totalLength;
    // Sort occupiedStalls first
    std::sort(occupiedStalls, occupiedStalls + C);
    if (M == 1) {
        totalLength = occupiedStalls[C - 1] - occupiedStalls[0] + 1;
    }
    else {
        if (C == 1) {
            totalLength = 1;
        }
        else {
            // Calculate the intervals
            map<int, int> intervalsMap = map<int, int>();
            int currentInterval;
            for (int i = 1; i <= C - 1; i++) {
                currentInterval = occupiedStalls[i] - occupiedStalls[i - 1] - 1;
                if (intervalsMap.find(currentInterval) != intervalsMap.end()) {
                    intervalsMap[currentInterval]++;
                }
                else {
                    intervalsMap[currentInterval] = 1;
                }
            }
        
            // Select the intervals to be omitted and calculate the total length needed
            int intervalsToOmitCount = 0;
            totalLength = occupiedStalls[C - 1] - occupiedStalls[0] + 1;
            for (map<int, int>::reverse_iterator reverseIter = intervalsMap.rbegin(); reverseIter != intervalsMap.rend(); reverseIter++) {
                if (reverseIter->second >= M - 1 - intervalsToOmitCount) {
                    totalLength -= (M - 1 - intervalsToOmitCount) * reverseIter->first;
                    break;
                }
                else {
                    totalLength -= reverseIter->second * reverseIter->first;
                    intervalsToOmitCount += reverseIter->second;
                }
            }
        }
    }
    fout << totalLength << std::endl;
    fout.close();
    
    return 0;
}
