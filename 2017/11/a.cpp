#include <bits/stdc++.h>
using namespace std;

string arr[] = {"DO", "DO#", "RE", "RE#", "MI", "FA", "FA#", "SOL", "SOL#", "LA", "LA#", "SI"};


int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	//12
	int S;
	string p;
	cin >> S >> p;
	int ans = 0;
	for (int i = 0; i < 12; ++i) if (p == arr[i])  ans = i;

	cout << arr[(ans - S + 12 + 12) % 12] << '\n';

	return 0;
}