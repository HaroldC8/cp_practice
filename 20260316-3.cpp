/*
    Problem link: 
    Tags: 
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
    vector<bool> a(n);
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        a[j] = 1;
        if(s[j] == 'R') {
            j++;
        }
        else {
            j--;
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += a[i];
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