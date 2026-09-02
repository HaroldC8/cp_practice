/*
    Problem link: https://codeforces.com/problemset/problem/575/H
    Tags: combinatorics, math
*/

#include<bits/stdc++.h>

using namespace std;

//#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

const int MAX_FACT = 1e6+2, MOD = 1e9+7;

ll fact[MAX_FACT];

ll inv(ll x) {
    if(x <= 1) {
        return x;
    }
    return MOD - ((ll)(MOD / x)*inv(MOD % x)) % MOD;
}

void solve() {
    ll n;
    cin >> n;

    fact[0] = 1;
    for (int i = 1; i < MAX_FACT; i++)
    {
        fact[i] = (fact[i-1]*i) % MOD;
    }
    ll ans = 1;
    for (int i = n+2; i <= 2*n+2; i++)
    {
        ans = (ans*i) % MOD;
    }
    cout << ((ans*inv(fact[n+1]))%MOD-1)%MOD << "\n";
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