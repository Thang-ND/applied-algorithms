#include <bits/stdc++.h>

using namespace std;
#define NMAX 2000006
int n, t[NMAX], s[NMAX], F[NMAX], F2[NMAX];
void enter()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
        scanf("%d %d", &s[i], &t[i]);
}

void solve()
{
    for (int i=1; i<=n; i++)
        F[t[i]] = max(F[t[i]], t[i]-s[i]);
    for (int i=1; i <= NMAX; i++)
        F2[i] = max(F2[i-1], F[i]);
    int best = 0;
    for (int i=1; i<=n; i++)
        best = max(best, t[i]-s[i]+F2[s[i]-1]);
    printf("%d", best);
}
main()
{
    enter();
    solve();
    return 0;
}
