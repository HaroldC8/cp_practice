/*
    Problem link: https://codeforces.com/problemset/problem/1452/D
    Tags: dp, combinatorics, math
*/

#include<bits/stdc++.h>

using namespace std;

//#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

const ll MOD = 998244353;

ll inv(ll x) {
    if(x <= 1) {
        return x;
    }
    return MOD - (ll)(MOD / x)*inv(MOD % x) % MOD;
}

void solve() {
    int n;
    cin >> n;

    ll fib[n+1];
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fib[i] = (fib[i-1] + fib[i-2]) % MOD;      
    }

    ll cur = 1, x = 2;
    for (int i = 0; (1 << i) <= n; i++)
    {
        if((1 << i) & n) {
            cur = (cur * x) % MOD;
        }
        x = (x*x) % MOD;
    }

    cout << (fib[n-1]*inv(cur)) % MOD << "\n";
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