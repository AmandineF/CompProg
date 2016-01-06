/*  
	Amandine FOUILLET
	INSA Rennes 
	10/2015
  	UVA Problem 11173 - 
*/
# include <cstdio>

using namespace std;


int main(int argc, const char * argv[]) {
    int nbCases;
    scanf("%d", &nbCases);

    while(nbCases--){
    	unsigned int n, k;
    	scanf("%d %d", &n, &k);
		printf("%d\n", k ^(k >> 1));
	}
    return 0;
}

