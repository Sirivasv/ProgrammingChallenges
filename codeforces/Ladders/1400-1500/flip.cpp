#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	int ccnt = 0, mno = 0, qno = 0, tqno = 0, zno = 0, tzno = 0;
	int mats = -1;
	for (int i = 0; i < N; ++i) {
		int xi;
		cin >> xi;
		if (xi == 0) {
			ccnt++;
			zno++;
		} else {
			mno++;
			qno++;
			ccnt--;
		}
		if (ccnt > mats) {
			mats = ccnt;
			tqno = qno;
			tzno = zno;
		}
		mats = max(ccnt, mats);
		if (ccnt < 0) {
			qno = 0;
			ccnt = 0;
			zno = 0;
		}
	}
	if (mno == N)
		cout << (mno - 1) << '\n';
	else
		cout << (tzno + (mno - tqno)) << '\n';
	return 0;
}