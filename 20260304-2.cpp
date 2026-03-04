/*
    Problem link: https://codeforces.com/problemset/problem/2023/B
    Tags: graph, djikstra, priority queue
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n), b(n), p(n+1), res(n, LONG_LONG_MIN);
    vector<vector<pair<int, int>>> edges(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        p[i+1] = a[i] + p[i];
        if(i == 0) continue;
        edges[i].push_back({i-1, 0});
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        b[i]--;
        edges[i].push_back({b[i], -a[i]});
    }
    
    priority_queue<pair<int, int>> pq;
    pq.push({0, 0});
    res[0] = 0;
    while(!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        for(auto i: edges[top.second]) {
            if(res[top.second] + i.second > res[i.first]) {
                res[i.first] = res[top.second] + i.second;
                pq.push({res[i.first], i.first});
            }
        }
    }
    ll mx = 0;
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, p[i+1]+res[i]);
    }
    cout << mx << endl;
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