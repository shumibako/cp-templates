#include <bits/stdc++.h>
using namespace std;

vector<pair<char, int>> RunLength(string s)
{
    vector<pair<char, int>> R;
    int n = s.size();
    int pre = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i + 1] != s[i])
        {
            R.push_back({s[i], i - pre + 1});
            pre = i + 1;
        }
    }
    if (pre != n)
        R.push_back({s[n - 1], n - pre});
    
    return R;
}