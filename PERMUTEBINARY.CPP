#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int n;
int x[MAX];

void solution() {
    for(int i = 1; i <= n; i++)
        cout<< x[i];
    cout << endl;
}

void TRY(int k) {
    for (int i = 0; i <= 1; i++) {
        x[k] = i;
        if(k==n) solution();
        else TRY(k+1);
    }
}
int main() {
    cin >> n;
    //TRY(1);
    for (int i=1; i<= pow(2, n); i++){

    }
}
