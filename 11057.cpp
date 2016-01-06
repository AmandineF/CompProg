/*  
	Amandine FOUILLET
	INSA Rennes 
	10/2015
  	UVA Problem 11057 - 
*/

# include <iostream>
# include <algorithm> 
# include <stdio.h> 
# include <climits>

using namespace std;

int main(int argc, const char * argv[]) {
    int nbBooks;
    while(scanf("%d", &nbBooks) != EOF) {
    	
    	int booksPrices[nbBooks];
    	for(int i = 0; i < nbBooks; i++){
    		scanf("%d", &booksPrices[i]);
    	}
		
	    int money;
		scanf("%d", &money);
    		
    	int mini; 
    	int minj;
    	int mindiff = INT_MAX;	
		for(int i = 0; i < nbBooks; i++){
			for(int j = i+1; j < nbBooks; j++){
				if(booksPrices[i] + booksPrices[j] == money) {
					if(abs(booksPrices[i] - booksPrices[j]) < mindiff) {
						mindiff = abs(booksPrices[i] - booksPrices[j]);
						mini = min(booksPrices[i],booksPrices[j]);
						minj = max(booksPrices[i],booksPrices[j]);;
					}
				}
			}
		}

		cout << "Peter should buy books whose prices are " << mini << " and " << minj << "." << endl;
		cout << "" << endl;
	}

    return 0;
}

