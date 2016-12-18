#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000009;
map<int, int> mp;
int arr[MAXN], N, M, C; 

int main() {
	scanf("%d%d%d",&N, &M, &C);
	int aux;
	for (int i = 1; i <= N; ++i)
		scanf("%d", &arr[i]);
	int i = 1; 
	int j = 1;
	int lim = (i + M - 1);
	for (; j <= lim; ++j)
		mp[arr[j]]++;
	j--;
	int fnd = 0;
	for (; j <= N; ++i) {
		auto it_ = mp.begin(), it = mp.end();
		it--;		
		if ((((*it).first) - ((*it_).first)) <= C) {
			printf("%d\n", i);
			fnd = 1;
		}
		mp[arr[i]]--;
		if (!mp[arr[i]])mp.erase(arr[i]);
		++j;
		mp[arr[j]]++;
	}
	if(!fnd) printf("NONE\n");
	return 0;
}