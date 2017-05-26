#include <bits/stdc++.h>
using namespace std;

int conWin, currStars, currRank;

int starsInRank(int xi) {
	if (xi == 0) return 1000000;
	if ((xi >= 1) && (xi <= 10)) return 5;
	if ((xi >= 11) && (xi <= 15)) return 4;
	if ((xi >= 16) && (xi <= 20)) return 3;
	if ((xi >= 21) && (xi <= 25)) return 2;
} 

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	string s;
	cin >> s;
	currRank = 25;
	int l = s.size();
	for (int i = 0; i < l; ++i) {
		//cout << currStars << ' ' << currRank << ' ' << conWin << '\n';
		if (s[i] == 'W') {
			currStars++;
			conWin++;
			if ((conWin >= 3) && (currRank >= 6) && (currRank <= 25)) currStars++;
			if (currStars > starsInRank(currRank)) {
				currStars -= starsInRank(currRank);
				currRank--;
			}
		} else {
			conWin = 0;
			if (currRank > 20) continue;
			if (currRank == 20) {
				currStars = max(0, currStars - 1);
				continue;
			}
			currStars--;
			if ((currStars < 0) && (currRank)) {
				currRank++;
				currStars = starsInRank(currRank) - 1;
			}
		}
	}
	//cout << currStars << ' ' << currRank << ' ' << conWin << '\n';
	if (currRank) cout << currRank << '\n';
	else cout << "Legend\n";
	return 0;
}