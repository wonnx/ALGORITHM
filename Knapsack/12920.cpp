#include<iostream>
using namespace std;
int dp[10001];
int main()
{
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int v, c, k, t = 1;
		cin >> v >> c >> k;
		while (k > 0) {
			int l = min(t, k);
			for (int j = m; j >= v * l; j--)
				dp[j] = max(dp[j], dp[j - v * l] + c * l);
			t <<= 1; k -= l;
		}
	}
	cout << dp[m];
}