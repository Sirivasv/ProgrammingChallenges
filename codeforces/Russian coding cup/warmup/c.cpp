#include <bits/stdc++.h>
using namespace std;

typedef pair<int, long long> pil;

int findMedian(long long s, const vector<long long>& sums) {
    vector<pil> as;
	
    for (int i = 0; i < sums.size(); i++)
        if (sums[i] != 0)
            as.push_back(pil(i, sums[i]));
			
    long long needSum = s >> 1;
    long long currentSum = 0;
	
    for (int i = 0; i < as.size(); i++) {
        currentSum += as[i].second;
        if (currentSum == needSum) {
            if (s & 1)
                return as[i + 1].first;
			return ((as[i].first + as[i + 1].first + 1) >> 1);
        } else if (currentSum > needSum) 
            return as[i].first;
    }
    return -1;
}

long long calcSum(const vector< vector<int> >& a, int x, int y) {
    long long value = 0;
    int n = a.size();
    int m = a[0].size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)  
			value += (a[i][j] * 2LL * (abs(i - x) + abs(j - y) + 1));
    return value;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector< vector<int> > a(n, vector<int>(m));
    long long sumH = 0;
    long long sumV = 0;
    vector<long long> H(n);
    vector<long long> V(m);
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            H[i] += a[i][j];
            V[j] += a[i][j];
            sumH += a[i][j];
            sumV += a[i][j];
        }              
    int x = findMedian(sumH, H);
    int y = findMedian(sumV, V);
    cout << x + 1 << ' ' << y + 1 << ' ' << calcSum(a, x, y) << '\n';
    return 0;
}
