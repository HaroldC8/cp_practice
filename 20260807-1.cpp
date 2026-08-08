/*
    Problem link: https://codeforces.com/problemset/problem/913/C
    Tags: bitmasks, greedy
*/

#include<bits/stdc++.h>

using namespace std;

//#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    ll n, L;
    cin >> n >> L;
    vector<ll> a(31, LLONG_MAX);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < 31; i++)
    {
        a[i] = min(a[i], a[i-1]*2);
    }
    ll res = 0;
    for (int i = 30; i >= 0; i--)
    {
        res += ((1ll << i) & L) > 0 ? a[i] : 0;
    }
    ll t = 0;
    for (int i = 30; i >= 0; i--)
    {
        t += (1ll << i) & L;
        if(t == 0) {
            res = min(res, a[i]);
        }
        else if(((1ll << i) & L) == 0) {
            ll cur = 0;
            for (int j = 30; j >= 0; j--)
            {
                cur += ((t | (1ll << i)) & (1ll << j)) > 0 ? a[j] : 0;
            }
            res = min(res, cur);
        }
    }
    cout << res << "\n";
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