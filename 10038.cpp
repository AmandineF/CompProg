/*  
	Amandine FOUILLET
	INSA Rennes 
	10/2015
  	UVA Problem 10038 - Jolly Jumpers
*/

# include <iostream>
# include <stdlib.h> 

using namespace std;

int main(int argc, const char * argv[]) {
	int n;
	while(scanf("%d", &n) != EOF) {
		bool jolly = true;
		int data[n];

		for(int i = 0; i < n; i++) 
			cin >> data[i];

		if(n > 1) {
			int diff[n-1];

			for(int i = 0; i < (n - 1); i++)
				diff[i] = abs(data[i + 1] - data[i]);

			for(int i = 1; i < n; i++) {
				bool isin = false;
				for(int j = 0; j < n - 1; j++) {
					if(i == diff[j]) {
						isin = true;
						break;
					}
				}
				if(!isin) {
					jolly = false;
					break;
				}
			}
		}

		if(jolly)
			cout << "Jolly" << endl;
		else
			cout << "Not jolly" << endl;		
	}	
	return 0;
}

