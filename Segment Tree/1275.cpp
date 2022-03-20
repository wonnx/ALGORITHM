#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
class segtree {
public:
	vector<ll> tree;
	ll size = 1;
	segtree(ll n) {
		for (; size < n; size *= 2);
		tree.resize(size * 2);
	}
	void update(ll pos, ll value) {
		ll idx = (size - 1) + pos;
		ll u = value - tree[idx];
		tree[idx] = value;
		while (idx /= 2) tree[idx] += u;
	}
	ll sum(ll pos, ll left, ll right, ll start, ll end) {
		if (end<left || start>right) return 0;
		if (start >= left && end <= right) return tree[pos];
		ll mid = (start + end) / 2;
		return sum(2*pos, left, right, start, mid)
			+sum(2*pos+1, left, right, mid + 1, end);
	}
};
int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	int n, q; cin >> n >> q;
	segtree tree(n);
	for (ll i = 1; i <= n; i++) {
		ll x; cin >> x;
		tree.update(i, x);
	}
	for (ll i = 0; i < q; i++)
	{
		ll x, y, a, b; 
		cin >> x >> y >> a >> b;
		if (y < x) { int t = y; y = x; x = t; }
		cout << tree.sum(1, x, y, 1, tree.size) << "\n";
		tree.update(a, b);
	}
}