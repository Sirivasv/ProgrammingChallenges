#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <set>
#include <utility>
#include <iomanip> 
#include <queue>

using namespace std;

#define pb push_back

#define N 100100

typedef unsigned long long ll;

ll d[N], n;
const ll maxn = (ll)1e18+(ll)2;

int main() {

	d[0] = (ll)0;
	d[1] = (ll)1;
	int k = 1;
	while (d[k] < maxn)
	{
		k++;
		d[k] = d[k-1]+d[k-2]+(ll)1;
	}

	cin >> n; n--;
	int i;
	for (i = 0; i <= k; i++)
		if (d[i] > n)
			break;

	cout << i-1 << endl;
	return 0;
}