#include <iostream>
using namespace std;

int m[3][3];
int main() 
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> m[i][j];

    int s = 0;
    for (int i = 0; i < 3; i++)
    {
        if (!(!m[i][0] + !m[i][1] + !m[i][2])) s = m[i][0] + m[i][1] + m[i][2];
        if (!(!m[0][i] + !m[1][i] + !m[2][i])) s = m[0][i] + m[1][i] + m[2][i];
    }
    if (!(!m[0][0] + !m[1][1] + !m[2][2])) s = m[0][0] + m[1][1] + m[2][2];
    if (!(!m[0][2] + !m[1][1] + !m[2][0])) s = m[0][2] + m[1][1] + m[2][0];

    if (s == 0)
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                s += m[i][j];
        s /= 2;
    }

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (!m[i][j] && (!m[i][0] + !m[i][1] + !m[i][2]) == 1) m[i][j] = s - m[i][0] - m[i][1] - m[i][2];
                if (!m[i][j] && (!m[0][j] + !m[1][j] + !m[2][j]) == 1) m[i][j] = s - m[0][j] - m[1][j] - m[2][j];
            }
        }
    }
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++)
            cout << m[i][j] << " ";
        cout << endl;
    }
}