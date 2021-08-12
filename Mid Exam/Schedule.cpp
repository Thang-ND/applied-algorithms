#include <bits/stdc++.h>
using namespace std;
#define NMAX 1006

int n;
int d[NMAX];
int L[NMAX];
int sum=0;
int best=INT_MAX;
int curr[NMAX];
bool visited[NMAX];
int Sub[NMAX];
int Q;
inline int max(int a, int b) {
    if (a >= b) return a;
    else return b;
}
bool check(int i, int k) {
    if (d[k]+curr[i] > 6) return false;
    if (i >= best) return false;
    if (curr[i]==0) if((Q+1) >= best) return false;
    else return true;
}
void TRY(int k) {
    for (int i=1; i<=n; i++) {
        if (check(i, k)) {
            if (curr[i]==0) Q++;
            curr[i] += d[k];
            if (k==n) {
                best = min(best, Q);

            } else if (Q < best) TRY(k+1);
            curr[i] -= d[k];
            if (curr[i]==0) Q--;
        }
    }
}

int main() {
   // freopen("testcase.inp", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> d[i];
    }
    TRY(1);
    cout << best << endl;
    return 0;
}
