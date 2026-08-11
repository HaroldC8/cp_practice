/*
    Problem link: https://codeforces.com/problemset/problem/1343/D
    Tags: prefix sums
*/


#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto& i: a) {
        cin >> i;
    }
    vector<int> res(2*k+4);
    for (int i = 0; i < n/2; i++)
    {
        int zero = a[i] + a[n-1-i];
        int mn = min(a[i], a[n-1-i])+1;
        int mx = max(a[i], a[n-1-i])+k;
        res[2] += 2;
        res[mn]--;
        res[zero]--;
        res[zero+1]++;
        res[mx+1]++;
        res[2*k+1] -= 2;
    }
    for (int i = 0; i < 2*k+2; i++)
    {
        res[i+1] += res[i];
    }
    int ans = INT_MAX;
    for (int i = 2; i <= 2*k; i++)
    {
        ans = min(ans, res[i]);
    }
    cout << ans << "\n";
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