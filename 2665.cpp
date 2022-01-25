#include<iostream>
#include<queue>
using namespace std;
#define INF 1987654321

char vertex[51][51];
int check[51][51];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> vertex[i];
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) check[i][j] = INF;

	queue<pair<int, int> > qu;
	qu.push({ 0,0 }); check[0][0] = 0;
	while (!qu.empty())
	{
		int x = qu.front().first;
		int y = qu.front().second;
		qu.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1)continue;
			if (vertex[nx][ny] == '0' && check[nx][ny] > check[x][y] + 1)
			{
				check[nx][ny] = check[x][y] + 1;
				qu.push({ nx,ny });
			}
			else if (vertex[nx][ny] == '1' && check[nx][ny] > check[x][y])
			{
				check[nx][ny] = check[x][y];
				qu.push({ nx,ny });
			}
		}
	}
	cout << check[n - 1][n - 1];
}