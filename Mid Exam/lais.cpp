#include <bits/stdc++.h>
using namespace std;

long long n;
long long a[1000006];
long long b[1000006];


int main(){
    //freopen("testcase.inp", "r", stdin);
    cin >> n;
    long long tmp=0;
    for (int i=1; i<=n; i++) {
          cin >> a[i];
          if (a[i] < 0) tmp++;
    }
    cout << tmp + tmp;
}
