/*
    Problem link: https://codeforces.com/contest/2207/problem/E2
    Tags: cominatorics, math, TODO
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

const int MOD = 1e9+7; 

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    bool ye = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(i > 0 && a[i] > a[i-1]) {
            ye = 0;
        }
    }

    if(!ye) {
        cout << 0 << endl;
        return;
    }

    ll res = 1;
    for (int i = 0; i < n; i++)
    {
        if(a[i] > n || a[i] < n-i-1) {
            cout << 0 << endl;
            return;
        }

        // TODO: Unclear as to how we calculate / transitions. Tutorial: https://codeforces.com/blog/entry/151886
        if(i > 0 && a[i] == a[i-1]) {
            res = (res * (a[i]-(n-i-1))) % MOD;
        }
        else {
            res = (res * (i+1)) % MOD;
        }
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