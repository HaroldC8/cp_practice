/*
    Problem link: https://codeforces.com/problemset/problem/644/B
    Tags: two pointers
*/

#include<bits/stdc++.h>

using namespace std;

//#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    ll n, b;
    cin >> n >> b;
    vector<pair<ll, ll>> a(n);
    vector<ll> res(n, -1);
    queue<ll> q;
    ll finish = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
        while(!q.empty() && a[i].first >= finish) {
            finish = max(finish, a[q.front()].first) + a[q.front()].second;
            res[q.front()] = finish;
            q.pop();
        }
        if(q.size() < b) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        finish = max(finish, a[q.front()].first) + a[q.front()].second;
        res[q.front()] = finish;
        q.pop();
    }
    for(auto i: res) {
        cout << i << " ";
    }
    cout << endl;
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