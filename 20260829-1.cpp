#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

ll gcd(ll a, ll b) {
    if(a == 1) {
        return b;
    }
    return gcd(b % a, a);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i: a) {
        cin >> i;
    }
    cout << gcd(a[0], a[n-1]) << "\n";
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