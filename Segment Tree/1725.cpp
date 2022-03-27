#include<iostream>
using namespace std;
using ll = long long;
#define MAXN (int)1e5+1

int tree_size = 1;
ll arr[MAXN], tree[4 * MAXN];

void update(int pos) {
	int idx = (tree_size - 1) + pos;
	tree[idx] = pos;
	while (idx /= 2) {
		if (arr[tree[idx * 2]] <= arr[tree[idx * 2 + 1]])
			tree[idx] = tree[idx * 2];
		else tree[idx] = tree[idx * 2 + 1];
	}
}

int index(int pos, int left, int right, int start, int end) {
	if (left > end || right < start) return -1;
	if (left <= start && right >= end) return tree[pos];
	int mid = (start + end) / 2;
	int a = index(pos * 2, left, right, start, mid);
	int b = index(pos * 2 + 1, left, right, mid + 1, end);
	if (a == -1)return b;
	if (b == -1)return a;
	if (arr[a] <= arr[b])return a;
	return b;
}

ll get_max_area(int left, int right) {
	if (left > right) return -1;
	int idx = index(1, left, right, 1, tree_size);
	ll height = arr[idx];
	if (left == right)return height;
	ll s1 = height * (right - left + 1);
	ll s2 = get_max_area(left, idx - 1);
	ll s3 = get_max_area(idx + 1, right);
	return max(s1, max(s2, s3));
}

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	for (; tree_size < n; tree_size *= 2);
	arr[0] = 1e11;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		update(i);
	}
	cout << get_max_area(1, n) << endl;
}