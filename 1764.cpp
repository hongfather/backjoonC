// °á°ú : 12988kb 64ms
#include <iostream>	
#include <queue>
#include <map>
using namespace std;
int main(void) {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	string t;
	priority_queue<string, vector<string>, greater<string>> pq;
	cin >> n >> m;
	map<string, bool> twice;
	while (n-- > 0) {
		cin >> t;
		twice[t] = 1;
	}

	while (m-- > 0) {
		cin >> t;
		if (twice[t])  pq.push(t);
	}
	int size = pq.size();
	cout << size << '\n';
	for (int i = 0;i < size;i++, pq.pop())
		cout << pq.top() << '\n';
	return 0;
}