#include <iostream>
#include <cmath>
using namespace std;
int cnt, n, r, c, ans;
void sol(int p) {//p´Â n
	for (int i = p / 2 - 1;i < p;i += p / 2) {
		for (int j = p / 2 - 1;j < p;j += p / 2) {
			if (r <= i && c <= j) {
				if (p == 2) {
					cout << ans;
					return;
				}

				r -= i - p / 2 + 1;
				c -= j - p / 2 + 1;
				sol(p / 2);
				return;
			}
			else
				ans += p * p / 4;
		}
	}
}
int main(void) {
	cin >> n >> r >> c;
	sol(pow(2, n));
	return 0;
}