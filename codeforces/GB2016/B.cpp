#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;

int arr[MAXN];
string dir[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N; 
	for (int i = 0; i < N; ++i)
		cin >> arr[i] >> dir[i];
	
	int ok = 1;
	
	int ypos = 20000;
	int npole = 20000;
	int spole = 0;
	
	for (int i = 0; i < N; ++i) {
		if (dir[i] == "North") {
			if (ypos + arr[i] > npole) { ok = 0; break; }
			if (ypos == npole) { ok = 0; break; }
			ypos += arr[i];
		} else if (dir[i] == "South") {
			if (ypos - arr[i] < spole) { ok = 0; break; }
			if (ypos == spole) { ok = 0; break; }
			ypos -= arr[i];
		} else {
			if (ypos == npole) { ok = 0; break; }
			if (ypos == spole) { ok = 0; break; }
		}
	}
	
	if (ypos != npole) ok = 0;
	
	cout << ((ok)?("YES\n"):("NO\n"));
	return 0;
}