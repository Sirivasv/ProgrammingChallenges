#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30;

int npath;
int lpath[MAXN];

int PRE(int xj, int yj) {
	if (yj > xj) {
		npath = 2;
		lpath[0] = xj;
		lpath[1] = yj;
		return true;
	}
	return false;
}

void Process(int xi, int yi, int xj, int yj) {
	if (yi >= yj) {
		npath = -1;
		return;
	}
	int dx = xj - xi;
	int muy = dx - 1;
	int disfn = fabs(yj - (yi - (dx - 1)));
	if (disfn < (dx - 1)) {
		lpath[npath + 1] = lpath[npath] + 1;
		npath++;
		lpath[npath + 1] = lpath[npath] + 1;
		npath++;
		lpath[npath + 1] = lpath[npath] + 1;
		npath++;
		lpath[npath + 1] = lpath[npath] + 1;
		npath++;
		Process(xi - 2, yi + 2, xj, yj);
		return;
	}
	int fy = xi, iy = yi - (dx - 1);
	cout << "** " << iy << '\n';
	int ans = fy;
	while (iy <= fy) {
		cout << "***\n";
		int my = (iy + fy) >> 1;
		int disy = fabs(yj - my);
		if (disy >= (dx + 1)) {
			ans = my;
			cout << ans  << '\n';
			fy = fy - 1;
		} else {
			iy = iy + 1;
		}
	}
	lpath[npath] = fabs(yi - ans);
	npath++;
	lpath[npath] = dx;
	npath++;
	lpath[npath] = fabs(yj - ans);
	npath++;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) {
		int nc, xj, yj;
		cin >> nc >> xj >> yj;
		if ((xj == 1) && (yj == 1)) {
			cout << nc << " NO PATH\n";
			continue;
		} 
		npath = -1;
		if (PRE(xj, yj)) {
			cout << nc << ' ';
			cout << npath << ' ';
			for (int i = 0; i < npath; ++i) {
				if (i)
					cout << ' ';
				cout << lpath[i];
			}
			cout << '\n';
			continue;
		}
		//cout << "**\n";
		npath = 0;
		lpath[npath++] = 1;
		lpath[npath++] = 2;
		lpath[npath++] = 3;
		Process(-2, 2, xj, yj);
		cout << nc << ' ';
		if (npath == -1) {
			cout << " NO PATH\n";
			continue;
		}
		cout << npath << ' ';
		for (int i = 0; i < npath; ++i) {
			if (i)
				cout << ' ';
			cout << lpath[i];
		}
		cout << '\n';
	}
	return 0;
}