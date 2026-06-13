/*
    Problem link: https://codeforces.com/problemset/problem/2232/C2
    Tags: binary search, greedy
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

int score(int x, ll s, int k, string& person) {
    int res = 0;
    ll space = 0;
    int left = x;
    for(auto i: person) {
        if(i == 'I' && left > 0) {
            left--;
            space += s-1;
            res++;
        }
        if(i == 'E' && space > 0) {
            space--;
            res++;
        }
        if(i == 'A') {
            if(left > 0 && k > 0) {
                k--;
                left--;
                space += s-1;
                res++;
            }
            else if(space > 0) {
                space--;
                res++;
            }
        }
    }
    //printf("it = %i, res = %i\n", k, res);
    return res;
}

void solve() {
    int n, x, s;
    cin >> n >> x >> s;
    string person;
    cin >> person;
    int l = 0, r = 0;    
    for (int i = 0; i < n; i++)
    {
        r += (person[i] == 'A');
    }
    while(l < r) {
        int mid = l+(r-l)/2;

        int res1 = score(x, s, mid, person);
        int res2 = score(x, s, mid+1, person);

        if(res1 < res2) {
            l = mid+1;
        }
        else {
            r = mid;
        }
    }

    cout << score(x, s, l, person) << "\n";

    /*
    - Allways seat I's at empty tables (there's no benefit to not seating them first)

    - For each I see how many others can it support after itself?
    - Can we place everything after I until the next I comes
    - If we can't we should consider placing an A

    - If an A enables an E that wouldn't be enabled by I then it is worth placing first

    - Ultimatelly, there are 2 choices for each A: first or in existing

    - Try placing the first k A's as first

    DP?
    */
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