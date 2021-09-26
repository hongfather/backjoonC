#include <iostream>
#include <queue>
#include <vector>
const int blue = 1;
const int red = -1;
using namespace std;
vector<int>* connected;
int* colors;
bool checkBipartite;
void dfs(int idx, int color) {
	if (!checkBipartite) return;
	colors[idx] = color;
	for (int i = 0;i < connected[idx].size();i++) {
		if (colors[connected[idx][i]] != 0) {
			if (colors[connected[idx][i]] == color) {
				checkBipartite = 0;break;
			}
		}
		else
			dfs(connected[idx][i], -color);
	}
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int k, v, e, t1, t2; //v정점 e간선
	cin >> k;


	while (k-- > 0) {
		checkBipartite = 1;
		cin >> v >> e;
		connected = new vector<int>[v + 1];
		colors = new int[v + 1]{};
		for (int i = 0;i < e;i++) {
			cin >> t1 >> t2;
			connected[t1].push_back(t2);
			connected[t2].push_back(t1);
		}
		for (int i = 1;i < v + 1;i++) {
			if (!checkBipartite) break;
			if (colors[i] == 0)dfs(i, blue);

		}
		if (checkBipartite)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
	return 0;
}