#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

lli L, O, S, T;
lli l, o, s, t;

lli cont;
lli contG;

void func1() {
	lli mint = min(t / 2LL, min(s, l));
	cont += mint;
	t -= mint * 2LL;
	s -= mint;
	l -= mint;
}

void func2() {
	lli mint = min(s / 2LL, l / 2LL);
	cont += mint;

	s -= mint * 2LL;
	l -= mint * 2LL;
}

void func3() {
	lli mint = min(o / 2LL, l / 2LL);
	cont += mint;

	o -= mint * 2LL;
	l -= mint * 2LL;
}

void func4() {
	cont += t / 4LL;
	t -= (t / 4LL) * 4LL;
}

void func5() {
	cont += l / 4LL;
	l -= (l / 4LL) * 4LL;
}

void func6() {
	cont += o / 4LL;
	o -= (o / 4LL) * 4LL;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	cin >> L >> O >> S >> T;

	vector<int> V;
	V.push_back(1);
	V.push_back(2);
	V.push_back(3);
	V.push_back(4);
	V.push_back(5);
	V.push_back(6);


	do {
		
		l = L;
		o = O;
		s = S;
		t = T;
		cont = 0;

		for (int i = 0; i < V.size(); ++i) {
			if (V[i] == 1) func1();
			if (V[i] == 2) func2();
			if (V[i] == 3) func3();
			if (V[i] == 4) func4();
			if (V[i] == 5) func5();
			if (V[i] == 6) func6();
		}

		contG = max(cont, contG);
	} while (next_permutation(V.begin(), V.end()));

	cout << contG << '\n';

	return 0;
}