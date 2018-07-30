#include <bits/stdc++.h>

using namespace std;

// UnionFind : join(a,b), set(a), find(a)
template<typename T> struct UnionFind {
	vector<int> p; vector<T> sets;
	UnionFind(int n, T v={}) : p(n),sets(n){
		for (int i=0; i<n; i++)
			p[i]=i, sets[i]=v;
	}
	UnionFind(int n, vector<T> &v) : p(n),sets(move(v)){
		for (int i=0; i<n; i++) p[i]=i;
	}
	T & set(int a){ return sets[find(a)]; }
	int find(int a){
		if (p[a] == a) return a;
		return p[a] = find(p[a]);
	}
	bool join(int a, int b){
		a = find(a); b = find(b);
		if (a == b) return false;
		p[b] = p[a];
		sets[a] += sets[b];
		return true;
	}
};

//example
int main(){
	UnionFind<int> u(5, 1);
	u.join(0,1);
	u.join(0,2);
	for (int i = 0; i < 5; i += 1){
		cout << u.find(i) << "\n";
	}
	cout << "--\n";
	for (int i = 0; i < 5; i += 1){
		cout << u.set(i) << "\n";
	}
}

//output
/*
0
0
0
3
4
--
3
3
3
1
1
*/
