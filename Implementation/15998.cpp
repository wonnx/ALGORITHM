#include<iostream>
using namespace std;
using ll = long long;
#define MAXN 300001

ll n, m, a[MAXN], b[MAXN];
ll gcd(ll a, ll b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i];
		m = gcd(m, b[i] - b[i - 1] - a[i]);
	}

	for (int i = 1; i <= n; i++) {
		if (b[i] - b[i - 1] == a[i])continue;
		if (m && m <= b[i] || a[i] > 0 || a[i] < 0 && -a[i] < b[i - 1])
		{ cout << -1; return 0;}
	}
	if (m)cout << m;
	else cout << 1;
}