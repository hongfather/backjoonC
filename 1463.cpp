#include <iostream>
using namespace std;
int* dp;
int temp[3];
int n;
int main(void) {
	cin >> n;
	dp = new int[n+1];
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4;i <= n;i++) {
		temp[0] = temp[1] = temp[2] = 1000000;
		if (i % 2 == 0)temp[0] = dp[i / 2] + 1;
		if (i % 3 == 0)temp[1] = dp[i / 3] + 1;
		temp[2] = dp[i - 1] + 1;
		int minVal = 1000000;
		for (int j = 0;j < 3;j++)
			minVal = min(minVal, temp[j]);
		dp[i] = minVal;
	}
	cout << dp[n];
	return 0;
}