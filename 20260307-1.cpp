/*
    Problem link: https://codeforces.com/problemset/problem/734/C
    Tags: binary search
*/

#include<bits/stdc++.h>

using namespace std;

//#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll x, s;
    cin >> x >> s;
    ll mn = n*x;

    vector<ll> a(m), b(m), c(k), d(k);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        if(b[i] <= s) {
            mn = min(mn, a[i]*n);
        }
    }
    for (int i = 0; i < k; i++)
    {
        cin >> c[i];
    }
    for (int i = 0; i < k; i++)
    {
        cin >> d[i];
        if(d[i] <= s) {
            mn = min(mn, x*(n-c[i]));
        }
    }

    for (int i = 0; i < m; i++)
    {
        if(b[i] > s) {
            continue;
        }
        auto t = upper_bound(all(d), s-b[i])-d.begin()-1;

        if(t < 0 || t >= k) {
            continue;
        }
        
        mn = min(mn, a[i]*(n-c[t]));
    }

    cout << mn << endl;
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