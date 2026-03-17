/*
    Problem link: https://codeforces.com/problemset/problem/1012/C
    Tags: dp
*/

#include<bits/stdc++.h>

using namespace std;

//#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    // Pick the one with the smallest requirement and the one whose sides are lowest
    int n;
    cin >> n;
    vector<ll> a(n), res(ceil(n/2.0));
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(n, 0));

    for (int i = 0; i < n; i++)
    {
        if(i > 0) {
            dp[i][0] += max(0ll, a[i-1]-a[i]+1);
        }
        if(i < n-1) {
            dp[i][0] += max(0ll, a[i+1]-a[i]+1);
        }
    }    

    for (int cnt = 1; cnt < ceil(n/2.0); cnt++)
    {
        ll mn = INT_MAX;

        for (int i = cnt*2; i < n; i++)
        {
            if(i > 0) {
                ll t = max(0ll, a[i-1]-a[i]+1) + mn;
                
                ll red = min(a[i-1], a[i-2]-1);
                t = min(t, max(0ll, red-a[i]+1) + dp[i-2][cnt-1]);
                
                dp[i][cnt] += t;
            }
            if(i < n-1) {
                dp[i][cnt] += max(0ll, a[i+1]-a[i]+1);
            }

            mn = min(mn, dp[i-2][cnt-1]);
        }
    }

    for (int cnt = 0; cnt < ceil(n/2.0); cnt++)
    {
        ll ans = INT_MAX;
        for (int i = cnt*2; i < n; i++)
        {
            ans = min(ans, dp[i][cnt]);
            //cout << dp[i][cnt] << " ";
        }        
        //cout << "\n";
        res[cnt] = ans;
    }
    

    for(auto i: res) {
        cout << i << " ";
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