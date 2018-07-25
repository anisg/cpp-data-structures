#include <bits/stdc++.h>

using namespace std;

// FenTree : sum(i), add(i,v), range(l,r), get(i)
struct FenTree {
	int n; vector<int> d;
	FenTree(const vector<int> & v) : n(int(v.size()+1)), d(n,0) {
		for (int i=0; i<n-1; i++) d[i+1] = v[i];
		for (int i=1; i<n; i++){
			int j = i + (i & -i); if (j < n) d[j] += d[i];
		}
	}
	void add(int i, int v){
		i += 1;
		while (i < n)
			d[i] += v, i += (i & -i);
	}
	int sum(int i){
		int r = 0; i += 1;
		while (i > 0)
			r += d[i], i -= (i & -i);
		return r;
	}
	int range(int l, int r){ return sum(r) - sum(l-1); }
	int get(int i){ return range(i,i); }
};

int main(){
	FenTree d({1,2,3,4});

	cout << d.sum(0) << "\n";
	cout << d.sum(1) << "\n";
	cout << d.sum(2) << "\n";
	cout << d.sum(3) << "\n";
	cout << "--\n";
	cout << d.range(1,2) << "\n";
}

//output
/*
1
3
6
10
--
5
*/
