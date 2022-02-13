#include<iostream>
#include<vector>
using namespace std;

int vtx[101];
vector<pair<int, pair<int, int> > > vec;

int main()
{
	int n, k, r = 0; cin >> n >> k;
	for (int i = 1; i <= k; i++) cin >> vtx[i];

	for (int i = 1; i <= k; i++)
	{
		int flag = 0;
		for (int j = 0; j < vec.size(); j++)
			if (vec[j].first == vtx[i])flag = 1;
		if (flag) continue;
		else if (vec.size() < n)vec.push_back({ vtx[i], {0,0} });
		else
		{
			for (int j = 0; j < vec.size(); j++)
			{
				int x = 0;
				for (int l = i + 1; l <= k; l++)
					if (vtx[l] == vec[j].first)
					{
						if (x==0) vec[j].second.second = l;
						x++;
					}
				vec[j].second.first = x;
			}

			int m = 101;
			for (int j = 0; j < vec.size(); j++)
				if (vec[j].second.first < m)m = vec[j].second.first;

			if (m == 0)
			{
				for (int j = 0; j < vec.size(); j++)
					if (vec[j].second.first == m)
					{
						vec[j] = { vtx[i], {0,0} }, r++;
						break;
					}
			}
			else
			{
				int p = 0;
				for (int j = 0; j < vec.size(); j++)
					if (vec[j].second.second > p)p = vec[j].second.second;
				for (int j = 0; j < vec.size(); j++)
					if (vec[j].second.second == p)
					{
						vec[j] = { vtx[i], {0,0} }, r++;
						break;
					}
			}
		}
	}
	cout << r;
}