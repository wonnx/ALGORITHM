#include<iostream>
using namespace std;

int n, m, r;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int vtx[501][501], dp[501][501];

int dfs(int x, int y)
{
	if (x == m && y == n)return 1;
	if (dp[x][y] != -1)return dp[x][y];

	dp[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<1 || nx>m || ny<1 || ny>n) continue;
		if (vtx[nx][ny] < vtx[x][y]) 
			dp[x][y] += dfs(nx, ny);
	}
	return dp[x][y];
}

int main()
{
	cin >> m >> n;
	
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = -1;
			cin >> vtx[i][j];
		}
	cout << dfs(1, 1);
}