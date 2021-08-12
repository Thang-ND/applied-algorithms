#include <bits/stdc++.h>
using namespace std;
#define NMAX 1005
int T;
int n;
long long X[NMAX], Y[NMAX];
long long res;
long long best;
void print(int X[]) {
    for (int i=1; i<=n; i++) cout << X[i] << " ";
    cout << endl;
}
int main() {
    freopen("testcase.inp", "r", stdin);
    cin >> T;
    for (int i=1; i<=T; i++) {
        cin >> n;
        for (int j=1; j<=n; j++) {
            cin >> X[j];
        }
        for (int j=1; j<=n; j++) {
            cin >> Y[j];
        }
        sort(X+1, X+n+1);
        sort(Y+1, Y+n+1);
        res=0;
        for (int k=1; k<=n; k++)
            res += X[k]*Y[n-k+1];
        cout << "Case #" << i << ": " << res << endl;

    }
    return 0;
}
