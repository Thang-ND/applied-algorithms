#include<bits/stdc++.h>
using namespace std;
#define NMAX 600
int W, H, N, h[NMAX], w[NMAX];
int dp[NMAX][NMAX];

void input() {
    cin >> W >> H;
    cin >> N;
    for (int i=1; i<=N; i++) cin >> w[i] >> h[i];
}

void solve() {
    for (int i=1; i<=W; i++) {
        for (int j=1; j<=H; j++) {
            dp[i][j] = i*j;

            for (int k=1; k<=N; k++)
                if (i == w[k] && j == h[k]) {
                    dp[i][j] = 0;
                    break;
                }

            for (int k=1; k<i; k++)
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j]);

            for (int k=1; k<j; k++)
                dp[i][j] = min(dp[i][j], dp[i][j-k] + dp[i][k]);
        }
    }
    cout << dp[W][H];
}

main() {
    input();
    solve();
}
