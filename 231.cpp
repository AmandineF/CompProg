/*  
	Amandine FOUILLET
	INSA Rennes 
	11/2015
  	UVA 231 - Testing the CATCHER
*/

# include <algorithm>
# include <vector>
# include <iostream>
# include <math.h>
# include <list>
# include <climits>

using namespace std;

int catch_counter(vector<int> missiles, int i, int limit, vector<int> memo){
	if(i==missiles.size()) return 0;
	if(missiles[i] > limit) return catch_counter(missiles, i + 1, limit, memo);
	if(memo[i] != -1) return memo[i];
	int res = max(1 + catch_counter(missiles, i + 1, missiles[i], memo), catch_counter(missiles, i + 1, limit, memo));
	memo[i] = res;
	return res;
}


int main(int argc,char *argv[]){
	int tmp;
	int nbCase = 1;
	while(scanf("%d", &tmp), tmp != -1) {
		int height;
		vector<int> missiles;
		missiles.push_back(tmp);
		while(scanf("%d", &height), height != -1) {
			missiles.push_back(height);
		}

		vector<int> memo(missiles.size(), -1);
	 	if (nbCase != 1) putchar('\n');
        printf("Test #%d:\n", nbCase++);
        printf("  maximum possible interceptions: %d\n", catch_counter(missiles, 0, INT_MAX, memo) );

	}

	return 0;                    
}
