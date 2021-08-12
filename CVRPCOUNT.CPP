#include <bits/stdc++.h>
using namespace std;
#define N 100000

int K, Q, n;
int d[N];
bool visited[N];
int currQ;
void input() {
    cin >> n >> K >> Q;
    for (int i=1; i <= n; i++)
        cin >> d[i];
}

bool check(int i, int k) {
    if(visited[i]==true) return false;
    else {
            if (currQ - d[i] >= 0) return true;
            else return false;
    }
}

void TRY(int k) {
    for (int i=0; i <= n; i++) {
        if (check(i, k)) {

        } else {
            if (i == n && k != n)
        }
    }
}

int main() {
    input();

    return 0;
}
