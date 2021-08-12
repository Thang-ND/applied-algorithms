#include<bits/stdc++.h>
using namespace std;
#define pp pair<long long, long long>
#define NMAX 1000006
deque<pp> Deq;
int n, L1, L2;
long long a[NMAX], f[NMAX];
long long best;

void input(){
    cin >> n >> L1 >> L2;
    for (int i=1; i<=n; i++) cin >> a[i];
}

void solve() {
    for (int i=1; i<=L1; i++) f[i] = a[i];
    for (int i=L1+1; i<=n; i++) {
        while(!Deq.empty() && f[i-L1] > Deq.back().second) Deq.pop_back();
        Deq.push_back(make_pair(i, f[i-L1]));
        while(i - Deq.front().first > L2) Deq.pop_front();
        f[i] = Deq.front().second + a[i];
        best = max(best, f[i]);
    }
    cout << best << endl;
}

main() {
    input();
    solve();
}
