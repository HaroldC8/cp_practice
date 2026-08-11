/*
    Problem link: https://codeforces.com/problemset/problem/603/B
    Tags: math, combinatorics
*/

#include<bits/stdc++.h>

using namespace std;

//#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

ll MOD = 1e9+7;

ll inv(ll x) {
    if(x <= 1) {
        return x;
    }
    return MOD - ((MOD / x)*inv(MOD % x)) % MOD;
}

void solve() {
    ll p, k;
    cin >> p >> k;
    if(k < 2) {
        ll res = 1;
        for (int i = 0; i < p-1+k; i++)
        {
            res = (res*p) % MOD;
        }
        cout << res << "\n";
        return;
    }
    ll m = 1;
    ll cur = k;
    while(cur % p != 1) {
        m++;
        cur = cur*k % p;
    }
    ll res = 1;
    for (int i = 0; i < ((p-1) * (inv(m) % MOD)) % MOD; i++)
    {
        res = (res*p) % MOD;
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