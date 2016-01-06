/*  
	Amandine FOUILLET
	INSA Rennes 
	10/2015
  	UVA Problem 10911 - Forming Quiz Teams
*/

# include <iostream>
# include <algorithm> 

using namespace std;

int N, target;
double dist[20][20], memo[1 << 16];

double matching(int bitmsask) {
	if(memo[bitmsask] > -0.5) return memo[bitmsask];
	if(bitmsask == target) return memo[bitmsask] = 0;
	double ans = 2000000000.0;
	int p1, p2;
	for(p1 = 0; p1 < 2 * N - 1; p1++)
		if(!(bitmsask & (1 << p1))) break;

	for(p2 = p1 + 1; p2 < 2 * N; p2++){
		if(!(bitmsask & (1 << p2)))
			ans = min(ans, dist[p1][p2] + matching(bitmsask | (1 << p1) | (1 << p2)));
	}

	return memo[bitmsask] = ans;
}

int main(int argc, const char * argv[]) {

    int i, j, caseNo = 1, x[20], y[20];
    while(scanf("%d", &N), N) {
    	for(i = 0; i < 2 * N; i++)
    		scanf("%s %d %d", &x[i], &y[i]);
    	for(i = 0; i < 2 * N - 1; i++)
    		for(j = 0; j < 2 * N; j++)
    			dist[i][j] = dist[j][i] = hypot(x[i] - x[j], y[i] - y[j]);

    	for(i = 0; i < (1 << 16); i++) memo[i] = -1.0;
    	target = (1 << (2 * N)) - 1;
    	printf("Case %d: %.2lf\n", caseNo++, matching(0));
    }
    
    return 0;
}

