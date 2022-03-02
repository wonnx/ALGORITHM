#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define ll long long
#define MAXN 300001
using pl = pair<ll, ll>;

ll r, idx, b[MAXN];
pl jewel[MAXN];
priority_queue<int> pq;

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> jewel[i].first >> jewel[i].second;
	for (int i = 0; i < k; i++)cin >> b[i];
	sort(jewel, jewel + n);
	sort(b, b + k);

	for (int i = 0; i < k; i++)
	{
		if (idx < n && jewel[idx].first <= b[i])
			pq.push(jewel[idx++].second);
		if (!pq.empty()) { r += pq.top(); pq.pop(); }
	}
	cout << r;
}