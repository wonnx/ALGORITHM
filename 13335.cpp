#include<iostream>
#include<queue>
using namespace std;

int truck[1001];

int main()
{
	int n, w, l; cin >> n >> w >> l;
	for (int i = 0; i < n; i++)cin >> truck[i];

	queue<int> qu;
	int time = 0, weight = 0;
	for (int i = 0; i < n; i++)
	{
		while (true)
		{
			if (qu.size() == w)
			{
				weight -= qu.front();
				qu.pop();
			}
			if (weight + truck[i] <= l) break;
			qu.push(0);
			time++;
		}
		qu.push(truck[i]);
		weight += truck[i];
		time++;
	}
	cout << time+w;
}