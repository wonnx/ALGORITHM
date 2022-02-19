#include<iostream>
using namespace std;

int adj[1001][1001], p[1001];
int find(int x)
{
	if (p[x] == x)return x;
	else return p[x] = find(p[x]);
}

int main()
{
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> adj[i][j];

	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (adj[i][j]) p[find(i)] = p[find(j)];

	int c = 0;
	for (int i = 0; i < m; i++)
	{
		int x; cin >> x;
		if (!c)c = p[find(x)];
		else if (c != p[find(x)]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}