#include <iostream>
#include <queue>
using namespace std;
bool visited[300][300];
int dx[] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[] = { -2,-1,1,2,2,1,-1,-2 };
struct p {
	p(int _y, int  _x) { y = _y;x = _x; }
	int y, x;
};
int main(void) {
	int t, l, x, xx, y, yy;
	bool end = 0;
	cin >> t;
	while (t-- > 0) {
		queue<p> q;
		int cnt = 0;
		cin >> l >> y >> x >> yy >> xx;
		q.push(p(y, x));
		visited[y][x] = 1;
		while (!q.empty()) {
			int size = q.size();
			for (int i = 0;i < size;i++) {
				p t = q.front();
				q.pop();
				int tx = t.x;
				int ty = t.y;
				if (tx == xx && ty == yy) { end = 1; break; }
				for (int j = 0;j < 8;j++) {
					int nx = tx + dx[j];
					int ny = ty + dy[j];
					if (nx < 0 || nx >= l || ny < 0 || ny >= l)continue;
					if (visited[ny][nx]) continue;
					q.push(p(ny, nx));
					visited[ny][nx] = 1;
				}
			}
			if (end) {
				cout << cnt << endl;
				for (int i = 0;i < l;i++)
					for (int j = 0;j < l;j++)
						visited[i][j] = 0;
				end = 0;
				break;
			}
			cnt++;
		}
	}
	return 0;
}