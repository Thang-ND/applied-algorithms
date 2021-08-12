#include <bits/stdc++.h>
using namespace std;
#define NMAX 20005
int n, m, M;
int a[NMAX];
long long res;
long long FinalRes;
long long SUM[NMAX];

int main() {
    //freopen("testcase.inp", "r", stdin);
    cin >> n >> m >> M;
    SUM[0]=0;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        SUM[i] += SUM[i-1]+a[i];
    }
    //long long SUM = DAC(1, n);
    //cout << SUM[n] << endl;
    long long tmp;
    for (int i=1; i<=n; i++){
        if (SUM[i] >=m && SUM[i] <= M) FinalRes++;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j <=i-1; j++) {
            tmp = SUM[i]-SUM[j];
            if (tmp >=m && tmp <= M) FinalRes++;
        }
    }
    cout << FinalRes << endl;
    return 0;
}
