/*
    Problem link: https://codeforces.com/problemset/problem/2232/B
    Tags: math
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll mn = INT_MAX, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        mn = min(mn, (ll)floorl(sum/(long double)(i+1)));
        cout << mn << " ";
    }
    cout << endl;
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