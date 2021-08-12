#include <bits/stdc++.h>
using namespace std;
#define NMAX 1005
long long hold = 0;
unsigned long long kq = 0;
struct point {
    long long x;
    long long m;
    point (long long x1, long long m1) {
        x = x1; m = m1;
    }
};
long long n, k;
vector <point> pos;
vector <point> neg;

void solve()
{
    for (long long i=0; i<pos.size(); i++) {
        if (pos[i].m < hold ) {
            hold -= pos[i].m;
            continue;
        }
        long long s = pos[i].m - hold;
        hold=0;
        long long t = (s/k);
        if (s%k!=0) {
            t++;
            hold = k - (s%k);
        }
        kq += t*pos[i].x*2;
    }

    hold = 0;
    for (long long i=0; i< neg.size(); i++) {
        if (neg[i].m < hold ) {
            hold -= neg[i].m;
            continue;
        }
        long long s = neg[i].m - hold;
        hold=0;
        long long t = (s/k);
        if (s%k>0) {
            t++;
            hold = k - (s%k);
        }
        kq += t*neg[i].x*2;
    }
}

void printP() {
    for (auto a: pos)
        cout << a.m << endl;
    for (auto a: neg)
        cout << a.m << endl;
}
bool compare(point A, point B) {
    return A.x >= B.x;
}
main()
{
    cin >> n >> k;
    long long tmp1, tmp2;
    for (long long i=1; i<=n; i++) {
        cin >> tmp1 >> tmp2;
        if (tmp1 >= 0) {
            point A(tmp1, tmp2);
            pos.push_back(A);
        } else {
            point  B(-tmp1, tmp2);
            neg.push_back(B);
        }
    }
    sort(pos.begin(), pos.end(), compare);
    sort(neg.begin(), neg.end(), compare);
    //prlong longP();
    solve();
    cout << kq << endl;
}
