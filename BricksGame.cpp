/*  
	Amandine FOUILLET
	INSA Rennes 
	11/2015
  	HackerRank Problem - Bricks Game!
*/

# include <algorithm>
# include <vector>
# include <iostream>

using namespace std;

int main(int argc,char *argv[]){
	int TC;
	cin >> TC;
	while (TC--){
		int N;
		cin >> N;
	  vector<long long> bricks(N + 1, 0);
	  for (int i = N; i >= 1; --i)
	  {
	    cin >> bricks[i];
	  }
	  vector<long long> sum(N + 1, 0);
	  for (int i = 1; i <= N; ++i)
	  {
	    sum[i] += sum[i - 1] + bricks[i];
	  }
	  vector<long long> dp(N + 1, 0);
	  dp[1] = sum[1];
	  dp[2] = sum[2];
	  dp[3] = sum[3];
	  for (int i = 4; i <= N; ++i){
	    dp[i] = max(bricks[i] + sum[i - 1] - dp[i - 1],
	                max(bricks[i] + bricks[i - 1] + sum[i - 2] - dp[i - 2],
	                    bricks[i] + bricks[i - 1] + bricks[i - 2] + sum[i - 3] - dp[i -3]));
		}
	  cout << dp[N] << endl;
	}
	return 0;                    
}
