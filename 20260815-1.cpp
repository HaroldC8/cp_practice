/*
    Problem link: https://codeforces.com/contest/84/problem/C
    Tags: math, sorting
*/

#include<bits/stdc++.h>

using namespace std;

//#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }
    
    int m;
    cin >> m;
    vector<vector<int>> b(m, vector<int>(3));
    for (int i = 0; i < m; i++)
    {
        cin >> b[i][0] >> b[i][1];
        b[i][2] = i;
    }
    sort(all(a));
    sort(all(b));
    int j = 0;
    vector<int> res(n, m);
    for (int i = 0; i < n; i++)
    {
        while(j < m && b[j][0] < a[i][0]+a[i][1]) {
            if(pow(b[j][0]-a[i][0], 2) + pow(b[j][1], 2) <= pow(a[i][1], 2)) {
                res[a[i][2]] = min(res[a[i][2]], b[j][2]);
            }
            j++;
        }
        int k = j;
        while(k < m && b[k][0] == a[i][0]+a[i][1]) {
            if(pow(b[k][0]-a[i][0], 2) + pow(b[k][1], 2) <= pow(a[i][1], 2)) {
                res[a[i][2]] = min(res[a[i][2]], b[k][2]);
            }
            k++;
        }
    }
    int ans = 0;
    for(auto &i: res) {
        ans += (i != m);
    }
    cout << ans << "\n";
    for(auto &i: res) {
        cout << (i == m ? -1 : i+1) << " ";
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