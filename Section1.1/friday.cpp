/*
ID: 
PROB: friday
LANG: C++
*/

#include <fstream>

using namespace std;

bool isLeapYear(int year) {
	if (year % 400 == 0) {
		return true;
	}
	else if (year % 100 == 0) {
		return false;
	}
	else if (year % 4 == 0) {
		return true;
	}
	else {
		return false;
	}
}

int daysOfMonthYear(int month, int year) {
	switch (month) {
		case 1:
			return 31;
			break;
			
		case 2:
			if (isLeapYear(year)) {
				return 29;
			}
			else {
				return 28;
			}
			
			break;
		
		case 3:
			return 31;
			
			break;
			
		case 4:
			return 30;
			
			break;
			
		case 5:
			return 31;
			
			break;
			
		case 6:
			return 30;
			
			break;
			
		case 7:
			return 31;
			
			break;
			
		case 8:
			return 31;
			
			break;
			
		case 9:
			return 30;
			
			break;
			
		case 10:
			return 31;
			
			break;
			
		case 11:
			return 30;
			
			break;
		
		case 12:
			return 31;
			
			break;
			
		default:
			break;
	}
}

int main() {
	ifstream fin("friday.in");
	
	// Input
	int N;
	fin >> N;
	fin.close();
	
	// Calculating...
	int weekdayNum[7]; // Index 0 for Saturday, the rest indices incremented by this
	for (int i = 0; i < 7; i++) {
		weekdayNum[i] = 0;
	}
	int currentWeekday = 0;
	for (int i = 0; i < N; i++) {
		for (int currentMonth = 0; currentMonth < 12; currentMonth++) {
			if (currentMonth) {
				currentWeekday = (currentWeekday + daysOfMonthYear(currentMonth, 1900 + i)) % 7;
			}
			else {
				if (i) {
					currentWeekday = (currentWeekday + daysOfMonthYear(12, 1900 + i)) % 7;
				}
			}
			weekdayNum[currentWeekday]++;
		}
	}
	
	// Output
	ofstream fout("friday.out");
	for (int i = 0; i < 6; i++) {
		fout << weekdayNum[i] << " ";
	}
	fout << weekdayNum[6] << endl;
	fout.close();
	
	return 0;
}
