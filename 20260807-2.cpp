/*
    Problem link: https://codeforces.com/problemset/problem/73/A
    Tags: greedy math
*/

#include<bits/stdc++.h>

using namespace std;

//#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    ll v[3], res[3];
    ll k;
    cin >> v[0] >> v[1] >> v[2] >> k;
    sort(v, v+3);
    ll three = min(v[0]-1, k / 3ll);
    for(int i = 0; i < 3; i++) {
        res[i] = 1 + three;
    }
    //printf("%i %i %i\n", res[0], res[1], res[2]);
    k -= three*3;

    ll two = min(v[1]-1-three, k / 2ll);
    for(int i = 0; i < 2; i++) {
        res[i] += two;
    }
    //printf("%i %i %i\n", res[0], res[1], res[2]);
    k -= two*2;

    ll one = min(v[2]-1-three-two, k);
    res[0] += one;
    //printf("%lld %lld %lld\n", res[0], res[1], res[2]);
    cout << res[0]*res[1]*res[2] << "\n";
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