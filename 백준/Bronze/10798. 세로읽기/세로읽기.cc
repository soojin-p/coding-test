#include  <bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> st(5);

    for (int i = 0; i < 5; i++)
    {
        getline(cin, st[i]);
    }
    for (int j = 0; j < 15; j++)
    {

        for (int i = 0; i < 5; i++)
        {
            if (j >= st[i].size())
                continue;
            cout << st[i][j];
        }
    }
    return 0;
}