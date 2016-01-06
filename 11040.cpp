/*  
	Amandine FOUILLET
	INSA Rennes 
	10/2015
  	UVA Problem 11040 - 
*/
# include <iostream>
# include <algorithm> 
# include <stdio.h> 
# include <climits>

using namespace std;

int getZ(int lines[9][9], int i, int j) {
	int res = lines[i - 2][j - 1] - lines[i][j-1] - lines[i][j+1];
	res = res / 2;
	//cout << res << endl;
	return res;
}

int getX(int lines[9][9], int i, int j) {
	//cout << i << " - " << j << " // " <<  lines[i+1][j] + lines[i+1][j+1] << endl;
	return (lines[i+1][j] + lines[i+1][j+1]);
}

int main(int argc, const char * argv[]) {
    int nbCases;
    scanf("%d", &nbCases);

    while(nbCases--){
    	int lines[9][9];
    	int nblines = 0;
    	int nbcolonne = 0;

		for(int i =0; i<9; i++){
			for(int j =0;j<9; j++){
				lines[i][j] = 0;
			}
		}

		for(int i = 0; i < 5; i++){
			nbcolonne = 0;
			for(int j = 0; j < i + 1; j++){
				int v;
				scanf("%d", &v);
				lines[nblines][nbcolonne] = v;
				nbcolonne = nbcolonne + 2;
			}
			nblines = nblines + 2;
		}

		nblines = 0;
		for(int i = 0; i < 5; i++){
			nbcolonne = 1;
			for(int j = 0; j < i; j++){
				lines[nblines][nbcolonne] = getZ(lines, nblines, nbcolonne);
				nbcolonne = nbcolonne + 2;
			}
			nblines = nblines + 2;
		}

		nblines = 1;
		nbcolonne = 2;
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < nbcolonne; j++){
				lines[nblines][j] = getX(lines, nblines, j);
			}
			nblines = nblines + 2;
			nbcolonne = nbcolonne + 2;
		}



		for(int i =0; i<9; i++){		
			for(int j = 0;j<i + 1; j++){
				if(j!=0)
					printf(" %d", lines[i][j]);
				else
					printf("%d", lines[i][j]); 
			}
			printf("\n");	
		}
	}

    return 0;
}

