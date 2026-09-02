/*
    Problem link: https://codeforces.com/problemset/problem/1450/D
    Tags: set
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i: a) {
        cin >> i;
    }

    vector<vector<int>> b(n);
    for (int i = 0; i < n; i++)
    {
        b[a[i]-1].push_back(i);
    }
    set<int> s;
    vector<bool> res(n);
    for (int num = 0; num < n-1; num++)
    {
        if(b[num].empty()) {
            break;
        }
        bool can = s.empty();
        for(auto& i: b[num]) {
            if(s.empty()) {
                break;
            }
            /*
            find the range and check if it is bigger then n-i
            if so break
            else continue searching
            */
            auto j = s.lower_bound(i);
            int r = (j == s.end() ? n : *j);
            int l = -1;
            if(j == s.begin()) {
                if(*j < i) {
                    l = *j;
                }
            }
            else {
                l = *prev(j);
            }
            if(r-l-1 >= n-num) {
                //printf("i:%i l:%i r:%i\n", num+1, l, r);
                can = 1;
                break;
            }
        }
        if(!can) {
            break;
        }
        res[num] = can | s.empty();
        s.insert(all(b[num]));
    }
    res[n-1] = 1;
    for (int i = 0; i < n; i++)
    {
        res[n-1] = res[n-1] & !b[i].empty();
    }
    for (int i = 0; i < n; i++)
    {
        cout << res[n-i-1];
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