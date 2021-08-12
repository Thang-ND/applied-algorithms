#include <bits/stdc++.h>
#define NMAX 1003
using namespace std;
typedef unsigned long long ull;
ull C[NMAX][NMAX];
ull k, n;
ull res;
const ull mod = 1e9+7;

ull CNK(ull k, ull n) {
    if (k==0 || k==n) return 1;
    if (k==1 || k==n-1) return n;
    if  (C[k][n] != 0) return C[k][n];
    C[k][n] = (CNK(k-1, n-1) + CNK(k, n-1)) % mod;
    return C[k][n];
}
main() {
    cin >> k >> n;
    res = CNK(k, n);
    cout << res%mod;
}

