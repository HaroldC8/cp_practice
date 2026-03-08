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

    for (int i = 1; i < n-1; i++)
    {
        if(s[i-1] == '1' && s[i+1] == '1') {
            s[i] = '1';
        }
    }
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        if(s[i] == '1') {
            mx++;
        }
    }
    int mn = mx;
    for (int i = 1; i < n-1; i++)
    {
        if(s[i-1] == '1' && s[i+1] == '1') {
            s[i] = '0';
            mn--;
        }
    }
    cout << mn << " " << mx << endl;
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