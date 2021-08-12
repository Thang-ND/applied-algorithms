#include <bits/stdc++.h>
using namespace std;
#define NMAX 502
typedef unsigned long long ull;
int n_test;
int k, n;
ull a[NMAX];
vector <int> pos;
vector <int> res;
bool check (ull max_val) {
    pos.clear(); // vi tri
    ull sum=0;
    for (int i=n; i>=1; i--) {
        if (sum + a[i] <= max_val) {
            sum += a[i];
        } else {
            sum = a[i];
            if (a[i] > max_val) return false;
            pos.push_back(i); // cac phan tu ngan cach
        }
    }
    if (pos.size() >= k) {return false;}
    res = pos;
    return true;
}

void printResult(long long maxvalue) {
    int cnt = k - 1;
    deque<int> pos;
    long long sum = 0;
    for (int i = n; i >= 1; i--) {
        if (cnt == i) {
            pos.push_front(i);
            cnt--;
            continue;
        }
        if (sum + a[i] <= maxvalue) {
            sum += a[i];
        }
        else {
            sum = a[i];
            pos.push_front(i);
            cnt--;
        }
    }
    pos.push_back(-1);
    int i = 0;
    for (int j = 1; j <= n; j++) {
        if (j != pos[i]) {
            cout << a[j] << " ";
        }
        else {
            cout << a[j] << " / ";
            i++;
        }
    }
    cout << endl;
}

main (){
    cin >> n_test;
    while (n_test--) {
        cin >> n >> k;
        for (int i=1; i<=n; i++) cin >> a[i];
        ull l = 0, r = 1e10;
        while ( r - l > 1) {
            ull mid = (l+r) >> 1;
            if (check(mid)) r=mid;
            else l = mid;
        }
        printResult(r);
    }
}
