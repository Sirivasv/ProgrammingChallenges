#include <bits/stdc++.h>
using namespace std;

class SubsetSumExtreme {
	private:
	public:
	int mf;
	vector<int> fa, blo;
	vector<double> memo;
	vector< vector<int> > mnc;
	
	int CalcSumI(int m) {
		int lb = blo.size();
		int sum = 0;
		for (int i = 0; i < lb; ++i)
			if (m & (1 << i))
				sum += blo[i];
		return sum;
	}
	
	int CalcSum(int m) {
		int lb = blo.size();
		int sum = 0;
		for (int i = 0; i < lb; ++i) {
			if (m & (1 << i))
				continue;
			sum += blo[i];
		}
		return sum;
	}
	
	bool CanM(int a, int b) {
		return ((a & b) == 0);
	}
	
	double DPE(int mask) {
		if (memo[mask] != -1.0)
			return memo[mask];
		double mint = 0;
		
		for (int i = 0; i < mf; ++i) {
			int ok = 0;
			double posr = 100000.0;
			for (int j = 0; j < mnc[i].size(); ++j) {
				if (CanM(mnc[i][j], mask)) {
					ok = 1;
					posr = min(posr, DPE(mask | mnc[i][j]) * (((double)1.0) / ((double)mf)));
				}
			}
			if (!ok)
				posr = (CalcSum(mask)) * (((double)1.0) / ((double)mf));
			mint += posr;
		}
		return memo[mask] = mint;
	}
	
	void CalcMN() {
		int lim = 1 << blo.size();
		int limf = fa.size();
		for (int i = 0; i < lim; ++i) {
			int ps = CalcSumI(i);
			for (int j = 0; j < limf; ++j)
				if (ps == fa[j])
					mnc[j].push_back(i);
		}
	}
	
	double getExpectation(vector<int> block, vector<int> face) {
		blo =  block;
		fa = face;
		mf = fa.size();
		memo = vector<double>(1 << (blo.size()), -1.0);
		mnc = vector< vector<int> >(fa.size()); 
		CalcMN();
		return DPE(0);
	}
};
