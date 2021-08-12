#include <bits/stdc++.h>
using namespace std;
#define NMAX 10004
int n;
char x[NMAX];
main() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> x[i];
    int index=-1;
    for (int i=n; i>=1; i--) if (x[i] == '0') { index = i; break;}
    if (index == -1) {
        cout << -1;
    } else {
        x[index]='1';
        for (int i=index+1; i<=n; i++) x[i]='0';
        for (int i=1; i<=n; i++) cout << x[i];
    }
}
