/*
    Problem link: https://codeforces.com/problemset/problem/1801/B
    Tags: greedy, data structures, sorting
*/

#include<bits/stdc++.h>
 
using namespace std;
 
#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    multiset<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
        s.insert(a[i].first);
    }
    
    sort(all(a), [](auto x, auto y) {
        if(x.second == y.second) {
            return x.first < y.first;
        }
        return x.second > y.second;
    });
 
    int above_max = 0, best = INT_MAX;
    
    for (int i = 0; i < n; i++)
    {
        s.erase(s.find(a[i].first));
        if(i > 0) {
            best = min(best, abs(a[i].second-above_max));
        }
        auto j = s.lower_bound(a[i].second);
        if(j != s.end() && *j >= above_max) {
            best = min(best, abs(a[i].second-*j));
        }
        if(j != s.begin() && *prev(j) >= above_max) {
            best = min(best, abs(a[i].second-*prev(j)));
        }
        
        above_max = max(above_max, a[i].first);
    }
    cout << best << "\n";
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