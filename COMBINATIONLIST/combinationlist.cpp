#include <bits/stdc++.h>
using namespace std;
#define NMAX 10004
int n, m, K;
int count1 = 0;
int x[NMAX];
void solution() {
    for(int i=1; i<=m; i++) printf("%d ", x[i]);
}
void TRY(int k) {
    for (int i=1; i<=n; i++) {
        if (x[k-1] < i) {
            x[k] = i;
            if (k==m) {
                count1++;
                //cout << count1 << endl;
                if (count1 == K)
                    solution();
            }
            else TRY(k+1);
        }
    }
}
main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> K;
    TRY(1);
    if (count1 < K) printf("-1");
    //cout << "DONE" << endl;
}
