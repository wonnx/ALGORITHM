#include<iostream>
using namespace std;
#define MAXN 1001
#define INF 1987654321
using ll = long long;

ll road[MAXN][MAXN];
int main()
{
	int n, m, x; cin >> n >> m >> x;
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
			road[i][j] = INF;
	for (int i = 0; i < MAXN; i++)road[i][i] = 0;
	for (int i = 0; i < m; i++)
	{
		int a, b, w; cin >> a >> b >> w;
		road[a][b] = w;
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				road[i][j] = min(road[i][j], road[i][k] + road[k][j]);
	ll r = 0;
	for (int i = 1; i <= n; i++)
		r = max(r, road[i][x] + road[x][i]);
	cout << r;
}