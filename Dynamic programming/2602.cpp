#include<stdio.h>
#include<iostream>
using namespace std;

char m[21], s[2][101];
int dp[21][2] = { 1,1 }, l;
int main()
{
	scanf("%s%s%s", m, s, s[1]);
	while (m[++l]);
	for (int i = 0; s[0][i]; i++)
		for (int j = l; j--;)
		{
			dp[j + 1][0] += (s[0][i] == m[j]) * dp[j][1];
			dp[j + 1][1] += (s[1][i] == m[j]) * dp[j][0];
		}
	cout << dp[l][0] + dp[l][1] << endl;
	return 0;
}