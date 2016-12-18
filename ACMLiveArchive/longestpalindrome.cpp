#include <bits/stdc++.h>
using namespace std;
char ans [5000];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int T, N;
	cin >> T; 
	while (T--) {
		cin >> N;
		string s;
		map<string, int> conteo;
		for (int i = 0; i < N; ++i) {
			cin >> s;
			conteo[s]++;
		}
		//caso raro puras aa
		if ((conteo.count("aa")) && (conteo.count("bb") == 0) && (conteo.count("ab") == 0) && (conteo.count("ba") == 0)) {
			int lim = conteo["aa"];
			for (int i = 0; i < lim; ++i) cout << "aa";
			cout << '\n';
			continue;
		}
		//caso raro puras bb
		if ((conteo.count("bb")) && (conteo.count("aa") == 0) && (conteo.count("ab") == 0) && (conteo.count("ba") == 0)) {
			int lim = conteo["bb"];
			for (int i = 0; i < lim; ++i) cout << "bb";
			cout << '\n';
			continue;
		}
		//caso raro puras ab ba y aa 
		if ((conteo.count("aa")) && (conteo.count("ab")) && (conteo.count("ba")) && (conteo.count("bb") == 0)) {
			int aux = 0;
			int lim = conteo["aa"] >> 1;
			for (int i = 0; i < lim; ++i) {
				ans[aux++] = 'a';
				ans[aux++] = 'a';
			}
			lim = min(conteo["ab"], conteo["ba"]);
			for (int i = 0; i < lim; ++i) {
				ans[aux++] = 'a';
				ans[aux++] = 'b';
			}
			if (conteo["aa"] % 2) ans[aux++] = 'a';
			for (int i = 0; i < aux; ++i) cout << ans[i];
			for (int i = aux - 1; i >= 0; --i) cout << ans[i];
			cout << '\n';
			continue;
		}
		//caso general
		int cnt = 0;
		if (conteo.count("aa")) {
			if (conteo["aa"] >> 1) {
				int lim = conteo["aa"] >> 1;
				for (int i = 0; i < lim; ++i) {
					ans[cnt++] = 'a';
					ans[cnt++] = 'a';
				}
			} 
		}
		if (conteo.count("ab") && conteo.count("ba")) {
				int lim = min(conteo["ab"], conteo["ba"]);
				for (int i = 0; i < lim; ++i) {
					ans[cnt++] = 'a';
					ans[cnt++] = 'b';
				}
		}
		if (conteo.count("bb")) {
			int lim = conteo["bb"] >> 1;
			for (int i = 0; i < lim; ++i) {
				ans[cnt++] = 'b';
				ans[cnt++] = 'b';
			}
		}
		if (conteo["aa"] % 2) ans[cnt++] = 'a';
		else if (conteo["bb"] % 2) ans[cnt++] = 'b';
		for (int i = 0; i < cnt; ++i) cout << ans[i];
		for (int i = cnt - 1; i >= 0; --i) cout << ans[i];
		cout << '\n';
	}
	return 0;
}