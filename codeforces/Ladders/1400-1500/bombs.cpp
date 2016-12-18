#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, char> ter;

vector<ter> instr;

int Abs(int x) { return ((x < 0)?(-x):(x)); }

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	priority_queue<pii> pfc; // first cuadrant x >= 0 && y >= 0 //poner negativos ambos
	priority_queue<pii> psc; // second cuadrant x < 0 && y >= 0 //poner negativo la y
	priority_queue<pii> ptc; // third cuadrant x < 0 && y < 0
	priority_queue<pii> pfrc; // fourth cuadrant x >= 0 && y < 0 //poner negativo a la x
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int xi, yi;
		cin >> xi >> yi;
		if ((xi >= 0) && (yi >= 0)) {
			pfc.push(pii(-xi, -yi));
		} else if ((xi < 0) && (yi >= 0)) {
			psc.push(pii(xi, -yi));
		} else if ((xi < 0) && (yi < 0)) {
			ptc.push(pii(xi, yi));
		} else if ((xi >= 0) && (yi < 0)) {
			pfrc.push(pii(-xi, yi));
		}
	}
	while (!pfc.empty()) {
		int xi = Abs(pfc.top().first);
		int yi = Abs(pfc.top().second);
		pfc.pop();
		if (xi > 0)
			instr.push_back(ter(pii(1, xi), 'R'));
		if (yi > 0)
			instr.push_back(ter(pii(1, yi), 'U'));
		instr.push_back(ter(pii(2, yi), 'U'));
		if (yi > 0)
			instr.push_back(ter(pii(1, yi), 'D'));
		if (xi > 0)
			instr.push_back(ter(pii(1, xi), 'L'));
		instr.push_back(ter(pii(3, yi), 'U'));
	}
	while (!psc.empty()) {
		int xi = Abs(psc.top().first);
		int yi = Abs(psc.top().second);
		psc.pop();
		if (xi > 0)
			instr.push_back(ter(pii(1, xi), 'L'));
		if (yi > 0)
			instr.push_back(ter(pii(1, yi), 'U'));
		instr.push_back(ter(pii(2, yi), 'U'));
		if (yi > 0)
			instr.push_back(ter(pii(1, yi), 'D'));
		if (xi > 0)
			instr.push_back(ter(pii(1, xi), 'R'));
		instr.push_back(ter(pii(3, yi), 'U'));
	}
	while (!ptc.empty()) {
		int xi = Abs(ptc.top().first);
		int yi = Abs(ptc.top().second);
		ptc.pop();
		if (xi > 0)
			instr.push_back(ter(pii(1, xi), 'L'));
		if (yi > 0)
			instr.push_back(ter(pii(1, yi), 'D'));
		instr.push_back(ter(pii(2, yi), 'U'));
		if (yi > 0)
			instr.push_back(ter(pii(1, yi), 'U'));
		if (xi > 0)
			instr.push_back(ter(pii(1, xi), 'R'));
		instr.push_back(ter(pii(3, yi), 'U'));
	}
	while (!pfrc.empty()) {
		int xi = Abs(pfrc.top().first);
		int yi = Abs(pfrc.top().second);
		pfrc.pop();
		if (xi > 0)
			instr.push_back(ter(pii(1, xi), 'R'));
		if (yi > 0)
			instr.push_back(ter(pii(1, yi), 'D'));
		instr.push_back(ter(pii(2, yi), 'U'));
		if (yi > 0)
			instr.push_back(ter(pii(1, yi), 'U'));
		if (xi > 0)
			instr.push_back(ter(pii(1, xi), 'L'));
		instr.push_back(ter(pii(3, yi), 'U'));
	}
	cout << instr.size() << '\n';
	for (int i = 0; i < instr.size(); ++i) {
		int tp = instr[i].first.first;
		int k = instr[i].first.second;
		char dir = instr[i].second;
		if (tp == 1)
			cout << tp << ' ' << k << ' ' << dir << '\n';
		else
			cout << tp << '\n';
	}
	return 0;
}