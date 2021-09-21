#include <iostream>
using namespace std;
int n;
int** dp;
const int modNum = 1000000000;
int dfs(int depth, int num) {
	if (depth == n)return 1;
	int* ret = &dp[depth][num];
	if (*ret > 0)return *ret;
	if (num > 0) *ret += (dfs(depth + 1, num - 1) % modNum);
	if (num <= 8) *ret += (dfs(depth + 1, num + 1) % modNum);
	return *ret;
}
long long sol() {
	long long  ret = 0;
	for (int i = 1;i <= 9;i++) {
		ret += (dfs(1, i) % modNum);
	}
	return ret % modNum;
}
int main(void) {
	cin >> n;
	dp = new int* [n];
	for (int i = 0;i < n;i++) {
		dp[i] = new int[10]{};
	}
	cout << sol();
}