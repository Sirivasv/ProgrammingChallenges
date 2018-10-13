#include <bits/stdc++.h>

using namespace std;

int main() {

	cin.tie(0); ios_base::sync_with_stdio(0);

	string nm;

	int N;
	cin >> N; 
	int cnt = 1;
	int flag = 1;
	while (N--) {
		cin >> nm;
		if (nm[0] != 'm') {

			stringstream iss(nm);
			int num;
			iss >> num;
			if (num != cnt) {
				flag = 0;
			}
		}
		cnt++;
	}

	cout << ((flag)?("makes sense"):("something is fishy")) << '\n';

	return 0;
}