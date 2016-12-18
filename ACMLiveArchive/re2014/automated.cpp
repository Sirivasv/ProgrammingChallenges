#include <bits/stdc++.h>
using namespace std;

int arr[10];

int main() {
	while ( cin >> arr[0] ) {
		for (int i = 1; i < 5; ++i)
			cin >> arr[i];
		int comp = 1, aux;
		for (int i = 0; i < 5; ++i) { 
			cin >> aux;
			comp &= (aux + arr[i] == 1);
		}
		if (comp)
			cout << "Y\n";
		else
			cout << "N\n";
	}
	return 0;
}