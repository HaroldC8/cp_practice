/*
    Problem link: https://codeforces.com/problemset/problem/1468/F
    Tags: geometry, map
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

ll gcd(ll a, ll b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void solve() {
    int n;
    cin >> n;
    map<vector<ll>, ll> mp;
    vector<vector<ll>> a(n, {0, 0});
    for(auto& i: a) {
        ll x, y, u, v;
        cin >> x >> y >> u >> v;
        i[0] = u-x;
        i[1] = v-y;
        ll d = gcd(abs(i[0]), abs(i[1]));
        i[0] /= d;
        i[1] /= d;
        //printf("(%i %i)\n", i[0], i[1]);
        mp[i]++;
    }
    ll res = 0;
    for(auto& i: a) {
        res += mp[{-i[0], -i[1]}];
    }
    cout << res/2 << "\n";
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