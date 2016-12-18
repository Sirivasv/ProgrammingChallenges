#include <bits/stdc++.h>
using namespace std;

#define A first.first
#define X first.second
#define Y second.first
#define Z second.second

typedef pair<int, int> pii;
typedef pair<pii, pii> Fourv;
typedef pair<int, pii> Ter;

const int MAXN = 6009;
Ter Case[MAXN];
Fourv Box[MAXN];
int DP[MAXN];
int idB;

void Build(int n) {
	idB = 0;
	for (int i = 0; i < n; ++i) {
		int x_ = Case[i].first;
		int y_ = Case[i].second.first;
		int z_ = Case[i].second.second;
		//Rot 1
		Box[idB].A = x_ * y_;
		Box[idB].X = x_;
		Box[idB].Y = y_;
		Box[idB++].Z = z_;
		//Rot 2
		x_ = Case[i].first;
		z_ = Case[i].second.first;
		y_ = Case[i].second.second;
		Box[idB].A = x_ * y_;
		Box[idB].X = x_;
		Box[idB].Y = y_;
		Box[idB++].Z = z_;
		//Rot 3
		y_ = Case[i].first;
		x_ = Case[i].second.first;
		z_ = Case[i].second.second;
		Box[idB].A = x_ * y_;
		Box[idB].X = x_;
		Box[idB].Y = y_;
		Box[idB++].Z = z_;
		//Rot 4
		y_ = Case[i].first;
		z_ = Case[i].second.first;
		x_ = Case[i].second.second;
		Box[idB].A = x_ * y_;
		Box[idB].X = x_;
		Box[idB].Y = y_;
		Box[idB++].Z = z_;
		//Rot 5
		z_ = Case[i].first;
		y_ = Case[i].second.first;
		x_ = Case[i].second.second;
		Box[idB].A = x_ * y_;
		Box[idB].X = x_;
		Box[idB].Y = y_;
		Box[idB++].Z = z_;
		//Rot 6
		z_ = Case[i].first;
		x_ = Case[i].second.first;
		y_ = Case[i].second.second;
		Box[idB].A = x_ * y_;
		Box[idB].X = x_;
		Box[idB].Y = y_;
		Box[idB++].Z = z_;
	}
	sort(Box, Box + idB);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T, H, N;
	cin >> T;
	for (int nc = 1; nc <= T; ++nc) {
		cin >> H >> N;
		for (int i = 0; i < N; ++i)
			cin >> Case[i].first >> Case[i].second.first >> Case[i].second.second; 
		Build(N);
		int mt = 0;
		for (int i = idB - 1; i >= 0; --i) {
			DP[i] = 0;
			for (int j = i + 1; j < idB; ++j)
				if ((Box[i].X < Box[j].X) && (Box[i].Y < Box[j].Y))
					DP[i] = max(DP[i], DP[j]);
			DP[i] += Box[i].Z;
			mt = max(mt, DP[i]);
		}
		cout << "Case #" << nc << ": ";
		if (mt >= H)
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}