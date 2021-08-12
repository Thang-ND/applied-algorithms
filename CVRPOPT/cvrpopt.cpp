#include <bits/stdc++.h>
using namespace std;
#define NMAX 15
typedef unsigned long long ull;
int n, K, Q, d[NMAX];
int c[NMAX][NMAX];
ull minRES = INT_MAX;
ull RES=0;
int m[NMAX];

int load[NMAX];
int packInTruck[NMAX];
int mark[NMAX];
int x[NMAX];
ull bestSub;
ull curr;

void TRY_ON_TRUCK(int k, int t) {
   for (int i=1; i<=n; i++) {
        if ((packInTruck[t] >> i) & 1) {
            if (!mark[i]) {
                x[k] = i;
                curr += c[x[k-1]][i];
                mark[i] = 1;
                if (k==load[t]) {
                    bestSub = min(bestSub, curr + c[i][0]);
                }
                TRY_ON_TRUCK(k+1, t);
                curr -= c[x[k-1]][i];
                mark[i] = 0;
            }
        }
   }
}
int minPath(int truck_id) {
    bestSub = INT_MAX;
    memset(x, 0, NMAX*sizeof(int));
    memset(mark, 0, NMAX*sizeof(int));
    curr = 0;
    TRY_ON_TRUCK(1, truck_id);
    return bestSub;
}
void TRY(int k) {
    for (int i=1; i<=K; i++) {
        int p = load[i];
        int t = m[i];
        load[i]++;
        m[i] = m[i] + d[k];
        packInTruck[i] += (1 << k);
        if(m[i] <= Q) {
            if(k==n) {
                RES = 0;
                for (int j=1; j<=K; j++) {
                    if (load[j] == 0) return;
                    RES += minPath(j);
                }
                minRES = min(minRES, RES);
            } else TRY(k+1);
        }
        load[i] = p;
        m[i] = t;
        packInTruck[i] -= (1 << k);

    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    cin >> n >> K >> Q;
    for (int i=1; i<=n; i++) {
        cin >> d[i];
    }
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            cin >> c[i][j];
        }
    }
    TRY(1);
    cout << minRES;
}
