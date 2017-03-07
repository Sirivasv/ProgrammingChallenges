#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 200009;

lli arr[MAXN], le[MAXN], ri[MAXN], ans[MAXN];

int main() {
	
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	int N;
	
	cin >> N;
	
	for (int i = 1; i <= N; ++i) cin >> arr[i];
	
	stack<int>  incs; 
	
	for (int i = 1; i <= N; ++i) {
		if (incs.empty()) incs.push(i);
		else if (arr[incs.top()] <= arr[i]) incs.push(i);
		else {
			int tp = incs.top();
			while (arr[tp] > arr[i]) {
				ri[tp] = i - 1;
				incs.pop();
				if (incs.empty()) break;
				tp = incs.top();
			}
			incs.push(i);
		}
	}
	
	while (!incs.empty()) {
		ri[incs.top()] = N;
		incs.pop();
	}
	
	for (int i = N; i >= 1; --i) {
		if (incs.empty()) incs.push(i);
		else if (arr[incs.top()] <= arr[i]) incs.push(i);
		else {
			int tp = incs.top();
			while (arr[tp] > arr[i]) {
				le[tp] = i + 1;
				incs.pop();
				if (incs.empty()) break;
				tp = incs.top();
			}
			incs.push(i);
		}
	}
	
	while (!incs.empty()) {
		le[incs.top()] = 1;
		incs.pop();
	}
	
	for (int i = 1; i <= N; ++i) {
		int leng = ri[i] - le[i] + 1;
		//cout << i << ' ' << arr[i] << ' ' << le[i] << ' ' << ri[i] << '\n'; 
		ans[leng] = max(ans[leng], arr[i]);
	}
	
	for (int i = N; i >= 1; --i)
		ans[i] = max(ans[i], ans[i + 1]);
	
	for (int i = 1; i <= N; ++i)
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}