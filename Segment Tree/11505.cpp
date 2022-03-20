#include<iostream>
#include<vector>
using namespace std;
#define num 1000000007
using ll = long long;

class segtree {
public:
	vector<ll> tree;
	ll size = 1;
	segtree(ll n)
	{
		for (; size < n; size *= 2);
		tree.resize(size * 2, 1);
	}
	void update(ll pos, ll value)
	{
		ll idx = (size - 1) + pos;
		tree[idx] = value;
		while (idx /= 2)
			tree[idx] = tree[idx * 2] * tree[idx * 2 + 1] % num;
	}
	ll mult(ll pos, ll left, ll right, ll start, ll end)
	{
		if (left > end || right < start) return 1;
		if (left <= start && right >= end) return tree[pos];
		ll mid = (start + end) / 2;
		return mult(2 * pos, left, right, start, mid)
			* mult(2 * pos + 1, left, right, mid + 1, end) % num;
	}
};

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	ll n, m, k; cin >> n >> m >> k;

	segtree tree(n);
	for (ll i = 1; i <= n; i++)
	{
		ll v; cin >> v;
		tree.update(i, v);
	}
	for (ll i = 1; i <= m + k; i++)
	{
		ll a, b, c; cin >> a >> b >> c;
		if (a == 1)tree.update(b, c);
		if (a == 2)cout << tree.mult(1, b, c, 1, tree.size) << "\n";
	}
}