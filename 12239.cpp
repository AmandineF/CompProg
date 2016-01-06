/*  
	Amandine FOUILLET
	INSA Rennes 
	10/2015
  	UVA Problem 12239 - Bingo!
*/

# include <iostream>
# include <stdlib.h> 

using namespace std;

int add(int n) {
	return n > 1 ? (n + add(n - 1)) : 1;
}

int main(int argc, const char * argv[]) {
	int N = 0;
	int B = 0; 

	while(scanf("%d %d", &N, &B) != EOF) {
		if(N == 0 && B == 0)
			return 0;
		string res = "Y";

		int data[B];
		int size = add(B-1);
		int tab[size];

		for(int i = 0; i < B; i++)
			cin >> data[i];

		int k = 0;
		for(int i = 0; i < B; i++) { 
			for(int j = i + 1; j < B; j++) {
				tab[k] = abs(data[i] - data[j]);
				k++;
			}
		}

		for(int i = 1; i <= N; i++) {
			bool isin = false;
			for(int j = 0; j < size; j++) {
				if(i == tab[j]) {
					isin = true;
					break;
				}
			}
			if(!isin) {
				res = "N";
				break;
			}
		}

		cout << res << endl;
	} 
	return 0;
}

