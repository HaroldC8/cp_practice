/*
    Problem link: https://codeforces.com/problemset/problem/1156/B
    Tags: greedy, sorting
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    map<char, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;
    }

    sort(all(s));
    
    string res1, res2;
    for (int i = 0; i < n; i++)
    {
        if(s[i] % 2) {
            if(!res1.empty() && res1.back() == s[i]) {
                continue;
            }
            res1.push_back(s[i]);
        }
        else {
            if(!res2.empty() && res2.back() == s[i]) {
                continue;
            }
            res2.push_back(s[i]);
        }
    }

    if(res2.empty() || abs(res1.back()-res2.front()) != 1) {
        res1.insert(res1.end(), res2.begin(), res2.end());
        
        for(auto i : res1) {
            for (int j = 0; j < mp[i]; j++)
            {
                cout << i;
            }        
        }
        cout << endl;
    } 
    else if(res1.empty() || abs(res2.back()-res1.front()) != 1) {
        res2.insert(res2.end(), res1.begin(), res1.end());

        for(auto i : res2) {
            for (int j = 0; j < mp[i]; j++)
            {
                cout << i;
            }        
        }
        cout << endl;
    }
    else {
        cout << "No answer" << endl;
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