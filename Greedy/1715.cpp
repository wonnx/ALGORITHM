#include<iostream>
#include<queue>
using namespace std;
#define MAXN (int)1e5+1
priority_queue<int, vector<int>, greater<int> > pq;

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int c; cin >> c; pq.push(c);
	}
	int r = 0;
	while (pq.size()>=2)
	{
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		r += (a + b);
		pq.push(a + b);
	}
	cout << r;
}