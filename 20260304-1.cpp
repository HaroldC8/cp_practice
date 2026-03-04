/*
    Problem link: https://codeforces.com/problemset/problem/855/C
    Tags: dp, tree, graph
*/

#include<bits/stdc++.h>

using namespace std;

//#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

ll n, m, k, x;
const ll MOD = 1000000007;

ll dp[100001][3][12];

bool visited[100001];

void printi(int cur) {
    cout << "Printing " << cur+1 << endl;
    for (int cnt = 0; cnt <= x; cnt++)
    {
        cout << dp[cur][0][cnt] << " " << dp[cur][1][cnt] << " " << dp[cur][2][cnt] << endl;
    }
}

bool dfs(vector<vector<int>>& edges, int cur = 0) {
    if(visited[cur]) {
        return false;
    }
    visited[cur] = 1;

    // Leaf case
    if(edges[cur].size() == 1 && cur > 0) {
        dp[cur][0][0] = k-1;
        dp[cur][1][0] = 0;
        dp[cur][1][1] = 1;
        dp[cur][2][0] = m-k;

        //cout << "Leaf "; printi(cur);
        return true;
    }
    
    ll a[3][12], b[3][12];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            a[i][j] = 0;
            b[i][j] = 0;
        }    
        // When 0 of x is used want to multiply by 1 (start) 
        a[i][0] = 1;
    }  

    ll temp;
    for(auto i: edges[cur]) {
        if(!dfs(edges, i)) {
            continue;
        }

        for (int l = 0; l <= x; l++)
        {
            for (int r = 0; r <= x; r++)
            {
                if(l+r > x) {
                    continue;
                }
                // r selects in a
                // l selects in dp

                temp = dp[i][0][l] % MOD;
                b[1][r+l] += (a[1][r] * temp) % MOD;

                temp += dp[i][2][l];
                temp %= MOD;
                b[2][r+l] += (a[2][r] * temp) % MOD;
                
                temp += dp[i][1][l];
                temp %= MOD;
                b[0][r+l] += (a[0][r] * temp) % MOD;
            }
        }

        for (int j = 0; j < 3; j++)
        {
            for (int l = 0; l <= x; l++)
            {
                a[j][l] = b[j][l] % MOD;
                b[j][l] = 0;
            }        
        }  
    }     

    for (int cnt = 0; cnt <= x; cnt++)
    {
        dp[cur][0][cnt] = ((k-1)*a[0][cnt]) % MOD;
        dp[cur][1][cnt+1] = a[1][cnt] % MOD;
        dp[cur][2][cnt] = ((m-k)*a[2][cnt]) % MOD;
    }
    //printi(cur);
    return true;
}

void solve() {
    cin >> n >> m;
    vector<vector<int>> edges(n);
    for (int i = 0; i < n-1; i++)
    {
        int a0, a1;
        cin >> a0 >> a1;
        a0--;
        a1--;
        edges[a0].push_back(a1);
        edges[a1].push_back(a0);
    }
    
    cin >> k >> x;

    dfs(edges, 0);

    ll res = 0;
    for (int i = 0; i <= x; i++)
    {
        res += (dp[0][0][i] + dp[0][1][i] + dp[0][2][i]) % MOD;
    }

    cout << res % MOD << endl;
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