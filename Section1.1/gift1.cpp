/*
ID: 
PROB: gift1
LANG: C++
*/

#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
	ifstream fin("gift1.in");
	
	// Input the number of the group and the names of all the members
	int number;
	fin >> number;
	vector<string> group;
	string currentMember;
	for (int i = 0; i < number; i++) {
		fin >> currentMember;
		group.push_back(currentMember);
	}
	
	// Input the information of the gifts giving
	map<string, int> giving;
	map<string, int> receiving;
	for (vector<string>::iterator iter = group.begin(); iter != group.end(); iter++) {
		giving[*iter] = 0;
		receiving[*iter] = 0;
	}
	while (fin >> currentMember) {
		int initialAmount, givingNum;
		fin >> initialAmount >> givingNum;
		if (givingNum) {
			giving[currentMember] = initialAmount - initialAmount % givingNum;
		}
		
		if (givingNum) {
			int dividedAmount = initialAmount / givingNum;
			string currentReceiver;
			for (int i = 0; i < givingNum; i++) {
				fin >> currentReceiver;
				receiving[currentReceiver] += dividedAmount;
			}
		}
	}
	fin.close();
	
	// Output
	ofstream fout("gift1.out");
	for (vector<string>::iterator iter = group.begin(); iter != group.end(); iter++) {
		fout << *iter << " " << receiving[*iter] - giving[*iter] << endl;
	}
	fout.close();
	
	return 0;
}
