#include<iostream>
#include<stack>
using namespace std;
#define MAXN (int)1e6

int vertex[MAXN], NGE[MAXN];
stack<int> st;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	fill(NGE, NGE + MAXN, -1);

	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> vertex[i];
	for (int i = n - 1; i >= 0; i--)
	{
		while (!st.empty() && st.top() <= vertex[i])st.pop();
		if (!st.empty())NGE[i] = st.top();
		st.push(vertex[i]);
	}
	for (int i = 0; i < n; i++)cout << NGE[i] << " ";
}