#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAXN 1001
#define INF (int)1e11
using ll = long long;
using pl = pair<ll, ll>;

ll dist[MAXN];
vector<pl> vec[MAXN];

int main()
{
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, w; cin >> a >> b >> w;
		vec[a].push_back({ b,w });
	}
	fill(dist, dist + MAXN, INF);
	int s, d; cin >> s >> d;
	priority_queue<pl> pq;
	pq.push({ 0,s }); dist[s] = 0;
	while (pq.size())
	{
		auto now = pq.top(); pq.pop();
		for (auto e : vec[now.second])
			if (dist[e.first] > dist[now.second] + e.second)
			{
				dist[e.first] = dist[now.second] + e.second;
				pq.push({ -dist[e.first], e.first });
			}
	}
	cout << dist[d];
}