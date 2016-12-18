#include <bits/stdc++.h>
using namespace std;

int arr[5];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int A, B, C;
	while (cin >> A >> B >> C) {
		if (!(A || B || C))
			break;
		if ((A == B) && (B == C)) { //is a set
			if (A < 13)
				cout << (A + 1) << ' ' << (A + 1) << ' ' << (A + 1) << '\n';
			else
				cout << "*\n";
			continue;
		} else if ((A == B) || (A == C) || (C == B)) { //is a pair
			int unp, pa;
			if (A == B) {
				unp = C;
				pa = A;
			} else if (A == C) {
				unp = B;
				pa = C;
			} else { 
				unp = A;
				pa = B;
			}
			if (unp < 13) {
				if ((unp + 1) != (pa)) {
					arr[0] = pa;
					arr[1] = pa;
					arr[2] = unp + 1;
				} else {
					if ((unp + 2) <= 13) {
						arr[0] = pa;
						arr[1] = pa;
						arr[2] = unp + 2;
					} else {
						if ((pa + 1) <= 13) {
							arr[0] = pa + 1;
							arr[1] = pa + 1;
							arr[2] = 1;
						} else {
							arr[0] = 1;
							arr[1] = 1;
							arr[2] = 1;
						}
					}
				}
			} else {
				arr[0] = pa + 1;
				arr[1] = pa + 1;
				arr[2] = 1;
			}
		} else {
			arr[0] = 1;
			arr[1] = 1;
			arr[2] = 2;
		}
		sort(arr, arr + 3);
		for (int i = 0; i < 3; ++i) {
			if (i)
				cout << ' ';
			cout << arr[i];
		}
		cout << '\n';
	}
	return 0;
}