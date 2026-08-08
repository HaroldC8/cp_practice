/*
    Problem link: https://codeforces.com/problemset/problem/276/D
    Tags: bitmasks, greedy, math
*/

#include<bits/stdc++.h>

using namespace std;

//#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    const int length = 63;
    ll l, r;
    cin >> l >> r;
    ll res = 0;
    for (ll bit = length; bit >= 0; bit--)
    {
        if(((1ll << bit) & r) > 0 && ((1ll << bit) & l) == 0) {
            res = (1ll << (bit+1))-1;
            break;
        }
    }
    cout << res << "\n";
    /*
    from the first 1 in r that is 0 in l
    10000
    01000

    1010
    1000
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