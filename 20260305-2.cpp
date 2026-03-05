/*
    Problem link: https://codeforces.com/problemset/problem/617/C
    Tags: geometry, sorting
*/

#include<bits/stdc++.h>

using namespace std;

//#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    pair<ll, ll> r1, r2;
    cin >> r1.first >> r1.second >> r2.first >> r2.second;

    vector<pair<ll, ll>> coord(n), dist1(n), dist2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coord[i].first >> coord[i].second;
        dist1[i].first = pow(r1.first-coord[i].first, 2) + pow(r1.second-coord[i].second, 2);
        dist1[i].second = i;
        dist2[i].first = pow(r2.first-coord[i].first, 2) + pow(r2.second-coord[i].second, 2);
        dist2[i].second = i;
    }
    sort(all(dist1));
    sort(all(dist2));

    set<int> in;
    ll mn = min(dist1.back().first, dist2.back().first);
    for (int i = 0; i < n; i++)
    {
        in.insert(dist1[i].second);
        set<int> cur = in;
        for (int j = 0; j < n; j++)
        {
            cur.insert(dist2[j].second);
            ll ans = dist1[i].first + dist2[j].first;
            if(cur.size() >= n) {
                mn = min(mn, ans);
            }
        }
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