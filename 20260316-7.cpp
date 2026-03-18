/*
    Problem link: https://codeforces.com/contest/2204/problem/E
    Tags: math, brute force
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define __int128_t long long
#define all(x) (x).begin(), (x).end()

string tryfind(string target) {
    string res = target;
    
    __int128_t sum = 0;
    for(auto i: target) {
        sum += i-'0';
    }

    if(sum >= 10) {
        string t = tryfind(to_string(sum));
        res.insert(res.end(), all(t));
    }
    else {
        res += to_string(sum);
    }
    return res;
}

void solve() {
    string s;
    cin >> s;
    if(s.size() == 1) {
        cout << s << "\n";
        return;
    }
    int n = s.size();
    __int128_t sum = 0;
    vector<__int128_t> mp(10);
    for (int i = 0; i < s.size(); i++)
    {
        sum += s[i]-'0';
        mp[s[i]-'0']++;
    }

    for (int guess = 1; guess <= n*9; guess++)
    {
        string res = tryfind(to_string(guess));
        if(guess <= 9) {
            res = to_string(guess);
        }
        vector<__int128_t> mp2(10);
        __int128_t sum2 = 0;
        for(auto i: res) {
            mp2[i-'0']++;
            sum2 += i-'0';
        }
        bool found = 1;
        for (int i = 0; i < 10; i++)
        {
            if(mp2[i] > mp[i]) {
                found = 0;
                break;
            }
        }
        if(sum2+guess != sum || !found) {
            continue;
        }
        string ans = "";
        for (int i = 9; i >= 0; i--)
        {
            for (int j = 0; j < mp[i]-mp2[i]; j++)
            {
                ans += '0'+i;
            }
        }
        cout << ans+res << "\n";
        return;
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