#include<bits/stdc++.h>
using namespace std;

const int N = 1002;
typedef pair<long long, long long> pii;
long long n, nn, np, k, x, m;
long long ans = 0;
pii negCus[N], posCus[N];

long long calSegment(pair<long long, long long> p[], long long np) {
    long long res = 0;
    long long cur = 0;
    for (long long i=1; i <= np; i++) {
        if(p[i].second > 0){
            if (cur >= p[i].second) {
            //Du so kien de phat
            cur -= p[i].second;
            } else {
                // Khong du so kien de phat
                p[i].second -= cur;
                long long times = (p[i].second-1)/k+1;
                res += 2*abs(p[i].first)*times;
                cur = times*k-p[i].second;
            }
        }
    }
    return res;
}

int main() {
    cin >> n >> k;
    nn = np = 0;
    for (long long i=1; i<=n; i++) {
        cin >> x >> m;
        // Chia 2 tap
        if (x<0) negCus[++nn] = make_pair(x, m);
        else posCus[++np] = make_pair(x, m);
    }
    // sap xep khach hang trong tap theo khoang cach
    sort(negCus+1, negCus+nn+1);
    sort(posCus+1, posCus+np+1, greater<pii>());

    //Tinh khoang thoi gian nho nhat voi moi tap
    long long negSeg = calSegment(negCus, nn);
    long long posSeg = calSegment(posCus, np);
    ans = negSeg + posSeg;
    cout << ans << endl;
    return 0;
}
