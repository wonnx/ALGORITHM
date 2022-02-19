#include<iostream>
using namespace std;
int c[101], d[10001];
int main()
{
	int n, k; cin >> n >> k; d[0] = 1;
	for (int i = 0; i < n; i++) cin >> c[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= k - c[i]; j++)
			d[j + c[i]] += d[j];
	cout << d[k] << endl;
	return 0;
}