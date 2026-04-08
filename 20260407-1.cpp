/*
    Problem link: 
    Tags: 
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    int n, k;
    cin >> n >> k;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        sum += a;
    }
    if(sum % 2 == 0 && n*k % 2) {
        printf("NO\n");
        return;
    }
    printf("YES\n");
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