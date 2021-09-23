#include <iostream>
#include <queue>
using namespace std;
int n;
int maxVal = -1000000001;
int minVal = 1000000001;
int* val;
void dfs(int depth, int sum, int plus, int minus, int multiply, int divided) {
	if (depth == n - 1) {
		if (plus > 0)sum += val[depth];
		else if (minus > 0)sum -= val[depth];
		else if (multiply > 0)sum *= val[depth];
		else sum /= val[depth];
		maxVal = max(sum, maxVal);
		minVal = min(sum, minVal);
		return;
	}
	if (plus > 0)dfs(depth + 1, sum + val[depth], plus - 1, minus, multiply, divided);
	if (minus > 0)dfs(depth + 1, sum - val[depth], plus, minus - 1, multiply, divided);
	if (multiply > 0)dfs(depth + 1, sum * val[depth], plus, minus, multiply - 1, divided);
	if (divided > 0) dfs(depth + 1, sum / val[depth], plus, minus, multiply, divided - 1);
}
int main(void) {
	cin >> n;
	val = new int[n];
	int op[4];
	for (int i = 0;i < n;i++)	cin >> val[i];
	for (int i = 0;i < 4;i++)cin >> op[i];
	int sum = val[0];
	dfs(1, sum, op[0], op[1], op[2], op[3]);
	cout << maxVal << endl << minVal;
}