/*
    Problem link: https://oj.uz/problem/view/LMIO19_triusis
    Tags: dp
*/

#include<bits/stdc++.h>

using namespace std;

//#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n+1), dp;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] = k*i-a[i];
    }
    
    // longest increasing subsequence in n log n
    for (ll i = 1; i <= n; i++)
    {
        if(a[i] < 0) continue;
        
        auto t = upper_bound(all(dp), a[i]);
        if(t == dp.end()) {
            dp.push_back(a[i]);
        }
        else {
            dp[t-dp.begin()] = a[i];
        }
    }
    cout << n-dp.size() << endl;
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