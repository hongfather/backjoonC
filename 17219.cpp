//°á°ú : 16684kb 264ms
#include <iostream>	
#include <map>
using namespace std;
int dp[1000];
int main(void) {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	string t1, t2;
	cin >> n >> m;
	map<string, string> mp;
	while (n-- > 0) {
		cin >> t1 >> t2;
		mp[t1] = t2;
	}
	while (m-- > 0) {
		cin >> t1;
		cout << mp[t1] << '\n';
	}
	return 0;
}