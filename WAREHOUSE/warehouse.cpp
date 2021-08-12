#include <bits/stdc++.h>
using namespace std;
#define NMAX 1003
int N, T, D;
int a[NMAX], t[NMAX];
int ans=0;
int dp[NMAX][NMAX];
void input() {
    cin >> N >> T >> D;
    for (int i=1; i<=N; i++) cin >> a[i];
    for (int i=1; i<=N; i++) cin >> t[i];
}

main() {
    input();
    for (int i=1; i<=N; i++) {
        for (int k=t[i]; k<=T; k++) {
            for (int j=i-1; j>= max(0, i-D); j--)
                dp[i][k] = max(dp[i][k], dp[j][k-t[i]] + a[i]);
            ans = max(ans, dp[i][k]);
        }
    }
    cout << ans;
}
