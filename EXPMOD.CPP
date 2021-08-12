#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
const ull MOD = 1e9 + 7;

int main() {
    ull a, b, c, res;
    cin >> a >> b;

    a = a % MOD;
    res = 1;
    ull i;
    for (i = b; i; i>>=1){
        // neu i le
        if(i&1) res = (res*a) % MOD;
        a = (a*a)%MOD;
    }
    cout << res;
    return 0;
}
