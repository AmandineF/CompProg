/*  
	Amandine FOUILLET
	INSA Rennes 
	10/2015
  	Yet Another Number Game
*/

# include <iostream>
# include <stdlib.h> 

using namespace std;

int main(int argc, const char * argv[]) {
	int games;
	cin >> games;
	for(int i = 0; i < games; i++) {
		int T, N;
		cin >> T;
		if(T % 2 == 1) {
			cout << "BOB" << endl;
		} else {
			cout << "ALICE" << endl;
		}
	}
	return 0;
}

