#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int zeroes = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        zeroes += a[i] == 0;
    }
    int to_replace = (a[0] == 1) + (a[n-1] == 1);
    if(zeroes < 2) {
        cout << "-1\n";
        return;
    } 
    cout << to_replace << "\n";
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