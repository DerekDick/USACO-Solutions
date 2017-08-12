/*
ID: 
PROB: ariprog
LANG: C++
*/

#include <fstream>
#include <set>
#include <algorithm> // For std::find

using namespace std;

int main() {
    // Input
    ifstream fin("ariprog.in");
    int N, M;
    fin >> N >> M;
    fin.close();
    
    // Generate the bisquare set
    set<int> bisquares = set<int>();
//    int count = 0; // Derek is debugging...
    for (int i = 0; i <= M; i++) {
        for (int j = 0; j <= M; j++) {
            bisquares.insert(i*i + j*j);
//            count++; // Derek is debugging...
        }
    }
    
    // Output
    ofstream fout("ariprog.out");
    //////////////////////////////////////////////
    // Derek is debugging...
//    for (set<int>::iterator iter = bisquares.begin(); iter != bisquares.end(); iter++) {
//        fout << *iter << endl;
//    }
//    fout << "The size of the bisquare set: " << bisquares.size() << endl;
//    fout << "count = " << count << endl; 
    //////////////////////////////////////////////
    int largestBisquare = 2 * M * M;
    int b = 1;
    bool hasAnswer = false;
    do {
        int end = largestBisquare - b * (N - 1);
//        fout << "    " << "end = " << end << endl; // Derek is debugging...
        for (int begin = 0; begin <= end; begin++) {
            bool isFeasible = true;
            for (int i = 0; i < N; i++) {
                if (find(bisquares.begin(), bisquares.end(), begin + b * i) == bisquares.end()) {
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
