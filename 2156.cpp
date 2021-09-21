#include <iostream>
using namespace std;
int n;
int* val;
int** dp;
int dfs(int depth, int cnt) {
	if (depth == n - 1) {
		if (cnt < 2) return val[depth];
		return 0;
	}
	int* ret = &dp[depth][cnt];
	if (*ret >= 0)return *ret;
	if (cnt < 2) *ret = val[depth] + dfs(depth + 1, cnt + 1);
	*ret = max(*ret, dfs(depth + 1, 0));
	return *ret;
}
int main(void) {
	cin >> n;
	val = new int[n];
	dp = new int* [n];
	for (int i = 0;i < n;i++) {
		cin >> val[i];
		dp[i] = new int[3]{ -1,-1,-1 };
	}
	cout << dfs(0, 0);
	return 0;
}