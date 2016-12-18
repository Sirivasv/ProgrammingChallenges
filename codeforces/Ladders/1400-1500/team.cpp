#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2000009;

char arr[MAXN], arri[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int Z, O;
	cin >> Z >> O;
	int arrl = 0;
	while (O) { //mientras hay unos poner 1 o 2 unos
		int mn = min(2, O);
		O -= mn;
		while (mn--) {
			arr[arrl++] = '1';
		}
		if (Z) { //poner 0 final
			Z--;
			arr[arrl++] = '0';
		}
	}
	//cout << O << ' ' << Z << '\n';
	int arril = 0;
	if (Z) {
		arri[arril++] = '0';
		Z--;
	}
	for (int i = 0; i < arrl; ++i) {
		arri[arril++] = arr[i];
		if (((arr[i] == '1') && (arr[i + 1] == '1')) && (Z)) {
			arri[arril++] = '0';
			Z--;
		}
	}
	int ok = 1;
	for (int i = 0; i < arril; ++i) {
		if (((i + 1) < arril) && (arri[i] == arri[i + 1]) && (arri[i] == '0'))
			ok = 0;
		if (((i + 2) < arril) && (arri[i] == arri[i + 1]) && (arri[i] == arri[i + 2]) && (arri[i] == '1'))
			ok = 0;
	}
	if (Z || O)
		ok = 0;
	if (ok) {
		for (int i = 0; i < arril; ++i)
			cout << arri[i];
		cout << '\n';
	} else cout << "-1\n";
	return 0;
}