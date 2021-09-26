//bfs  버전 
//결과 : 19964kb 912ms
#include <iostream>
#include <queue>
#include <vector>
const int blue = 1;
const int red = -1;
using namespace std;
vector<int>* connected;
int* colors;
bool checkBipartite;
void bfs(int idx, int color) {
	queue<int> q;
	q.push(idx);
	colors[idx] = color;
	while (!q.empty() && checkBipartite) {
		int v = q.front();q.pop();
		int c = colors[v];
		for (int i = 0;i < connected[v].size();i++) {
			if (colors[connected[v][i]] == 0) {
				q.push(connected[v][i]);
				colors[connected[v][i]] = -c;
			}
			else if (colors[connected[v][i]] == c) {
				checkBipartite = 0;
				break;
			}
		}
	}
}
int main(void) {
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
			if (colors[i] == 0)bfs(i, blue);

		}
		if (checkBipartite)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
	return 0;
}