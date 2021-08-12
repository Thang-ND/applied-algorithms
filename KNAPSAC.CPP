// A dynamic programming based
// solution for 0-1 Knapsack problem
#include <bits/stdc++.h>
using namespace std;

long long val[1000];
long long wt[1000];
int n, W;
long long max(long long a, long long b) {
    if (a > b) return a;
    else return b;
}
int main()
{
    freopen("TSP.inp", "r", stdin);
    cin >> n >> W;
    for (int i=1; i<=n; i++) {
        cin >> wt[i] >> val[i];
    }

    long long mat[n+1][W+1];
    for(int i=1; i <= n; i++) mat[i][0] = 0;
    for(int i=1; i <= W; i++) mat[0][i] = 0;
    for (int item = 1; item <=n; item++){
        for(int cap=1; cap <=W; cap++) {
            if (cap < wt[item]) mat[item][cap] = mat[item-1][cap];
            else
                mat[item][cap] = max(val[item] + mat[item-1][cap - wt[item]], mat[item-1][cap]);
        }
    }
    cout << mat[n][W];
    return 0;
}
