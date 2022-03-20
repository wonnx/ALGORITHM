#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
class segtree {
public:
	vector<ll> tree;
	ll size = 1;
	segtree(ll n, ll mode) {
		for (; size < n; size *= 2);
		if (!mode)tree.resize(size * 2, int(1e10));
		else tree.resize(size * 2, 0);
	}
	void min_update(ll pos, ll value) {
		ll idx = (size - 1) + pos;
		tree[idx] = value;
		while (idx /= 2)
			tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
	}
	void max_update(ll pos, ll value) {
		ll idx = (size - 1) + pos;
		tree[idx] = value;
		while (idx /= 2)
			tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
	}
	ll get_min(ll pos, ll left, ll right, ll start, ll end) {
		if (left > end || right < start)return (int)1e10;
		if (left <= start && right >= end)return tree[pos];
		ll mid = (start + end) / 2;
		return min(get_min(2 * pos, left, right, start, mid),
			get_min(2 * pos + 1, left, right, mid + 1, end));
	}
	ll get_max(ll pos, ll left, ll right, ll start, ll end) {
		if (left > end || right < start)return -1;
		if (left <= start && right >= end)return tree[pos];
		ll mid = (start + end) / 2;
		return max(get_max(2 * pos, left, right, start, mid),
			get_max(2 * pos + 1, left, right, mid + 1, end));
	}
};
int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	segtree min_tree(n,0), max_tree(n,1);
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		min_tree.min_update(i, x);
		max_tree.max_update(i, x);
	}
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		cout << min_tree.get_min(1, a, b, 1, min_tree.size) << " ";
		cout << max_tree.get_max(1, a, b, 1, max_tree.size) << "\n";
	}
}