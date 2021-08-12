#include <bits/stdc++.h>
using namespace std;
#define NMAX 1000006
typedef long long ull;
ull N, M;
ull w[NMAX];
ull maxHeight=0;
ull result;
void input(){
    scanf("%ld %ld", &N, &M);
    for (int i=1; i<=N; i++) {
        scanf("%ld", &w[i]);
        if (w[i] > maxHeight) maxHeight = w[i];
    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    input();
    ull start= 1, end = maxHeight, mid;
    ull res;
    while (start <= end) {
        mid = (start+end)/2;
        res=0;
        for (ull i=1; i<=N; i++) {
            if (w[i]-mid>0) res+=w[i]-mid;
        }
        if (res > M) {
            result = max(result, mid);
            start = mid + 1;
        }
        else if (res < M) {
            end = mid - 1;
        } else {
            result = mid;
            break;
        }
    }
    cout << result;

}
