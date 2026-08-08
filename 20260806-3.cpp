/*
    Problem link: https://codeforces.com/problemset/problem/1336/B
    Tags: greedy, binary search
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

ll calc(ll a, ll b, ll c) {
    return powl(a-b, 2) + powl(b-c, 2) + powl(c-a, 2);
}

ll tryout(vector<ll>& a, vector<ll>& b, vector<ll>& c) {
    ll res = LONG_LONG_MAX;
    int na = a.size(), nb = b.size(), nc = c.size();
    for (int i = 0; i < na; i++)
    {
        int j = lower_bound(all(b), a[i])-b.begin();
        int k = lower_bound(all(c), a[i])-c.begin();
        
        if(j-1 >= 0 && k-1 >= 0) {
            res = min(res, calc(a[i], b[j-1], c[k-1]));
        }
        if(j-1 >= 0 && k < nc) {
            res = min(res, calc(a[i], b[j-1], c[k]));
        }
        if(k-1 >= 0 && j < nb) {
            res = min(res, calc(a[i], b[j], c[k-1]));
        }
        if(k < nc && j < nb) {
            res = min(res, calc(a[i], b[j], c[k]));
        }
    }
    return res;
}

void solve() {
    int na, nb, nc;
    cin >> na >> nb >> nc;
    vector<ll> a(na), b(nb), c(nc);
    for (int i = 0; i < na; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < nb; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < nc; i++)
    {
        cin >> c[i];
    }
    sort(all(a));
    sort(all(b));
    sort(all(c));
    ll res = tryout(a, b, c);
    res = min(res, tryout(b, a, c));
    res = min(res, tryout(c, a, b));
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