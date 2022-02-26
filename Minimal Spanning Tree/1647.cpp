#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN (int)1e5 + 1
using pip = pair<int, pair<int, int> >;

int p[MAXN];
pip road[MAXN];
int find(int x)
{
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		road[i] = { c, {a,b} };
	}
	for (int i = 0; i < MAXN; i++)p[i] = i;

	int s = 0, r = 0;
	sort(road, road + m);
	for (int i = 0; i < m; i++)
	{
		int a = road[i].second.first;
		int b = road[i].second.second;
		int c = road[i].first;
		int x = find(a), y = find(b);
		if (x != y)
		{
			p[max(x, y)] = min(x, y);
			if (r < c)r = c;
			s += c;
		}
	}
	cout << s - r;
}