/*
    Problem link: https://codeforces.com/problemset/problem/269/A
    Tags: greedy
*/

#include<bits/stdc++.h>

using namespace std;

//#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }    
    sort(all(a));
    int prev = 0, p = -1;
    for(auto& [i, j]: a) {
        int times = i-p;
        while(times > 0 && prev > 1) {
            prev = ceil(prev / 4.0);
            times--;
        }
        prev = max(prev, j);
        p = i;
    }
    if(prev == 1) {
        cout << p+1 << "\n";
        return;
    }
    while(prev > 1) {
        prev = ceil(prev / 4.0);
        p++;
    }
    cout << p << "\n";
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