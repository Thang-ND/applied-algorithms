#include <bits/stdc++.h>
using namespace std;
#define NMAX 100005
int n, m;
vector<int> A[NMAX];
int d[NMAX];

void enter()
{
    scanf("%d %d", &n, &m);
    int u, v;
    for (int i=1; i<=m; i++) {
        scanf("%d %d", &u, &v);
        A[u].push_back(v);
        A[v].push_back(u);
    }
}

bool BFS(int u)
{
    queue<int> Q;
    Q.push(u); d[u] = 0;
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        for (int i=0; i<A[v].size(); i++) {
            int t = A[v][i];
            if (d[t] == -1){
                Q.push(t); d[t] = d[v] + 1;
            }
            else if ((d[t] + d[v])%2==0)
                return false;
        }
    }
    return true;
}

void BipGraph()
{
    int ans=1;
    for (int i=1; i<= n; i++) d[i] = -1;
    for (int i=1; i<= n; i++) {
        if(d[i] == -1) {
           int ok = BFS(i);
           if (!ok) {
                ans = 0; break;
           }
        }
    }
    cout << ans;
}

main()
{
    enter();
    BipGraph();
    return 0;
}
