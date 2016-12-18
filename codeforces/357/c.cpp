#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;

string inst[1000009];
int numb[1000009];

int main () {
	cin.tie(0);
	int N, a = 0;
	cin >> N; 
	string s;
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		cin >> s;
		if (s[0] == 'i') {
			cin >> a;
			inst[cnt] = s;
			numb[cnt] = a;
			cnt++;
			mp[a]++;
		} else if (s[0] == 'r') {
			int c = (mp.begin())->first;
			if (mp.begin() == mp.end()) {
				inst[cnt] = "insert";
				numb[cnt] = 1;
				cnt++;
			} else {
				mp[c]--;
				if (mp[c] == 0)
					mp.erase(c);
			}
			inst[cnt] = s;
			numb[cnt] = a;
			cnt++;
		} else {
			cin >> a;
			if ((a == (mp.begin())->first) && (mp.count(a))) {
				inst[cnt] = "getMin";
				numb[cnt] =  a;
				cnt++;
			}
			else {
				int fv = 0;
				if (!mp.count(a)) {
					mp[a]++;
					fv = 1;
				}
				while (a != (mp.begin())->first) {
					int lim = (mp.begin())->second;
					int b = (mp.begin())->first;
					for (int j = 0; j < lim; ++j) {
						inst[cnt] = "removeMin";
						numb[cnt] =  a;
						cnt++;
					}
					mp.erase(b);
				}
				if (fv) {
					inst[cnt] = "insert";
					numb[cnt] =  a;
					cnt++;
				}
				inst[cnt] = "getMin";
				numb[cnt] =  a;
				cnt++;
			}
		}
	}
	
	cout << cnt << '\n';
	
	for (int i = 0; i < cnt; ++i) {
		if (inst[i][0] == 'r')
			cout << inst[i] << '\n';
		else {
			cout << inst[i] << ' ';
			cout << numb[i] << '\n';
		}
	}
	
	return 0;
}