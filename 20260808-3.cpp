/*
    Problem link: https://codeforces.com/problemset/problem/1365/D
    Tags: greedy, flood fill
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void tryblock(vector<string>& grid, int i, int j) {
    if(i >= 0 && j >= 0 && i < grid.size() && j < grid[i].size() && 
    grid[i][j] == '.') {
        grid[i][j] = '#';
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    int good = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(grid[i][j] == 'B') {
                tryblock(grid, i+1, j);
                tryblock(grid, i-1, j);
                tryblock(grid, i, j+1);
                tryblock(grid, i, j-1);
            }
            else if(grid[i][j] == 'G') {
                good++;
            }
        }
    }
    queue<pair<int, int>> q;
    q.push({n-1, m-1});
    while(!q.empty()) {
        int i = q.front().first, j = q.front().second;
        q.pop();

        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || 
        grid[i][j] == '#') {
            continue;
        }
        if(grid[i][j] == 'G') {
            good--;
        }
        if(grid[i][j] == 'B') {
            cout << "No\n";
            return;
        }
        grid[i][j] = '#';

        q.push(make_pair(i+1, j));
        q.push(make_pair(i-1, j));
        q.push(make_pair(i, j+1));
        q.push(make_pair(i, j-1));
    }

    cout << (good == 0 ? "Yes\n" : "No\n");
    
    /*
    all B should be surounded by other B or #
    then flood fill and check if got all G
    */
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