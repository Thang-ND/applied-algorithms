#include <bits/stdc++.h>
using namespace std;

int n;
int Plus, Sub;

int main() {
    freopen("testcase.inp", "r", stdin);
    cin >> n;
    string s;
    for (int i=1; i<=n; i++) {
        cin >> s;
        if (s=="X++" || s == "++X") Plus+=1;
        else Sub+=1;
    }
    cout << Plus-Sub;
    return 0;
}
