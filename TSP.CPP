#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int n, m;
int iCost[MAX][MAX];
bool visited[20];
int iMin = INT_MAX;
int iRes = 0;
int x[20];
int best = INT_MAX;

void TRY(int k) {
    for (int i=2; i <= n; i++) {
        if(visited[i]==false && iCost[x[k-1]][i]) {
            visited[i] = true;
            x[k] = i;
            iRes += iCost[x[k-1]][i];
            if (k==n && iCost[x[k]][x[1]]) {
                best = min(best, iRes + iCost[x[k]][x[1]]);
            }
            else {
                int g = iRes + iMin*(n-k+1);
                if (g < best) TRY(k+1);
            }
            visited[i] = false;
            iRes -= iCost[x[k-1]][i];
        }
    }
}

int main() {
    freopen("TSP.inp", "r", stdin);
    cin >> n >> m;
    int I,J,C;
    for (int i=1; i <= m; i++) {
        cin >> I >> J >> C;
        iCost[I][J] = C;
        if (iMin > C) iMin = C;
    }
    x[1] = 1;
    visited[1] = true;

    TRY(2);
    cout << best;
    return 0;
}
