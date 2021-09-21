#include <iostream>
#include <queue>
using namespace std;
int n, cnt;
int* visited;
int main(void) {
	cin >> n;
	visited = new int[n + 1]{};
	queue<int> q;
	q.push(n);
	visited[n] = 1;
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0;i < size;i++) {
			n = q.front();
			q.pop();
			if (n == 1) { cout << cnt;break; }
			if (n % 3 == 0 && !visited[n / 3]) { q.push(n / 3);visited[n / 3] = 1; }
			if (n % 2 == 0 && !visited[n / 2]) { q.push(n / 2);visited[n / 2] = 1; }
			if (!visited[n - 1]) { q.push(n - 1);visited[n - 1] = 1; }
		}
		cnt++;
	}
	return 0;
}