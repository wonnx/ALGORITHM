#include<iostream>
#include<string>
using namespace std;

string seq;
bool is_good_seq(string str)
{
	int flag = 1, size = str.size();
	for (int i = 1; i <= size / 2; i++)
	{
		for (int j = 0; j <= size - 2 * i; j++)
		{
			string a = str.substr(j, i);
			string b = str.substr(j + i, i);
			if (a == b) { flag = 0; break; }
		}
		if (!flag) break;
	}
	return flag;
}

void find_good_seq(string str, int n)
{
	if (str.size() == n && seq.empty()) seq = str;
	if (!seq.empty()) return;
	for(int i=1; i<=3; i++)
		if(is_good_seq(str+to_string(i)))
			find_good_seq(str+to_string(i),n);
}

int main()
{
	int n; cin >> n;
	find_good_seq("1", n);
	cout << seq;
	return 0;
}