/*
ID: 
PROB: wormhole
LANG: C++
*/

#include <fstream>
#include <algorithm> // For std::find, std::sort
#include <vector>

using namespace std;

struct Wormhole {
    int index;
    long x;
    long y;
    
    Wormhole* findNextWormhole(Wormhole* wormholesArr, int N) {
        vector<Wormhole*> candidateWormholes = vector<Wormhole*>();
        for (int i = 0; i < N; i++) {
            if ((wormholesArr[i].y == this->y) && (wormholesArr[i].x != this->x)) {
                candidateWormholes.push_back(wormholesArr + i);
            }
        }
        Wormhole* nextWormhole = NULL; 
        int size = candidateWormholes.size();
        for (int i = 0; i < size; i++) {
            if (candidateWormholes[i]->x > this->x) {
                if (!nextWormhole) {
                    nextWormhole = candidateWormholes[i];
                }
                else {
                    if (candidateWormholes[i]->x < nextWormhole->x) {
                        nextWormhole = candidateWormholes[i];
                    }
                }
            }
        }
        
        return nextWormhole;
    }
    
    Wormhole* findPairedWormhole(int* combination, Wormhole* wormholesArr, int N) {
        // Return the index of the paired wormhole in the wormholes array according to the current combination
        
        int* positionPointer = find(combination, combination + N, index);
        int i = 0;
        while (combination + i != positionPointer) {
            i++;
        }
        // If i is odd
        if (i % 2) {
            return wormholesArr + combination[i - 1];
        }
        // Else, i is even
        else {
            return wormholesArr + combination[i + 1];
        }
    }
};

struct Edge {
    Wormhole* wormhole;
    bool isPaired;
    
    bool operator == (const Edge &edge) const {
        return (this->wormhole == edge.wormhole) && (this->isPaired == edge.isPaired);
    }
};

bool generateNextCombination(int* combination, int start, int N);
bool isTrapping(int* combination, Wormhole* wormholesArr, int N);

int main() {
    // Input
    ifstream fin("wormhole.in");
    int N;
    fin >> N;
    Wormhole wormholesArr[12];
    for (int i = 0; i < N; i++) {
        fin >> wormholesArr[i].x >> wormholesArr[i].y;
        wormholesArr[i].index = i;
    }
    fin.close();
    
    // Count the number of all the distinct pairings that may trap Bessie the cow
    int count = 0;
    int currentCombination[12];
    for (int i = 0; i < N; i++) {
        currentCombination[i] = i;
    }
    do {
        if (isTrapping(currentCombination, wormholesArr, N)) {
            count++;
        }
    } while (generateNextCombination(currentCombination, 0, N));
    
    // Output
    ofstream fout("wormhole.out");
    fout << count << endl;
    fout.close();
    
    return 0;
}

bool generateNextCombination(int* combination, int start, int N) {
    if (start == N - 2) {
        return false;
    }
    
    if (generateNextCombination(combination, start + 2, N)) {
        return true;
    }
    else {
        int isBiggest = true;
        for (int i = start + 2; i < N; i++) {
            if (combination[i] > combination[start + 1]) {
                isBiggest = false;
            }
        }
        if (isBiggest) {
            return false;
        }
        else {
            sort(combination + start + 2, combination + N);
            int temp = combination[start + 1];
            int* pointer = combination + start + 2;
            while (*pointer < temp) {
                pointer++;
            }
            combination[start + 1] = *pointer;
            *pointer = temp;
            
            return true;
        }
    }
}

bool isTrapping(int* combination, Wormhole* wormholesArr, int N) {
    for (int i = 0; i < N; i++) {
        Wormhole* currentWormhole = wormholesArr + i;
        vector<Edge> visitedEdges = vector<Edge>();
        do {
            // If still not trapping
            Edge currentEdge = { currentWormhole, false };
            if (find(visitedEdges.begin(), visitedEdges.end(), currentEdge) == visitedEdges.end()) {
                visitedEdges.push_back(currentEdge);
            }
            // Else, this combination is trapping
            else {
                return true;
            }
            
            currentWormhole = currentWormhole->findPairedWormhole(combination, wormholesArr, N);
            
            // If still not trapping
            currentEdge.wormhole = currentWormhole;
            currentEdge.isPaired = true;
            if (find(visitedEdges.begin(), visitedEdges.end(), currentEdge) == visitedEdges.end()) {
                visitedEdges.push_back(currentEdge);
            }
            // Else, this combination is trapping
            else {
                return true;
            }
        } while (currentWormhole = currentWormhole->findNextWormhole(wormholesArr, N));
    }
    
    return false;
}
