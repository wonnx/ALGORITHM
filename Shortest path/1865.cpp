#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
const int MAXN = 501;

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while (t--)
	{
		vector<pi> adj[MAXN];
		ll dist[MAXN];
		int minuscycle = 0;

		int n, m, w; cin >> n >> m >> w;
		for (int i = 0; i < m; i++)
		{
			int a, b, c; cin >> a >> b >> c;
			adj[a].push_back({ b,c });
			adj[b].push_back({ a,c });
		}
		for (int i = 0; i < w; i++)
		{
			int a, b, c; cin >> a >> b >> c;
			adj[a].push_back({ b,-c });
		}
		fill(dist, dist + MAXN, 0);
		for (int i = 0; i < n; i++)
			for (int j = 1; j <= n; j++)
				for (auto e : adj[j])
				{
					if (dist[e.first] > dist[j] + e.second)
					{
						dist[e.first] = dist[j] + e.second;
						if (i == n - 1)minuscycle = 1;
					}
				}
		minuscycle ? cout << "YES\n" : cout << "NO\n";
	}
}