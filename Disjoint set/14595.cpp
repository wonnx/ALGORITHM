#include<iostream>
using namespace std;
const int MAXN = 1e6 + 1;
int p[MAXN];

int find(int u)
{
	if (p[u] == u)return u;
	else return p[u] = find(p[u]);
}

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n; cin >> n; int m; cin >> m;
	for (int i = 0; i < MAXN; i++) p[i] = i;
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		p[x] = y;
	}

	int r = 0;
	for (int i = 1; i <= n; i++)
	{
		if (p[i] == i)r++;
		else
		{
			int j, t = p[i];
			for (j = i + 1; j <= t; j++)
				if (t < p[j])t = p[j];
			i = j - 1; r++;
		}
	}
	cout << r;
}