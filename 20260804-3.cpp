/*
    Problem link: https://codeforces.com/problemset/problem/546/D
    Tags: dp, math
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()
    
const int MX = 5000001;
int primefact[MX] = {0}, prime[MX] = {0}, prefix[MX] = {0};

void precalc() {
    for (int i = 2; i*i < MX; i++)
    {
        if(prime[i] > 0) continue;
        for (int j = 2*i; j < MX; j+=i)
        {
            prime[j] = i;
        }
    }
    for (int i = 1; i < MX; i++)
    {
        if(prime[i] == 0) {
            primefact[i] = 1;
            continue;
        }
        primefact[i] = primefact[i / prime[i]]+1;
    }
    for (int i = 1; i < MX; i++)
    {
        prefix[i] = prefix[i-1] + primefact[i];
    }
}

void solve() {
    int a, b;
    cin >> a >> b;
    
    cout << prefix[a] - prefix[b] << "\n";
}

int main(int argc, char **argv)
{    
    ios::sync_with_stdio(false);
    cin.tie(0);
    precalc();
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