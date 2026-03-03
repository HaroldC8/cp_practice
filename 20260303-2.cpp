/*
    Problem link: https://codeforces.com/problemset/problem/2014/E
    Tags: djikstra, graph, priority queue
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void djikstra(vector<vector<ll>>& res, vector<vector<pair<int, ll>>>& edges, vector<bool>& horses, int s) {
    auto cmp = [&](auto &a, auto &b) {
        return make_pair(res[a.first][a.second],a) < make_pair(res[b.first][b.second],b);
    };

    // This is a priority queue
    set<pair<int,int>,decltype(cmp)> pq(cmp);
    
    res[s][0] = 0;
    pq.insert(make_pair(s, 0));

    while(!pq.empty()) {
        auto j = *pq.begin();
        pq.erase(pq.begin());
        bool horse = (j.second || horses[j.first]);
        
        for(auto i: edges[j.first]) {
            ll amount = (horse ? i.second/2 : i.second);

            if(res[i.first][horse] > amount + res[j.first][j.second]) {
                pq.erase(make_pair(i.first, horse));
                res[i.first][horse] = amount + res[j.first][j.second];
                pq.insert(make_pair(i.first, horse));
            }
        }
    }
}

void solve() {
    int n, m, h;
    cin >> n >> m >> h;
    vector<vector<ll>> res1(n, {LONG_LONG_MAX, LONG_LONG_MAX}), res2(n, {LONG_LONG_MAX, LONG_LONG_MAX});
    vector<bool> horses(n);
    
    for (int i = 0; i < h; i++)
    {
        int x;
        cin >> x;
        horses[x-1] = true;
    }    
    vector<vector<pair<int, ll>>> edges(n);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges[a].push_back(make_pair(b, c));
        edges[b].push_back(make_pair(a, c));
    }
    djikstra(res1, edges, horses, 0);
    if(res1[n-1][0] == LONG_LONG_MAX && res1[n-1][1] == LONG_LONG_MAX) {
        cout << -1 << endl;
        return;
    }
    djikstra(res2, edges, horses, n-1);
    ll mn = LONG_LONG_MAX;
    for (int i = 0; i < n; i++)
    {
        mn = min(mn, max(min(res1[i][0], res1[i][1]), min(res2[i][0], res2[i][1])));
    }    
    cout << mn << endl;
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