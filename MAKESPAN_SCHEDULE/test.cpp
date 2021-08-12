#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
int ans;
int MOD = 1000000007;
int keo, hs;
void binomialCoeff(int n, int k)
{
    int C[n + 1][k + 1];
    int i, j;

    // Caculate value of Binomial Coefficient
    // in bottom up manner
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= min(i, k); j++) {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;

            // Calculate value using previously
            // stored values
            else
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j])%MOD;
        }
    }

    cout << C[n][k] % MOD;
}
main () {
    cin >> keo >> hs;
    binomialCoeff(keo+hs-1, keo);

}
