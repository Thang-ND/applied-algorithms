#include <bits/stdc++.h>
using namespace std;
int n;
int A[]= {0, -16, 7, -3, 0, -1, 5, -4};;
int iMem[100];
int iVisit[100];

int maxSub(int k) {
    if (k==1) return A[1];
    if (iVisit[k]!=0) return iMem[k];
    iMem[k] = max(A[k], A[k]+maxSub(k-1));
    iVisit[k] = 1;
    return iMem[k];
}
void Trace(int i) {
    if (i!=1 && iMem[i] == A[i] + iMem[i-1]) {Trace(i-1);
    cout << A[i] << " ";}
}
main () {
    n = 7;
    int res=-INT_MAX;
    int index;
    for (int i=1; i<=n; i++) {
        if (res < maxSub(i)) {
            res = max(res, maxSub(i));
            index = i;
        }
    }
    cout << index << endl;
    Trace(index);
}
