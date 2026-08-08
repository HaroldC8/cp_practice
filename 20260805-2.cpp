/*
    Problem link: https://codeforces.com/problemset/problem/1137/B
    Tags: prefix function, strings
*/

#include<bits/stdc++.h>

using namespace std;

//#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    string s, t;
    cin >> s >> t;
    int ones_s = 0, ones_t = 0;
    for (int i = 0; i < s.size(); i++)
    {
        ones_s += s[i]-'0';
    }
    for (int i = 0; i < t.size(); i++)
    {
        ones_t += t[i]-'0';
    }
    int zeroes_s = s.size()-ones_s, zeroes_t = t.size()-ones_t;
    string res = "";
    
    if(ones_s >= ones_t && zeroes_s >= zeroes_t) {
        ones_s -= ones_t;
        zeroes_s -= zeroes_t;
        res += t;
    }

    vector<int> pi(t.size());
    for (int i = 1; i < t.size(); i++)
    {
        int j = pi[i-1];
        while(j > 0 && t[i] != t[j]) {
            j = pi[j-1];
        }
        if(t[i] == t[j]) {
            j++;
        }
        pi[i] = j;
    }    
    t = t.substr(pi.back(), t.size()-pi.back());
    //cout << t << " ";

    ones_t = 0;
    for (int i = 0; i < t.size(); i++)
    {
        ones_t += t[i]-'0';
    }
    zeroes_t = t.size()-ones_t;
    
    while(ones_s >= ones_t && zeroes_s >= zeroes_t) {
        ones_s -= ones_t;
        zeroes_s -= zeroes_t;
        res += t;
    }
    while(ones_s > 0) {
        res += '1';
        ones_s--;
    }
    while(zeroes_s > 0) {
        res += '0';
        zeroes_s--;
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