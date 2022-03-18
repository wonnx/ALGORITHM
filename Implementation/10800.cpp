#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define MAXN (int)2e5+1
using ppi = pair<pair<int, int>, int>;
bool compare(const ppi& a, const ppi& b) {
	return a.first.second < b.first.second;
}
ppi ball[MAXN]; int color[MAXN], r[MAXN];
int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int c, s; cin >> c >> s;
		ball[i] = { {c,s},i };
	}
	sort(ball, ball + n, compare);

	int sum = 0;
	for (int i = 0, j = 0; i < n; i++) {
		for (; ball[i].first.second > ball[j].first.second; j++) {
			sum += ball[j].first.second;
			color[ball[j].first.first] += ball[j].first.second;
		}
		r[ball[i].second] = sum - color[ball[i].first.first];
	}
	for (int i = 0; i < n; i++)
		cout << r[i] << "\n";
}