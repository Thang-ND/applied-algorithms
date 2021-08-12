#include <bits/stdc++.h>
using namespace std;
#define NMAX 10004
int n, m;
int x[NMAX];
void solution() {
    for (int i=1; i<=m; i++) cout << x[i] << " ";
}
main () {
    cin >> n >> m;
    for (int i=1; i<=m; i++) cin >> x[i];
    if (x[m] != n) {
        x[m] ++;
        solution();
    } else {
        int id=-1;
        int j=n;
        for (int i=m; i>=1; i--) {
            if (x[i] < (j)) {
                id = i;
                break;
            } j--;
        }
        //cout << id << endl;
        if (id == -1) cout << -1;
        else {
            int base=x[id]+1;
            for (int i=id; i<=m; i++) {
                x[i] = base;
                base++;
            }
            solution();
        }
    }
}

