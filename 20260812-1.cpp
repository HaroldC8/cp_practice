/*
    Problem link: https://codeforces.com/problemset/problem/991/E
    Tags: combinatorics, math
*/

#include<bits/stdc++.h>

using namespace std;

//#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    ll fact[19];
    fact[0] = 1;
    for (int i = 1; i < 19; i++)
    {
        fact[i] = fact[i-1]*i;
    }
     
    string s;
    cin >> s;
    int n = s.size();
    set<int> st;
    set<string> seen;
    for (int i = 0; i < n; i++)
    {
        st.insert(s[i]-'0');
    }
    ll res = 0;
    for (int i = 1; i < (1 << n); i++)
    {
        map<int, int> mp;
        string cur = "";
        for (int j = 0; j < n; j++)
        {
            if(((1 << j) & i) > 0) {
                mp[s[j]-'0']++;
                cur += s[j];
            }
        }
        bool legal = 1;
        for(auto &j: st) {
            legal &= (mp[j] > 0);
        }
        sort(all(cur));
        if(!legal || seen.count(cur)) {
            continue;
        }
        seen.insert(cur);
        ll temp = (cur.size()-mp[0]) * fact[cur.size()-1];
        for(auto i: mp) {
            temp /= fact[i.second];
        }
        res += temp;
        //cout << cur << " ";
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