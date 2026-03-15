/*
    Problem link: https://codeforces.com/contest/2208/problem/D1
    Tags: dfs, graph, greedy, tree, sort
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

const int NMAX = 8010;

vector<vector<int>> res(NMAX), mp(NMAX);

bool dfs1(string& s, int i, int prev = -1) {
    if(s[i] == '1') {
        return 0;
    }
    s[i] = '1';
    bool ye = 1;
    for(auto j: mp[i]) {
        if(prev == j) continue;
        ye &= dfs1(s, j, i);
    }
    return ye;
}

bool dfs2(string& s, int i) {
    if(s[i] == '1') {
        return 0;
    }
    s[i] = '1';
    bool ye = 1;
    for(auto j: res[i]) {
        ye &= dfs2(s, j);
    }
    return ye;
}

void solve() {
    int n;
    cin >> n;
    vector<string> a(n), b(n);
    vector<int> amount(n), id(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
        for(auto j: a[i]) {
            amount[i] += j-'0';
        }
        amount[i]--;
        id[i] = i;
    }
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        res[i].clear();
        mp[i].clear();
    }

    sort(all(id), [&](auto i, auto j) {
        return amount[i] > amount[j];
    });

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int v = id[j];
            if(i == v || a[i][v] == '0' || b[i][v] == '0') continue;

            for (int k = 0; k < n; k++)
            {
                if(a[v][k] == '1') {
                    b[i][k] = '0';
                }
            }
            
            res[i].push_back(v);
            mp[i].push_back(v);
            mp[v].push_back(i);
            counter++;

            if(counter > n-1) {
                cout << "No\n";
                return;
            }
        }
    }    

    string t(n, '0');
    if(counter != n-1 || !dfs1(t, 0)) {
        cout << "No\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        string s(n, '0');
        if(!dfs2(s, i) || mp[i].empty()) {
            cout << "No\n";
            return;
        }
        if(s != a[i]) {
            cout << "No\n";
            return;
        }
    }    

    cout << "Yes\n";
    for (int i = 0; i < n; i++)
    {
        for(auto j: res[i]) {
            cout << i+1 << " " << j+1 << "\n";
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