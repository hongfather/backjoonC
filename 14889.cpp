#include <iostream>
#include <vector>
using namespace std;
int n;
int ans = 1000;
int** val;
bool* selected;
int cal(int i, int j) {
	return val[i][j] + val[j][i];
}
void select(int start, int cnt) {
	if (cnt == n / 2) {
		vector<int> team1, team2;
		for (int i = 0;i < n;i++) {
			if (selected[i])
				team1.push_back(i);
			else
				team2.push_back(i);
		}

		int val1 = 0, val2 = 0;
		for (int i = 1;i < team1.size();i++)
			for (int j = 0;j < i;j++)
				val1 += cal(team1[i], team1[j]);

		for (int i = 1;i < team2.size();i++)
			for (int j = 0;j < i;j++)
				val2 += cal(team2[i], team2[j]);
		ans = min(abs(val1 - val2), ans);
		return;
	}
	for (int i = start;i < n;i++) {
		if (!selected[i]) {
			selected[i] = 1;
			select(i + 1, cnt + 1);
			selected[i] = 0;
		}
	}

}
int main(void) {
	cin >> n;

	val = new int* [n];
	selected = new bool[n] {};
	for (int i = 0;i < n;i++)val[i] = new int[n];
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)cin >> val[i][j];
	select(0, 0);
	cout << ans;

}