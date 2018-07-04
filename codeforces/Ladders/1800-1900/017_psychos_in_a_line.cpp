#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100009;

int arr[MAXN];
int matsM[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	stack<int> st;
	int mats = 0;
	for (int i = N - 1; i >= 0; --i) {
		if (st.empty()){
			st.push(i);
			continue;
		}
		int tp = st.top();
		while (arr[tp] < arr[i]) {
			matsM[i] = max(matsM[i] + 1, matsM[tp]);
			st.pop();
			if (st.empty()) break;
			tp = st.top();
		}
		mats = max(mats, matsM[i]);
		st.push(i);
	}
	cout << mats << '\n';
	return 0;
}