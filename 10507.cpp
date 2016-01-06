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

int nbYears(int brain[26][26], vector<string> list, int nbReach, int nbLink){
	cout << " ------- " << endl;
	for(int i=0; i< list.size(); i++){
		string link = list[i];
		cout << link[0] << endl;
		/*if(brain[link[0] - 65] == 1 && brain[link[1] - 65] == 0){
				//wakeup = wakeup + 1;
				brain[link[1] - 65]++;
		}else if(brain[link[1] - 65] == 0 && brain[link[0] - 65] == 1){
				//wakeup = wakeup + 1;
				brain[link[0] - 65]++;
		}*/
	}

	for(int i=0; i< list.size(); i++){
		if(brain[i] == 3) {
			brain[i] = 1;
			nbReach++;
		}
	}
	return 1;
	if(nbReach == nbLink)
		return 1;
	else
		return 1 + nbYears(brain, list, nbReach, nbLink);
}


int main(int argc, const char * argv[]) {
	int nbLink;

    while(scanf("%d", &nbLink) != EOF){
    	if(nbLink == 0)
    		break;

    	int nbCase;
    	int wakeup = 0;

    	
    	scanf("%d", &nbCase);
    	
		int brain[26][26] = {0};   
		char third [3];
    	scanf("%s", third);
    	
    	for(int i = 0; i < 26; i++) {
	    	brain[third[0] - 65][i] = 1;
	    	brain[third[1] - 65][i] = 1;
	    	brain[third[2] - 65][i] = 1;
	    	brain[i][third[0] - 65] = 1;
	    	brain[i][third[1] - 65] = 1;
	    	brain[i][third[2] - 65] = 1;
    	}

   		vector<string> list(nbCase);
   		char link[2];

   		for(int i=0; i<nbCase;i++){
			scanf("%s", link);
			list[i] = link;
   		}	
		
		cout << nbYears(brain, list, 3, nbLink) << endl;
		/*
		if((wakeup + 3) != nbLink)
			cout << "THIS BRAIN NEVER WAKES UP" << endl;
		else
			cout << "WAKE UP IN, " << nbYears(brain, list); << ", YEARS !" << endl;*/
	}

    return 0;
}

