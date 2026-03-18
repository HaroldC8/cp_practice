/*
    Problem link: https://codeforces.com/problemset/problem/1380/D
    Tags: math, two pointers
*/

#include<bits/stdc++.h>

using namespace std;

//#define MULTI
#define __int128_t long long
#define all(x) (x).begin(), (x).end()

void solve() {
    int n, m;
    cin >> n >> m;
    __int128_t x, y, k;
    cin >> x >> k >> y;
    vector<__int128_t> a(n), b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    int j = 0;
    vector<int> c;
    if(a.front() != b.front()) {
        c.push_back(-1);
    }
    for (int i = 0; i < m; i++)
    {
        while(j < n && a[j] != b[i]) {
            j++;
        }
        c.push_back(j);
        if(j >= n) {
            cout << "-1\n";
            return;
        }
    }
    if(a.back() != b.back()) {
        c.push_back(n);
    }
    __int128_t res = 0;
    for (int i = 0; i < c.size()-1; i++)
    {
        __int128_t length = c[i+1]-c[i]-1, mx = 0;
        for (int j = c[i]+1; j < c[i+1]; j++)
        {
            mx = max(mx, a[j]);
        }
        if(length < k && (c[i+1] == n || a[c[i+1]] < mx) && (c[i] == -1 || a[c[i]] < mx)) {
            cout << "-1\n";
            return;
        }
        if(length % k > 0) {
            res += y * (length % k);
            length -= length % k;
        }
        if(length > 0)  {
            if(x > y*k) {
                // better berserk
                if((c[i+1] == n || a[c[i+1]] < mx) && (c[i] == -1 || a[c[i]] < mx)) {
                    res += x;
                    length -= k;
                }
                res += y*length;
            }
            else {
                // better fireball
                res += x * (length / k);
            }
        }        
        //cout << res << endl;
    }    
    cout << res << "\n";
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