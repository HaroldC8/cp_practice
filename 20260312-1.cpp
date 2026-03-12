/*
    Problem link: https://codeforces.com/contest/2207/problem/D
    Tags: dfs, dp, tree, shortest path
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

// If reach a node that is reachable 
/*
    - Initially all leaf nodes are reachable (0).
    - If there are 2 children nodes that are reachable in < k then the 
    parent is also reachable
    - Otherwise the parent distance is min of children +1
*/
void dfs(vector<vector<int>>& a, vector<int>& res, int k, int cur, int prev = -1) {
    if(a[cur].size() == 1) {
        res[cur] = 0;
        return;
    }

    vector<int> ans;
    for(auto i: a[cur]) {
        if(i == prev) continue;
        dfs(a, res, k, i, cur);
        ans.push_back(res[i]);
    }
    sort(all(ans));
    if(ans.size() >= 2 && ans[0]+ans[1] < k) {
        res[cur] = 0;
    }
    else {
        res[cur] = ans[0]+1;
    }
}

void solve() {
    int n, k, v;
    cin >> n >> k >> v;
    v--;
    vector<vector<int>> a(n);
    for (int i = 0; i < n-1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    vector<int> res(n);
    dfs(a, res, k, v);    

    if(res[v] == 0) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
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