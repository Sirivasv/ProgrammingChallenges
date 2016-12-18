#include <bits/stdc++.h>
using namespace std;
//--min
//int arr[] = {7, 6, 3, 5, 6};
//int arr[] = {7, 6, 5, 3, 5, 6, 7};
//--max
//int arr[] = {1, 2, 2, 5, 2, 2, 1};
//int arr[] = {1, 2, 3, 4, 5};
//int arr[] = {5, 4, 3, 2, 1};
int arr[] = {1, 2, 3, 2, 1};
//int arr[] = {1, 2, 2, 2, 2, 2, 5};

int main() {
	int ini = 0;
	int fin = 4;
	int ans = 0;
	while (ini < fin) {
		int m1 = ceil((double)(ini + fin) / 3.0);
		m1 = max(m1, ini);
		int m2 = (floor(((double)(ini + fin)) / 3.0) * 2.0);
		if (m2 == m1)
			m2 = m1 + 1;
		m2 = min(m2, fin);
		cout << "**\n";
		cout << ini << ' ' << fin << '\n';
		cout << m1 << ' ' << m2 << '\n';
		cout << arr[m1] << ' ' << arr[m2] << '\n';
		
		if (arr[m1] > arr[m2]) {
			fin = m2 - 1;
			ans = arr[m1];
		} else if (arr[m2] >= arr[m1]){
			ini = m1 + 1;
			ans = arr[m2];
		}
	}
	cout << ans << '\n';
	return 0;
}