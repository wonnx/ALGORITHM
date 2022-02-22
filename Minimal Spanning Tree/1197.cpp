#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 10001
using ll = long long;
using pi = pair<int, pair<int, int> >;

int p[MAXN]; 
pi edge[MAXN];
bool compare(const pi& a, const pi& b)
{
	return a.first < b.first;
}

int find(int x)
{
	if (p[x] == x)return x;
	return p[x] = find(p[x]);
}

int main()
{
	int v, e; cin >> v >> e;
	for (int i = 0; i < MAXN; i++)p[i] = i;
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edge[i] = { c,{a,b} };
	}
	sort(edge, edge + e, compare);

	ll r = 0;
	for (int i = 0; i < e; i++)
	{
		int a = edge[i].second.first;
		int b = edge[i].second.second;
		int c = edge[i].first;
		int x = find(a), y = find(b);
		if (x != y) p[x] = y, r += c;
	}
	cout << r;
}