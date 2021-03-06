#include <iostream>
using namespace std;
int value[1001];
int dp[1001];

int max(int x, int y) {
	if (x < y) return y;
	return x;
}

int main() {
	int n;
	int res = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> value[i];
	}
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (value[j] < value[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		res = max(dp[i], res);
	}
	cout << res;	
}