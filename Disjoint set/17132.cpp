#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN (int)1e6+1
using ll = long long;
using pi = pair<int, pair<int, int> >;

pi vtx[MAXN];
ll p[MAXN], d[MAXN];

bool compare(const pi& a, const pi& b)
{
	return a.first > b.first;
}
int find(int x)
{
	if (p[x] == x)return x;
	return p[x] = find(p[x]);
}

int main()
{
	int n; cin >> n;
	for (int i = 0; i < n-1; i++)
	{
		int x, y, w; cin >> x >> y >> w;
		vtx[i] = { w,{x,y} };
	}
	sort(vtx, vtx + n - 1, compare);
	for (int i = 0; i < MAXN; i++)
		p[i] = i, d[i] = 1;

	ll r = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int a = vtx[i].second.first;
		int b = vtx[i].second.second;
		int w = vtx[i].first;
		int x = find(a), y = find(b);
		p[max(x, y)] = min(x, y);
		r += d[x] * d[y] * w;
		d[min(x, y)] += d[max(x, y)];
	}
	cout << r;
}