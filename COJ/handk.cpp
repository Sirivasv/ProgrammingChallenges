#include <bits/stdc++.h>
using namespace std;
int T, K, H, x, y;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> K >> H;
		x = (1.0 + ((sqrt(1.0 + (8.0 * H))) / 2.0));
		int x_ = x;
		int H_ = H;
		if (H == 0.0 || (H != ((x_ * (x_ - 1)) >> 1))) {
			cout << "Uhh... I do not know.\n";
			continue;
		}
		y = ((1.0 - (2.0 * x)) + (sqrt(1.0 + (8.0 * H) + (8.0 * K))))/2.0;
		int y_ = y;
		//cout << x << ' ' <<  y << '\n';
		cout << "There are " << y_ << " women and " << x_ << " men at the party.\n";
	}
	return 0;
}