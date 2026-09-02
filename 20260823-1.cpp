/*
    Problem link: https://codeforces.com/problemset/problem/1809/D
    Tags: greedy, constructive algorithms
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

const ll p1 = 1e12, p2 = 1e12+1;

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    vector<int> pfx(n+1), sfx(n+1);
    for (int i = n-1; i >= 0; i--)
    {
        sfx[i] = sfx[i+1] + (s[i] == '1');
    }
    ll ans = LLONG_MAX;
    for (int i = 0; i < n; i++)
    {
        pfx[i+1] = pfx[i] + (s[i] == '0');
        ans = min(ans, (ll)(n-pfx[i+1]-sfx[i])*p2);
    }

    for (int i = 1; i < n; i++)
    {
        if(s[i-1] == '1' && s[i] == '0') {
            ans = min(ans, (ll)(n-pfx[i-1]-sfx[i+1]-2)*p2 + p1);
        }
    }    
    cout << (ans == LLONG_MAX ? 0 : ans) << "\n";
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