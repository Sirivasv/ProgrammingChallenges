#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100009;

map<string, int> mc;

int arrT[MAXN], arrP[MAXN];
int F[MAXN], ans;

int Abs(int x) {
	return (x < 0)?(-x):(x);
}

int Ps, Ts;

void CF() {
	F[0] = -1;
	for (int i = 0, j = -1; i < Ps; ) {
		while (~j && (arrP[i] != arrP[j])) 
			j = F[j];
		F[++i] = ++j;
	}
}

void KMPS() {
	for (int iter = 0; iter < 13; ++iter) {
		int i = 0, j = 0;
		while (i < Ts) {
			while (j >= 0 && (((arrT[i] + iter) % 12) != arrP[j])) j = F[j];
			i++; j++;
			if (j == Ps) {
				j = F[j];
				ans++;
			}
		}
	}
}

int main() {
	mc["C"] = 0;
	mc["B#"] = 0;
	
	mc["C#"] = 1;
	mc["Db"] = 1;
	
	mc["D"] = 2;
	
	mc["D#"] = 3;
	mc["Eb"] = 3;
	
	mc["E"] = 4;
	mc["Fb"] = 4;
	
	mc["F"] = 5;
	mc["E#"] = 5;
	
	mc["F#"] = 6;
	mc["Gb"] = 6;
	
	mc["G"] = 7;
	
	mc["G#"] = 8;
	mc["Ab"] = 8;
	
	mc["A"] = 9;
	
	mc["A#"] = 10;
	mc["Bb"] = 10;
	
	mc["B"] = 11;
	mc["Cb"] = 11;

	while (cin >> Ts >> Ps) {
		if ((Ps + Ts) == 0)
			break;
		ans = 0;
		for (int i = 0; i < Ts; ++i) {
			string s;
			cin >> s;
			arrT[i] = mc[s];
		}
		
		for (int i = 0; i < Ps; ++i) {
			string s;
			cin >> s;
			arrP[i] = mc[s];
		}
		
		CF();
		
		KMPS();
		
		if (ans) 
			cout << "S\n";
		else
			cout << "N\n";
	}
	
	return 0;
}