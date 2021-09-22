#include <iostream>
#include <queue>
using namespace std;
int main(void) {
	int n, k;
	cin >> n >> k;
	int* w = new int[n];
	int* v = new int[n];
	int** dp = new int* [n + 1];
	for (int i = 0;i < n + 1;i++)
		dp[i] = new int[k + 1]{};
	for (int i = 0;i < n;i++) {
		cin >> w[i] >> v[i];
	}
	for (int i = 1;i <= n;i++) {//i°¡ v
		for (int j = 1;j <= k;j++) { //j°¡ w
			if (w[i - 1] > j)dp[i][j] = dp[i - 1][j];
			else {
				dp[i][j] = max(dp[i - 1][j], v[i - 1] + dp[i - 1][j - w[i - 1]]);
			}
		}
	}
	cout << dp[n][k];
	return 0;
}