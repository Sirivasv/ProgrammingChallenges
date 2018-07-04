#include <bits/stdc++.h>
using namespace std;

typedef long double Double;

const Double ERROR = 1e-9;
map<string, Double> mp;

bool mayorIgual(Double a, Double b) {
	if ((a > b) || (Double(fabs(a - b)) < ERROR)) return true;
	return false;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	int N;
	cin >> N;

	mp["pink"] = Double(log10(Double(1.0)));

	for (int i = 0; i < N; ++i) {
		string a, b;
	 	Double rt;
	 	cin >> a >> b >> rt;
	 	if (mp.count(b)) { 
 			Double valor = Double(log10(rt)) + mp[b];
 			if (mp.count(a)) {
	 			if (mayorIgual(valor, mp[a])) {
	 				mp[a] = valor;
	 			}
	 		} else {
	 			mp[a] = valor;
	 		}
 		}
	}

	if (!mp.count("blue")) {
		cout << fixed << setprecision(9) << 0 << '\n';
		return 0;
	}

	if (mayorIgual(mp["blue"], Double(1.0))) {
		cout << fixed << setprecision(9) << 10.0 << '\n';
	} else {
		Double pval = pow(Double(10.0), mp["blue"]);
		if (mayorIgual(pval, 10.0)) {
			cout << fixed << setprecision(9) << 10.0 << '\n';
		} else {
			cout << fixed << setprecision(9) << pval << '\n';
		}
	}

	return 0;
}