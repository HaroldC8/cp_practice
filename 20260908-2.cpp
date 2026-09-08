#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    ll x, y, k;
    cin >> x >> y >> k;
    ll res = 0;

    ll j = y-2*x;
    for (ll i = 0; i < j && i < k; i++)
    {
        res += (y+i) % (x+i);
    }

    res += max(k-j-1, 0ll) * ((y+j+1) % (x+j+1));

    if(j < 0) {
        res = k * (y % x);
    }
    
    cout << res << "\n";

    // get at 
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