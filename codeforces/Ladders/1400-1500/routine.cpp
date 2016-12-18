#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b) { 
	return ((!b)?(a):(gcd(b, a % b))); 
}

int main() {
	int a, b, c, d;
    cin >> a >> b >> c >> d;
    int p = a * d;
    int q = b * c;
    if(p > q)
        swap(p, q);
    cout << q << ' ' << p << '\n';
	p = q - p;
    int GCD = gcd(p, q);
    cout << (p / GCD) << '/' << (q / GCD) << '\n';
    return 0;
}