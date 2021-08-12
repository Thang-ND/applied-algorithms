#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int N, M;
int c[MAX];
int A[MAX][MAX];
long long loadPer[MAX];
long long best = INT_MAX;
int cnt=0;
int x[MAX];
bool visited[MAX];

void input() {
    cin >> N >> M;
    for (int i=1; i <= N; i++)
        cin >> c[i];
    for (int i=1; i <= N; i++) {
        for (int j=1; j <= N; j++) {
            cin >> A[i][j];
        }
    }
}

bool check(int i, int k) {
    // i is ith cources, k is kth periods
    for (int j = 1; j <= N; j++)
        if (A[j][i] == 1) {
            if(x[j] != 0 && x[j] >= k)
                return false;
        }
    return true;
}
void output() {
    for (int i=1; i <= M; i++) {
        cout << loadPer[i] << "->";
    } cout << endl;
}
void solution() {
    //output();
    //cout << ++cnt << endl;
    //sort(loadPer+1, loadPer+M+1);
    long long maxE = loadPer[1];
      for (int i = 2; i <= M; i++)
        if (loadPer[i] > maxE)
            maxE = loadPer[i];
    best = min(best, maxE);

}
void TRY(int k) {
    for (int i=1; i <= M; i++) {
        if (check(i, k)) {
            x[k] = i;
            loadPer[i] += c[k];
            if (k == N) solution();
            else {
                if (loadPer[i] <= best)
                    TRY(k+1);
            }
            loadPer[i] -= c[k];
            //x[k] = 0;
        }
    }
}
int main() {
    //freopen("a.inp", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    TRY(1);
    cout << best;
}
