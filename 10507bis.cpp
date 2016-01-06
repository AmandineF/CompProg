/*  
	Amandine FOUILLET
	INSA Rennes 
	10/2015
  	UVA Problem 10507 - 
*/ 
# include <iostream>
# include <algorithm> 
# include <stdio.h> 
# include <climits>
# include <math.h>
# include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
	int nbLink;

    while(scanf("%d", &nbLink) != EOF){
    	int nbCase;
    	scanf("%d", &nbCase);
		cout << nbCase << endl;

		char third[3];
    	scanf("%s", third);
    	vector<char> princip(nbLink);
    	princip.push_back(third[0]);
    	princip.push_back(third[1]);
    	princip.push_back(third[2]);

		cout << nbLink << endl;

    	vector<string> links(nbCase);
    	char second[2];
   		while(nbCase--){
   			cout << nbCase << endl;
			scanf("%s", second);
			links.push_back(second);
   		}	
		
	}

    return 0;
}

