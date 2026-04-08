/*
    Problem link: 
    Tags: 
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

ll gcd(ll a, ll b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void solve() {
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    if(gcd(n, a) != 1 || gcd(m, b) != 1 || gcd(n, m) > 2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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