#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

int ask(int u, int v, int d) {
    cout << "? " << u << " " << v << " " << d << endl;
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> longer;
    int cur = 1;
    int f = 1, s = 1;
    for (int i = 2; i <= n; i++)
    {
        while(cur < n && ask(1, i, cur)) {
            f = i;
            cur++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if(i == f) {
            continue;
        }
        while(cur < n && ask(f, i, cur)) {
            s = i;
            cur++;
        }
    }
    cout << "! " << f << " " << s << " " << cur-1 << endl;
    cout.flush();
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