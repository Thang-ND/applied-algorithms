#include <bits/stdc++.h>
using namespace std;
#define NMAX 100000

unsigned int n;
unsigned int a[NMAX];
int res=0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("testcase.inp", "r", stdin);
    cin >> n;
    a[0] = 0;
    for (int i=1; i <= n; i++) {
        cin >> a[i];
        if (a[i] <= a[i-1]) res++;
    }
    cout << res << endl;
    return 0;
}
