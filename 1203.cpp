/*  
	Amandine FOUILLET
	INSA Rennes 
	10/2015
  	UVA Problem 1203
*/

# include <iostream>
# include <stdlib.h> 
# include <map> 
# include <queue>     

using namespace std;

class comparison{
	public:
		bool operator() (const pair<int, int>& p1, const pair<int, int>& p2) const {
			return p1.first > p2.first || (p1.first == p2.first && p1.second > p2.second);
		}
};

int main(int argc, const char * argv[]) {
	char tmp[1024];
	vector<int> registers(3001);
	priority_queue<pair<int, int>, vector<pair<int, int> >, comparison> listPeriods;

	while(scanf("%s", tmp), tmp[0] != '#') {
		int Qnum, Period;
		cin >> Qnum >> Period;
		registers[Qnum] = Period;
		listPeriods.push(make_pair(Period, Qnum));
	}

	int K;
	cin >> K;

	while(K--){
		pair<int, int> mPair = listPeriods.top();
		listPeriods.pop();
		cout << mPair.second << endl;;
		listPeriods.push(make_pair(mPair.first + registers[mPair.second], mPair.second));
	}

}