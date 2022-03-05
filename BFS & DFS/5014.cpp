#include<iostream>
#include<queue>
using namespace std;
#define MAXN (int)1e6+1
#define INF (int)1e9

int chk[MAXN];
queue<int> qu;

int main()
{
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;
	fill(chk, chk + MAXN, INF);
	qu.push(s); chk[s] = 0;
	while (!qu.empty())
	{
		int n = qu.front(); qu.pop();
		if (n + u <= f && chk[n] + 1 < chk[n + u]) {
			chk[n + u] = chk[n] + 1;
			qu.push(n + u);
		}
		if (n - d >= 1 && chk[n] + 1 < chk[n - d]) {
			chk[n - d] = chk[n] + 1;
			qu.push(n - d);
		}
	}
	chk[g] == INF ? cout << "use the stairs" : cout << chk[g];
}