//°á°ú : 2020kb 0ms
#include <iostream>	
using namespace std;
int main(void) {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t, n;
	cin >> t;
	int dp[10];
	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 4;
	for (int i = 3;i < 10;i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	while (t-- > 0) {
		cin >> n;
		cout << dp[n - 1] << '\n';
	}
	return 0;
}