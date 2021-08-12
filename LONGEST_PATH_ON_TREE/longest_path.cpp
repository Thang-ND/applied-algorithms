#include <bits/stdc++.h>
using namespace std;
#define NMAX 100004
struct Edge{
    int node;
    int w;
    Edge(int _node, int _w) {
        node = _node;
        w = _w;
    }
};
vector <Edge> A[NMAX];
int d[NMAX];
int p[NMAX];
int n;
void input() {
    int u, v, x;
    cin >> n;
    for (int i=1; i<=n-1; i++) {
        cin >> u >> v >> x;
        A[u].push_back(Edge(v, x));
        A[v].push_back(Edge(u, x));
    }
}
void init() {
    for (int i=1; i<=n; i++) {
        d[i] = -1;
        p[i] = -1;
    }
}

void BFS(int u) {
    d[u] = 0;
    p[u] = 0;
    queue<int> Q;
    Q.push(u);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int i=0; i<A[v].size(); i++) {
            Edge x = A[v][i];
            int k = x.node;
            int kw = x.w;
            if (k == v) continue;
            if (d[k] == -1) {
                Q.push(k);
                d[k] = d[v] + kw;
                p[k] = v;
            }
        }
    }
}

int findMax() {
    int max_d=-1; int p_max;
    for (int i=1; i<= n; i++) {
        if(max_d < d[i]) {
            max_d = d[i];
            p_max = i;
        }
    }
    return p_max;
}

void solve() {
    init();
    BFS(1);
    int x = findMax();
    init();
    BFS(x);
    int i = findMax();
    cout << d[i];
}

main() {
    input();
    solve();
}
