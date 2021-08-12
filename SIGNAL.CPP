#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 200005
int n, b;
int a[MAX];
int max_L[MAX], max_R[MAX];
int res=0;
void input() {
    cin >> n >> b;
    int tmp = LONG_MIN;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        tmp = max(tmp, a[i]);
        max_L[i] = tmp;
    }
    tmp = LONG_MIN;
    for (int i=n; i>=1; i--) {
        tmp = max(tmp, a[i]);
        max_R[i] = tmp;
    }
}

main() {
    input();
    for (int i=2; i<=n-1; i++) {
        if((max_L[i-1]-a[i]>=b) && (max_R[i+1]-a[i]>=b)) {
            int tmp = max_L[i-1]-a[i] + max_R[i+1]-a[i];
            res = max(res, tmp);
        }
    }
    if(res==0) res = -1;
    cout << res;
}
