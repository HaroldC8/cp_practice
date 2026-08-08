/*
    Problem link: https://codeforces.com/problemset/problem/1721/D
    Tags: bitmasks, greedy
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    int ans = 0;
    for (int bit = 29; bit >= 0; bit--)
    {
        int mask = ans | (1 << bit);
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[a[i] & mask]++;
            mp[~b[i] & mask]--;
        }
        bool can = 1;
        for(auto i: mp) {
            can &= i.second == 0;
        }
        if(can) {
            ans |= 1 << bit;
        }
    }
    
    cout << ans << "\n";
}

int main(int argc, char **argv)
{    
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifdef MULTI
        int t;
        cin >> t;
        while (t--)
        {
            solve();   
        }
    #else
        solve();
    #endif
    return 0;
}