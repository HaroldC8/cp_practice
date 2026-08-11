/*
    Problem link: https://codeforces.com/problemset/problem/2255/B
    Tags: strings, math, stars & bars, binomial, modular inverse
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

ll fact[(int)1e6+1];
ll MOD = 998244353;

void precomp_fact() {
    fact[0] = 1;
    for (int i = 1; i < 1e6+1; i++)
    {
        fact[i] = (fact[i-1] * i) % MOD;
    }
}

ll inv(ll x) {
    if(x <= 1) {
        return x;
    }
    return MOD - ((ll)(MOD/x) * inv(MOD % x)) % MOD;
}

ll binomial(ll n, ll k) {
    return (fact[n] * inv((fact[k]*fact[n-k]) % MOD)) % MOD;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll count0 = 0, count1 = 0;
    ll run0 = 0, run1 = 0;
    for (int i = 0; i < n; i++)
    {
        count0 += (s[i] == '0');
        count1 += (s[i] == '1');
    }
    for (int i = 1; i < n; i++)
    {
        run0 += (s[i-1] == '0' && s[i] == '1');
        run1 += (s[i-1] == '1' && s[i] == '0');
    }
    if(s[n-1] == '0') {
        run0++;
    }
    else {
        run1++;
    }
    //printf("0 -> c:%i r:%i\n1 -> c:%i r:%i\n", count0, run0, count1, run1);
    ll res = 1;
    if(run0 > 1) {
        res *= binomial(count0-1, run0-1);
    }
    if(run1 > 1) {
        res *= binomial(count1-1, run1-1);
    }
    cout << res % MOD << "\n";
}

int main(int argc, char **argv)
{    
    precomp_fact();

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