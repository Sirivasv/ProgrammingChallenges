#include <bits/stdc++.h>
using namespace std;

int many[15];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	string num, tot = "998877665544332211";
	while (cin >> num) {
		for (int i = 0; i < 10; ++i)
			many[i] = 0;
		
		int fl = 0, lim = num.size();
		
		for (int i = 0; i < lim; ++i) {
			many[num[i] - '0']++;
			if (many[num[i] - '0'] > 2) 
				fl = 1;
		}
		
		if (!fl) {
			cout << num << '\n';
			continue;
		}
		
		for (int i = 0; i < 10; ++i)
			many[i] = 0;
		
		int id = 0, ft = 0, frv = 0;
 		while (true) {
			if (id >= lim) break;
			
			int val = num[id] - '0';
			
			if (many[val] < 2) {
				many[val]++;
				id++;
				if (frv) 
					break;
			} else {
				while ((val >= 0) && (many[val] == 2)) { 
					val--;
				}
				
				if (val < 0) {
					id--;
					if (id < 0) {
						ft = 1;
						break;
					}
					while((num[id] - '0') == 0) {
						many[num[id] - '0']--;
						id--;
					}
					many[num[id] - '0']--;
					num[id] = num[id] - 1;
					frv = 1;
				} else {
					num[id] = val + '0';
					many[val]++;
					id++;
					break;
				}
			}
		}
		
		if (ft) {
			lim--;
			for (int i = 0; i < lim; ++i)
				cout << tot[i];
			cout << '\n';
		} else {
			int value = 9;
			int i  = 0;
			while (num[i] == '0') ++i;
			
			for (; i < id; ++i)
				cout << num[i];
			for (; id < lim;) {
				if (many[value] < 2) {
					cout << value;
					many[value]++;
					id++;
				} else {
					value--;
					if (value < 1)
						break;
				}
			}
		}
		cout << '\n';
	}
	return 0;
}