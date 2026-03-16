/*
    Problem link: 
    Tags: 
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

bool dfs(vector<vector<int>>& edges, vector<int>& dirs, int i, int dir, int& count) {
    if(dirs[i] != 0) {
        if(dirs[i] == dir) {
            return true;
        }
        else {
            return false;
        }
    }
    dirs[i] = dir;

    count += (dir == 1);
    bool ans = 1;
    for(auto j: edges[i]) {
        ans &= dfs(edges, dirs, j, -dir, count);
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    vector<int> dir1(n, 0), dir2(n, 0); // 1, -1, 0-undefined
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(dir1[i] != 0 || dir2[i] != 0) continue;
        int c1 = 0, c2 = 0, res = 0;
        if(dfs(edges, dir1, i, -1, c1)) {
            res = max(res, c1);
        }
        if(dfs(edges, dir2, i, 1, c2)) {
            res = max(res, c2);
        }
        ans += res;
    }
    cout << ans << "\n";
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