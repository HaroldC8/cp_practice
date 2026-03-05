/*
    Problem link: https://codeforces.com/problemset/problem/1428/D
    Tags: greedy, priority queue
*/

#include<bits/stdc++.h>

using namespace std;

//#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), ones;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] == 1) {
            ones.push_back(i);
        }
    }
    vector<vector<pair<int, int>>> res(n);
    int ans = 0;
    priority_queue<pair<int, int>> pq;
    for (int i = n-1; i >= 0; i--)
    {
        if(a[i] == 3) {
            if(pq.empty()) {
                cout << -1 << endl;
                return;
            }
            // Greedily select 3s, 2s and only then 1s (leave 1s for a[i] == 2)
            auto t = pq.top();
            pq.pop();
            res[t.second].push_back({i, t.second});
            if(t.first == 1) {
                ones.pop_back();
            }
            ans++;
        }
        else if(a[i] == 2) {
            // Look for last 1
            if(ones.empty() || ones.back() < i) {
                cout << -1 << endl;
                return;
            }
            res[ones.back()].pop_back();
            res[ones.back()].push_back({i, ones.back()});
            ones.pop_back();
        }
        if(a[i] != 0) {
            res[i].push_back({i, i});
            pq.push({a[i], i});
            ans++;
        }
    }
    cout << ans << endl;
    for(auto i: res) {
        for(auto j: i) {
            cout << j.first+1 << " " << j.second+1 << endl;
        }
    }
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