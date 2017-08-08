/*
ID: 
PROB: milk 
LANG: C++
*/

#include <fstream>
#include <map>

using namespace std;

int main() {
    // Input
    ifstream fin("milk.in");
    int N, M;
    fin >> N >> M;
    map<int, int> farmersPriceAmount = map<int, int>();
    int currentPrice, currentAmount;
    for (int i = 0; i < M; i++) {
        fin >> currentPrice >> currentAmount;
        if (farmersPriceAmount.find(currentPrice) != farmersPriceAmount.end()) {
            farmersPriceAmount[currentPrice] += currentAmount;
        }
        else {
            farmersPriceAmount[currentPrice] = currentAmount;
        }
    }
    fin.close();
    
    // Output
    ofstream fout("milk.out");
    int purchasedAmount = 0;
    int cost = 0;
    for (map<int, int>::iterator iter = farmersPriceAmount.begin(); iter != farmersPriceAmount.end(); iter++) {
        if (iter->second > (N - purchasedAmount)) {
            cost += iter->first * (N - purchasedAmount);
            break;
        }
        else {
            cost += iter->first * iter->second;
            purchasedAmount += iter->second;
        }
    }
    fout << cost << std::endl;
    fout.close();
    
    return 0;
}
