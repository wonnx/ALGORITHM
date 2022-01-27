#include<iostream>
#include<queue>
#include<vector>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define INF 1987654321
#define MAXN 801

ll d1[MAXN], d2[MAXN], d3[MAXN];
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, e, p, q; cin >> n >> e;
	vector<pii> vec[MAXN];
	for (int i = 0; i < e; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		vec[a].push_back({ b,c });
		vec[b].push_back({ a,c });
	}
	cin >> p >> q;

	priority_queue<pii> qu;
	fill(d1, d1 + MAXN, INF);
	qu.push({ 0,1 }); d1[1] = 0;
	while (!qu.empty())
	{
		int now = qu.top().second; qu.pop();
		for (int i = 0; i < vec[now].size(); i++)
		{
			int next = vec[now][i].first;
			int weight = vec[now][i].second;
			if (d1[next] > d1[now] + weight)
			{
				d1[next] = d1[now] + weight;
				qu.push({-d1[next], next});
			}
		}
	}

	fill(d2, d2 + MAXN, INF);
	qu.push({ 0,p }); d2[p] = 0;
	while (!qu.empty())
	{
		int now = qu.top().second; qu.pop();
		for (int i = 0; i < vec[now].size(); i++)
		{
			int next = vec[now][i].first;
			int weight = vec[now][i].second;
			if (d2[next] > d2[now] + weight)
			{
				d2[next] = d2[now] + weight;
				qu.push({ -d2[next], next });
			}
		}
	}

	fill(d3, d3 + MAXN, INF);
	qu.push({ 0,n }); d3[n] = 0;
	while (!qu.empty())
	{
		int now = qu.top().second; qu.pop();
		for (int i = 0; i < vec[now].size(); i++)
		{
			int next = vec[now][i].first;
			int weight = vec[now][i].second;
			if (d3[next] > d3[now] + weight)
			{
				d3[next] = d3[now] + weight;
				qu.push({ -d3[next], next });
			}
		}
	}

	ll r1 = d1[p] + d2[q] + d3[q]; // 1 - p - q - n
	ll r2 = d1[q] + d2[q] + d3[p]; // 1 - q - p - n
	if (r1 >= INF && r2 >= INF)cout << -1;
	else r1 < r2 ? cout << r1 : cout << r2;
}