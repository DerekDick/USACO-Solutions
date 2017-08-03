/*
ID: 
PROB: milk2 
LANG: C++
*/

#include <fstream>

using namespace std;

int main() {
	// Intput
	ifstream fin("milk2.in");
	int n;
	fin >> n;
	bool timeLine[1000000];
	for (int i = 0; i < 1000000; i++) {
		timeLine[i] = false;
	}
	for (int i = 0; i < n; i++) {
		int start, end;
		fin >> start >> end;
		for ( ; start < end; start++) {
			timeLine[start] = true;
		}
	}
	fin.close();
	
	// Output
	ofstream fout("milk2.out");
	int longestMilked = 0, longestIdle = 0;
	int currentMilked, currentIdle;
	// Find the starting second of the milking time
	int start;
	for (int i = 0; i < 1000000; i++) {
		if (timeLine[i]) {
			start = i;
			break;
		}
	}
	// Find the ending second of the milking time
	int end;
	for (int i = 999999; i > -1; i--) {
		if (timeLine[i]) {
			end = i;
			break;
		}
	}
	// Initialize the current state
	bool currentState = false;
	currentIdle = 0;
	for (int i = start; i < end + 1; i++) {
		// If the current state converts
		if (currentState != timeLine[i]) {
			if (currentState) {
				if (currentMilked > longestMilked) {
					longestMilked = currentMilked;
				}
				currentIdle = 1;
			}
			else {
				if (currentIdle > longestIdle) {
					longestIdle = currentIdle;
				}
				currentMilked = 1;
			}
			
			// Change the current state
			currentState = timeLine[i];
		}
		
		// Else the current state stays unchanged
		else {
			if (currentState) {
				currentMilked++;
			}
			else {
				currentIdle++;
			}
		}
	}
	// For the last interval
	if (currentMilked > longestMilked) {
		longestMilked = currentMilked;
	}
	fout << longestMilked << ' ' << longestIdle << std::endl;
	fout.close();
	
	return 0;
}
