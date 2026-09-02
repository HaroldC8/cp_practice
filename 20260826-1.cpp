/*
    Problem link: https://codeforces.com/problemset/problem/2236/F1
    Tags: combinatorics
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

const ll MOD = 1e9+7;
const int MX = 5e5+1;

int p[MX]{0};

void pre() {
    p[1] = 0;
    for (int i = 2; i*i < MX; i++)
    {
        if(p[i] > 0) {
            continue;
        }
        for (int j = i; j < MX; j += i)
        {
            p[j] = i;
        }    
    }
    for (int i = 2; i < MX; i++)
    {
        if(p[i] == 0) {
            p[i] = i;
        }
    }    
}

void solve() {
    int n, x;
    cin >> n >> x;
    map<int, int> mp;
    for (int i = 0; i < n; i++) 
    {
        int a;
        cin >> a;
        while(a > 1) {
            mp[p[a]]++;
            a /= p[a];
        }
    }
    ll res = 1;
    for(auto i: mp) {
        res = (res * (i.second + 1)) % MOD;
    }

    cout << res << "\n";
}

int main(int argc, char **argv)
{    
    pre();
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