//결과 : 17600kb 1720ms
#include <iostream>	
#include <queue>
#include <set>
using namespace std;
int main(void) {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(0);
	int k, t, v;
	char op;
	cin >> k;
	multiset<int>::iterator iter;
	while (k-- > 0) {
		multiset<int> ms;//가장작은게 ms.begin() 가장큰게 ms.end()
		cin >> t;
		while (t-- > 0) {
			cin >> op >> v;
			if (op == 'I')
				ms.insert(v);
			else {
				if (ms.size() == 0)continue;
				if (v == 1) { iter = ms.end(); iter--; }
				else iter = ms.begin();
				ms.erase(iter);
			}

		}
		if (ms.size() == 0) cout << "EMPTY\n";
		else if (ms.size() == 1) { iter = ms.begin();cout << *iter << " " << *iter << '\n'; }
		else {
			iter = ms.end();
			iter--;
			cout << *iter << " ";
			iter = ms.begin();
			cout << *iter << '\n';
		}
	}
	return 0;
}