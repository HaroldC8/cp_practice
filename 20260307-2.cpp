/*
    Problem link: https://codeforces.com/problemset/problem/1301/D
    Tags: graphs
*/

#include<bits/stdc++.h>

using namespace std;

//#define MULTI
#define ll long long
#define all(x) (x).begin(), (x).end()

vector<string> commands;

void printer() {
    cout << commands.size() << endl;
    for(auto i: commands) {
        cout << i << endl;
    }
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if(4*n*m-2*n-2*m < k) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    if(m > 1) {
        if(k <= m-1) {
            commands.push_back(to_string(k) + " R");
            printer();
            return;
        }
        else {
            commands.push_back(to_string(m-1) + " R");
            k -= m-1;
        }

        if(k <= m-1) {
            commands.push_back(to_string(k) + " L");
            printer();
            return;
        }
        else {
            commands.push_back(to_string(m-1) + " L");
            k -= m-1;
        }
    }
    for (int i = 0; i < n-1; i++)
    {
        if(k <= 1) {
            commands.push_back("1 D");
            printer();
            return;
        }
        else {
            commands.push_back("1 D");
            k--;
        }
        if(m > 1) {
            if(k <= 3*m-3) {
                if(floor(k / 3.0) > 0) {
                    commands.push_back(to_string((int)floor(k / 3.0)) + " RUD");
                }
                if(k % 3 == 2) {
                    commands.push_back("1 RU");
                }
                else if(k % 3 == 1) {
                    commands.push_back("1 R");
                }
                printer();
                return;
            }
            else {
                commands.push_back(to_string(m-1) + " RUD");
                k -= 3*m-3;
            }
            
            if(k <= m-1) {
                commands.push_back(to_string(k) + " L");
                printer();
                return;
            }
            else {
                commands.push_back(to_string(m-1) + " L");
                k -= m-1;
            }
        }
    }
    if(n > 1) {
        if(k <= n-1) {
            commands.push_back(to_string(k) + " U");
            printer();
            return;
        }
        else {
            commands.push_back(to_string(n-1) + " U");
            k -= n-1;
        }
    }
    //printer();
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