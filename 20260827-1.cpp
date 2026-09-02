/*
    Problem link: https://codeforces.com/problemset/problem/2061/C
    Tags: dp, combinatorics
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    ll dp[(int)2e5+2]{0};
    vector<int> a(n+1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        // We assume dp[i] is honest
        // If prev was honest too
        if(a[i] == a[i-1]) {
            dp[i] = (dp[i] + dp[i-1]) % MOD;
        }
        // If prev lied then i-2 must be honest
        if(i-2 >= 0 && a[i] == a[i-2]+1) {
            dp[i] = (dp[i] + dp[i-2]) % MOD;
        }
    }
    cout << (dp[n] + dp[n-1]) % MOD << "\n";    
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