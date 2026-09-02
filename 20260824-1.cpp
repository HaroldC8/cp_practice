/*
    Problem link: https://codeforces.com/problemset/problem/1469/C
    Tags: dp, greedy
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
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    pair<int, int> h = {a[0], a[0]};
    // base, top
    k--;
    for (int i = 1; i < n; i++)
    {
        h = {max(h.first-k, a[i]), min(h.second+k, a[i]+k)};
        if(h.first > h.second) {
            cout << "NO\n";
            return;
        }
    }    
    if(a[n-1] < h.first || a[n-1] > h.second) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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