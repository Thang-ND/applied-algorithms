#include <bits/stdc++.h>
using namespace std;
#define NMAX 10005
int n, k;
int a[NMAX];
long long sum[NMAX];
double best = INT_MIN;
double res;

int main() {
    freopen("testcase.inp", "r", stdin);
    cin >> n >> k;
    sum[0]=0;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }

    for (int i=k; i<=n; i++) {
        for (int j=0; j <= i-k; j++) {
            res = (sum[i]-sum[j])*1.0/(i-j);
            best = max(best, res);
            //cout << i << "-" << j << "-" << res << endl;
        }
    }
    cout << best << endl;
    return 0;
}

