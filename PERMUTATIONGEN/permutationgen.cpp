#include <bits/stdc++.h>
using namespace std;
const int NMAX=10004;
int n;
int H[NMAX];
main() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> H[i];
    int k=n;
    while(k>1) {
        if(H[k] < H[k-1]) k--;
        else break;
    }
    if (k==1) cout << -1;
    else {
        int m = n;
        while(H[m] < H[k-1]) m--;
        swap(H[m], H[k-1]);
        for (int i=1; i <= k-1; i++) cout << H[i] << " ";
        for (int i=n; i >= k; i--) cout << H[i] << " ";
    }
}
