/*
    Problem link: https://codeforces.com/problemset/problem/2140/D?adcd1e=caf4fpjy09z84d&csrf_token=0c22dd0bd1874c047aa3ef2bbb3cde27&__cf_chl_tk=SRSBWqHcuLLfNLGUScvfpOexTzGfUHfj1FlsYPI1U3Y-1772814396-1.0.1.1-QGSgQgUHBgNdie4VWwFG1E5MfghCNXc9KAqb6SXUt_4
    Tags: greedy, sorting
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
        res += a[i].second - a[i].first;
    }
    sort(all(a), [](auto i, auto j) {
        return i.first+i.second < j.first+j.second;
    });
    
    if(n == 1) {
        cout << res << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if(n % 2 && i == n/2) {
            continue;
        }
        res += a[i].second;
    }

    for (int i = 0; i < n/2; i++)
    {
        res -= a[i].second + a[i].first;
    }

    if(n % 2) {
        ll mx = 0;
        for (int i = 0; i < n/2; i++)
        {
            mx = max(mx, a[i].first-a[n/2].first);
        }

        for (int i = n/2; i < n; i++)
        {
            mx = max(mx, a[n/2].second-a[i].second);
        }
        
        res += mx;
    }
    cout << res << endl;
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