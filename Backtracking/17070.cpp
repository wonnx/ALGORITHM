#include<iostream>
using namespace std;

int h[20][20], n, r;

void dfs(int x, int y, int z)
{
	if (z == 1)
	{
		if (x == n && y == n - 1) {
			r++; return;
		}
		if (y + 2 <= n && !h[x][y + 2])
			dfs(x, y + 1, 1);
		if (x + 1 <= n && y + 2 <= n && !h[x][y + 2] 
			&& !h[x + 1][y + 1] && !h[x + 1][y + 2])
			dfs(x, y + 1, 3);
	}
	else if (z == 2)
	{
		if (x == n - 1 && y == n) {
			r++; return;
		}
		if (x + 2 <= n && !h[x + 2][y])
			dfs(x + 1, y, 2);
		if (x + 2 <= n && y + 1 <= n && !h[x + 1][y + 1]
			&& !h[x + 2][y] && !h[x + 2][y + 1])
			dfs(x + 1, y, 3);
	}
	else if (z == 3)
	{
		if (x == n - 1 && y == n - 1) {
			r++; return;
		}
		if (x + 1 <= n && y + 2 <= n && !h[x + 1][y + 2])
			dfs(x + 1, y + 1, 1);
		if (x + 2 <= n && y + 1 <= n && !h[x + 2][y + 1])
			dfs(x + 1, y + 1, 2);
		if (x + 2 <= n && y + 2 <= n && !h[x + 1][y + 2]
			&& !h[x + 2][y + 1] && !h[x + 2][y + 2])
			dfs(x + 1, y + 1, 3);
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> h[i][j];
	dfs(1, 1, 1);
	cout << r;
}