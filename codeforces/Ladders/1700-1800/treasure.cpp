#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100009; 

int BIT[MAXN];

int sum(int idx) {
	int res = 0;
	while (idx) {
		res += BIT[idx];
		idx -= (idx & (-idx));
	}
	return res;
}

void upd(int idx, int val) {
	while (idx < MAXN) {
		BIT[idx] += val;
		idx += (idx & (-idx));
	}
}

int range(int I, int J) { return sum(J) - sum(I - 1); }

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	string s;
	cin >> s;
	int ok = 1;
	int ls = 0, ms = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '#') {
			if (sum(i + 1) <= 0) ok = 0;
			if (ok) upd(i + 1, -1);
			ls = i;
			ms++;
		} else if (s[i] == '(') upd(i + 1, 1);
		else upd(i + 1, -1);
		//cout << i << ' ' << ok << '\n';
	}
	
	if (sum(ls + 1) < sum(s.size())) ok = 0;
	if (sum(s.size()) < 0) ok = 0;
	
	int val = sum(s.size()) + 1;
	
	upd(ls + 1, -(val - 1));
	
	//cout << sum(ls + 1) << ' ' << sum(s.size()) << '\n';
	
	for (int i = 0; i < s.size(); ++i) if(sum(i + 1) < 0) ok = 0;
	
	if (sum(s.size()) != 0) ok = 0;

	if (!ok) {
		cout << "-1\n";
		return 0;
	}
	
	for (int i = 1; i < ms; ++i) cout << "1\n";
	
	cout << val << '\n';
	
	return 0;
} 