#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int red = 0, blue = 0;
    for (int i = 1; i < 2*n; i++)
    {
        if(s[i-1] == '1' && s[i] == '0') {
            red += (i % 2 == 1);
            blue += (i % 2 == 0);
        }
        if(s[i-1] == '1' && s[i] == '1') {
            red += (i % 2 == 0);
            blue += (i % 2 == 1);
        }
    }
    if(s[2*n-1] == '1' && s[0] == '0') {
        blue++;
    }
    if(s[2*n-1] == '1' && s[0] == '1') {
        red++;
    }
    cout << red << " " << blue << "\n";
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