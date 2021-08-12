#include <bits/stdc++.h>
using namespace std;
const int NMAX = 10;
int N;
int digit[NMAX+1]; // I,C,T,H,U,S,K
int res;
bool mark[10];

void TRY(int k) {
    if (k > 7) {
        int x = digit[1]*100 + digit[2]*10 + digit[3] - digit[7]*100 + digit[4]*1000+digit[5]*100+digit[6]*10+ digit[3];
        if (x == (N+62)) res++;
        return;
    }
    for (int i=1; i<=9; i++) {
        if (mark[i]==0) {
            digit[k] = i;
            mark[i] = true;
            TRY(k+1);
            mark[i] = false;
        }
    }
}
main ()
{
    cin >> N;
    TRY(1);
    cout << res;
}
