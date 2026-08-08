/*
    Problem link: https://codeforces.com/contest/432/problem/D
    Tags: prefix function, strings
*/

#include<bits/stdc++.h>

using namespace std;

//#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pi(n), res(n+1);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j]) {
            j = pi[j-1];
        }
        if(s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
        res[pi[i]]++;
    }
    for (int i = n-1; i > 0; i--)
    {
        res[pi[i-1]] += res[i];
    }
    for (int i = 0; i <= n; i++)
    {
        res[i]++;
    }    
    
    vector<pair<int, int>> ans;
    int j = pi[n-1];
    while(j > 0) {
        if(s.back() == s[j-1]) {
            ans.push_back({j, res[j]});
        }
        j = pi[j-1];
    }
    sort(all(ans));
    ans.push_back({n, 1});
    cout << ans.size() << "\n";
    for(auto i: ans) {
        cout << i.first << " " << i.second << "\n";
    }
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