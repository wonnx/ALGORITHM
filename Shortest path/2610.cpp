#include<iostream>
#include<algorithm>
using namespace std;
#define INF (int)1e7

int p[101], q[101], dist[101][101];
int find(int x)
{
	if (p[x] == x)return x;
	else return p[x] = find(p[x]);
}

int main()
{
	int n, m; cin >> n >> m;
	for (int i = 0; i < 101; i++)p[i] = i;
	for (int i = 0; i < 101; i++) for (int j = 0; j < 101; j++)
		i == j ? dist[i][j] = 0 : dist[i][j] = INF;

	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		dist[a][b] = 1, dist[b][a] = 1;
		int x = find(a), y = find(b);
		if (x != y)p[max(x, y)] = min(x, y);
	}
	for (int i = 1; i <= n; i++)p[i] = find(i);
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	int cnt = 0, r[101] = { 0, };
	for (int i = 1; i <= n; i++)q[p[i]]++;
	for (int i = 1; i <= n; i++)cout << p[i] << " ";
	for (int i = 1; i <= n; i++)
	{
		if (q[i])
		{
			int t = INF, idx = 0;
			for (int j = 1; j <= n; j++)
			{
				if (p[j] == i)
				{
					int tt = 0;
					for (int k = 1; k <= n; k++)
						if (p[k] == i) tt = max(tt, dist[j][k]);
					if (tt < t)t = tt, idx = j;
				}
			}
			r[cnt++] = idx;
		}
	}
	cout << cnt << endl;
	sort(r, r + cnt);
	for (int i = 0; i < cnt; i++)
		cout << r[i] << endl;
}