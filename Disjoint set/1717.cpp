#include<iostream>
using namespace std;
#define MAXN (int)1e6+1

int p[MAXN];
int find(int x)
{
	if (p[x] == x)return x;
	else return p[x] = find(p[x]);
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	for (int i = 0; i < MAXN; i++)p[i] = i;
	for (int i = 0; i < m; i++)
	{
		int c, a, b; cin >> c >> a >> b;
		if (!c)p[find(a)] = p[find(b)];
		else if (p[find(a)] == p[find(b)])cout << "YES\n";
		else cout << "NO\n";
	}
}