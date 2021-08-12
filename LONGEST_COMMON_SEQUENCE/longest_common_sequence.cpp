#include<bits/stdc++.h>
using namespace std;
#define NMAX 10004
int m,n;
int x[NMAX], y[NMAX];
int L[NMAX][NMAX];

main() {
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> x[i];
    for (int j=1; j<=m; j++) cin >> y[j];

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            L[i][j] = max(L[i-1][j], L[i][j-1]);
            if (x[i] == y[j]) L[i][j] = max(L[i][j], L[i-1][j-1]+1);
        }
    }
    cout << L[n][m];
}
