#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	int* val = new int[n];
	int* dp = new int[n];
	int* rvsDp = new int[n];
	for (int i = 0;i < n;i++)
		cin >> val[i];

	for (int i = 0;i < n;i++) {
		int min = 0;
		for (int j = 0;j < i;j++) {
			if (val[j] < val[i])
				min = max(dp[j], min);
		}
		dp[i] = min + 1;
	}
	for (int i = n - 1;i >= 0;i--) {
		int min = 0;
		for (int j = n - 1;j > i;j--) {
			if (val[j] < val[i])
				min = max(rvsDp[j], min);
		}
		rvsDp[i] = min + 1;

	}
	int maxVal = -1;
	for (int i = 0;i < n;i++)
		maxVal = max(maxVal, dp[i] + rvsDp[i]);
	cout << maxVal - 1;
}