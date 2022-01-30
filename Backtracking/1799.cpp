#include<iostream>
#include<vector>
using namespace std;
using pii = pair<int, int>;

int n, chk[22];
vector<vector<pii> > vec;

int btk(int i)
{
	if (i >= vec.size())return 0;
	int ret = 0;
	for (int j = 0; j < vec[i].size(); j++)
	{
		int x = vec[i][j].first;
		int y = vec[i][j].second;
		if (!chk[x - y + n])
		{
			chk[x - y + n] = true;
			ret = max(ret, btk(i + 2) + 1);
			chk[x - y + n] = false;
		}
	}
	ret = max(ret, btk(i + 2));
	return ret;
}

int main()
{
	cin >> n;
	vec.resize(2 * n + 1);
	for(int i=0; i<n; i++)for(int j=0; j<n; j++)
	{
		int vtx; cin >> vtx;
		if (vtx)vec[i + j].emplace_back(i, j);
	}
	cout << btk(0) + btk(1);
}