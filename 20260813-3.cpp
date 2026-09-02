/*
    Problem link: https://codeforces.com/problemset/problem/1822/E
    Tags: greedy, math
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n % 2) {
        cout << "-1\n";
        return;
    }
    map<char, int> cnt;
    for (int i = 0; i < n; i++)
    {
        cnt[s[i]]++;
        if(cnt[s[i]] > n/2) {
            cout << "-1\n";
            return;
        }
    }
    map<char, int> mp;
    for (int i = 0; i < n/2; i++)
    {
        if(s[i] == s[n-i-1]) {
            mp[s[i]]++;
        }
    }
    int res = 0, mx = 0;
    for(auto i: mp) {
        res += i.second;
        mx = max(mx, i.second);
    }
    cout << max(mx, (int)ceil(res/2.0)) << "\n";
    /*
    - best to swap 2 pairs that are out of order
    */
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