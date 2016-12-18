#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);	ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	map<long long, int> maxi, mini;
	for (int i = 0; i < N; ++i) {
		long long num;
		cin >> num;
		maxi[(-num)]++;
		mini[num]++;
	}
	int lim = N - 2;
	for (int i = 0; i < lim; ++i) {
		long long minia = (mini.begin())->first;
		auto it = maxi.begin();
		long long maxia = -(it->first);
		if ((it->second) == 1)
			it++;
		long long maxib = -(it->first);
		long long nvalue = (maxia + maxib) >> 1;
		mini[nvalue] += 2;
		maxi[-nvalue] += 2;
		mini[minia]--;
		if (!mini[minia])
			mini.erase(minia);
		maxi[-minia]--;
		if (!maxi[-minia])
			maxi.erase(-minia);
		mini[maxia]--;
		if (!mini[maxia])
			mini.erase(maxia);
		maxi[-maxia]--;
		if (!maxi[-maxia])
			maxi.erase(-maxia);
		mini[maxib]--;
		if (!mini[maxib])
			mini.erase(maxib);
		maxi[-maxib]--;
		if (!maxi[-maxib])
			maxi.erase(-maxib);
	}
	cout << ((mini.begin())->first) << '\n';
	return 0;
}