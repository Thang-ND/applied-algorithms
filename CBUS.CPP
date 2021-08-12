#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

int n, K;
int c[MAX][MAX];
long long best = INT_MAX;
long long currRes;
int x[MAX];
bool visited[MAX];
int numOfK;
int cMin = INT_MAX;
void input() {
    cin >> n >> K;
    for (int i=0; i <= 2*n; i++) {
        for (int j=0; j <= 2*n; j++){
            cin >> c[i][j];
            if (c[i][j] < cMin && c[i][j] !=0) cMin = c[i][j];
        }
    }
}
void output() {
    for (int i=0; i <= 2*n; i++) {
        cout << x[i] << "->";
    }
    cout << endl;
}
bool check(int i, int k) {
    // i is ith place
    if (visited[i]== true) return false;
    else {
        if (i <= n) {
            if (numOfK < K) return true;
            else return false;
        }else {
            if (visited[i-n] == false) return false;
            else return true;
        }
    }

}
void TRY(int k) {
    for (int i=1; i <= 2*n; i++) {
        if (check(i, k)) {
            x[k] = i;
            visited[i] = true;
            currRes += c[x[k-1]][i];
            if (i <= n) numOfK++;
            else numOfK--;

            if (k == 2*n) {
                best = min (best, currRes + c[x[2*n]][0]);
                //output();
            } else {
                long long g = currRes + (2*n - k + 1)*cMin;
                if(g < best) TRY(k+1);
            }
            if (i <= n) numOfK--;
            else numOfK++;
            visited[i] = false;
            currRes -= c[x[k-1]][i];
        }
    }
}

int main() {
    freopen("a.inp", "r", stdin);
    input();
    x[0] = 0;
    TRY(1);
    cout << best << endl;

}
