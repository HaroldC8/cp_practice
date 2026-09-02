/*
    Problem link: https://codeforces.com/problemset/problem/1157/E
    Tags: binary search, map, greedy
*/

#include<bits/stdc++.h>

using namespace std;

//#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        mp[b]++;
    }

    for (int i = 0; i < n; i++)
    {
        auto f = mp.lower_bound(0);
        auto s = mp.lower_bound(n-a[i]);

        if(s == mp.end() || ((a[i]+f->first)%n < (a[i]+s->first)%n)) {
            cout << (a[i]+f->first)%n << " ";
            mp[f->first]--;
            if(mp[f->first] == 0) {
                mp.erase(f);
            }
        }
        else {
            cout << (a[i]+s->first)%n << " ";
            mp[s->first]--;
            if(mp[s->first] == 0) {
                mp.erase(s);
            }
        }
    }    
    cout << "\n";
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