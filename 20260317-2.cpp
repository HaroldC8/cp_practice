/*
    Problem link: https://codeforces.com/problemset/problem/1244/E
    Tags: binary search, sort, two pointers
*/

#include<bits/stdc++.h>

using namespace std;

//#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), p(n+1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(all(a));
    for (int i = 0; i < n; i++)
    {        
        p[i+1] = a[i]+p[i];
    }

    ll ans = LLONG_MAX;
    for (int i = 0; i < n-1; i++)
    {
        ll k0 = k - (a[i]*(i+1)-p[i+1]);
        if(k0 < 0) {
            break;
        }
        ll l = a[i], r = a.back(), prev = -1;
        while(l < r) {
            ll mid = l+(r-l)/2;
            if(mid == prev) {
                break;
            }
            
            int j = upper_bound(all(a), mid)-a.begin();
            if(p[n]-p[j] - mid*(n-j) <= k0) {
                r = mid;
            }
            else {
                l = mid+1;
            }
            prev = mid;
        }
        ans = min(ans, r-a[i]);
    }

    for (int i = n-1; i > 0; i--)
    {
        ll k0 = k - (p[n]-p[i] - a[i]*(n-i));
        if(k0 < 0) {
            break;
        }
        ll l = a.front(), r = a[i], prev = -1;
        while(l < r) {
            ll mid = l+(r-l)/2;
            if(mid == prev) {
                break;
            }

            int j = lower_bound(all(a), mid)-a.begin()-1;

            if(mid*(j+1) - p[j+1] <= k0) {
                l = mid;
            }
            else {
                r = mid-1;
            }
            prev = mid;
        }
        ans = min(ans, a[i]-l);
    }
    cout << ans << "\n";
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