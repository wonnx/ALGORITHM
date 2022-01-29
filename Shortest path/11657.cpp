#include<iostream>
#include<vector>
using namespace std;
#define MAXN 501
#define INF 1987654321
using pii = pair<int, int>;
using ll = long long;

ll dist[MAXN];
vector<pii> vec[MAXN];
int main()
{
	int n, m; cin >> n >> m;
	fill(dist, dist + MAXN, INF);
	for (int i = 0; i < m; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		vec[a].push_back({ b,c });
	}
	int flag = 0;
	dist[1] = 0;
	for(int i=0; i<n; i++)
		for(int j=1; j<=n; j++)
			for(auto e: vec[j])
				if (dist[j] != INF && dist[e.first] > dist[j] + e.second)
				{
					dist[e.first] = dist[j] + e.second;
					if (i == n - 1)flag = 1;
				}
	if (flag)cout << -1;
	else for (int i = 2; i <= n; i++)
		dist[i] != INF ? cout << dist[i] << endl : cout << -1 << endl;
}