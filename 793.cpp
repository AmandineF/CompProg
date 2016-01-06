/*  
	Amandine FOUILLET
	INSA Rennes 
	10/2015
  	UVA Problem 793
*/

# include <iostream>
# include <stdlib.h>      
# include <map>
# include <vector>

using namespace std;

class union_find {
	private:
		std::vector<int> id; // id[i] = parent of i
		std::vector<int> sz;//sz[i] = number of objects in subtree rooted at i
		int count; // number of components
	public:
		union_find(int N){
			count = N;
			id.assign(N, 0);
			sz.assign(N, 1);
			for (int i = 0; i < N; i++) {
				id[i] = i;
			}
		}
		int nb_components() {
			return count;
		}
		int size_set(int i) {
			return sz[find_set(i)];
		}
		int find_set(int i) {
			return (id[i] == i) ? i : (id[i] = find_set(id[i]));
		}
		bool connected(int i, int j) {
			return find_set(i) == find_set(j);
		}
		void union_set(int p, int q) {
			int i = find_set(p);
			int j = find_set(q);
			if (i == j) return;
			// make smaller root point to larger one
			if (sz[i] < sz[j]) { 
				id[i] = j; sz[j] += sz[i]; 
			} else { 
				id[j] = i; sz[i] += sz[j]; 
			}
			count--;
		}
};

int main(int argc, const char * argv[]) {
	int nbCase;
	scanf("%d", &nbCase);
	while(nbCase--){
		int nbComputers;
		scanf("%d%*c", &nbComputers);
		union_find uf(nbComputers+1);

		int counter;
		char firstChar = getchar();
		int nbQuestion = 0;
		int nbSuccessQuestions = 0;

		while(firstChar != '\n' && firstChar != EOF){
			int computer1, computer2;
			scanf("%d %d%*c", &computer1, &computer2);
			if(firstChar == 'c') {
			    uf.union_set(computer1, computer2);
			} else {
				nbQuestion++;
				if(uf.connected(computer1, computer2))
					nbSuccessQuestions++;
			}
			firstChar = getchar();
		}
		cout << nbSuccessQuestions << "," << (nbQuestion - nbSuccessQuestions) << endl; 
		if(nbCase) printf ("\n");
	}

}
























