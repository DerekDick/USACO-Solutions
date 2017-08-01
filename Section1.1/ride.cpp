/*
ID: 
PROB: ride
LANG: C++
*/

#include <fstream>
#include <string>

#define num(x) x - 'A' + 1

using namespace std;

int main() {
	ifstream fin("ride.in");
	ofstream fout("ride.out");
	
	string comet, group;
	fin >> comet >> group;
	fin.close();
	
	int len1 = comet.length();
	int len2 = group.length();
	int convert1 = 1, convert2 = 1;
	for (int i = 0; i < len1; i++) {
		convert1 *= num(comet[i]);
	}
	convert1 %= 47;
	for (int i = 0; i < len2; i++) {
		convert2 *= num(group[i]);
	}
	convert2 %= 47;
	
	if (convert1 - convert2) {
		fout << "STAY" << endl;
	}
	else {
		fout << "GO" << endl;
	}
	
	fout.close();
	
	return 0;
}
