#include<iostream>
#include<vector>
#include<queue>
using namespace std;

queue<int> qu;
vector<int> vec[501];
int tm[501], ind[501], dp[501];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int t; cin >> t; tm[i] = t;
		while (true)
		{
			int tmp; cin >> tmp;
			if (tmp != -1)vec[tmp].push_back(i), ind[i]++;
			else break;
		}
	}
	for (int i = 1; i <= n; i++)	if (!ind[i])qu.push(i);
	while (!qu.empty())
	{
		int now = qu.front(); qu.pop();
		for (int i = 0; i < vec[now].size(); i++)
		{
			int next = vec[now][i];
			if (dp[next] < dp[now] + tm[now])
				dp[next] = dp[now] + tm[now];
			if (!--ind[next])qu.push(next);
		}
	}
	for (int i = 1; i <= n; i++)
		cout << dp[i] + tm[i] << endl;
}