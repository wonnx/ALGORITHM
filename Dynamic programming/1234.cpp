#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll fac(int x)
{
	int r = 1;
	for (int i = 1; i <= x; i++)r *= i;
	return r;
}

ll comb(int a, int b, int c)
{
	return fac(a + b + c) / fac(a) / fac(b) / fac(c);
}

ll answer = 0, n, r, g, b;
void solve(int level, int red, int green, int blue, ll ans)
{
	if (ans == 0)return;
	if (level == n + 1) { answer += ans; return; }
	if (level % 2 == 0)
	{
		if (red >= level / 2 && green >= level / 2)
			solve(level + 1, red - (level / 2), green - (level / 2), blue, ans * comb(level / 2, level / 2, 0));
		if (red >= level / 2 && blue >= level / 2)
			solve(level + 1, red - (level / 2), green, blue - (level / 2), ans * comb(level / 2, level / 2, 0));
		if (blue >= level / 2 && green >= level / 2)
			solve(level + 1, red, green - (level / 2), blue - (level / 2), ans * comb(level / 2, level / 2, 0));
	}
	if (level % 3 == 0)
	{
		if (red >= level / 3 && blue >= level / 3 && green >= level / 3)
			solve(level + 1, red - (level / 3), green - (level / 3), blue - (level / 3), ans * comb(level / 3, level / 3, level / 3));
	}
	if (red >= level)solve(level + 1, red - level, green, blue, ans);
	if (green >= level)solve(level + 1, red, green - level, blue, ans);
	if (blue >= level)solve(level + 1, red, green, blue - level, ans);
	return;
}

int main()
{
	cin >> n >> r >> g >> b;
	solve(1, r, g, b, 1);
	cout << answer;
}