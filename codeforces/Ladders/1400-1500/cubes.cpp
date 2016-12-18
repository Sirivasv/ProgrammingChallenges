#include <bits/stdc++.h>
using namespace std;

int arr[200009];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n_, m_;
	cin >> n_ >> m_;
	int lim = n_ + m_;
	
	int pntsame1 = 0;
	int pntsame2 = 0;
	
	int pntdif1 = 0;
	int pntdif2 = 0;
	
	//petya first selects a red cube
	int n = n_;
	int m = m_;
	
	arr[0] = 1;
	n--;
	
	for (int i = 1; i < lim; ++i) {
		if (i & 1) { //wants a dif color
			if (arr[i - 1]) {
				if (m) {
					m--;
					arr[i] = 0;
				} else {
					n--;
					arr[i] = 1;
				}
			} else {
				if (n) {
					n--;
					arr[i] = 1;
				} else {
					m--;
					arr[i] = 0;
				}
			}
		} else { //wants same color
			if (arr[i - 1] == 0) {
				if (m) {
					m--;
					arr[i] = 0;
				} else {
					n--;
					arr[i] = 1;
				}
			} else {
				if (n) {
					n--;
					arr[i] = 1;
				} else {
					m--;
					arr[i] = 0;
				}
			}
		}
	}
	
	//calcs points for first try
	for (int i = 1; i < lim; ++i)
		if (arr[i] == arr[i - 1])
			pntsame1++;
		else
			pntdif1++;
		
	//petya now selects a blue cube
	n = n_;
	m = m_;
	
	arr[0] = 0;
	m--;
	
	for (int i = 1; i < lim; ++i) {
		if (i & 1) { //wants a dif color
			if (arr[i - 1]) {
				if (m) {
					m--;
					arr[i] = 0;
				} else {
					n--;
					arr[i] = 1;
				}
			} else {
				if (n) {
					n--;
					arr[i] = 1;
				} else {
					m--;
					arr[i] = 0;
				}
			}
		} else { //wants same color
			if (arr[i - 1] == 0) {
				if (m) {
					m--;
					arr[i] = 0;
				} else {
					n--;
					arr[i] = 1;
				}
			} else {
				if (n) {
					n--;
					arr[i] = 1;
				} else {
					m--;
					arr[i] = 0;
				}
			}
		}
	}
	
	//calcs points for first try
	for (int i = 1; i < lim; ++i)
		if (arr[i] == arr[i - 1])
			pntsame2++;
		else
			pntdif2++;
	
	if (pntsame1 > pntsame2)
		cout << pntsame1 << ' ' << pntdif1 << '\n';
	else
		cout << pntsame2 << ' ' << pntdif2 << '\n';
	
	return 0;
}