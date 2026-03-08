/*
    Problem link: 
    Tags: 
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

class SegTree {
    int n;
    ll tree[10000][2];

public:
    void setup(vector<ll>& a) {
        n = a.size();
        for (int i = 0; i < n; i++)
        {
            tree[i+n+1][0] = a[i];
            tree[i+n+1][1] = i;
        }
        for (int i = n; i > 0; i--)
        {
            if(tree[2*i][0] > tree[2*i+1][0]) {
                tree[i][0] = tree[2*i][0];
                tree[i][1] = tree[2*i][1];
            }
            else {
                tree[i][0] = tree[2*i+1][0];
                tree[i][1] = tree[2*i+1][1];
            }
        }        
        /*for (int i = 0; i <= 2*n+2; i++)
        {
            cout << tree[i][0] << " ";
        }
        cout << endl;*/
    }

    int get(int l, int r) {
        l += n+1;
        r += n+1;
        ll mx = 0;
        int i = -1;
        while(l <= r) {
            if(l % 2 == 1) {
                if(mx < tree[l][0]) {
                    mx = tree[l][0];
                    i = tree[l][1];
                }
                l++;
            }
            if(r % 2 == 0) {
                if(mx < tree[r][0]) {
                    mx = tree[r][0];
                    i = tree[r][1];
                }
                r--;
            }
            l /= 2;
            r /= 2;
        }
        return i;
    }
};

void solve() {
    ll n, h;
    cin >> n >> h;
    vector<ll> a(n), amount(n);
    SegTree stree;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    stree.setup(a);

    for (int i = 0; i < n; i++)
    {
        amount[i] += h-a[i];
        ll x = a[i];
        for (int j = i+1; j < n; j++)
        {
            x = max(x, a[j]);
            amount[i] += h-x;
        }
        x = a[i];
        for (int j = i-1; j >= 0; j--)
        {
            x = max(x, a[j]);
            amount[i] += h-x;
        }
        //cout << amount[i] << " ";
    }   
    //cout << endl;

    /*cout << stree.get(0, 0) << endl;
    cout << stree.get(2, 3) << endl;
    cout << stree.get(0, 3) << endl;
    cout << stree.get(2, 4) << endl;*/

    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            ll shared = amount[stree.get(i, j)];
            //cout << i << j << amount[i]+amount[j]-shared << endl;
            res = max(res, amount[i]+amount[j]-shared);
        }        
    }
    cout << res << endl;
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