/*
    Problem link: https://codeforces.com/problemset/problem/2255/C
    Tags: math, greedy, communication, center of mass
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

ll n;
string s[801];
ll w, si, sj;

ll inv(ll x) {
    for (int t = 1; t < n; t++)
    {
        if((x*t) % n == 1) {
            return t;
        }
    }
    return -1;
}

void solve1() {
    ll rx, cx;
    cin >> rx >> cx;
    rx--;
    cx--;
    ll d[2] = {((w*rx - si) % n + n) % n, ((w*cx - sj) % n + n) % n};
    if(d[0] == 0 && d[1] == 0) {
        cout << "1 1 1 1\n";
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int nw_i = (i + d[0]) % n;
            int nw_j = (j + d[1]) % n;
            if(s[i][j] == '#' && s[nw_i][nw_j] == '.') {
                cout << i+1 << " " << j+1 << " " << nw_i+1 << " " << nw_j+1 << "\n";
                return;
            }
        }
    }
}

void solve2() {
    cout << (si*inv(w))%n+1 << " " << (sj*inv(w))%n+1 << "\n";
}

int main(int argc, char **argv)
{    
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifdef MULTI
        string turn;
        cin >> turn;
        int t;
        cin >> t;
        while (t--)
        {
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cin >> s[i];
            }
            w = 0;
            si = 0;
            sj = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if(s[i][j] == '#') {
                        w++;
                        si += i;
                        sj += j;
                    }
                }
            }
            si %= n;
            sj %= n;
            
            if(turn == "first") {
                solve1();
            }
            else {
                solve2();
            }
        }
    #else
        solve();
    #endif
    return 0;
}