/*
    Problem link: https://codeforces.com/problemset/problem/1759/D
    Tags: math, number theory
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    ll n, m;
    cin >> n >> m;
    ll temp = n;
    ll twoes = 0;
    while(temp > 0 && temp % 2 == 0) {
        twoes++;
        temp /= 2;
    }
    while(temp > 0 && temp % 5 == 0) {
        twoes--;
        temp /= 5;
    }
    ll res = 1;
    while(twoes < 0 && res*2 < m) {
        res *= 2;
        twoes++;
    }
    while(twoes > 0 && res*5 < m) {
        res *= 5;
        twoes--;
    }
    while(res*10 < m) {
        res *= 10;
    }
    res *= (m-(m % res)) / res;
    cout << n*res << "\n";
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