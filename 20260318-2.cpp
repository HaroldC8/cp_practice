/*
    Problem link: https://codeforces.com/problemset/problem/689/B
    Tags: djikstra, graph
*/

#include<bits/stdc++.h>

using namespace std;

//#define MULTI
#define __int128_t long long
#define all(x) (x).begin(), (x).end()

const __int128_t INF = LLONG_MAX;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> edges(n);
    vector<__int128_t> dist(n, LLONG_MAX);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        a--;
        edges[i].push_back(a);
        if(i > 0) {
            edges[i].push_back(i-1);
            edges[i-1].push_back(i);
        }
    }
    priority_queue<pair<int, int>> pq;
    dist[0] = 0;
    pq.push({-dist[0], 0});
    while(!pq.empty()) {
        //cout << "fine" << endl;
        auto cur = pq.top().second;
        pq.pop();

        for(auto i: edges[cur]) {
            if(dist[cur]+1 < dist[i]) {
                dist[i] = dist[cur]+1;
                pq.push({-dist[i], i});
            }
        }
    }
    for(auto i: dist) {
        cout << i << " ";
    }
    cout << "\n";
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