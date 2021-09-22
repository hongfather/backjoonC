#include <iostream>
using namespace std;
string val1, val2;
int l1, l2;
int main(void) {
	cin >> val1 >> val2;
	l1 = val1.length();
	l2 = val2.length();
	int** lcs = new int* [l1 + 1];
	for (int i = 0;i < l1 + 1;i++)
		lcs[i] = new int[l2 + 1]{};
	for (int i = 1;i < l1 + 1;i++) {
		for (int j = 1;j < l2 + 1;j++) {
			if (val1[i - 1] == val2[j - 1])  lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
		}
	}
	cout << lcs[l1][l2];
}