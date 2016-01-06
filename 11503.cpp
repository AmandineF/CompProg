/*  
	Amandine FOUILLET
	INSA Rennes 
	10/2015
  	UVA Problem 11503 - 
*/
# include <iostream>
# include <algorithm> 
# include <stdio.h> 
# include <vector> 
# include <map> 

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

int main(void) {
  int t;
  int n;
  string a, b;

  cin >> t;

  while (t--) {
    int counter = 0;
    map<string,int> m;
    union_find ds(200000);

    cin >> n;

    while (n--) {
      cin >> a >> b;

      if (m.find(a) == m.end()) {
        m[a] = counter;
        counter++;
      }

      if (m.find(b) == m.end()) {
        m[b] = counter;
        counter++;
      }

      ds.union_set(m[a], m[b]);
      cout << ds.size_set(m[a]) << endl;
    }
  }

  return 0;
}

