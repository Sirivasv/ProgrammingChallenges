#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10;

int arr[MAXN];

bool IsOp(char c) {
	return ((c == '+') || (c == '-' ) || (c == '*'));
}

int GetResult(int a, int b, char c) {
	if (c == '+')
		return a + b;
	else if (c == '-')
		return a - b;
	return a * b;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	for (int nc = 1; nc <= T; ++nc) {
		int N;
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> arr[i]; 
		int M;
		cin >> M;
		string s;
		cin >> s;
		int lim = s.size();
		sort(arr, arr + N);
		int flag = 0;
		do {
			stack <int> S;
			stack <char> O;
			int v = 0;
			for (int i = 0; i < lim; ++i) {
				if (IsOp(s[i]))
					O.push(s[i]);
				else if ((s[i] >= 'a') && (s[i] <= 'z'))
					S.push(arr[v++]);
				else if (s[i] == ')') {
					int b = S.top();
					S.pop();
					int a = S.top();
					S.pop();
					S.push(GetResult(a, b, O.top()));
					O.pop();
				} 
			}
			if (S.top() == M)
				flag = 1;
		} while(next_permutation(arr, arr + N));
		if (flag)
			cout << "Case #" << nc << ": YES\n";
		else
			cout << "Case #" << nc << ": NO\n";
	}
	return 0;
}