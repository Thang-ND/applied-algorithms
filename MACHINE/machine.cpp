#include <bits/stdc++.h>
using namespace std;

const int N = (int) 3e6;
const int INF = (int) 3e6;
int L[N+1], R[N+1];
int n;
int ans = -1;
void input() {
    for (int i=1; i<=N; i++) L[i] = R[i] = -INF;
    cin >> n;
    int a, b;
    for (int i=1; i<=n; i++) {
        scanf("%d %d", &a, &b);
        L[b] = max(L[b], b-a);
        R[a] = max(R[a], b-a);
    }
}

void solve() {
    for (int i=1; i<=N; i++) L[i] = max(L[i-1], L[i]);
    for (int i=N; i>=1; i--) R[i] = max(R[i+1], R[i]);
    ans = -INF;
    for (int i=1; i<=N-1; i++) {
        ans = max(ans, L[i] + R[i+1]);
    }

    if (ans == -INF) ans = -1;
    cout << ans;
}
main() {
    input();
    solve();
}
