#include <iostream>
using namespace std;
int val[501];
int main(void) {
	int n;
	cin >> n;
	int* lis = new int[n];
	int* dp = new int[n];
	for (int i = 0;i < n;i++) {
		int t;
		cin >> t;
		cin >> val[t];
	}
	for (int i = 1, idx = 0;i < 501;i++) {
		if (val[i] > 0) {
			lis[idx++] = val[i];
			if (idx == n)break;
		}
	}
	int maxVal = 0;
	for (int i = 0;i < n;i++) {
		int min = 0;
		for (int j = 0;j < i;j++)
			if (lis[j] < lis[i])
				min = max(dp[j], min);
		dp[i] = min + 1;	
		maxVal = max(maxVal, dp[i]);
	}
	cout << n - maxVal;
}