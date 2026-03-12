/*
    Problem link: https://codeforces.com/contest/2207/problem/E1
    Tags: greedy
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> s;
    bool ye = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s.insert(a[i]);
        if(i > 0 && a[i] > a[i-1]) {
            ye = 0;
        }
    }
    if(!ye) {
        cout << 0 << endl;
        return;
    }
    vector<int> res(n);
    int j = n;
    for (int i = 0; i < n; i++)
    {
        if(a[i] > n || a[i] < n-i-1) {
            cout << 0 << endl;
            return;
        }
        if(i > 0 && a[i] == a[i-1]) {
            j--;
        }
        while(s.count(j) == 1) {
            j--;
        }
        res[i] = j;
    }
    
    cout << "YES" << endl;
    for(auto i: res) {
        cout << i << " ";
    }
    cout << endl;
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