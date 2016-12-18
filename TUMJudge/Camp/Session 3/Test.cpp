#include <bits/stdc++.h>
using namespace std;

int main() {
	set<int> median;
	int aux;
	int manyl = 0;
	int manys = 0;
	cin >> aux;
	median.insert(aux);
	multiset<int>::iterator it = median.begin();
	cout << (*it) << '\n';
	while(cin >> aux) {
		median.insert(aux);
		if (aux >= (*it)) {
			//(it++);
			manyl++;
		} else {
			//(it--);
			manys++;
		}
		if (median.size() & 1) {
			if (manyl > manys) {
				it++;
				manyl--;
				manys++;
			} else if (manys > manyl){
				it--;
				manyl++;
				manys--;
			}	
		}
		if (median.size() & 1) {
			cout << (*it) << '\n';
		} else {
			set<int>::iterator aux = it;
			if (manyl > manys) it++;
			else it--;
			cout << (((*it) + (*aux)) / 2) << '\n';
			it = aux;
		}
	}
	return 0;
}