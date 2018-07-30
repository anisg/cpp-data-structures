#include <bits/stdc++.h>

using namespace std;

// Trie : insert(s), find(s), remove(s,decr)
template <typename X, typename S=string, typename C=char>struct Trie {
	struct Node { int count = 0; X d; unordered_map<C,Node*> m; };
	typedef int (*lengthFunc)(const S &); typedef C(*accessFunc)(const S &, int);
	Node *root; lengthFunc lf; accessFunc af;
	Trie(lengthFunc lf = [](const S & s){return int(s.size());}, accessFunc af = ([](const S &s, int i){return s[i];})) : root(new Node()), lf(lf), af(af) {}
	void insert(const S & s) {
		Node *z = root;
		int n = lf(s);
		for (int i = 0; i < n; i++){
			C c = af(s, i);
			if (!z->m[c]) z->m[c] = new Node();
			z = z->m[c];
		}
		z->count += 1;
	}
	bool remove(const S & s, bool decr = false){
		Node *z;
		if (!(z = find(s))) return false;
		z->count = (decr) ? z->count - 1 : 0;
		return true;
	}
	Node *find(const S & s, int m = -1){
		Node *z = root;
		int n = lf(s);
		for (int i = 0; i < n; i++){
			C c = af(s, i);
			if (!z->m[c]) return 0x0;
			z = z->m[c];
			if (i == m) return z;
		}
		return z->count || m == n ? z : 0x0;
	}
};

//example
int main(){
	Trie<bool> t;
	t.insert("ab");
	t.insert("abc");
	cout << (t.find("hello") ? "yes" : "no") << "\n";
	cout << (t.find("a") ? "yes" : "no") << "\n";
	cout << (t.find("ab") ? "yes" : "no") << "\n";
	cout << (t.find("abc") ? "yes" : "no") << "\n";

	cout << "----\n";

	cout << "count:" << t.find("abc")->count << "\n";
	t.insert("abc");
	cout << "count:" << t.find("abc")->count << "\n";
}

//output
/*
no
no
yes
yes
----
count:1
count:2
*/
