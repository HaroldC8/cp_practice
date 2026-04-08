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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), ks(k);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++)
    {
        cin >> ks[i];
        ks[i]--;
    }

    int val = a[ks[0]];
    int l = ks[0], r = ks[0];
    for (int i = ks[0]+1; i < n; i++)
    {
        if(a[i] != val) {
            r = i;
        }
    }
    for (int i = ks[0]-1; i >= 0; i--)
    {
        if(a[i] != val) {
            l = i;
        }
    }

    int ls = 0, rs = 0;
    for (int i = ks[0]+1; i < r+1; i++)
    {
        if(a[i] != a[i-1]) {
            rs++;
        }
    }
    for (int i = ks[0]-1; i >= l; i--)
    {
        if(a[i] != a[i+1]) {
            ls++;
        }
    }
    int res = max(ls, rs);
    if(res % 2) {
        res++;
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