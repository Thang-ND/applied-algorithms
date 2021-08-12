#include <bits/stdc++.h>
using namespace std;
#define NMAX 105

int n, A[NMAX], T[NMAX];
vector<int> arr_0;
vector<int> arr_1;
vector<int> arr_neg;
void input() {
    cin >> n;
    int u;
    for (int i=1; i<=n; i++) {
        cin >> u;
        if (u>0) arr_1.push_back(u);
        else if (u==0) arr_0.push_back(u);
        else arr_neg.push_back(u);
    }
}
main () {
    input();
    int size_1, size_neg;
    size_1 = arr_1.size();
    size_neg = arr_neg.size();
    if (size_1 == 0) {
        size_1 = 2;
        arr_1.push_back(arr_neg[size_neg-1]);
        arr_1.push_back(arr_neg[size_neg-2]);
        size_neg -= 2;
    }
    if (size_neg % 2 == 0) {
            size_neg--;
            arr_0.push_back(arr_neg[size_neg]);
    }
    cout << size_neg << " ";
    for (int i=0; i<size_neg; i++) cout << arr_neg[i] << " ";
    cout << endl;
    cout << size_1 << " ";
    for (int i=0; i<size_1; i++) cout << arr_1[i] << " ";
    cout << endl;
    cout << arr_0.size() << " ";
    for (int i=0; i<arr_0.size(); i++) cout << arr_0[i] << " ";
    cout << endl;
}
