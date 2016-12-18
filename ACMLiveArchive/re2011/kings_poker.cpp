#include <bits/stdc++.h>
using namespace std; 
int arr[5], typ;

void Bws() {
	int v = arr[0] + 1;
	if (v <= 13)
		cout << v << ' ' << v << ' ' << v << '\n';
 	else 
		cout << "*\n";
}

int unmtch() {
	if ((arr[0] != arr[1]) && (arr[0] != arr[2]))
		return 0;
	if ((arr[1] != arr[0]) && (arr[1] != arr[2]))
		return 1;
	return 2;
}

bool Bwp() {
	int unid = unmtch();
	int id;
	for (int i = 0; i < 2; ++i)
		if (i != unid)
			id = i;
	int val = arr[unid] + 1;
	
	for (; val <= 13; ++val)
		if (val != arr[id])
			break;
	
	if (val <= 13) {
			arr[unid] = val;
			sort(arr, arr + 3);
			for (int i = 0; i < 3; ++i) {
				if (i) cout << ' ';
				cout << arr[i];
			}
			cout << '\n';
			return true;
	} else {
		if (arr[id] + 1 <= 13) {
			cout << "1 " << arr[id] + 1 << ' ' << arr[id] + 1 << '\n';
			return true;
		}
		return false;
	}
	
}

int dt(){
	if ((arr[0] == arr[1]) && (arr[0] == arr[2])) 
		return 1;
	if ((arr[0] == arr[1]) || (arr[0] == arr[2]) || (arr[1] == arr[2]))
		return 2;
	return 3;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	while (cin >> arr[0] >> arr[1] >> arr[2]) {
		if (!(arr[0] + arr[1] + arr[2])) 
			break;
		typ = dt();
		//typ = 1 set
		//typ = 2 pair
		//typ = 3 unm
		if (typ == 1)
			Bws();
		else if (typ == 2) {
			if (!Bwp())
				cout << "1 1 1\n";
		} else 
			cout << "1 1 2\n";
	}
	return 0;
}