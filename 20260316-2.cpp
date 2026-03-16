/*
    Problem link: https://codeforces.com/problemset/problem/1815/B
    Tags: graph, tree, shortest path, interactive
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    int trash;
    cout << "+ " << n+1 << endl;
    cin >> trash;
    cout << "+ " << n+2 << endl;
    cin >> trash;

    vector<int> ord(n);
    for (int i = 0; i < n; i++)
    {
        if(i % 2 == 0) {
            ord[i] = i/2+1;
        }
        else {
            ord[i] = n-(i/2);
        }
    }

    int mx = 0, j = 0;
    for (int i = 2; i <= n; i++)
    {
        cout << "? 1 " << i << endl;
        cin >> trash;
        if(trash > mx) {
            j = i;
            mx = trash;
        }
    }
    vector<int> res(n*2);
    res[j-1] = ord[0];
    res[n+j-1] = ord[n-1];
    for (int i = 1; i <= n; i++)
    {
        if(i == j) continue;
        cout << "? " << j << " " << i << endl;
        cin >> trash;
        res[i-1] = ord[trash];
        res[n+i-1] = ord[n-trash-1];
    }
    
    cout << "!";
    for(auto i: res) {
        cout << " " << i;
    }
    cout << endl;
    cin >> trash;
}

int main(int argc, char **argv)
{    
    //ios::sync_with_stdio(false);
    //cin.tie(0);
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