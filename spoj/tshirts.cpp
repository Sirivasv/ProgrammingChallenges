#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> ter;
typedef unsigned long long ull;

const int MAXN = 20009;
const int MAXC = 109;

ull HashT[MAXN][MAXC];
string Strs[MAXN];
ull HB[MAXC];
ull B = 71LL;

int MLen[MAXN];

void CB() {
	HB[0] = 1LL;
	for (int i = 1; i < MAXC; ++i)
		HB[i] = HB[i - 1] * B;
}

ull F(char a) {
	return (a - 'A' + 1LL);
}

void MHash(const string& s, int id) {
	int lim = s.size();
	MLen[id] = lim;
	for (int i = 1; i <= lim; ++i)
		HashT[id][i] = (HashT[id][i - 1] * B) + F(s[i - 1]);
}

ull Subs(int idh, int I, int J) {
	return (HashT[idh][J] - (HashT[idh][I - 1] * HB[(J - I + 1)]));
}

int MaxCnt(int ida, int idb) {
	int ini = 1, fin = min(MLen[ida], MLen[idb]), ans = fin + 1;
	while (ini <= fin) {
		int mid = (ini + fin) / 2;
		if (Subs(ida, 1, mid) != Subs(idb, 1, mid)) {
			ans = mid;
			fin = mid - 1;
		} else {
			
			ini = mid + 1;
		}
	}
	return ans;
}


struct Struh {
	int len;
	int id;
	bool operator<(const Struh& cmp) const {
		int ans = MaxCnt(id, cmp.id);
		ans--;
		//cout << "+++ "<< ans << ' ' << id << ' ' << cmp.id << '\n';
		if ((ans == len) && (len == cmp.len))
			return (id < cmp.id);
		if ((ans == len) || (ans == cmp.len))
			return len < cmp.len;
		//cout << Subs(ans + 1, ans + 1, id) << ' ' << Subs(ans + 1, ans + 1, cmp.id) << '\n';
		return Strs[id][ans] < Strs[cmp.id][ans];
	}
};

int main() {
	//cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	CB();
	while (cin >> N) {
		if (N == -1)
			break;
		int lim = 2 * N;
		set<Struh> vivosA, vivosB;
		for (int i = 0; i < N; ++i) {
			cin >> Strs[i];
			//cout << Strs[i] << ' ' << i << '\n';
			MHash(Strs[i], i);
			Struh A;
			A.id = i;
			A.len = MLen[i];
			vivosA.insert(A);
		}
		for (int i = N; i < lim; ++i) {
			cin >> Strs[i];
			//cout << Strs[i] << ' ' << i << '\n';
			MHash(Strs[i], i);
			Struh A;
			A.id = i;
			A.len = MLen[i];
			vivosB.insert(A);
		}
		/*
		for (set<Struh>::iterator it = vivosA.begin(); it != vivosA.end(); ++it) {
			cout << (*it).id << '\n';
		}
		for (set<Struh>::iterator it = vivosB.begin(); it != vivosB.end(); ++it) {
			cout << (*it).id << '\n';
		}*/
		
		//cout << "**\n";
		int ans = 0;
		for(;(vivosA.size()) && (vivosB.size());) {
			//cout << "**\n";
			int matsl = -1;
			set<Struh>::iterator matu;
			set<Struh>::iterator matv;
			
			for (set<Struh>::iterator it = vivosA.begin(); it != vivosA.end(); ++it) {
				set<Struh>::iterator sup = vivosB.lower_bound(*it);
				if (sup != vivosB.end()) { //hay mayor o igual
					int pans = MaxCnt((*it).id, (*sup).id);
					pans--;
					if (pans > matsl) {
						matsl = pans;
						matu = it;
						matv = sup;
					}
				}
				if (sup != vivosB.begin()) { //hay menor
					sup--;
					int pans = MaxCnt((*it).id, (*sup).id);
					pans--;
					if (pans > matsl) {
						matsl = pans;
						matu = it;
						matv = sup;
					}
				}
			}
			
			ans += matsl;			//cout << (*matu).id << ' ' << (*matv).id << '\n';
			vivosA.erase(matu);
			vivosB.erase(matv);
		}
		cout << ans << '\n';
		//cout << "*\n";
	}
	return 0;
}