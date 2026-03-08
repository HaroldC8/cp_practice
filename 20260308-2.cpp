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
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }    
    
    int k = 0;
    for (int i = 1; i <= l; i++)
    {
        priority_queue<pair<int, int>> pq;
        for (int j = 0; j < m; j++)
        {
            pq.push({-b[j], j});
        }

        while(pq.size() > 1 && pq.size()-1 > a.size()-k) {
            pq.pop();
        }
        
        b[pq.top().second]++;

        if(k < n && a[k] == i) {
            b[max_element(all(b))-b.begin()] = 0;
            k++;
        }
    }
    cout << *max_element(all(b)) << endl;
    
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