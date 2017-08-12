/*
ID: 
PROB: ariprog
LANG: C++
*/

#include <fstream>
#include <algorithm> // For std::fill

using namespace std;

int main() {
    // Input
    ifstream fin("ariprog.in");
    int N, M;
    fin >> N >> M;
    fin.close();
    
    // Generate the bisquare set
    bool bisquaresSet[1000000];
    fill(bisquaresSet, bisquaresSet + 1000000, false);
    for (int i = 0; i <= M; i++) {
        for (int j = 0; j <= M; j++) {
            bisquaresSet[i*i + j*j - 1] = true;
        }
    }
    
    // Output
    ofstream fout("ariprog.out");
    int largestBisquare = 2 * M * M;
    int b = 1;
    bool hasAnswer = false;
    do {
        int end = largestBisquare - b * (N - 1);
        for (int begin = 0; begin <= end; begin++) {
            bool isFeasible = true;
            for (int i = 0; i < N; i++) {
                if (!bisquaresSet[begin + b * i - 1]) {
                    isFeasible = false;
                    break;
                }
            }
            
            // If the sequence is feasible
            if (isFeasible) {
                fout << begin << ' ' << b << endl;
                hasAnswer = true;
            }
        }
        
        b++;
    } while (b * (N - 1) <= largestBisquare);
    if (!hasAnswer) {
        fout << "NONE" << endl;
    }
    fout.close();
    
    return 0;
}
