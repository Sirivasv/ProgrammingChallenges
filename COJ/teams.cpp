#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	long long ans = 0;
	ordered_set ST;
	
	cin >> N;
	
	for (int i = 0; i < N; ++i) {
		int ax;
		cin >> ax;
		ans += ST.order_of_key(-ax);
		ST.insert(-ax);
	}
	cout << ans << '\n';
	return 0;
}

