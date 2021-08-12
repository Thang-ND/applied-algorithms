#include <bits/stdc++.h>
using namespace std;
#define NMAX 100005

int n;
int v[NMAX];
int q;
unsigned int mon[NMAX];
unsigned int trace[NMAX];
int res[NMAX];
map<int, int> value;
int currPos=1;

inline void TRY(int k) {
    if (currPos <= n)
    {
        for (; currPos<=n; currPos++) {
            if(v[currPos] > mon[k]) {
                value[mon[k]] = currPos-1;
                break;
            }
        }
    }
    if (currPos > n) value[mon[k]] = n;
    else value[mon[k]] = currPos-1;


}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("testcase.inp", "r", stdin);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> v[i];
    sort(v+1, v+n+1);
    cin >> q;
    for (int i=1; i<=q; i++) {
            cin >> mon[i];
        trace[i] = mon[i];
    }
    sort(mon+1, mon+q+1);

    for (int i=1; i<=q; i++) {
        TRY(i);
    }
    for (int i=1; i<=q; i++) {
        cout << value[trace[i]] << endl;
    }
    return 0;
}
