#include <bits/stdc++.h>
using namespace std;
#define NMAX 10006

int A[NMAX];
int m,n;
bool visited[NMAX];
void solution() {
    for (int i=1; i<=m; i++) cout << A[i] << " ";
    cout << endl;
}
void TRY(int k)
{
    for (int i=1; i<=n; i++) {
        if (visited[i] == false) {
            visited[i] = true;
            A[k] = i;
            if (k == m) solution();
            else TRY(k+1);
            visited[i] = false;
        }
    }
}
int main() {
    cin >> m >> n;
    TRY(1);
    return 0;
}
