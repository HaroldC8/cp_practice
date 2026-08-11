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
    vector<string> patterns = {"0110", "1001", "0011", "1100"};
    int res = 4;
    for(auto p: patterns) {
        for (int i = 0; i < n; i++)
        {
            if(s[i] != '?' && p[i%4] != s[i]) {
                res--;
                break;
            }            
        }
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