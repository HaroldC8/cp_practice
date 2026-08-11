/*
    Problem link: https://codeforces.com/problemset/problem/2065/E
    Tags: greedy
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if((k > n && k > m) || (abs(n-m) > k)) {
        cout << "-1\n";
        return;
    }
    if(n == 0 || m == 0) {
        for (int i = 0; i < max(n, m); i++)
        {
            if(n < m) {
                cout << "1";
            }
            else {
                cout << "0";
            }
        }
        cout << "\n";
        return;
    }

    bool s_one = m >= n;
    for (int i = 0; i < k; i++)
    {
        if(s_one) {
            cout << "1";
            m--;
        }
        else {
            cout << "0";
            n--;
        }
    }
    
    while(n > 0 && m > 0) {
        if(s_one) {
            cout << "01";
        }
        else {
            cout << "10";
        }
        n--;
        m--;
    }

    while(n > 0) {
        cout << "0";
        n--;
    }

    while(m > 0) {
        cout << "1";
        m--;
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