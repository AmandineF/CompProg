/*  
	Amandine FOUILLET
	INSA Rennes 
	11/2015
  	UVA 116 - Unidirectional TSP
*/

# include <algorithm>
# include <vector>
# include <iostream>
# include <math.h>
# include <list>

using namespace std;
int limits(int i, int size){
	if(i==-1)
		return size-1;
	if(i==size)
		return 0;

	return i;
}

int weight(vector<vector<int> > matrix, int i, int j, vector<vector<int> >  memo){
	if(j == matrix[0].size()) return matrix[i][j];
	if(memo[i][j] != -1) return memo[i][j];
	int res = matrix[i][j] + min(weight(matrix, limits(i-1,matrix.size()), j+1,memo), 
			min(weight(matrix, limits(i,matrix.size()), j+1,memo), weight(matrix, limits(i+1,matrix.size()), j+1,memo)));
	
	memo[i][j] = res;
	return res;
}


int main(int argc,char *argv[]){
	int nbLine, nbColumn;
	while(scanf("%d %d", &nbLine, &nbColumn) == 2) {
		vector<vector<int> > matrix(nbLine, vector<int>(nbColumn));
		vector<vector<int> > memo(11,vector<int>(101, -1)); 

		for(int i=0; i<nbLine;i++)
			for(int j=0;j<nbColumn;j++)
				scanf("%d",&matrix[i][j]);

		cout << weight(matrix, 0, 0, memo) << endl;
	}
	return 0;                    
}
