//°á°ú : 6400kb 96ms
#include <iostream>	
#include <vector>
using namespace std;
vector<int> connected[1001];
bool visited[1001]{};
void dfs(int v) {
	visited[v] = 1;
	for (int i = 0;i < connected[v].size();i++) {
		if (!visited[connected[v][i]]) dfs(connected[v][i]);
	}
}
int main(void) {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m, a, b;
	cin >> n >> m;

	while (m-- > 0) {
		cin >> a >> b;
		connected[a].push_back(b);
		connected[b].push_back(a);
	}
	int cnt = 0;
	for (int i = 1;i <= n;i++) {
		if (!visited[i]) {
			dfs(i); cnt++;
		}

	}
	cout << cnt << '\n';
	return 0;
}