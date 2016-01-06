/*  
	Amandine FOUILLET
	INSA Rennes 
	10/2015
  	UVA Problem 10583 - 
*/
# include <iostream>
# include <algorithm> 
# include <stdio.h> 
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
    int nbStudent = 0;
    int nbCase;
    int cpt = 1;

    while(scanf("%d %d", &nbStudent, &nbCase) != EOF) {
	if(nbStudent == 0 && nbCase == 0)
		return 0;
	
	union_find *religions = new union_find(nbStudent);
	int student1, student2;
	for(int i = 0; i < nbCase; i++) {
		scanf("%d %d", &student1, &student2);
		if(!religions->connected(student1, student2))
			religions->union_set(student1, student2);
	}

	cout << "Case " << cpt++ << ": " << religions->nb_components() << endl;
    }
    
    return 0;
}

