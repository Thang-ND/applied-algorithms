#include <bits/stdc++.h>
using namespace std;
#define NMAX 10005
const double PI  =3.1415926;

int T,N,F, r[NMAX];
double S[NMAX];
double max_size;

void enter() {
    cin >> N >> F;
    for (int i=1; i<=N; i++) {
        cin >> r[i];
        S[i] = r[i]*r[i]*PI;
        max_size = max(max_size, S[i]);
    }
}

bool mid(double m) {
    int sum = 0;
    for (int i=1; i<=N; i++) {
        sum = floor(sum + S[i]/m);
    }
    return sum >= (F+1);
}

main()
{
    cin >> T;
    while (T--) {
        max_size = -1;
        enter();
        double l = 0, r = max_size;
        while (r-l > 1e-6) {
            double m = (r+l)/2;
            if (mid(m)) l = m;
            else r = m;
        }
        printf("%.6lf\n", l);
    }
}
