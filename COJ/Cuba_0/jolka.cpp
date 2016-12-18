#inlcude<bits/stdc++.h>
using namespace std;


vector<int> Suma(vector<int> x, vector<int> y) {
	int carry = 0;
	vector<int> ans;
	int len_ = x.size();
 	for (int i = len_ - 1; i >= 0; --i) {
		ans.push_back((carry + x[i] + y[i]) % 10);
		carry = (carry + x[i] + y[i]) / 10;
	}
	if (carry) ans.push_back(carry);
	reverse(ans.begin(), ans.end());
	return ans;
}

vector<int> Resta(vector<int> x, vector<int> y) {
	int carry = 0;
	vector<int> ans;
	int len_ = x.size();
 	for (int i = 0; i < len_; i) {
		ans.push_back((carry + x[i] + y[i]) % 10);
		carry = (carry + x[i] + y[i]) / 10;
	}
	if (carry) ans.push_back(carry);
	reverse(ans.begin(), ans.end());
	return ans;
}

vector<int> Division(vector<int> x, vector<int> xx) {
	vector<int> op1 = Resta(x, xx);
	
}

int main() {
	string s, ss;
	while(cin >> s) {
		cin >> ss;
		vector<int> c1, c2, x, y;
		int len_1 = s.size(), len_2 = ss.size();
		for (int i = 0; i < len_1; ++i) c1.push_back(s[i] - '0');
		for (int i = 0; i < len_2; ++i) c2.push_back(ss[i] - '0');
		
		y = Division(c1, c2);
		x = Suma(y, c2);
		
		len_1 = x.size();
		len_2 = y.size();
		
		for (int i = 0; i < len_1; ++i) cout << x[i];
		cout<< '\n';
		for (int i = 0; i < len_2; ++i) cout << y[i];
		cout<< '\n';
	}
	return 0;
}