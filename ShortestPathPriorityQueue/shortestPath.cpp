#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
const int INF = 1e9;

struct Arc{
    int node;
    int w;
    Arc(int _node, int _w){
        node = _node; w = _w;
    }
};

int n,m;
vector <Arc> A[N];
int s,t;
int d[N];

void solve() {
    for (int v=1; v<=n; v++) d[v] = INF;
    priority_queue<pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > qp;

    d[s] = 0;
    qp.push(make_pair(d[s], s));
    while(!qp.empty()) {
        pair<int, int> p = qp.top(); qp.pop();
        int u = p.second;
        if (u == t) break;
        for (int i=0; i < A[u].size(); i++) {
            Arc a = A[u][i]; int v = a.node; int w = a.w;
            if (w + d[u] < d[v]) {
                d[v] = d[u] + w; qp.push(make_pair(d[v], v));
            }
        }
    }
    cout << d[t] << endl;
}

void input() {
    cin >> n >> m;
    int x, y, z;
    for (int i=1; i<=m; i++) {
        cin >> x >> y >> z;
        A[x].push_back(Arc(y, z));
    }
    cin >> s >> t;
}
main()
{
    input();
    solve();
}
