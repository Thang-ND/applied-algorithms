#include <bits/stdc++.h>
using namespace std;
#define MAX 100006
#define int int
int n;
vector<int> result;
int L[MAX], R[MAX];
int kq;
int Stack[MAX];
int top;
int a[MAX];
int m;
int main() {
    do {
        cin >> m;
        if(m==0) break;

        for(int i = 1; i <= m; i++){
            cin >> a[i];
        }

        Stack[0]=0; top=0;
        for(int i = 1; i<=m; i++) {
            while( (top>0) && (a[ Stack[top] ] >= a[i])) top--;
            L[i] = Stack[top] + 1; // vi tri dau tien ve ben trai ma nho hon a[i]
            top++;
            Stack[top] = i;
        }

        Stack[m+1] = 0; top=0;
        for(int i=m; i>=1; i--) {
            while( (top>0) && (a[Stack[top]] >= a[i])) top--;
            R[i] = Stack[top] - 1;
            top++;
            Stack[top] = i;
        }
        for(int i=1; i<=m; i++) {
            kq = max(kq, (R[i]-L[i]+1)*a[i]);
        }
        cout << kq << endl;

    }while(true);
    return 0;
}
