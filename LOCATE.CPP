#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m;
vector<pair<int, int>> a, b;
int cnt[N*2][N*2];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--) {
        memset(cnt, 0, sizeof(cnt));
        cin >> n >> m;
        a.clear(); b.clear();
        for (int i=1; i<= n; i++) {
            for(int j=1; j <=m; j++) {
                int u;
                cin >> u;
                if (u == 1) a.push_back({i, j});
            }
        }

        for (int i=1; i <=n; i++) {
            for (int j=1; j<=m; j++) {
                int u;
                cin >> u;
                if (u==1) b.push_back({i, j});
            }
        }

        for (auto u : a) {
            for (auto v : b) {
                pair<int, int> w =
                 { u.first - v.first + N,
                  u.second - v.second + N};
                  cnt[w.first][w.second]++;
                 }
            }
        int res = 0;
        for (int i=0; i < N*2; i++){
            res = max(res, *max_element(cnt[i], cnt[i]+N*2));

        }
        cout << res << endl;
        }
        return 0;
}
