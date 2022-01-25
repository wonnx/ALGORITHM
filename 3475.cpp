#include<iostream>
#include<vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	while (cin >> n)
	{
		vector<int> vec;
		for (int i = 0; i < n; i++)
		{
			int x; cin >> x;
			int idx = lower_bound(vec.begin(), vec.end(), x) - vec.begin();
			if (idx == vec.size())vec.push_back(x);
			else vec[idx] = x;
		}
		cout << vec.size() << endl;
	}
}