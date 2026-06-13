/*
    Problem link: https://codeforces.com/problemset/problem/2232/A
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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(all(a));
    int med = a[n/2];
    
    int high = n-(upper_bound(all(a), med)-a.begin());
    int low = lower_bound(all(a), med)-a.begin();

    cout << max(high, low) << endl;
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