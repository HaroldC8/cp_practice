/*
    Problem link: https://codeforces.com/problemset/problem/1041/E
    Tags: tree, graph, greedy
*/

#include<bits/stdc++.h>

using namespace std;

//#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void find_next(vector<int>& used, int& j) {
    while(j < used.size() && used[j] == 1) {
        j++;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n-1);
    map<int, int> mp;
    bool ye = 1;
    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        v[i] = make_pair(a, b);
        mp[a]++;

        if(mp[a] > a || b != n) {
            ye = 0;
        }
    }
    sort(all(v));
    for (int i = 1; i < n-1; i++)
    {
        if(i >= v[i].first) {
            cout << "NO" << endl;
            return;
        }
    }
    
    if(!ye) {
        cout << "NO" << endl;
        return;
    }
    
    cout << "YES" << endl;
    int j = 0, l = v.front().first;
    vector<int> used(n);
    used[l-1] = 1;
    cout << l << " ";
    for (int i = 1; i < n-1; i++)
    {
        if(l < v[i].first) {
            cout << v[i].first << endl << v[i].first << " ";
            used[v[i].first-1] = 1;
        }
        else {
            find_next(used, j);
            cout << j+1 << endl << j+1 << " ";
            used[j] = 1;
        }
        l = v[i].first;
    }
    cout << n << endl;
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