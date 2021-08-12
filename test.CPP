#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int n;
int x[MAX];

void init(int x1) {
    for (int i=n; i>n-x1; i--) x[i] = 1;
    for (int i=1; i<=n-x1; i++) x[i] = 0;
}
void solve() {
    for (int i=0; i<=n; i++) {
        init(i);
        do {
            for (int j=1; j<=n; j++) {
                cout << x[j];
            } cout << endl;
        }while(next_permutation(x+1, x+n+1));
    }
}
int main() {
    cin >> n;
    solve();
}
