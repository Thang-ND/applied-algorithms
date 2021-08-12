#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define NMAX 1000006

ll n, a[NMAX], mem[NMAX];
void input() {
    scanf("%lld", &n);
    memset(mem, -1, sizeof(mem));
    for (int i=1; i<=n; i++) {
        scanf("%lld", &a[i]);
    }
}

ll F(ll i) {
    if (i==1) return a[1];
    if (mem[i] < 0) {
        ll tmp = F(i-1);
        mem[i] = max(a[i], tmp+a[i]);
    }
    return mem[i];
}
main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    input();
    ll best=INT_MIN;
    for (int i=1; i<=n; i++) {
        best = max(best, F(i));
    }
    cout << best;
}
