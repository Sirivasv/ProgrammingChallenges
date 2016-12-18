#include <bits/stdc++.h>
using namespace std;

const int MAXC = 30;

int cubeta[MAXC];

int main() {
    //cin.tie(0); ios_base::sync_with_stdio(0);
    int N;
    cin >> N;
    while (N--) {
        int M;
		cin >> M;
		string s;
		cin >> s;
		for (int i = 0; i < 30; ++i)
			cubeta[i] = 0;
        for (int i = 0; i < M; ++i) 
			cubeta[s[i] - 'A']++;
		char imp = -1;
		for (int i = 0; i < 26; ++i)
			if (cubeta[i] & 1) {
				imp = i + 'A';
				break;
			}
		string ans = "";
		for (int i = 0; i < 26; ++i)
			for (int j = 0; j < (cubeta[i] / 2); ++j)
				ans += (char)(i + 'A');
		cout << ans;
		if (imp != -1)
			cout << imp;
		int lim = ans.size();
		for (int i = lim -  1; i >= 0; --i)
			cout << ans[i];
		cout << '\n';
	}
    return 0;
}