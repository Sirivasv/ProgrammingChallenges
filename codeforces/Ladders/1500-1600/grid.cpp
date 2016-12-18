#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 60;

int tot, N, M;
char matr[MAXN][MAXN], vis[MAXN][MAXN];

int GetHN(const vector<pii>& Nodes) {
	int sum = 0;
	for (const auto& it : Nodes) {
		for (int j = it.second; j < M; ++j)
			if (matr[it.first][j] == 'B') {
				sum++;
				vis[it.first][j] = 1;
			} else
				break;
			
		for (int j = it.second - 1; j >= 0; --j)
			if (matr[it.first][j] == 'B') {
				sum++;
				vis[it.first][j] = 1;
			} else
				break;
	}
	return sum;
}

int Test1(int I, int J) {
	vector<pii> UpDwn;
	
	for (int i = I + 1; i < N; ++i) 
		if (matr[i][J] == 'B')
			UpDwn.push_back(pii(i, J));
		else
			break;
	
	for (int i = I - 1; i >= 0; --i)
		if (matr[i][J] == 'B')
			UpDwn.push_back(pii(i, J));
		else
			break;
	
	return GetHN(UpDwn);
}

int GetVN(const vector<pii>& Nodes) {
	int sum = 0;
	for (const auto& it : Nodes) {
		for (int i = it.first; i < N; ++i)
			if (matr[i][it.second] == 'B') {
				if (!vis[i][it.second])
					sum++;
			} else
				break;
			
		for (int i = it.first - 1; i >= 0; --i)
			if (matr[i][it.second] == 'B') {
				if (!vis[i][it.second])
					sum++;
			}  else
				break;
	}
	return sum;
}

int Test2(int I, int J) {
	vector<pii> LeRi;
	
	for (int j = J + 1; j < M; ++j) 
		if (matr[I][j] == 'B')
			LeRi.push_back(pii(I, j));
		else
			break;
	
	for (int j = J - 1; j >= 0; --j)
		if (matr[I][j] == 'B')
			LeRi.push_back(pii(I, j));
		else
			break;
	
	return GetVN(LeRi);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) 
		for (int j = 0; j < M; ++j) {
			cin >> matr[i][j];
			if (matr[i][j] == 'B')
				tot++;
		}
	for (int i = 0; i < N; ++i) 
		for (int j = 0; j < M; ++j) {
			for (int k = 0; k < N; ++k) 
				for (int l = 0; l < M; ++l)
					vis[k][l] = 0;
			if ((matr[i][j] == 'B') && ((Test1(i, j) + Test2(i, j) + 1) != tot) ) {
				cout << "NO\n";
				return 0;
			}
		}
	cout << "YES\n";
	return 0;
}