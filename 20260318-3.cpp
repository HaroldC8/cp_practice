/*
    Problem link: https://oj.uz/problem/view/LMIO19_noras
    Tags: math
*/

#include<bits/stdc++.h>

using namespace std;

//#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    ll n, r;
    cin >> n >> r;
    vector<vector<ll>> pos(n, vector<ll>(4));
    map<ll, ll> times;
    for (int i = 0; i < n; i++)
    {
        cin >> pos[i][0] >> pos[i][1] >> pos[i][2] >> pos[i][3];
        __int128_t kx = pos[i][2]-pos[i][0];
        __int128_t ky = pos[i][3]-pos[i][1];
        __int128_t a = (kx*kx) + (ky*ky);
        __int128_t b = (kx*pos[i][0] + ky*pos[i][1]);
        __int128_t c = (pos[i][0]*pos[i][0]) + (pos[i][1]*pos[i][1]) - (r*r);
        __int128_t D = (b*b) - a*c;
        if(D < 0) continue;
        ll t1 = ceil((-b - sqrtl(D))/a);
        ll t2 = floor((-b + sqrtl(D))/a);
        if(t2 < 0 || t2 < t1) continue;
        times[max(t1, 0ll)]++;
        times[t2+1]--;
    }
    ll mx = 0, cur = 0;
    for(auto i: times) {
        cur += i.second;
        mx = max(mx, cur);
    }
    cout << mx << "\n";
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