#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream in("input.txt");
    ofstream out("output.txt");
	int N, M;
	in >> N >> M;
	char mats, mint;
	if (N > M) {
		mats = 'B';
		mint = 'G';
	} else {
		mats = 'G';
		mint = 'B';
	}
	string s = "";
	for (;;) {
		if ((!N) || (!M))
			break;
		s += mats;
		s += mint;
		N--, M--;
	}
	while (N--)
		s += 'B';
	while (M--)
		s += 'G';
	out << s << '\n';
	return 0;
}