#include <bits/stdc++.h>
using namespace std;
#define NMAX 1000006
int n;
int a[NMAX];
int hillL;
int hillR;
int hill = 0;
int valleyL;
int valleyR;
int valley = 0;
void HILL() {
    int it=1, jt, kt;
    int i=1;
    while(i <= n-1) {
        it = i;
        while(i <= n-1 && a[i+1] > a[i]) i++;
        jt = i;
        hillL = jt-it;

        while (i <= n-1 && a[i+1] < a[i]) i++;
        kt = i;
        hillR = kt - jt;
        hill = max(min(hillL, hillR), hill);
        if (kt == jt) i++;
    }

}

void VALLEY() {
    int it=1, jt, kt;
    int i=1;
    while(i <= n-1) {
        it = i;
        while(i <= n-1 && a[i+1] < a[i]) i++;
        jt = i;
        valleyL = jt-it;
        while (i <= n-1 && a[i+1] > a[i]) i++;
        kt = i;
        valleyR = kt - jt;
        valley = max(min(valleyL, valleyR), valley);
        if (kt == jt) i++;
    }
}
int main() {
    freopen("testcase.inp", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    HILL();
    VALLEY();
    cout << hill <<" "<< valley << endl;
    return 0;
}
