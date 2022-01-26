#include<iostream>
using namespace std;

int r, c, result;
char vertex[21][21];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0, 0, -1,1 };
int alphabet[26];

void dfs(int x, int y, int n)
{
	alphabet[vertex[x][y] - 'A']++;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < r && ny >= 0 && ny < c)
			if (!alphabet[vertex[nx][ny] - 'A'])
				dfs(nx, ny, n + 1);
	}
	if (n > result) result = n;
	alphabet[vertex[x][y] - 'A']--;
}

int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++) cin >> vertex[i];
	dfs(0, 0, 1);
	cout << result;
}