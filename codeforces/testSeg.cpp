#include <bits/stdc++.h>
using namespace std;

const int MAXN = 19;

map<int, int> lpos; 

int previous[MAXN];

int getPrev(int xi, int yi) {
	cout << "Data: x{" << xi << "} yi{" << yi << "}\n";
	cout << "1\n";
	if (xi == -1) return -1;
	cout << "2\n";
	if (yi == 1) return previous[xi];
	cout << "3\n";
	return getPrev(getPrev(xi, 1), yi - 1);
}

int main() {
	
	int arr[] = { 1, 2, 3, 4, 5, 1, 1, 2, 3, 4, 5, 5, 3, 2, 2, 2, 3, 4, 5 };

	for (int i = 0; i < 19; ++i) {
		cout << arr[i] << ' ';
		lpos[arr[i]] = -1;
	}

	cout << '\n';

	for (int i = 0; i < 19; ++i) {
		previous[i] = lpos[arr[i]];
		lpos[arr[i]] = i;
		cout << previous[i] << " ";
	}

	cout << "\n";

	int k = 4;
	for (int i = 0; i < 19; ++i) {
		cout << "+++++\n";
		int val = getPrev(i, k);
		cout << "****\n";
		cout << val << '\n'; 
		cout << "-----\n";
	}
	

	return 0;
}