#include <bits/stdc++.h>
using namespace std;

struct Node {
	Node *izq, *der;
	char data;
	Node(char x): data(x), izq(NULL), der(NULL) { } ;
};

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) {
		Node* INI = new Node('*');
		Node* FIN = new Node('-');
		INI->der = FIN;
		FIN->izq = INI;
		Node* cur = INI;
		string s;
		cin >> s;
		int lim = s.size();
		for(int i = 0; i < lim; ++i) {
			if (s[i] == '-') {
				//cout << cur ->data << "%%\n";
				if ((cur != INI) && (cur != FIN)) {
					(cur->der)->izq = (cur->izq);
					(cur->izq)->der = (cur->der);
					Node* tmp = cur;
					cur = cur->izq;
					delete tmp;
				}
			} else if (s[i] == '<') {
				//cout << "**\n";
				if (cur != INI) 
					cur = (cur->izq);
			} else if (s[i] == '>') {
				//cout << "--\n";
				if ((cur->der) != FIN) 
					cur = (cur->der);
			} else {
				//cout << "++\n";
				Node* tmpder = cur->der;
				Node* tmpizq = cur;
				cur = new Node(s[i]);
				if (tmpder != NULL)
					tmpder->izq = cur;
				if (tmpizq != NULL)
					tmpizq->der = cur;
				cur->der = tmpder;
				cur->izq = tmpizq;
			}
		}
		while (cur->data != '*') {
			cur = cur->izq;
		}
		cur = cur->der;
		while (cur->data != '-') {
			cout << cur->data;
			cur = cur->der;
		}
		cout << '\n';
	}
	return 0;
}