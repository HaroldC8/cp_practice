#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

ll lowMatchingBit(ll a, ll b) {
    for (ll i = 1; i <= min(a, b); i = i << 1)
    {
        if((a & i) > 0 && (b & i) > 0) {
            return i;
        }
    }
    return 1;
}

void solve() {
    ll x, y;
    cin >> x >> y;

    ll ans = 0;

    while(x > 0) {
        if((x^y) == (x+y)) {
            break;
        }
        ll high = lowMatchingBit(x, y);
        //cout << high << "h" << endl;
        ll mn = max(1ll, min(((high-1)&x)+1, high - ((high-1)&y)));

        //cout << x << " " << y << " " << mn << endl;
        x -= mn;
        y += mn;
        ans += mn;
    }
    
    cout << x+y << " " << ans << "\n";
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