#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int MAXC = 100009;
ull HB[MAXC], B = 71;
ull hashu[MAXC], hashd;

ull F(char c) {
	if (c >= 'a' && c <= 'z') return c - 'a' + 1;
	return c - 'A' + 27;
}

void CB(){
	HB[0] = 1; HB[1] = B;
	for (int i = 2; i < MAXC; ++i)
		HB[i] = HB[i - 1] * B;
}

void MHash(string s) {
	int lim = s.size();
	for (int i = 0; i <= lim; ++i) hashu[i] = 0;
	for (int i = 1; i <= lim; ++i) 
		hashu[i] = hashu[i - 1] * B + F(s[i - 1]);
}

void MHashax(string s) {
	int lim = s.size();
	hashd = 0;
	for (int i = 1; i <= lim; ++i) 
		hashd = hashd * B + F(s[i - 1]);
}

ull Range(int a, int b) {
	return hashu[b] - hashu[a - 1] * HB[b - a + 1];
}

bool Check(int lima, int limb) {
	for (int i = 1; i + limb - 1 <= lima; ++i)
		if (hashd == Range(i, i + limb - 1))
			return true;
	return false;
}

int main() {
	CB();
	string S, ss;
	while (cin >> S) {
		MHash(S);
		int N;
		cin >> N;
		while (N--) {
			cin >> ss;
			MHashax(ss);
			//cout << hashd << '\n';
			if(Check(S.size(), ss.size())) cout << "y\n";
			else cout << "n\n";
		}
	}
	return 0;
}