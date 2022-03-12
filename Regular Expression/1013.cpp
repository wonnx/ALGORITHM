#include<iostream>
using namespace std;

int main()
{
	int t; cin >> t;
	for (int i = 0; i < t; i++)
	{
		string s; cin >> s;

		int state = 0;
		for (int j = 0; j < s.size(); j++) {
			if (state == 0) 
				if (s[j] == '0') state = 1; 
				else state = 3;
			else if (state == 1) 
				if (s[j] == '0') state = 9; 
				else state = 2;
			else if (state == 2)
				if (s[j] == '0') state = 1;
				else state = 3;
			else if (state == 3) 
				if (s[j] == '0') state = 4;
				else state = 9;
			else if (state == 4) 
				if (s[j] == '0') state = 5;
				else state = 9;
			else if (state == 5) 
				if (s[j] == '0') state = 5;
				else state = 6;
			else if (state == 6) 
				if (s[j] == '0') state = 1;
				else state = 7;
			else if (state == 7) 
				if (s[j] == '0') state = 8;
				else state = 7;
			else if (state == 8) 
				if (s[j] == '0') state = 5;
				else state = 6;
		}
		if (state == 2 || state == 6 || state == 7) cout << "YES\n";
		else cout << "NO\n";
	}
}