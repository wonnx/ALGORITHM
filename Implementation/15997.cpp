#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
using ld = long double;

int s[4];
ld rate[4];
struct match {
	int a, b;
	ld w, d, l;
};
struct match m[6];
map<string, int> idx;
pair<int, int> score[4];

void play(int game, ld p)
{
	if (game == 6)
	{
		if (p == 0)return;
		for (int i = 0; i < 4; i++)
			score[i] = { s[i],i };
		sort(score, score + 4);

		int x[4], y[4];
		for (int i = 0; i < 4; i++)
			x[i] = score[i].first, y[i] = score[i].second;

		if (x[3] > x[2])
			if (x[2] > x[1]) rate[y[3]] += p, rate[y[2]] += p;
			else if (x[1] > x[0])
			{
				rate[y[3]] += p;
				rate[y[2]] += p / 2;
				rate[y[1]] += p / 2;
			}
			else
			{
				rate[y[3]] += p;
				rate[y[2]] += p / 3;
				rate[y[1]] += p / 3;
				rate[y[0]] += p / 3;
			}
		else
		{
			if (x[2] > x[1]) rate[y[3]] += p, rate[y[2]] += p;
			else if (x[1] > x[0])
			{
				rate[y[3]] += p * 2 / 3;
				rate[y[2]] += p * 2 / 3;
				rate[y[1]] += p * 2 / 3;
			}
			else
			{
				rate[y[3]] += p / 2;
				rate[y[2]] += p / 2;
				rate[y[1]] += p / 2;
				rate[y[0]] += p / 2;
			}
		}
		return;
	}

	match t = m[game];
	s[t.a] += 3;
	play(game + 1, p * t.w);
	s[t.a] -= 3;

	s[t.a] += 1; s[t.b] += 1;
	play(game + 1, p * t.d);
	s[t.a] -= 1; s[t.b] -= 1;

	s[t.b] += 3;
	play(game + 1, p * t.l);
	s[t.b] -= 3;
}

int main()
{
	for (int i = 0; i < 4; i++)
	{
		string s; cin >> s;
		score[i] = { 0, i };
		idx[s] = i;
	}
	for (int i = 0; i < 6; i++)
	{
		string a, b; ld w, d, l;
		cin >> a >> b >> w >> d >> l;
		m[i] = { idx[a], idx[b], w,d,l};
	}
	play(0, 1.0);
	cout << fixed;
	cout.precision(10);
	for (int i = 0; i < 4; i++)
		cout << rate[i] << endl;
}