 /*  
	Amandine FOUILLET
	INSA Rennes 
	10/2015
  	UVA Problem 10189 - Minesweeper
*/

# include <iostream>
# include <algorithm> 

using namespace std;

int main(int argc, const char * argv[]) {
	int line = 0;
	int column = 0;
	int noCase = 1; 
	
	while(scanf("%d %d", &line, &column) != EOF) {
		if(line == 0 && column == 0)
			return 0;

		if(noCase > 1)
			printf("\n");
		
		int data[line][column];
		string input;

		for(int i = 0; i < line; i++) {
			cin >> input;
			for(int j = 0; j < column; j++) {
				if(input[j] == '*') {
					data[i][j] = -1;
				} else {
					data[i][j] = 0;
				}
			}
		}

		for(int i = 0; i < line; i++) {
			for(int j = 0; j < column; j++) {
				if(data[i][j] != -1) {
					if(i - 1 >= 0)
						if(data[i - 1][j] == -1)
							data[i][j]++;
					if(i + 1 < line)
						if(data[i + 1][j] == -1)
							data[i][j]++;
					if(j - 1 >= 0)
						if(data[i][j - 1] == -1)
							data[i][j]++;
					if(j + 1 < column)
						if(data[i][j + 1] == -1)
							data[i][j]++;		
					if(i + 1 < line && j + 1 < column)
						if(data[i + 1][j + 1] == -1)
							data[i][j]++;
					if(i - 1 >=0 && j - 1 >= 0)
						if(data[i - 1][j - 1] == -1)
							data[i][j]++;
					if(i + 1 < line && j - 1 >= 0)
						if(data[i + 1][j -
						 1] == -1)
							data[i][j]++;
					if(i - 1 >=0 && j + 1 < column)
						if(data[i - 1][j + 1] == -1)
							data[i][j]++;	
				}
			}
		}

		
		printf("Field #%d:\n", noCase++);
		for(int i = 0; i < line; i++) {
			for(int j = 0; j < column; j++) {
				if(data[i][j] != -1) {
					printf("%d", data[i][j]);
				} else {
					printf("*");
				}
			}
			printf("\n");
		}
	} 
	return 0;
}

