/*  
	Amandine FOUILLET
	INSA Rennes 
	10/2015
  	UVA Problem 11 517 - 
*/

# include <iostream>
# include <algorithm> 
# include <stdio.h> 
# include <vector> 

using namespace std;



long solve(vector<vector<int> > memo, vector<int> listCoins, int i, int sum) {
	if(sum < 0) {
	 	return 0;
	}	
	if(sum == 0) {
	 	return 1;
	}
	if(i == listCoins.size()) {
		return 0;
	}
	if(memo[i][sum] != -1) {
		return memo[i][sum];
	}

	long res = solve(memo, listCoins, i+1, sum) + solve(memo, listCoins, i, sum-listCoins[i]);
	memo[i][sum] = res; 
	
	return res;
}

int main(int argc, const char * argv[]) {
    int nbCases = 0;
    cin >> nbCases;
	
    while(nbCases--) {
		int price;
		cin >> price;

		int nbBillsCoins;
		cin >> nbBillsCoins;

		vector<int> listCoins(nbBillsCoins);
		vector<vector<int> > memo(nbBillsCoins,vector<int>(10000, -1)); 
		
		for(int i = 0; i<nbBillsCoins; i++) {
			cin >> listCoins[i];
		}

		long res = solve(memo, listCoins, 0, price);
		while(res == 0) {
			res = solve(memo, listCoins, 0, ++price);
		}

		cout << price << " " << res << endl;
    }
    
    return 0;
}

