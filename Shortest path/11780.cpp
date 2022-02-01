#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
#define INF (int)1e10

ll d[101][101], p[101][101];
void solve(vector<int> &v, int from, int to)
{
	if (!p[from][to])
	{
		v.push_back(from);
		v.push_back(to);
		return;
	}
	solve(v, from, p[from][to]);
	v.pop_back();
	solve(v, p[from][to], to);
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			i == j ? d[i][j] = 0 : d[i][j] = INF;
	for (int i = 0; i < m; i++)
	{
		ll a, b, c; cin >> a >> b >> c;
		d[a][b] = min(d[a][b], c);
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j], p[i][j] = k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			d[i][j] != INF ? cout << d[i][j] << " " : cout << 0 << " ";
		cout << endl;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (d[i][j] == INF || d[i][j] == 0) cout << "0" << endl;
			else
			{
				vector<int> vec;
				solve(vec, i, j);
				vector<int>::iterator iter;
				cout << vec.size() << " ";
				for (iter = vec.begin(); iter != vec.end(); iter++)
					cout << *iter << " ";
				cout << endl;
			}
		}
	}
}