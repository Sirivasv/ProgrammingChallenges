#include <bits/stdc++.h>
using namespace std;

typedef int lli;

const int MAXN = 1000007; 

int arr[5][MAXN];
vector<vector<int>> ciclos;

void DFS(int u, vector<int>& vi, int idvi, int idarr) {
    arr[idvi][u] = 1;
    vi.push_back(u);
    int v = arr[idarr][u];
   	while (arr[idvi][v] != 1) {
    	vi.push_back(v);
    	arr[idvi][v] = 1;
    	v = arr[idarr][v];
    }
}

set<lli> divs;

void getDivs(lli xi) {
	lli root = sqrt(xi) + 1LL;
	for (lli i = 1LL; i <= root; ++i) {
		if (!(xi % i)) {
			divs.insert(xi / i);
			divs.insert(i);
		}
	}
}

int main() {
	
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	lli N, T;
	
	cin >> N >> T;

	for (int j = 0; j < 2; ++j) for (int i = 1; i <= N; ++i) cin >> arr[j][i];

	if (T & 1) {
		for (int i = 1; i <= N; ++i) arr[2][i] = arr[1][arr[0][i]];
		for (int i = 1; i <= N; ++i) {
			arr[1][i] = arr[2][i];
			// cout << arr[1][i] << ' ';
		}
		// cout << '\n';
		T++;
	}	
	
	lli a = T >> 1;

	// cout << a << '\n';
	
	for (int i = 1; i <= N; ++i) {
	    if (!arr[3][i]) {
	    	vector<int> vi;
	        DFS(i, vi, 3, 1);
	        ciclos.push_back(vi);
	    }
	}

	map<int, vector< vector<int> > > ciclosBS;

    for (int i = 0; i < ciclos.size(); ++i) {
        // cout << "C (" << (i + 1) << "): len = " << ciclos[i].size() << '\n';
        ciclosBS[ciclos[i].size()].push_back(ciclos[i]); 
        // for (int j = 0; j < ciclos[i].size(); ++j) {
            // cout << ciclos[i][j] << ' ';   
        // }
        // cout << '\n';
    }
    ciclos.clear();

    for (map<int, vector<vector<int>>>::iterator it = ciclosBS.begin(); it != ciclosBS.end(); it++) {
    	// cout << "Tam: " << it.first << " Many: " << it.second.size() << '\n';
    	int cnt = 1;
    	getDivs(a);
    	set<lli>::iterator itd = divs.begin();
    	
    	lli gcd = -1;

    	while (itd != divs.end()) {
    		gcd = __gcd(lli(it->first), a / lli(*itd));
    		if (gcd == 1) {
    			// cout << it.first << ' ' << int(*itd) << '\n';
    			break;
    		}
    		itd++;	
    	}

    	if ((lli((it->second).size()) % lli(*itd)) != 0) {
    		cout << "-1\n";
    		return 0;
    	}

    	lli lim = lli(*itd);
    	// cout << "L: " << lim << '\n';
    	map<int, vector<vector<int>>> mf;

    	for (int j = 0; j < it->second.size(); ++j) {
    		int cub = j / lim;
    		mf[cub].push_back(it->second[j]); 
    	}

// /*
// 	9 3
// 	--- --- ---
// */	
    	for (map<int, vector<vector<int>>>::iterator itt = mf.begin(); itt != mf.end(); ++itt) {
    		int cnt = 0;
    		
    		for (int i = 0; i < itt->second.size(); ++i) {	
    			cnt = i; 
    			for (int j = 0; j < itt->second[i].size(); ++j) {
    				arr[2][cnt] = itt->second[i][j];
    				cnt = (cnt + a) % (lim * it->first);
    				// cout << cnt << ' ';
    				// dnt += a;
    			}
    		}

    		for (int j = 0; j < ((lim * it->first)); ++j) {
    			arr[3][arr[2][j]] = arr[2][(j + 1) % (lim * it->first)];
			}
    	}

    	it->second.clear();
    }

    for (int i = 1; i <= N; ++i) {
    	arr[4][arr[0][i]] = i;
    }


	for (int i = 1; i <= N; ++i) arr[2][i] = arr[3][arr[4][i]];
	for (int i = 1; i <= N; ++i) arr[3][i] = arr[2][i];
 
    for (int i = 1; i <= N; ++i) { 
    	if (i > 1) cout << ' ';
    	cout << arr[3][i];   
    }
    cout << '\n';

	return 0;
}
