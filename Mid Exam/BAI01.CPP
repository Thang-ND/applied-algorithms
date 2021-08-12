#include <bits/stdc++.h>
using namespace std;
#define NMAX 1006

int n;
int d[NMAX];
long long sum=0;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> d[i];
        sum += d[i];
    }

    return 0;
}
