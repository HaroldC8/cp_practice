/*
    Problem link: https://codeforces.com/problemset/problem/471/D
    Tags: prefix function, strings
*/

#include<bits/stdc++.h>

using namespace std;

//#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    int n, w;
    cin >> n >> w;
    vector<int> a(n), b(w), ad(n-1), bd(w-1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(i > 0) {
            ad[i-1] = a[i]-a[i-1];
        }
    }
    for (int i = 0; i < w; i++)
    {
        cin >> b[i];
        if(i > 0) {
            bd[i-1] = b[i]-b[i-1];
        }
    }
    if(w == 1) {
        cout << n << "\n";
        return;
    }
    bd.push_back(1e9+7);
    bd.insert(bd.end(), ad.begin(), ad.end());
    vector<int> pi(w+n-1);
    int res = 0;
    for (int i = 1; i < w+n-1; i++)
    {
        int j = pi[i-1];
        while(j > 0 && bd[i] != bd[j]) {
            j = pi[j-1];
        }
        if(bd[i] == bd[j]) {
            j++;
        }
        pi[i] = j;
        res += (j == w-1);
    }
    /*for (int i = 0; i < w+n-1; i++)
    {
        cout << bd[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < w+n-1; i++)
    {
        cout << pi[i] << " ";
    }*/
    
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