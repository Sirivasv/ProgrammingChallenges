#include <bits/stdc++.h>
using namespace std;

int distas[500];
int manyc[500];
int N, H;

int Abs(int x) {
	return x < 0 ? -x : x;
}

bool Valid (int id) {
	return ((id >= 0) && (id < N));
}

int Need(int hid) {
	if (distas[hid] == 0) 
		return 1;
	if (Valid(H + distas[hid]) && Valid(H - distas[hid]))
		return 2;
	return 1;
} 

bool Can(int id) {
	//cout << distas[id] << '\n';
	//cout << id << ' ' <<  Need(id) << ' ' << manyc[distas[id]] << '\n';
	return (Need(id) == manyc[distas[id]]);
} 

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int cr, dst;
	cin >> N >> H;
	H--;
	for (int i = 0; i < N; ++i) {
		cin >> cr;
		dst = Abs(H - i);
		manyc[dst] += cr;
		distas[i] = dst;
	}
	
	int ans = 0;
	for (int i = 0; i < N; ++i)
		if (Can(i))
			ans++;
	cout << ans << '\n';
	return 0;
}