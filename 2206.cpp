#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;
int n, m;
bool visited[2][1000][1000];
bool map[1000][1000];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
struct a {
	a(int _x, int _y, int _can) { x = _x;y = _y;can = _can; }
	int x, y, can = 1;
};
int main(void) {
	cin >> n >> m;
	int cnt = 0;
	bool end = 0;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < m;j++)
			scanf("%1d", &map[i][j]);
	queue<a> q;
	q.push(a(0, 0, 1));
	visited[1][0][0] = 1;

	while (!q.empty()) {
		int size = q.size();
		for (int i = 0;i < size;i++) {
			a t = q.front();
			q.pop();
			int x = t.x;
			int y = t.y;
			int can = t.can;
			if (x == m - 1 && y == n - 1) { end = 1;break; }
			for (int j = 0;j < 4;j++) {
				int nX = x + dx[j];
				int nY = y + dy[j];
				if (nX < 0 || nX >= m || nY < 0 || nY >= n) continue;
				if (map[nY][nX]) {
					if (can < 1 || visited[can - 1][nY][nX]) continue;
					q.push(a(nX, nY, can - 1));
					visited[can - 1][nY][nX] = 1;
				}
				else {
					if (visited[can][nY][nX]) continue;
					q.push(a(nX, nY, can));
					visited[can][nY][nX] = 1;
				}
			}
		}
		cnt++;
		if (end) break;
	}
	if (end)
		cout << cnt;
	else
		cout << -1;

}