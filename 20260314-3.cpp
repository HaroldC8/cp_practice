/*
    Problem link: 
    Tags: dp, greedy, math
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    vector<pair<long double, long double>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
        a[i].second = 100 - a[i].second;
    }
    long double res = a[n-1].first;
    for (int i = n-2; i >= 0; i--)
    {
        res = max(res, res * a[i].second / 100.0 + a[i].first);
    }
    
    cout << setprecision(16) << res << "\n";
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