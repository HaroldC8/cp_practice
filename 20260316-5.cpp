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
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void solve() {
    ll a, b, c, n;
    cin >> a >> b >> c >> n;
    ll resa = floor((long double)n / a) * 6, resb = floor((long double)n / b) * 6, resc = floor((long double)n / c) * 6;
    ll ab = a*b / gcd(a, b), bc = b*c / gcd(b, c), ac = a*c / gcd(a, c);
    ll all = ab*c / gcd(ab, c);

    ll resall = n / all;
    ll resab = n / ab - resall;
    ll resbc = n / bc - resall;
    ll resac = n / ac - resall;

    
    //cout << resall << " " << resab << resbc << resac << "\n";

    resa -= resab*3;
    resb -= resab*3;

    resb -= resbc*3;
    resc -= resbc*3;
    
    resa -= resac*3;
    resc -= resac*3;

    resa -= resall*4;
    resb -= resall*4;
    resc -= resall*4;

    cout << resa << " " << resb << " " << resc << "\n";
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