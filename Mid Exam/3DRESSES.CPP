#include <bits/stdc++.h>
using namespace std;
#define NMAX 1000
int n, m;
int v[NMAX];
int Rela[NMAX][NMAX];
bool visited[NMAX];
int x[NMAX];
int res;
int best = INT_MAX;
bool check(int i, int k){
    if (k==1) return true;
    if (visited[i]==false) {
        for (int j=1; j<= k-1; j++) if (Rela[i][x[j]] == 0) return false;
        return true;
    } else return false;
}
void TRY(int k) {
    //cout << "IN TRY" << endl;
    for (int i=1; i<=n; i++) {
        if (check(i, k)) {
           // cout << k << endl;
            visited[i] = true;
            res += v[i];
            x[k] = i;
            if (k==3) {
                best = min(best, res);
            } else {
                TRY(k+1);
            }
            visited[i] = false;
            res-= v[i];
        }
    }
}
int main() {
    freopen("testcase.inp", "r", stdin);
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> v[i];
    int a, b;
    for (int i=1; i<=m; i++) {
        cin >> a >> b;
        Rela[a][b] = 1;
        Rela[b][a] = 1;
    }
    //cout << n << m;
    //cout << v[1] << v[2] << v[3] << endl;
    //cout << "TRY" << endl;
    TRY(1);
    if (best == INT_MAX) best = -1;
    cout << best << endl;
    return 0;
}
