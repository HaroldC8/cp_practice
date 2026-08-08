/*
    Problem link: https://codeforces.com/contest/802/problem/A2
    Tags: priority queue, greedy
*/

#include<bits/stdc++.h>

using namespace std;

//#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<vector<int>> mp(n+1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = n-1; i >= 0; i--)
    {
        mp[a[i]].push_back(i);
    }
    
    vector<bool> books(n+1);
    priority_queue<pair<int, int>> pq;
    int res = 0;
    int inside = 0;
    for (int i = 0; i < n; i++)
    {
        mp[a[i]].pop_back();
        if(books[a[i]]) {
            pq.push(make_pair(mp[a[i]].empty() ? 1e9+7 : mp[a[i]].back(), a[i]));
            continue;
        }
        if(inside == k) {
            books[pq.top().second] = 0;
            pq.pop();
            inside--;
        }
        books[a[i]] = 1;
        pq.push(make_pair(mp[a[i]].empty() ? 1e9+7 : mp[a[i]].back(), a[i]));
        res++;
        inside++;
    }
    cout << res << "\n";
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