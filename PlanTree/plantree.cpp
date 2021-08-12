#include <bits/stdc++.h>
using namespace std;
#define NMAX 2000005
int N; int t[NMAX];
bool F[NMAX];

main()
{
    cin >> N;
    for (int i=1; i<=N; i++)
        scanf("%d", &t[i]);
    sort(t+1, t+N+1, greater<int>());

    for (int i=1; i<=N; i++) {
        int times = i + t[i];
        F[times] = true;
    }
    for (int i=NMAX; i >=0; i--)
        if (F[i]!=0) {
            cout << i+1;
            break;
        }
}
