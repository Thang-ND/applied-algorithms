#include <bits/stdc++.h>
using namespace std;

void enter() {
    scanf("%lld %lld", &n, &m);
    int x,y;
    for (int i=1; i<=m; i++) {
        col[i] = 0;
        adj[i].clear();
    }
    for (int i=1; i<=m; i++) {
        scanf("%lld %lld", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void dfs(int u, int color) {}
main()
{
    int k;
    scanf("%lld",&k);
    for (int i=1; i<=k; i++) {
        enter();
    }
}
