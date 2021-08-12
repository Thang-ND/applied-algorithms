#include <bits/stdc++.h>
using namespace std;
#define NMAX 10004
int n, a[NMAX], mem[NMAX];
int last;
void input() {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
}

main() {
    input();
    for (int i=1; i<=n; i++) mem[i] = 1;
    for (int i=2; i<=n; i++) {
        for (int j=1; j<i; j++) {
            if (a[i] > a[j]) {
                mem[i] = max(mem[i], mem[j]+1);
            }
        }
    }
    int ans=0;
    for (int i=1; i<=n; i++) {
        ans = max(ans, mem[i]);
    }
    cout << ans;
}
