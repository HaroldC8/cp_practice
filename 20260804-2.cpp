/*
    Problem link: https://codeforces.com/problemset/problem/1512/E
    Tags: greedy, math
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

int S(int i) {
    return i*(i+1)/2;
}

void solve() {
    int n, l, r, s;
    cin >> n >> l >> r >> s;
    l--;
    r--;
    int low = S(r-l+1), high = S(n) - S(n - (r-l+1));
    if(s > high || s < low) {
        cout << "-1\n";
        return;
    }
    int res[n];
    for(int i = l; i < r+1; i++) {
        res[i] = i-l+1;
    }
    int k = r;
    while(low < s) {
        if(res[k] == n-(r-k)) {
            k--;
        }
        res[k]++;
        low++;
    }
    bool used[500] = {0};
    for (int i = l; i < r+1; i++)
    {
        used[res[i]-1] = 1;
    }
    int j = 0;
    for (int i = 0; i < l; i++)
    {
        while(used[j]) {
            j++;
        }
        res[i] = j+1;
        used[j] = 1;
        cout << res[i] << " ";
    }
    for (int i = l; i < r+1; i++)
    {
        cout << res[i] << " ";
    }
    for (int i = r+1; i < n; i++)
    {
        while(used[j]) {
            j++;
        }
        res[i] = j+1;
        used[j] = 1;
        cout << res[i] << " ";
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
