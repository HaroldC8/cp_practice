/*
    Problem link: 
    Tags: greedy
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

void solve() {
    int n, k, p, m;
    cin >> n >> k >> p >> m;
    p--;
    vector<int> a(n), b(n);
    int have = -1, res = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = i;
    }

    while(m > 0) {
        int j = 0;
        for (int i = 0; i < k; i++)
        {
            if(b[i] == p) {
                if(a[b[i]] <= m) {
                    res++;
                }
                else {
                    cout << res << "\n";
                    return;
                }
                j = i;
                break;
            }

            if(a[b[i]] < a[b[j]]) {
                j = i;
            }
        }

        //cout << j << " ";
        
        m -= a[b[j]];
        b.push_back(b[j]);
        b.erase(b.begin()+j);
    }
    cout << res << "\n";
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