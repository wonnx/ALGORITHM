#include<bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;
using ll = long long;
const ll MINF = -1987654321;
const int MAXN = 101;

int check[MAXN];
ll dist[MAXN], money[MAXN];
vector<pi> vec[MAXN];
queue<int> qu;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, S, E, m; cin >> n >> S >> E >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		vec[a].push_back({ b,c });
	}
	for (int i = 0; i < n; i++)cin >> money[i];
	fill(dist, dist + MAXN, MINF);

	dist[S] = money[S];
	int pluscycle = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			for (auto e : vec[j])
				if (dist[j] != MINF && dist[e.first] < dist[j] + money[e.first] - e.second)
				{
					dist[e.first] = dist[j] + money[e.first] - e.second;
					if (i == n - 1 && !pluscycle)
					{
						//fill(check, check+MAXN, 0);
						qu.push(e.first); check[e.first] = 1;
						while (!qu.empty())
						{
							int now = qu.front(); qu.pop();
							if (now == E) { pluscycle = 1; break; }
							for (auto p : vec[now])
								if (!check[p.first])
								{
									qu.push(p.first);
									check[p.first] = 1;
								}
						}
					}
				}
	}
	if (dist[E] == MINF)cout << "gg\n";
	else if (pluscycle)cout << "Gee\n";
	else cout << dist[E];
}