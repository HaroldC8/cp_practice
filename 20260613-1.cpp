/*
    Problem link: https://codeforces.com/problemset/problem/2233/D
    Tags: brute force
*/

#include<bits/stdc++.h>

using namespace std;

#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

bool checker(vector<int>& a) {
    int n = a.size();
    vector<int> seen(n+1);
    for(int i = 0; i < n; i++) {
        int j = i+1;
        while(j < n && a[j] == a[i]) {
            j++;
        }
        if(seen[a[i]]) {
            return 0;
        }
        seen[a[i]] = 1;
        i = j-1;
    }
    return 1;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b;
    for(auto& i : a) {
        cin >> i;
    }
    b = a;
    sort(all(b));
	b.erase(unique(all(b)), b.end());
    for(auto& i : a) {
        i = upper_bound(all(b), i)-b.begin();
    }    

    vector<int> mp(n+1);
    vector<pair<int, int>> blocks;
    for(int i = 0; i < n; i++) {
        int j = i+1;
        while(j < n && a[j] == a[i]) {
            j++;
        }
        blocks.push_back({i, j-1});
        mp[a[i]]++;
        i = j-1;
    }

    int toChange = -1;
    for(int i = 0; i < n+1; i++) {
        //printf("f=%i s=%i\n", i.first, i.second);
        if(mp[i] > 3) {
            cout << "NO" << endl;
            return;
        }
        else if(mp[i] > 1) {
            toChange = i;
        }
    }
    
    if(toChange == -1) {
        cout << "YES" << endl;
        return;
    }
    
    vector<int> sw;
    for(auto i: blocks) {
        if(a[i.first] == toChange) {
            sw.push_back(i.first-1);
            sw.push_back(i.first);
            sw.push_back(i.second);
            sw.push_back(i.second+1);
        }
    }
    // Too much no
    // Potential problems: wrong sw array, wrong checker function
    for(int i = 0; i < sw.size(); i++) {
        for(int j = i+1; j < sw.size(); j++) {
            if(sw[i] < 0 || sw[i] >= n || sw[j] < 0 || sw[j] >= n || sw[i] == sw[j]) continue;
            //cout << a[sw[i]] << " ";
            swap(a[sw[i]], a[sw[j]]);
            if(checker(a)) {
                cout << "YES" << endl;
                return;
            }
            swap(a[sw[i]], a[sw[j]]);
        }
    }
    cout << "NO" << endl;
}

int main() {
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