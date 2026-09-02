/*
    Problem link: https://ioi.contest.codeforces.com/group/32KGsXgiKA/contest/106645/problem/C
    Tags: patterns
*/

#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()

const int MAXN = 101;

int n, m;
bool taken[MAXN][MAXN] = {{false}};
vector<vector<int>> bt, tb;
int bl, tl, tr, br;

void init(int N, int M) {
    tb.clear();
    bt.clear();
    n = N;
    m = M;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            tb.push_back({i+j, i, j});
            bt.push_back({j-i, i, j});
            taken[i][j] = 0;
        }        
    }
    sort(all(tb));
    sort(all(bt));
    bl = n*m-1;
    tl = n*m-1;
    tr = 0;
    br = 0;
}

pair<int, int> receive_block(int TL, int TR, int BL, int BR) {
    pair<int, int> ans;
    if(TL == 0) {
        while(taken[tb[tl][1]][tb[tl][2]]) {
            tl--;
        }
        ans = make_pair(tb[tl][1], tb[tl][2]);
        tl--;
    }
    else if(TR == 0) {
        while(taken[bt[tr][1]][bt[tr][2]]) {
            tr++;
        }
        ans = make_pair(bt[tr][1], bt[tr][2]);
        tr++;
    }
    else if(BL == 0) {
        while(taken[bt[bl][1]][bt[bl][2]]) {
            bl--;
        }
        ans = make_pair(bt[bl][1], bt[bl][2]);
        bl--;
    }
    else {
        while(taken[tb[br][1]][tb[br][2]]) {
            br++;
        }
        ans = make_pair(tb[br][1], tb[br][2]);
        br++;
    }
    
    taken[ans.first][ans.second] = 1;
    return make_pair(ans.first*2, ans.second*2);
}

/*void printans(pair<int, int> ans) {
    cout << ans.first << " " << ans.second << "\n";
}

int main(int argc, char **argv)
{    
    init(1, 2);
    printans(receive_block(1, 0, 1, 1));
    printans(receive_block(0, 1, 1, 1));
    init(2, 2);
    printans(receive_block(0, 1, 1, 1));
    init(2, 2);
    printans(receive_block(1, 0, 1, 1));
    init(2, 2);
    printans(receive_block(1, 1, 0, 1));
    init(2, 2);
    printans(receive_block(1, 1, 1, 0));
    
    return 0;
}*/