#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1000009;
int arr[MAXN];
int ida;

long long Func() {
	map<int, long long> mp;
	mp[0] = 1;
	int acum = 0;
	long long res = 0;
	for (int i = 0; i < ida; ++i) {
		//cout << arr[i] << ' ';
		acum += arr[i];
		int mod3 = acum % 3;
		res += mp[mod3];
		mp[mod3]++;
	}
	//cout << '\n';
	return res;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	string s;
	while (cin >> s) {
		long long ans = 0;
		ida = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (!((s[i] >= '0') && (s[i] <= '9'))) {
				if (ida) {
					//cout << ida << '\n';
					ans += Func();
					ida = 0;
				}
			} else {
				arr[ida++] = s[i] - '0';
			}
		}
		if (ida) {
			//cout << ida << '\n';
			ans += Func();
			ida = 0;
		}
		cout << ans << '\n';
	}
	return 0;
}