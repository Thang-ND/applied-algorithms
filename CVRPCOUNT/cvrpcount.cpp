#include <bits/stdc++.h>
using namespace std;
#define NMAX 12
typedef unsigned long long ull;

int n, K, Q, d[NMAX];
ull result = 0;
const int mod = 1000000007;
int load[NMAX]; // số địa điểm mà xe i đã đi qua
int m[NMAX]; // khối lượng xe i đã trở

ull fact(int t) {
    if (t==0) return 0;
    if (t==1) return 1;
    else return fact(t-1)*t;
}
void TRY(int k) {
    for (int i=1; i<=K; i++) {
        int p = load[i];
        int t = m[i];
        load[i]++;
        m[i] = m[i] + d[k];
        if (m[i] <= Q) {
            if (k == n) {
//                ull res = 1;
//                for (int j=1; j<=K; j++)
//                    res = res*fact(load[j]);
//                result += res;
            } else TRY(k+1);
        }
        load[i] = p;
        m[i] = t;
    }
}
main() {
    cin >> n >> K >> Q;
    for (int i=1; i<=n; i++)
        cin >> d[i];
    TRY(1);
    cout << (result/fact(K)) % mod;
}
