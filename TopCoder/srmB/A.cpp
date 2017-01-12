#include <bits/stdc++.h>
using namespace std;

class SuperUserDo {
	private:
	public:
	int mf;
	vector<int> libraries;
	
	int install(vector<int> A, vector<int> B) {
		libraries = vector<int> (1001);
		int lim = A.size();
		for (int i = 0; i < lim; ++i) {
			libraries[A[i]]++;
			libraries[B[i] + 1]--;
		}
		int cnt = 0;
		for (int i = 1; i <= 1000; ++i) {
			libraries[i] += libraries[i - 1];
			if (libraries[i]) cnt++;
		}
		return cnt;
	}
	
};
