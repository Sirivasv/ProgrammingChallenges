#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1 << 18;

bitset<MAXN> vistos;
string s;

int CalcN(int id, int len) {
	int res = 0;
	for (int i = 0; i < len; ++i) {
		res *= 2;
		if (s[id + i] == '1') 
			res++;
		//cout << s[id + i] << ' ';
	}
	//cout << '\n';
	//cout << res << '\n';
	return res;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		
		cin >> s;
		
		int acum = 0;
		
		int lim = s.size();
		
		for (int i = 1; i <= 17; ++i) {
			vistos.reset();
			acum = 0;
			for (int j = 0; j < lim; ++j) {
				if ((j + i - 1) >= lim)
					break;
				int numb = CalcN(j, i);
				if (vistos[numb] == 0)
					acum++;
				vistos[numb] = 1;
			}
			if (acum < (1 << i)) {
				cout << i << '\n';
				break;
			}
		}
		
	}
	return 0;
}