#include <bits/stdc++.h>

using namespace std;

// Trie : insert(s), find(s)
template <typename X, typename S=string, typename C=char>struct Trie {
	struct Node { bool leaf; X d; unordered_map<C,Node*> m; };
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
		z->leaf = true;
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
		return z->leaf || m == n ? z : 0x0;
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
}

//output
/*
no
no
yes
yes
*/
