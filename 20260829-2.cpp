/*
    Problem link: https://codeforces.com/problemset/problem/2258/B2
    Tags: math, greedy, implementation
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), freq(m+2), p(m+2);
    ll sum = 0;
    for(auto &i: a) {
        cin >> i;
        freq[i]++;
        sum += i;
    }

    for (int i = m; i >= 0; i--)
    {
        p[i] = freq[i] + p[i+1];
    }

    for (ll k = 1; k <= m; k++)
    {
        if(k >= 18 || (1 << k) >= m) {
            cout << sum << " ";
            continue;
        }
        ll mx = 0;
        for (ll x = 1; x <= (m / (1 << k)) + 3; x++)
        {
            ll cur = 0;
            for (ll j = 1; j < (1 << k) && x*j <= m; j++)
            {
                cur += p[x*j];
            }
            
            if(x * (1 << k) <= m) {
                cur += freq[x*(1 << k)];
            }

            mx = max(mx, cur);
        }        
        cout << mx << " ";
    }
    
    cout << "\n";
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