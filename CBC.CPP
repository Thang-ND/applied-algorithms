#include<bits/stdc++.h>
using namespace std;
#define NMAX 100

vector<int> G[NMAX];
int m, n, conflict[NMAX][NMAX], x[NMAX], best, load[NMAX];
// x[i] mean as teacher x[i] teach course i.

void enter() {
    int k, x, y;
    cin >> m >> n;
    for (int i=1; i<=m; i++){
        cin >> k;
        for(int j=1; j <=k; j++){
            cin >> x;
            G[x].push_back(i);
        }
    }
    cin >> k;
    for(int i; i <= k; i++){
        cin >> x >> y;
        conflict[x][y] = 1;
        conflict[y][x] = 1;
    }
}


bool check(int i, int v) { // k is subject, i is index of subject that is tautght by GV k.
    for (int j=1; j<= i-1; j++) {
        if (conflict[i][j])
            if (x[j] == v)
                return false;
    }
    return true;
}

void updateBest(){
    int local_Max = load[1];
    for(int i=2; i<=m; i++) {
        local_Max = max(local_Max, load[i]);
    }
    best = min(best, local_Max);
}
void TRY(int k){
    for (int i = 0; i < (int)G[k].size(); i++) {
        int v = G[k][i]; // v is teacher who taught subject k
        if (check(k, v)) {
            x[k] = v;
            load[v]++;

            if (k == n) {
                updateBest();
            }
            else
                if(load[v] < best) TRY(k+1);
            load[v]--;
        }
    }
}

int main() {
    //freopen("a.inp", "r", stdin);
    enter();
    best = LONG_MAX;
    TRY(1);
    cout << best;
    return 0;
}
