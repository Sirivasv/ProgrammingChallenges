#include <bits/stdc++.h>
using namespace std;

typedef pair<double, int> pdi;
typedef pair<char, pdi> pcd;

map< double, vector<pcd> > Xs;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		double xi, xj, yi, yj;
		cin >> xi >> yi >> xj >> yj;
		Xs[xi].push_back(pcd('I', pdi(yi, i)));
		Xs[xi].push_back(pcd('I', pdi(yj, -i)));
		Xs[xj].push_back(pcd('F', pdi(yi, i)));
		Xs[xj].push_back(pcd('F', pdi(yj, -i)));
	}
	
	set<pdi> Currp;
	double SumT = 0;
	double lx = (Xs.begin())->first;
	vector<pcd> tmp = ((Xs.begin())->second);
	int lim = tmp.size(); 
	for (int i = 0; i < lim; ++i)
		if (tmp[i].first == 'I')
			Currp.insert(tmp[i].second);
	
	for (map< double, vector<pcd> >:: iterator it = Xs.begin(); it != Xs.end(); ++it) {
		if (it == Xs.begin())
			continue;
		//Count Area Sum
		int cnt = (*Currp.begin()).second;
		double ly = (*Currp.begin()).first;
		for (set<pdi>::iterator sit = Currp.begin(); sit != Currp.end(); ++sit) {
			if (sit == Currp.begin())
				continue;
			int ax = cnt;
			cnt += (*sit).second;
			if ((ax == 0) && (cnt))
				ly = ((*sit).first);
			if (cnt == 0)
				SumT += ((it->first) - lx) * ((*sit).first - ly);
		}
		
		lx = (it)->first;
		tmp = (it)->second;
		lim = tmp.size(); 
		for (int i = 0; i < lim; ++i)
			if (tmp[i].first == 'I')
				Currp.insert(tmp[i].second);
			else
				Currp.erase(tmp[i].second);
	}
	cout << fixed << setprecision(2) << SumT << '\n';
	return 0;
}