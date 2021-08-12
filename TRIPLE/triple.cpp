#include <bits/stdc++.h>
using namespace std;
#define NMAX 5004
int N, K;
int a[NMAX];
int aMax=INT_MAX;
int res=0;

void input() {
    cin >> N >> K;
    for (int i=1; i<=N; i++) {
        cin >> a[i];
    }
}
int searchE(int head, int tail, int key) {
    if (head <= tail) {
        int mid = (head+tail) >> 1;
        if (a[mid] == key) {
            return 1 + searchE(head, mid-1, key) + searchE(mid+1, tail, key);
        }
        else if (a[mid] > key) return searchE(head, mid-1, key);
        else return searchE(mid+1, tail, key);
    }
    return 0;
}
main () {
    input();
    sort(a+1, a+1+N);
    for (int i=1; i<=N-2; i++) {
        for (int j=i+1; j<= N-1; j++) {
            if (K-a[i]-a[j]<=0) continue;
            res += searchE(j+1, N, K-a[i]-a[j]);
        }
    }
    cout << res << endl;
}
