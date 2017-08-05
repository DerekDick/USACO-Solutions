/*
ID: 
PROB: transform 
LANG: C++
*/

#include <fstream>

using namespace std;

bool isIdentical(char square1[10][10], char square2[10][10], int N);
bool is1(char square1[10][10], char square2[10][10], int N);
bool is2(char square1[10][10], char square2[10][10], int N);
bool is3(char square1[10][10], char square2[10][10], int N);
bool is4(char square1[10][10], char square2[10][10], int N);
bool is5(char square1[10][10], char square2[10][10], int N);
bool is6(char square1[10][10], char square2[10][10], int N);
bool is4_1(char square1[10][10], char square2[10][10], int N);
bool is4_2(char square1[10][10], char square2[10][10], int N);
bool is4_3(char square1[10][10], char square2[10][10], int N);

int main() {
	// Input
	ifstream fin("transform.in");
	int N;
	fin >> N;
	char initialSquare[10][10];
	for (int row = 0; row < N; row++) {
		for (int column = 0; column < N; column++) {
			fin >> initialSquare[row][column];
		} 
	}
	char changedSquare[10][10];
	for (int row = 0; row < N; row++) {
		for (int column = 0; column < N; column++) {
			fin >> changedSquare[row][column];
		}
	}
	fin.close();
	
	// Try the transformations one by one in order
	int result;
	if (is1(initialSquare, changedSquare, N)) {
		result = 1;
	}
	else if (is2(initialSquare, changedSquare, N)) {
		result = 2;
	}
	else if (is3(initialSquare, changedSquare, N)) {
		result = 3;
	}
	else if (is4(initialSquare, changedSquare, N)) {
		result = 4;
	}
	else if (is5(initialSquare, changedSquare, N)) {
		result = 5;
	}
	else if (is6(initialSquare, changedSquare, N)) {
		result = 6;
	}
	else {
		result = 7;
	}
	
	// Output
	ofstream fout("transform.out");
	fout << result << endl;
	fout.close();
}

bool isIdentical(char square1[10][10], char square2[10][10], int N) {
	for (int row = 0; row < N; row++) {
		for (int column = 0; column < N; column++) {
			if (square1[row][column] - square2[row][column]) {
				return false;
			}
		}
	}
	return true;
}

bool is1(char square1[10][10], char square2[10][10], int N) {
	/* #1: 90 Degree Rotation: The pattern was rotated clockwise 90 degrees. */
	
	for (int row = 0; row < N; row++) {
	    for (int column = 0; column < N; column++) {
	        if (square1[row][column] - square2[column][N - 1 - row]) {
	            return false;
            }
        }
    }
    return true;
}

bool is2(char square1[10][10], char square2[10][10], int N) {
	/* #2: 180 Degree Rotation: The pattern was rotated clockwise 180 degrees. */
	
	for (int row = 0; row < N; row++) {
	    for (int column = 0; column < N; column++) {
	        if (square1[row][column] - square2[N - 1 - row][N - 1 - column]) {
	            return false;
            }
        }
    }
    return true;
}

bool is3(char square1[10][10], char square2[10][10], int N) {
	/* #3: 270 Degree Rotation: The pattern was rotated clockwise 270 degrees. */
	
	for (int row = 0; row < N; row++) {
	    for (int column = 0; column < N; column++) {
	        if (square1[row][column] - square2[N - 1 - column][row]) {
	            return false;
            }
        }
    }
    return true;
}

bool is4(char square1[10][10], char square2[10][10], int N) {
    /* #4: Reflection: The pattern was reflected horizontally 
    *  (turned into a mirror image of itself by reflecting around a vertical line in the middle of the image).
    */ 
    
    for (int row = 0; row < N; row++) {
        for (int column = 0; column < N; column++) {
            if (square1[row][column] - square2[row][N - 1 - column]) {
                return false;
            }
        }
    }
    return true;
}

bool is5(char square1[10][10], char square2[10][10], int N) {
	/* #5: Combination: The pattern was reflected horizontally and then subjected to one of the rotations (#1-#3). */
	
	return is4_1(square1, square2, N) || is4_2(square1, square2, N) || is4_3(square1, square2, N);
}

bool is6(char square1[10][10], char square2[10][10], int N) {
	/* #6: No Change: The original pattern was not changed. */
	
	if (isIdentical(square1, square2, N)) {
		return true;
	}
	else {
		return false;
	}
}


bool is4_1(char square1[10][10], char square2[10][10], int N) {
    /* #4 + #1 */
    
    for (int row = 0; row < N; row++) {
        for (int column = 0; column < N; column++) {
            if (square1[row][column] - square2[N - 1 - column][N - 1 - row]) {
                return false;
            }
        } 
    }
    return true;
}

bool is4_2(char square1[10][10], char square2[10][10], int N) {
    /* #4 + #2 */
    
    for (int row = 0; row < N; row++) {
        for (int column = 0; column < N; column++) {
            if (square1[row][column] - square2[N - 1 - row][column]) {
                return false;
            }
        }
    }
    return true;
}

bool is4_3(char square1[10][10], char square2[10][10], int N) {
    /* #4 + #3 */
    
    for (int row = 0; row < N; row++) {
        for (int column = 0; column < N; column++) {
            if (square1[row][column] - square2[column][row]) {
                return false;
            }
        }
    }
    return true;
}
