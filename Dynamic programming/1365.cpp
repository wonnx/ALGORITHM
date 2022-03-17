#include<iostream>
#include<algorithm>
using namespace std;

int arr[100100], dp[100100];
int main()
{
	int n, cnt = 1; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++)
	{
		if (i == 1) dp[cnt++] = arr[1];
		else
		{
			if (arr[i] > dp[cnt - 1]) dp[cnt++] = arr[i];
			else
			{
				int idx = lower_bound(dp, dp + (cnt - 1), arr[i]) - dp;
				dp[idx] = arr[i];
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= 100100; i++)
	{
		if (dp[i] == 0)
		{
			res = i - 1;
			break;
		}
	}
	cout << n - res << endl;
	return 0;
}