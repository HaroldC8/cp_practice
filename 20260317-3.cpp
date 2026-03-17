/*
    Problem link: https://codeforces.com/problemset/problem/1611/F
    Tags: segment tree
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

ll tree[800050];
ll p[200050];
ll s, tl;

const ll MAX = 1e15;

void construct(int v, int l, int r) {
    if(l == r) {
        tree[v] = p[l];
    }
    else {
        int mid = l+(r-l)/2;
        construct(2*v, l, mid);
        construct(2*v+1, mid+1, r);
        tree[v] = min(tree[2*v], tree[2*v+1]);
    } 
}

void update(int v, int l, int r) {
    if(l == r) {
        tree[v] = MAX;
    }
    else {
        int mid = l+(r-l)/2;
        if(tl <= mid) {
            update(2*v, l, mid);
        }
        else {
            update(2*v+1, mid+1, r);
        }
        tree[v] = min(tree[2*v], tree[2*v+1]);
    }
}

int query(int v, int l, int r) {
    if(r < tl || (r == l && s + tree[v] - p[tl - 1] < 0)) {
        return -1;
    }
    if(r == l || s + tree[v] - p[tl - 1] >= 0) {
        return r;
    }

    int mid = l+(r-l)/2;

    if(mid < tl) {
        return query(2*v + 1, mid+1, r);
    }
    if(s + tree[2*v] - p[tl - 1] < 0) {
        return query(2*v, l, mid);
    }

    int res = query(2*v+1, mid+1, r);
    if(res == -1) {
        return mid;
    }
    else {
        return res;
    }
}

void solve() {
    ll n;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        p[i] = a;
        if(i > 0) p[i] += p[i-1];
    }
    
    construct(1, 0, n-1);
    
    pair<int, int> ans = {-1, -2};
    for (tl = 0; tl < n; tl++)
    {
        // find leftmost r so that p[r]-p[l-1]+s < 0
        int v = query(1, 0, n-1);
        if(v != -1 && ans.second-ans.first < v-tl) {
            ans.first = tl;
            ans.second = v;
        }
        update(1, 0, n-1);
    }
    if(ans.first == -1) {
        cout << -1 << "\n";
    }
    else {
        cout << ans.first+1 << " " << ans.second+1 << "\n";
    }
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