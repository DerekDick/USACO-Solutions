/*
ID: 
PROB: beads 
LANG: C++
*/

#include <fstream>

using namespace std;

int main() {
	ifstream fin("beads.in");
	
	// Input
	char necklace[700]; // The range of n is [3, 350], double the length for the convinence of calculation
	int n;
	fin >> n;
	for (int i = 0; i < n; i++) {
		fin >> necklace[i];
	}
	fin.close();
	
	// Calculate the largest number of beads that can be collected
	int largestNum = 1;
	for (int pivot = 0; pivot < n; pivot++) {
		// Calculate the number of beads that can be collected forward
		int forwardNum; 
		char forwardColor = 'w';
		for (forwardNum = 0; forwardNum < n; forwardNum++) {
			if ((necklace[pivot + forwardNum] - forwardColor) && (necklace[pivot + forwardNum] - 'w')) {
				if (forwardColor - 'w') {
					break;
				}
				else {
					forwardColor = necklace[pivot + forwardNum];
				}
			}
		}
		
		// Calculate the number of the beads that can be collected backward
		int backwardNum;
		char backwardColor = 'w';
		for (backwardNum = 0; backwardNum < n - forwardNum; backwardNum++) {
			if ((necklace[pivot + n - 1 - backwardNum] - backwardColor) && (necklace[pivot + n - 1 - backwardNum] - 'w')) {
				if (backwardColor - 'w') {
					break;
				}
				else {
					backwardColor = necklace[pivot + n - 1 - backwardNum];
				}
			}
		}
		
		// In order to find the largest number
		if (forwardNum + backwardNum > largestNum) {
			largestNum = forwardNum + backwardNum;
		}
		
		// Prepare for the next turn
		necklace[n + pivot] = necklace[pivot];
	}
	
	// Output
	ofstream fout("beads.out");
	fout << largestNum << std::endl;
	fout.close();
	
	return 0;
}
